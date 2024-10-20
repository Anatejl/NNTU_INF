def remove_last_letter(word):
    if len(word) > 0:
        return word[:-1]
    else:
        return word  # If the word is empty, return it as is.

def main():
    word = input("Enter a word: ")
    modified_word = remove_last_letter(word)
    print(f"Word after removing the last letter: {modified_word}")

if __name__ == "__main__":
    main()