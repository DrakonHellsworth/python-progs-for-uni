import random

# Define card values
card_values = {
    '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10,
    'J': 10, 'Q': 10, 'K': 10, 'A': 11
}

# ASCII Art for Cards
card_art = {
    'A': [
        " ___ ",
        "|A      |",
        "|+   *  |",
        "|    !  |",
        "|  -+-|",
        "|    |  |",
        "|   ~+|",
        "|      V|",
        " ~~~~"
    ],
    'K': [
        " ___ ",
        "|K |/|\\|  |",
        "|+ /o,o\\ |",
        "|  \\-/  |",
        "| -_--_ |",
        "|  /-\\  |",
        "|  \\o`o/ +|",
        "|  |\\|/| X|",
        " ~~~"
    ],
    'Q': [
        " ___ ",
        "|Q |~|  |",
        "|+ /o,o\\  |",
        "|  \\-/  |",
        "| -~+-~ |",
        "|  /-\\  |",
        "|  \\o`o/ +|",
        "|  |_| Q|",
        " ~~~"
    ],
    'J': [
        " ___ ",
        "|J /~~|_  |",
        "|+ | o`,  |",
        "|  | -|   |",
        "| =~)+(_= |",
        "|   |- |  |",
        "|  `.o | +|",
        "|  ~|__/ P|",
        " ~~~"
    ],
    '10': [
        " ___ ",
        "|10+   +  |",
        "|+   +    |",
        "|  +   +  |",
        "|         |",
        "|  +   +  |",
        "|    +   +|",
        "|  +   +0l|",
        " ~~~"
    ],
    '9': [
        " ___ ",
        "|9 +   +  |",
        "|+        |",
        "|  +   +  |",
        "|    +    |",
        "|  +   +  |",
        "|        +|",
        "|  +   + 6|",
        " ~~~"
    ],
    '8': [
        " ___ ",
        "|8 +   +  |",
        "|+        |",
        "|  +   +  |",
        "|         |",
        "|  +   +  |",
        "|        +|",
        "|  +   + 8|",
        " ~~~"
    ],
    '7': [
        " ___ ",
        "|7        |",
        "|+ +   +  |",
        "|    +    |",
        "|  +   +  |",
        "|         |",
        "|  +   + +|",
        "|        L|",
        " ~~~"
    ],
    '6': [
        " ___ ",
        "|6        |",
        "|+ +   +  |",
        "|         |",
        "|  +   +  |",
        "|         |",
        "|  +   + +|",
        "|        9|",
        " ~~~"
    ],
    '5': [
        " ___ ",
        "|5        |",
        "|+        |",
        "|  +   +  |",
        "|    +    |",
        "|  +   +  |",
        "|        +|",
        "|        S|",
        " ~~~"
    ],
    '4': [
        " ___ ",
        "|4        |",
        "|+        |",
        "|  +   +  |",
        "|         |",
        "|  +   +  |",
        "|        +|",
        "|        b|",
        " ~~~"
    ],
    '3': [
        " ___ ",
        "|3        |",
        "|+   +    |",
        "|         |",
        "|    +    |",
        "|         |",
        "|    +   +|",
        "|        E|",
        " ~~~"
    ],
    '2': [
        " ___ ",
        "|2        |",
        "|+        |",
        "|    +    |",
        "|         |",
        "|    +    |",
        "|        +|",
        "|        Z|",
        " ~~~"
    ]
}

# Define the deck
def create_deck():
    deck = []
    for card in card_values.keys():
        deck.append(card)
    return deck * 4  # Four suits

# Deal a card
def deal_card(deck):
    return deck.pop(random.randint(0, len(deck) - 1))

# Calculate the score
def calculate_score(hand):
    score = 0
    ace_count = hand.count('A')
    for card in hand:
        score += card_values[card]
    
    # Adjust for aces
    while score > 21 and ace_count:
        score -= 10
        ace_count -= 1
    
    return score

# Display the hand with ASCII art
def display_hand(hand, name):
    print(f"{name}'s hand:")
    for card in hand:
        for line in card_art[card]:
            print(line)
    print(f"Score: {calculate_score(hand)}\n")

# Main game function
def play_blackjack():
    print("Welcome to Blackjack!")
    
    # Create and shuffle deck
    deck = create_deck()
    random.shuffle(deck)

    # Deal initial cards
    player_hand = [deal_card(deck), deal_card(deck)]
    dealer_hand = [deal_card(deck), deal_card(deck)]

    # Show initial hands
    display_hand(player_hand, "Player")
    print(f"Dealer's hand: {card_art[dealer_hand[0]][0]}\n{card_art[dealer_hand[0]][1]}\n{card_art[dealer_hand[0]][2]}\n{card_art[dealer_hand[0]][3]}\n{card_art[dealer_hand[0]][4]}\n{card_art[dealer_hand[0]][5]}\n{card_art[dealer_hand[0]][6]}\n{card_art[dealer_hand[0]][7]}")
    
    # Player's turn
    while calculate_score(player_hand) < 21:
        move = input("Do you want to 'hit' or 'stand'? ").lower()
        if move == 'hit':
            player_hand.append(deal_card(deck))
            display_hand(player_hand, "Player")
        elif move == 'stand':
            break
        else:
            print("Invalid choice. Please choose 'hit' or 'stand'.")

    # Dealer's turn
    if calculate_score(player_hand) <= 21:
        print("\nDealer's turn...")
        display_hand(dealer_hand, "Dealer")
        while calculate_score(dealer_hand) < 17:
            print("Dealer hits!")
            dealer_hand.append(deal_card(deck))
            display_hand(dealer_hand, "Dealer")
    
    # Determine the winner
    player_score = calculate_score(player_hand)
    dealer_score = calculate_score(dealer_hand)
    
    if player_score > 21:
        print("\nPlayer busts! Dealer wins.")
    elif dealer_score > 21:
        print("\nDealer busts! Player wins.")
    elif player_score > dealer_score:
        print("\nPlayer wins!")
    elif player_score < dealer_score:
        print("\nDealer wins!")
    else:
        print("\nIt's a tie!")

# Play the game
if name == "_main_":
    play_blackjack()