import hashlib

# Create a hash object
h = hashlib.sha512()

plaintext = input("Enter Message : ")
plaintext_bytes = plaintext.encode("utf-8") # encode the plaintext using utf-8
h.update(plaintext_bytes)

# Get the hash digest
digest = h.hexdigest()

# Print the hash digest
print(f"Hash = {digest}")