#include "p_box_permutation.h"
#include "permute.h"

/**
 * Perform P-box permuatation for DES encryption
 *
 * @param input the input string, in binary number system
 * @returns the output after permutation, as a string in binary number system
 */
string p_box_permutation(string input)
{
    int p_box[32] = {16, 7, 20, 21, 
                     29, 12, 28, 17, 
                     1, 15, 23, 26, 
                     5, 18, 31, 10, 
                     2, 8, 24, 14, 
                     32, 27, 3, 9, 
                     19, 13, 30, 6, 
                     22, 11, 4, 25};
    string output = permute(input, p_box, 32);
    return output;               
}