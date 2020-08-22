#include "key_shifting.h"
#include "shift_left.h"

/**
 * Perform key shifting operation for getting the round keys
 *
 * @param input the input string, in binary number system
 * @param round the round of encryption, as an int
 * @returns the output after shifting, as a string in binary number system
 */
string key_shifting(string input, int round)
{
    int shift_table[16] = {1, 1, 2, 2, 
                           2, 2, 2, 2, 
                           1, 2, 2, 2, 
                           2, 2, 2, 1};
    int shift = shift_table[round];
    string output = shift_left(input, shift);
    return output;
}