#include "permute.h"

/**
 * Perform permuatation operation
 *
 * @param input the input string, in binary number system
 * @param perm_matrix the permutation matrix containing the permuted indices
 * @param size the size of the permuted string, as an int
 * @returns the output after permutation, as a string in binary number system
 */
string permute(string input, int* perm_matrix, int size)
{
    string output = "";
    for(int i = 0; i < size; i++) {
        output += input[perm_matrix[i] - 1];
    }
    return output;
}