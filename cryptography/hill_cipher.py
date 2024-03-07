import numpy as np
from sympy import Matrix

def text_to_numbers(text):
    return [ord(char) - ord('A') for char in text]

def numbers_to_text(numbers):
    return ''.join(chr(num + ord('A')) for num in numbers)

class HillCipher:
    def __init__(self, key_matrix):
        self.key_matrix = Matrix(key_matrix)
        self.inverse_key_matrix = self.key_matrix.inv_mod(26)
        
    def replace_digits_with_words(self, text):
        num_to_word = {
        '0': 'ZERO', '1': 'ONE', '2': 'TWO', '3': 'THREE', '4': 'FOUR',
        '5': 'FIVE', '6': 'SIX', '7': 'SEVEN', '8': 'EIGHT', '9': 'NINE'
        }
        
        for digit, word in num_to_word.items():
            text = text.replace(digit, word)
            
        return text
        
    def preprocess(self, text):
        text = text.upper()
        text = self.replace_digits_with_words(text)
        text = ''.join([char for char in text if char.isalpha()])
        if len(text) % 2 != 0:
            text += 'X'
        print(f"Processed text = {text}")
        return text
        
    def encrypt(self, plaintext):
        print("Encrypting...")
        plaintext = self.preprocess(plaintext)   
        encrypted = ""
        for i in range(0, len(plaintext), 2):
            vector = Matrix(2, 1, text_to_numbers(plaintext[i:i+2]))
            result_vector = (self.key_matrix * vector) % 26
            initial = numbers_to_text(list(vector))
            res = numbers_to_text(list(result_vector))
            # print(f"[{initial}]-->[{res}]")
            encrypted += res
            
        return encrypted
    
    def decrypt(self, ciphertext):
        print("Decrypting...")
        decrypted = ""
        for i in range(0, len(ciphertext), 2):
            vector = Matrix(2, 1, text_to_numbers(ciphertext[i:i+2]))
            result_vector = (self.inverse_key_matrix * vector) % 26
            initial = numbers_to_text(list(vector))
            res = numbers_to_text(list(result_vector))
            # print(f"[{initial}]-->[{res}]")
            decrypted += res

        return decrypted
    
    
key_matrix = [[2, 3], [1, 4]] #Invertible under modulo 26
cipher = HillCipher(key_matrix)

message = input("Enter Message : ")

encrypted = cipher.encrypt(message)
print(f"Encrypted : {encrypted}")

decrypted = cipher.decrypt(encrypted)
print(f"Decrypted : {decrypted}")