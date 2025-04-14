import pygame
import sys
import random

pygame.init()
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("City Simulation")

WHITE = (255, 255, 255)
GRAY = (230, 230, 230)
DARK_GRAY = (30, 30, 30)
BLUE = (70, 130, 180)
GREEN = (34, 139, 34)
LIGHT_BROWN = (255, 248, 220)
MINT = (224, 255, 255)
SHADOW = (180, 180, 180)
RED = (255, 0, 0)
ORANGE = (255, 165, 0)
PURPLE = (186, 85, 211)
GOLD = (255, 215, 0)

font = pygame.font.SysFont("arial", 36, bold=True)
small_font = pygame.font.SysFont("arial", 24)

player_balance = 300000
player_pos = [WIDTH // 2, HEIGHT - 100]
target_pos = player_pos[:]
player_speed = 4
player_radius = 20
player_color = RED
message = ""
destination = ""

class Button:
    def __init__(self, rect, color, text, text_color=WHITE):
        self.rect = pygame.Rect(rect)
        self.color = color
        self.text = text
        self.text_color = text_color
        self.hovered = False

    def draw(self, surface, highlight=False):
        border_col = GOLD if self.hovered else SHADOW
        glow_col = (min(self.color[0]+40,255), min(self.color[1]+40,255), min(self.color[2]+40,255)) if self.hovered else self.color
        pygame.draw.rect(surface, border_col, self.rect.inflate(8, 8), border_radius=12)
        pygame.draw.rect(surface, glow_col, self.rect, border_radius=12)
        txt = font.render(self.text, True, self.text_color)
        txt_rect = txt.get_rect(center=self.rect.center)
        surface.blit(txt, txt_rect)

    def is_clicked(self, pos):
        return self.rect.collidepoint(pos)

    def update_hover(self, mouse_pos):
        self.hovered = self.rect.collidepoint(mouse_pos)

class NPC:
    def __init__(self):
        self.x = random.randint(50, WIDTH - 50)
        self.y = random.randint(50, HEIGHT - 150)
        self.color = (random.randint(100,255), random.randint(100,255), random.randint(100,255))
        self.radius = 12
        self.speed = 1
        self.direction = random.choice([(1,0), (-1,0), (0,1), (0,-1)])

    def move(self):
        dx, dy = self.direction
        self.x += dx * self.speed
        self.y += dy * self.speed
        if self.x < 0 or self.x > WIDTH:
            self.direction = (-dx, dy)
        if self.y < 0 or self.y > HEIGHT:
            self.direction = (dx, -dy)

    def draw(self, surface):
        pygame.draw.circle(surface, self.color, (int(self.x), int(self.y)), self.radius)

    def animate_entry(self, surface):
        for alpha in range(0, 255, 15):
            fade = pygame.Surface((WIDTH, HEIGHT))
            fade.fill((0, 0, 0))
            fade.set_alpha(alpha)
            surface.blit(fade, (0, 0))
            pygame.display.update()
            pygame.time.delay(10)
        for alpha in range(255, 0, -15):
            fade = pygame.Surface((WIDTH, HEIGHT))
            fade.fill((0, 0, 0))
            fade.set_alpha(alpha)
            surface.blit(fade, (0, 0))
            pygame.display.update()
            pygame.time.delay(10)

library_btn = Button((150, 200, 200, 60), BLUE, "Library")
mall_btn = Button((450, 200, 200, 60), GREEN, "Mall")
tapri_btn = Button((150, 300, 200, 60), ORANGE, "Tapri")
pharmacy_btn = Button((450, 300, 200, 60), PURPLE, "Pharmacy")

books = {
    "The God of Small Things": {"copies": 3, "author": "Arundhati Roy", "year": 1997},
    "Midnight's Children": {"copies": 2, "author": "Salman Rushdie", "year": 1981},
    "A Suitable Boy": {"copies": 4, "author": "Vikram Seth", "year": 1993}
}

borrowed_books = {}

shops = {
    "Clothing": {"Shirt": {"price": 699, "stock": 19}, "Jeans": {"price": 1499, "stock": 7}},
    "Electronics": {"Phone": {"price": 99900, "stock": 4}, "Laptop": {"price": 140000, "stock": 2}},
    "Food Court": {"Pizza": {"price": 299, "stock": 100}, "Burger": {"price": 149, "stock": 250}}
}

cart = {}

tapri_menu = {
    "Tea": {
        "Masala Chai": {"price": 15, "stock": 100},
        "Ginger Tea": {"price": 20, "stock": 80},
        "Lemon Tea": {"price": 25, "stock": 60}
    },
    "Snacks": {
        "Samosa": {"price": 10, "stock": 150},
        "Vada Pav": {"price": 15, "stock": 100},
        "Pakora": {"price": 30, "stock": 50}
    },
    "Cigarettes": {
        "Gold Flake": {"price": 150, "stock": 60},
        "Choti Gold": {"price": 300, "stock": 40},
        "Badi Gold": {"price": 140, "stock": 50},
        "Choti Advance": {"price": 400, "stock": 25},
        "Marbalo Lite": {"price": 200, "stock": 35},
        "David Of": {"price": 120, "stock": 45},
        "Marbalo Red": {"price": 100, "stock": 55}
    }
}

pharmacy_items = {
    "Paracetamol": {"price": 25, "stock": 50},
    "Bandage": {"price": 50, "stock": 30},
    "Sanitizer": {"price": 100, "stock": 40},
    "Aspirin": {"price": 15, "stock": 20},
    "Cough Syrup": {"price": 50, "stock": 15},
    "Antibiotic": {"price": 100, "stock": 10}
}

# Generate buttons for tapri items
item_buttons = []
x, y = 50, 400
for category, items in tapri_menu.items():
    for item, data in items.items():
        btn = Button((x, y, 200, 40), ORANGE, f"{item} - ₹{data['price']}")
        item_buttons.append((btn, item, category))
        y += 50
        if y > HEIGHT - 50:
            y = 400
            x += 220

# Generate buttons for pharmacy items
pharmacy_buttons = []
x, y = 50, 150
for item, data in pharmacy_items.items():
    btn = Button((x, y, 300, 40), PURPLE, f"{item} - ₹{data['price']}")
    pharmacy_buttons.append((btn, item))
    y += 50

# Create NPCs
npcs = [NPC() for _ in range(6)]