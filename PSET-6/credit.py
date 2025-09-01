def LuhnAlgoritm(number):
    digits = [int(d) for d in str(number)][::-1]

    for i in range(1, len(digits), 2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9

    return sum(digits) % 10 == 0


def PrintCardFlag(number):
    number_str = str(number)

    if number_str.startswith(("34", "37")) and len(number_str) == 15:
        print("AMEX")
    elif number_str[:2] in map(str, range(51, 56)) and len(number_str) == 16:
        print("MASTERCARD")
    elif number_str.startswith("4") and len(number_str) in (13, 16):
        print("VISA")
    else:
        print("INVALID")


number = input("Informe um número: ")
if LuhnAlgoritm(number):
    PrintCardFlag(number)
else:
    print("INVALID")
