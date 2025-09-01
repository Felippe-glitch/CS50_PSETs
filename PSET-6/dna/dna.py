import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Uso: python dna.py banco.csv sequencia.txt")
        sys.exit(1)

    with open(sys.argv[1], newline='') as db_file:
        reader = csv.DictReader(db_file)
        database = list(reader)
        str_keys = reader.fieldnames[1:]

    with open(sys.argv[2]) as seq_file:
        sequence = seq_file.read()

    str_counts = {key: longest_match(sequence, key) for key in str_keys}

    for person in database:
        if all(int(person[str_key]) == str_counts[str_key] for str_key in str_keys):
            print(person['name'])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Retorna o maior número de repetições consecutivas de `subsequence` em `sequence`."""
    longest_run = 0
    sub_len = len(subsequence)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while sequence[i + count * sub_len:i + (count + 1) * sub_len] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
