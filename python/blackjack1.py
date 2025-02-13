import random as r
def create_deck():
    deck=[]
    for s in ["Hearts","Diamonds","Spades","Clubs"]:
        for v in ["2","3","4","5","6","7","8","9","10","J","Q","K","A"]:
            deck.append((v,s))
    r.shuffle(deck)
    return deck
def deal(deck):
    return deck.pop() if deck else None
def calc(hand):
    value=0
    aces=0
    for card in hand:
        if card[0] in ["J","Q","K"]:
            value+=10
        elif card[0]=="A":
            value+=11
            aces+=1
        else:
            value+=int(card[0])
    while value>21 and aces:
        value-=10
        aces-=1
    return value
def bj():
    deck=create_deck()
    player=[deal(deck),deal(deck)]
    computer=[deal(deck),deal(deck)]
    print(f"\nYour cards: {player}")
    print(f"Computer's visible card: {computer[0]}")
    while True:
        print(f"Your score: {calc(player)}")
        choice=input("\nDo you want another card? (y/n): ").lower()
        if choice=="y":
            player.append(deal(deck))
            print(f"\nYour cards: {player}")
            if calc(player)>21:
                print("You lose! BOOOOOOOOOOOOOO")
                return
        else:
            break
    while calc(computer)<17:
        computer.append(deal(deck))
    print(f"\nComputer's final cards: {computer}")
    print(f"Your score: {calc(player)} | Computer's score: {calc(computer)}")
    if calc(computer)>21 or calc(player)>calc(computer):
        print("You win!")
    else:
        print("You lose!")
bj()
