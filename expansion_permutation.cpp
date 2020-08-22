#include "expansion_permutation.h"
#include "permute.h"

/**
 * Perform expansion permutation for DES encryption
 * (32 bits --> 48 bits)
 *
 * @param input the input string, in binary number system
 * @returns the output after expanding, as a string in binary number system
 */
string expansion_permutation(string input)
{
    int exp_perm[48] = {32, 1, 2, 3, 4, 5, 4, 5, 
                        6, 7, 8, 9, 8, 9, 10, 11, 
                        12, 13, 12, 13, 14, 15, 16, 17, 
                        16, 17, 18, 19, 20, 21, 20, 21, 
                        22, 23, 24, 25, 24, 25, 26, 27, 
                        28, 29, 28, 29, 30, 31, 32, 1};
    string output = permute(input, exp_perm, 48);
    return output;
}