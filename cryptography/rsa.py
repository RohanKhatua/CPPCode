import random
from sympy import isprime, gcd
from sympy import invert

# Function to generate large prime numbers
def generate_prime(n):
    while True:
        prime_candidate = random.randrange(2**(n-1), 2**n)
        if isprime(prime_candidate):
            return prime_candidate

# RSA Key Generation
def generate_rsa_keys():
    p = generate_prime(512)
    q = generate_prime(512)
    n = p * q
    phi_n = (p-1) * (q-1)

    # Choose e
    e = random.randrange(2, phi_n)
    while gcd(e, phi_n) != 1:
        e = random.randrange(2, phi_n)

    # Compute d and convert to int
    d = int(invert(e, phi_n))

    # Public key: (e, n), Private key: (d, n)
    return ((e, n), (d, n))

# Encryption
def encrypt(plaintext, public_key):
    e, n = public_key
    # Convert plaintext to a number (simple conversion for demonstration)
    m = int.from_bytes(plaintext.encode('utf-8'), 'big')
    c = pow(m, e, n)
    return c

# Decryption
def decrypt(ciphertext, private_key):
    d, n = private_key
    m = pow(ciphertext, d, n)
    # Convert number back to plaintext
    plaintext = m.to_bytes((m.bit_length() + 7) // 8, 'big').decode('utf-8')
    return plaintext

public_key, private_key = generate_rsa_keys()
message = input("Enter Message : ")
encrypted_message = encrypt(message, public_key)
decrypted_message = decrypt(encrypted_message, private_key)

print(f"Original: {message}")
print(f"Encrypted: {encrypted_message}")
print(f"Decrypted: {decrypted_message}")
