#include "compression_permutation.h"
#include "permute.h"

/**
 * Perform compression permutation for getting the round keys
 * (select 48 out of the 56 bits in the key)
 *
 * @param input the input string, in binary number system
 * @returns the output after compression, as a string in binary number system
 */
string compression_permutation(string input)
{
    int key_comp[48] = {14, 17, 11, 24, 1, 5, 
                        3, 28, 15, 6, 21, 10, 
                        23, 19, 12, 4, 26, 8, 
                        16, 7, 27, 20, 13, 2, 
                        41, 52, 31, 37, 47, 55, 
                        30, 40, 51, 45, 33, 48, 
                        44, 49, 39, 56, 34, 53, 
                        46, 42, 50, 36, 29, 32}; 
    string output = permute(input, key_comp, 48);
    return output;
}