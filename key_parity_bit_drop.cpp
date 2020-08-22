#include "key_parity_bit_drop.h"
#include "permute.h"

/**
 * Drop the parity bits in the key for getting the round keys
 * (every 8th bit of the 64 bit key is dropped and then permuted)
 *
 * @param input the input string, in binary number system
 * @returns the output after dropping parity bits, as a string in binary number system
 */
string key_parity_bit_drop(string input)
{
    int key_perm[56] = {57, 49, 41, 33, 25, 17, 9, 
                        1, 58, 50, 42, 34, 26, 18, 
                        10, 2, 59, 51, 43, 35, 27, 
                        19, 11, 3, 60, 52, 44, 36, 
                        63, 55, 47, 39, 31, 23, 15, 
                        7, 62, 54, 46, 38, 30, 22, 
                        14, 6, 61, 53, 45, 37, 29, 
                        21, 13, 5, 28, 20, 12, 4};
    string output = permute(input, key_perm, 56);
    return output;
}