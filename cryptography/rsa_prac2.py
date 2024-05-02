import random
from sympy import isprime, gcd, invert

def generate_prime(n:int)->int:
    while True:
        num = random.randrange(2**(n-1), 2**n)
        if isprime(num):
            return num
        
def choose_e(phi_n):
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
    
    d = int(invert(e, phi_n)) # e.d === 1 mod phi_n
    
    return (e, n), (d, n)

def encrypt(text:str, pub_key)->int:
    e, n= pub_key
    
    # convert plaintext into bytes
    
    plaintext_bytes = text.encode()
    
    # get integer representation of plaintext bytes
    
    m = int.from_bytes(plaintext_bytes)
    c = pow(m, e, n)
    return c

def decrypt(ciphertext:int, pri_key)->str:
    d, n = pri_key
    m = pow(ciphertext, d, n)
    
    m_byte_length = (m.bit_length()+7)//8
    
    #get the bytes of the message
    m_bytes = m.to_bytes(m_byte_length, 'big')
    
    #decode the bytes
    message = m_bytes.decode()
    
    return message

message = "hello"
public_key, private_key = generate_rsa_keys()
encrypted = encrypt(message, public_key)
print(encrypted)

decrypted = decrypt(encrypted, private_key)
print(decrypted)
    
    