class VigenereCipher:
    def __init__(self, key):
        self.key = key.upper()  # Convert key to uppercase as well
        
    def replace_digits_with_words(self, text):
        num_to_word = {
            '0': 'ZERO', '1': 'ONE', '2': 'TWO', '3': 'THREE', '4': 'FOUR',
            '5': 'FIVE', '6': 'SIX', '7': 'SEVEN', '8': 'EIGHT', '9': 'NINE'
        }
        
        for digit, word in num_to_word.items():
            text = text.replace(digit, word)
            
        return text
        
    def _preprocess_text(self, text):
        # Convert to uppercase and remove spaces and special characters
        text = ''.join([char.upper() for char in text if char.isalnum()])
        # Replace digits with words
        text = self.replace_digits_with_words(text)
        print(f"Processed Text = {text}")
        return text
        
    def _shift_char(self, char, shift):
        if char.isalpha():
            shift = shift % 26
            shifted = ord(char) + shift
            
            if shifted > ord('Z'):
                shifted -= 26
            return chr(shifted)
        return char
    
    def _key_shift(self, i):
        return ord(self.key[i % len(self.key)]) - ord('A')
    
    def encrypt(self, plaintext):
        print("Encrypting...")
        plaintext = self._preprocess_text(plaintext)
        encrypted = ""
        for i, char in enumerate(plaintext):
            shift = self._key_shift(i)
            shifted_char = self._shift_char(char, shift)
            encrypted += shifted_char
            print(f"{char}-->{shifted_char} [Shift = {shift}]")
        return encrypted
    
    def decrypt(self, ciphertext):
        print("Decrypting...")
        decrypted = ""
        for i, char in enumerate(ciphertext):
            shift = -self._key_shift(i)
            shifted_char = self._shift_char(char, shift)
            decrypted += shifted_char
            print(f"{char}-->{shifted_char} [Shift = {shift}]")
        return decrypted
    
# Example usage
key = input("Enter Key : ")
message = input("Enter Message : ")    

cipher = VigenereCipher(key)
enctypted = cipher.encrypt(message)
print(f"Encrypted Text = {enctypted}")

decrypted = cipher.decrypt(enctypted)
print(f"Decrypted Text = {decrypted}")
