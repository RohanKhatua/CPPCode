import random
from sympy import isprime, gcd, invert


def generate_prime(n: int) -> int:
    while True:
        prime_candidate = random.randrange(2 ** (n - 1), 2 ** n)
        if isprime(prime_candidate):
            return prime_candidate


def choose_e(phi_n:int) -> int:
    while True:
        e = random.randrange(2, phi_n)
        if gcd(e, phi_n) == 1:
            return e


def generate_rsa_keys():
    p = generate_prime(512)
    q = generate_prime(512)

    n = p * q
    phi_n = (p-1)*(q-1)

    e = choose_e(phi_n)

    d = int(invert(e, phi_n))

    return (e, n), (d, n)


def encrypt(plaintext:str, pub_key) -> int:
    e, n = pub_key

    # encode plaintext into bytes
    plaintext_bytes = plaintext.encode()

    # get the integer representation of bytes
    m = int.from_bytes(plaintext_bytes, 'big')
    ciphertext = pow(m, e, n)
    return ciphertext


def decrypt(ciphertext: int, pri_key) -> str:
    d, n = pri_key
    m = pow(ciphertext, d, n)

    m_byte_length = (m.bit_length()+7)//8

    # byte representation of message
    m_bytes = m.to_bytes(m_byte_length, 'big')

    # decode the message from bytes
    decrypted = m_bytes.decode()

    return decrypted


message = "hello"
public_key, private_key = generate_rsa_keys()
encrypted = encrypt(message, public_key)
print(encrypted)

decrypted = decrypt(encrypted, private_key)
print(decrypted)



