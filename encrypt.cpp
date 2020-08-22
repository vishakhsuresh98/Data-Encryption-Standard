#include "encrypt.h"
#include "hex_to_bin.h"
#include "bin_to_hex.h"
#include "initial_permutation.h"
#include "expansion_permutation.h"
#include "exor.h"
#include "s_box_substitution.h"
#include "p_box_permutation.h"
#include "final_permutation.h"

/**
 * Encrypt a given plaintext and obtain the corresponding ciphertext
 *
 * @param plaintext the plaintext, as a string in hexadecimal number system
 * @param round_keys the references to the round keys 
 * @returns the ciphertext, as a string in hexadecimal number system
 */
string encrypt(string plaintext, string* round_keys)
{
    string ciphertext = "";

    plaintext = hex_to_bin(plaintext);

    // initial permutation
    plaintext = initial_permutation(plaintext);
    cout << "After initial permutation - " << bin_to_hex(plaintext) << endl;

    // splitting
    string left = plaintext.substr(0, 32);
    string right = plaintext.substr(32, 32);
    cout << "After splitting, LPT = " << bin_to_hex(left) 
         << " and RPT = " << bin_to_hex(right) << endl;

    // 16 rounds
    for(int i = 0; i < 16; i++) {
        // expansion permutation
        string intermediate = expansion_permutation(right);

        // xor with round key
        string round_key = *(round_keys + i);
        round_key = hex_to_bin(round_key);
        intermediate = exor(intermediate, round_key);

        // S-box substitution
        intermediate = s_box_substitution(intermediate);

        // P-box permutation
        intermediate = p_box_permutation(intermediate);

        if(i != 15) {
            string copy = left;
            left = right;
            right = exor(copy, intermediate);
        }
        else {
            left = exor(left, intermediate);
        }

        cout << "Round " << i << " - LPT (" << bin_to_hex(left) << "), " << \
            "RPT (" << bin_to_hex(right) << "), " << \
            "Round key (" << bin_to_hex(round_key) << ")" << endl; 
    }     
    // combining
    string combine = left + right;
    
    // final permutation
    ciphertext = final_permutation(combine);

    ciphertext = bin_to_hex(ciphertext);

    return ciphertext;
}