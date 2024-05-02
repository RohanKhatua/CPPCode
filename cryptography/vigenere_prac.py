def replace_digits_with_words(text:str)->str:
    digits_to_words = {
        0: 'ZERO',
        1: 'ONE',
        2: 'TWO',
        3: 'THREE',
        4: 'FOUR',
        5: 'FIVE',
        6: 'SIX',
        7: 'SEVEN',
        8: 'EIGHT',
        9: 'NINE'
    }
    
    for digit, word in digits_to_words.items():
        text = text.replace(str(digit), word)
        
    return text

def preprocess_text(text:str):
    text = replace_digits_with_words(text)
    text = ''.join(char.upper() for char in text if char.isalpha())
    
    return text

def key_shift(key:str, i:int)->int:
    key_len = len(key)
    return ord(key[i%key_len]) - ord('A')

def shift_char(char:str, shift:int)->str:
    shift = shift % 26
    shifted = ord(char) + shift
    if shifted>ord('Z'):
        shifted -= 26
    return chr(shifted)

def encrypt(text:str, key:str)->str:
    print("Encrypting...")
    text = preprocess_text(text)
    encrypted = ''
    for i,char in enumerate(text):
        shift = key_shift(key, i)
        shifted_char = shift_char(char, shift)
        print(f'[{char}]-->[{shifted_char}]')
        encrypted += shifted_char
    return encrypted

def decrypt(text:str, key:str)->str:
    print("Decrypting...")
    decrypted = ''
    for i, char in enumerate(text):
        shift = - key_shift(key, i)
        shifted_char = shift_char(char, shift)
        print(f'[{char}]-->[{shifted_char}]')
        decrypted += shifted_char
    return decrypted

message = input('Enter Message : ')
key = input('Enter Key : ')
key = key.upper()

encrypted = encrypt(message, key)
print(f"Encrypted = {encrypted}")

decrypted = decrypt(encrypted, key)
print(f"Decrypted = {decrypted}")


        