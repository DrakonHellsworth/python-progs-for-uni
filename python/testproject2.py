import pygame

# Initialize pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 500, 500
TILE_SIZE = 50
ROWS, COLS = 10, 10
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

# Maze layout (P = Player, E = Exit, # = Wall)
maze = [
    "##########",
    "#P   #   #",
    "# ## # # #",
    "#    #   #",
    "###### ###",
    "#   #    #",
    "# # #### #",
    "# #    #E#",
    "##########"
]

# Find player start position
player_x, player_y = 0, 0
for y, row in enumerate(maze):
    for x, tile in enumerate(row):
        if tile == "P":
            player_x, player_y = x, y

# Setup Pygame window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Maze Runner")

def draw_maze():
    """Draws the maze grid."""
    screen.fill(WHITE)
    for y, row in enumerate(maze):
        for x, tile in enumerate(row):
            rect = pygame.Rect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE)
            if tile == "#":
                pygame.draw.rect(screen, BLACK, rect)  # Walls
            elif tile == "E":
                pygame.draw.rect(screen, GREEN, rect)  # Exit
    pygame.draw.rect(screen, BLUE, (player_x * TILE_SIZE, player_y * TILE_SIZE, TILE_SIZE, TILE_SIZE))  # Player
    pygame.display.flip()

running = True
while running:
    pygame.time.delay(100)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()

    new_x, new_y = player_x, player_y
    if keys[pygame.K_UP]:
        new_y -= 1
    elif keys[pygame.K_DOWN]:
        new_y += 1
    elif keys[pygame.K_LEFT]:
        new_x -= 1
    elif keys[pygame.K_RIGHT]:
        new_x += 1

    # Check collision
    if maze[new_y][new_x] != "#":
        player_x, player_y = new_x, new_y

    # Check win condition
    if maze[player_y][player_x] == "E":
        print("You win!")
        running = False

    draw_maze()

pygame.quit()
