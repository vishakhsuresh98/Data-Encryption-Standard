#include "dec_to_bin.h"

/**
 * Convert a number (0 to 15) in decimal system to hexadecimal system
 *
 * @param dec the input number, as an int in decimal number system
 * @returns the equivalent string, in the hexadecimal number system
 */
string dec_to_bin(int dec)
{
	unordered_map <int, string> mp; 
    mp[0] = "0000"; 
    mp[1] = "0001";
    mp[2] = "0010";
    mp[3] = "0011";
    mp[4] = "0100";
    mp[5] = "0101";
    mp[6] = "0110";
    mp[7] = "0111";
    mp[8] = "1000"; 
    mp[9] = "1001";
    mp[10] = "1010";
    mp[11] = "1011";
    mp[12] = "1100";
    mp[13] = "1101";
    mp[14] = "1110";
    mp[15] = "1111";

    string bin = mp[dec];
    return bin;
}