#include "bin_to_dec.h"

/**
 * Convert a number in binary system to decimal system
 *
 * @param bin the input string, in binary number system
 * @returns the equivalent decimal, as an int in the decimal number system
 */
int bin_to_dec(string bin)
{
	unordered_map <string, int> mp; 
    mp["00"] = 0;
    mp["01"] = 1;
    mp["10"] = 2;
    mp["11"] = 3;
    mp["0000"] = 0; 
    mp["0001"] = 1; 
    mp["0010"] = 2; 
    mp["0011"] = 3; 
    mp["0100"] = 4; 
    mp["0101"] = 5; 
    mp["0110"] = 6; 
    mp["0111"] = 7; 
    mp["1000"] = 8; 
    mp["1001"] = 9; 
    mp["1010"] = 10; 
    mp["1011"] = 11; 
    mp["1100"] = 12; 
    mp["1101"] = 13; 
    mp["1110"] = 14; 
    mp["1111"] = 15;

    int dec = mp[bin];
    return dec;
}