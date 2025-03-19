STOPWORDS = ["the", "is", "in", "and", "to", "of", "a", "that", "it", "on", "for", "with", "as", "was", "at", "by", "an", "be", "this", "which", "or", "from"]

def clean_text(text):
    for char in "!#$%&'()*+,-./:;<=>?@[\]^_`{|}~":
        text = text.replace(char, "")
    return text.lower()

def cwl(text):
    words = clean_text(text).split()
    word_counts = {}
    for word in words:
        if word not in STOPWORDS and word.isalpha():
            length = len(word)
            word_counts[length] = word_counts.get(length, 0) + 1
    return sorted(word_counts.items(), key=lambda x: x[1], reverse=True)

def display_top_n(wlcs, n):
    if n <= 0 or n > len(wlcs):
        n = len(wlcs)
    print(f"\nTop {n} Word Lengths | Frequency")
    print("-" * 30)
    for length, count in wlcs[:n]:
        print(f"{length:<15} | {count}")

def main():
    text = input("Enter your text: ")
    wlc = cwl(text)
    print("\nWord Length | Frequency")
    print("-" * 25)
    for length, count in wlc:
        print(f"{length:<12} | {count}")
    
    top_n = int(input("\nEnter the number of elements to display: "))
    display_top_n(wlc, top_n)

if __name__ == "__main__":
    main()