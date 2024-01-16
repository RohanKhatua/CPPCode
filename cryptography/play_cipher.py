class PlayfairCipher:
    def __init__ (self, keyword):
        self.matrix = self.create_matrix(keyword)

    # This function creates the 5x5 matrix for the cipher
    def create_matrix(self, keyword):
        alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ" # J is omitted
        matrix = []

        # Appending keyword to matrix excluding duplicates

        for c in keyword.upper():
            if c not in matrix and c in alphabet:
                matrix.append(c)

        # Appending remaining alphabet to matrix
                
        for c in alphabet:
            if c not in matrix:
                matrix.append(c)              
                        
        print("Cipher Matrix : ")
        
        for i in range (5) :
            for j in range (5) :
                print(matrix[5*i+j], end=" ")
            print()  
            
        return [matrix[i:i + 5] for i in range(0, 25, 5)]
    
    def replace_digits_with_words(self, text):
        num_to_word = {
        '0': 'ZERO', '1': 'ONE', '2': 'TWO', '3': 'THREE', '4': 'FOUR',
        '5': 'FIVE', '6': 'SIX', '7': 'SEVEN', '8': 'EIGHT', '9': 'NINE'
        }
        
        for digit, word in num_to_word.items():
            text = text.replace(digit, word)
            
        return text
    
    # This function prepares the plaintext for encryption
    def preprocess (self, text):
        
        text = text.upper() #Convert to uppercase
        text = self.replace_digits_with_words(text) # Replace digits with spelled out numbers
        text = text.replace("J", "I") # Replace J with I
        text = ''.join([char for char in text if char.isalpha()]) # Remove all non-alphabetic characters such as spaces anb punctuation
        processed_text = ""

        i = 0
        while i < len(text):
            # Same letter in digram
            if i + 1 < len(text) and text[i] == text[i+1]:
                processed_text += text[i] + "X" # Add X to separate repeated letters
                i+=1
            else: 
                processed_text += text[i]
                if i+1 < len(text):
                    processed_text += text[i+1]
                i+=2
                
        if len(processed_text) %2 !=0:
            processed_text += "X" # Add X at the end if number of characters is odd
            
        print ("Processed Text =", processed_text)    
        return processed_text
    
    def find_position (self, char):
        for i, row in enumerate(self.matrix):
            for j, matrix_char in enumerate(row):
                if matrix_char == char:
                    return i, j                
        return 0, 0
    
    def encrypt_pair (self, a, b):
        row_a, col_a = self.find_position(a)
        row_b, col_b = self.find_position(b)
        
        if row_a == row_b:
            return self.matrix[row_a][(col_a + 1)%5] + self.matrix[row_b][(col_b + 1)%5]
        elif col_a == col_b:
            return self.matrix[(row_a+1)%5][col_a] + self.matrix[(row_b+1)%5][col_b]
        else:
            return self.matrix[row_a][col_b] + self.matrix[row_b][col_a]
        
    def decrypt_pair (self, a, b):
        row_a, col_a = self.find_position(a)
        row_b, col_b = self.find_position(b)
        
        if row_a == row_b:
            return self.matrix[row_a][(col_a-1)%5] + self.matrix[row_b][(col_b-1)%5]
        elif col_a == col_b:
            return self.matrix[(row_a-1)%5][col_a] + self.matrix[(row_b-1)%5][col_b]
        else:
            return self.matrix[row_a][col_b] + self.matrix[row_b][col_a]
        
    def encrypt (self, plaintext):
        print("Encrypting...")
        plaintext = self.preprocess(plaintext)
        res = ''
        for i in range(0, len(plaintext), 2):
            digram = plaintext[i]+plaintext[i+1]
            encrypted_pair = self.encrypt_pair(plaintext[i],plaintext[i+1])
            res = res + encrypted_pair
            print("[{}]-->[{}]".format(digram, encrypted_pair))
        return res
        
    def decrypt (self, ciphertext):
        print("Decrypting...")
        res = ''
        for i in range (0, len(ciphertext), 2):
            digram = ciphertext[i]+ciphertext[i+1]
            decrypted_pair = self.decrypt_pair(ciphertext[i], ciphertext[i+1])
            res = res + decrypted_pair
            print("[{}]-->[{}]".format(digram, decrypted_pair))
        return res       
                
                
keyword = input("Keyword : ")
plaintext = input("Plaintext : ")

cipher = PlayfairCipher(keyword)
cipher_text = cipher.encrypt(plaintext)
print("Encrypted Text =", cipher_text)

decrypted_text = cipher.decrypt(cipher_text)
print("Decrypted Text =", decrypted_text)