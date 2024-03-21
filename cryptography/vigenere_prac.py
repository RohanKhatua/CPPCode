def replace_digits_with_words(text: str) -> str:
    digits_to_words = {
        '0': 'ZERO',
        '1': 'ONE',
        '2': 'TWO',
        '3': 'THREE',
        '4': 'FOUR',
        '5': 'FIVE',
        '6': 'SIX',
        '7': 'SEVEN',
        '8': 'EIGHT',
        '9': 'NINE'
    }

    for digit, word in digits_to_words.items():
        text = text.replace(digit, word)

    return text


def key_shift(key:str, i:int) ->int:
    return ord(key[i%len(key)]) - ord('A')


def shift_char(char:chr, shift:int) -> chr:
    shift = shift % 26
    shifted = ord(char) + shift

    if shifted > ord('Z'):
        shifted -= 26

    return chr(shifted)


def preprocess(text: str) -> str:
    text = replace_digits_with_words(text)
    text = ''.join(char.upper() for char in text if char.isalpha())
    return text


def encrypt(plaintext:str, key:str) -> str:

    plaintext = preprocess(plaintext)

    encrypted = ""
    for i, char in enumerate(plaintext):
        shift = key_shift(key, i)
        shifted_char = shift_char(char, shift)

        encrypted += shifted_char
        print(f'{char}-->{shifted_char}[Shift={shift}]')

    return encrypted


def decrypt(ciphertext:str, key:str) -> str:


    decrypted = ""
    for i, char in enumerate(ciphertext):
        shift = - key_shift(key, i)
        shifted_char = shift_char(char, shift)

        decrypted += shifted_char

        print(f'{char}->{shifted_char}[Shift={shift}]')

    return decrypted


key = input("Enter Key : ").upper()
message = input("Enter Message : ")

encrypted_message = encrypt(message, key)
print(f'Encrypted Message = {encrypted_message}')

decrypted_message = decrypt(encrypted_message, key)
print(f'Decrypted Message = {decrypted_message}')
