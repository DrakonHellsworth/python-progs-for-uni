import random as r
class Card:
    def __init__(self,suite,value):
        self.suite=suite
        self.value=value
    def __str__(self):
        return f"{self.value} of {self.suite}"
class Deck:
    def __init__(self):
        self.cards=[]
        for suite in ["Hearts","Diamonds","Spades","Clubs"]:
            for value in ["2","3","4","5","6","7","8","9","10","J","Q","K","A"]:
                self.cards.append(Card(suite, value))
        r.shuffle(self.cards)
    def deal(self):
        return self.cards.pop() if self.cards else None

class Player:
    def __init__(self):
        self.cards=[]
        self.value=0
        self.aces=0
    def add(self,card):
        self.cards.append(card)
        if card.value in ["J","Q","K"]:
            self.value+=10
        elif card.value=="A":
            self.value+=11
            self.aces+=1
        else:
            self.value+=int(card.value)
    def calculate(self):
        while self.value>21 and self.aces:
            self.value-=10
            self.aces-=1
        return self.value

def bj():
    deck=Deck()
    player=Player()
    computer=Player()
    player.add(deck.deal())
    player.add(deck.deal())
    computer.add(deck.deal())
    computer.add(deck.deal())
    print(f"\nYour cards:{[str(card) for card in player.cards]}")
    print(f"Computer's visible card:{computer.cards[0]}")
    
    while True:
        print(f"Your score:{player.calculate()}")
        choice=input(f"\nDo you want another card? (y/n): ").lower()
        if choice=="y":
            player.add(deck.deal())
            print(f"\nYour cards:{[str(card) for card in player.cards]}")
            if player.calculate()>21:
                print("You lose!,BOOOOOOOOOOOOOO")
                return
        else:
            break
    while computer.calculate()<17:
        computer.add(deck.deal())
    print(f"\nComputer's final cards:{[str(card) for card in computer.cards]}")
    print(f"Your score: {player.calculate()} | Computer's score: { computer.calculate()}")
    if computer.calculate()>21 or player.calculate()>computer.calculate():
        print("You win!")
    else:
        print("You lose!")
bj()
