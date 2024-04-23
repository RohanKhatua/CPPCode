import hashlib

# Create a hashlib object for MD5
h = hashlib.md5()

plaintext = input("Enter Message : ")
plaintext_bytes = plaintext.encode("utf-8") #Encode the message using utf-8
h.update(plaintext_bytes)

# Get the hash digest
digest = h.hexdigest()

print(f"Hash = {digest}")
