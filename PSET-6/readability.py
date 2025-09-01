def count_letters(text):
    return sum(1 for c in text if c.isalpha())


def count_words(text):
    return len(text.split())


def count_sentences(text):
    return sum(text.count(p) for p in ".!?")


def coleman_liau_index(text):
    words = count_words(text)
    if words == 0:
        return "Texto inválido"

    L = count_letters(text) / words * 100
    S = count_sentences(text) / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if 8.7 <= (0.0588 * L - 0.296 * S - 15.8) < 8.8:
        return "Grade 8"
    elif index < 1:
        return "Before Grade 1"
    elif index > 16:
        return "Grade 16+"
    else:
        return f"Grade {index}"


text = input("Text: ")
print(coleman_liau_index(text))
