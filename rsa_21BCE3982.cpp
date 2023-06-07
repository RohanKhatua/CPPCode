#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the modular exponentiation
int modPow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    int p = 61; // Prime number p
    int q = 53; // Prime number q

    int modulus = p * q;         // Modulus
    int phi = (p - 1) * (q - 1); // Euler's Totient Function

    int publicKey = 17;    // Public key (e)
    int privateKey = 2753; // Private key (d)

    int message = 389; // Message to be encrypted

    // Encryption
    int encryptedMessage = modPow(message, publicKey, modulus);

    // Decryption
    int decryptedMessage = modPow(encryptedMessage, privateKey, modulus);

    cout << "Original Message: " << message << endl;
    cout << "Public Key : " << publicKey << endl;
    cout << "Private Key : " << privateKey << endl;
    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
