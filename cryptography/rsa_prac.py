import random
from sympy import isprime, gcd, invert


def generate_prime(n: int) -> int:
    """
    Generates a prime number of n bits.

    Args:
        n (int): The number of bits for the prime number.

    Returns:
        int: A prime number of n bits.
    """
    while True:
        prime_candidate = random.randrange(2 ** (n - 1), 2 ** n)
        if isprime(prime_candidate):
            return prime_candidate


def choose_e(phi_n:int) -> int:
    """
    Choose a value for e that is coprime with phi_n.

    Parameters:
    phi_n (int): The value of phi_n.

    Returns:
    int: The chosen value of e.
    """
    while True:
        e = random.randrange(2, phi_n)
        if gcd(e, phi_n) == 1:
            return e


def generate_rsa_keys() -> tuple[tuple[int, int], tuple[int, int]]:
    """
    Generates RSA key pairs.

    Returns:
        A tuple containing two tuples:
        - The first tuple contains the public key (e, n).
        - The second tuple contains the private key (d, n).
    """
    p = generate_prime(512)
    q = generate_prime(512)

    n = p * q
    phi_n = (p-1)*(q-1)

    e = choose_e(phi_n)

    d = int(invert(e, phi_n))

    return (e, n), (d, n)


def encrypt(plaintext: str, pub_key: tuple[int, int]) -> int:
    """
    Encrypts the given plaintext using the provided public key.

    Args:
        plaintext (str): The plaintext to be encrypted.
        pub_key (tuple[int, int]): The public key used for encryption.

    Returns:
        int: The ciphertext obtained after encrypting the plaintext.
    """
    e, n = pub_key

    # encode plaintext into bytes
    plaintext_bytes = plaintext.encode()

    # get the integer representation of bytes
    m = int.from_bytes(plaintext_bytes, 'big')
    ciphertext = pow(m, e, n)
    return ciphertext


def decrypt(ciphertext: int, pri_key: tuple[int, int]) -> str:
    """
    Decrypts a ciphertext using the provided private key.

    Args:
        ciphertext (int): The encrypted message to be decrypted.
        pri_key (tuple[int, int]): The private key used for decryption.

    Returns:
        str: The decrypted message.

    """
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



