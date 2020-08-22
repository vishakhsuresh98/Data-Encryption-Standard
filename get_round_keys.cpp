#include "get_round_keys.h"
#include "hex_to_bin.h"
#include "bin_to_hex.h"
#include "key_parity_bit_drop.h"
#include "compression_permutation.h"
#include "key_shifting.h"

/**
 * Getter function to compute and return the round keys
 *
 * @param key the key, as a string in hexadecimal number system
 * @returns the round keys, as strings in hexadecimal number system
 */
string* get_round_keys(string key)
{
    static string round_keys[16] = {};

    // convert key to 64 bit binary equivalent
    key = hex_to_bin(key); 
    
    // drop parity bits to get 56 bits
    key = key_parity_bit_drop(key); 

    string left = key.substr(0, 28);
    string right = key.substr(28, 28);

    for(int i = 0; i < 16; i++) {
        // left shift each half separately
        left = key_shifting(left, i);
        right = key_shifting(right, i);
        
        // combining both halves
        key = left + right; 
        
        // compression permutation to get 48 bits
        key = compression_permutation(key);

        round_keys[i] = bin_to_hex(key);
    }
    return round_keys;
}