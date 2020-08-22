#include "decrypt.h"
#include "encrypt.h"

/**
 * Decrypt a given ciphertext and obtain the corresponding plaintext
 *
 * @param ciphertext the ciphertext, as a string in hexadecimal number system
 * @param round_keys the references to the round keys 
 * @returns the plaintext, as a string in hexadecimal number system
 */
string decrypt(string ciphertext, string* round_keys)
{
    // reversing the sequence of round keys
    for(int i = 0; i < 8; i++) {
        string rk_1 = *(round_keys + i);
        string rk_2 = *(round_keys + 15 - i);
        string copy = rk_1;
        rk_1 = rk_2;
        rk_2 = copy;
        *(round_keys + i) = rk_1;
        *(round_keys + 15 - i) = rk_2;
    }

    string plaintext = encrypt(ciphertext, round_keys); 
    return plaintext;
}