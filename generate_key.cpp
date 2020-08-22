#include "generate_key.h"

/**
 * Convert a number in decimal system to hexadecimal system
 *
 * @param dec the input, as an int in decimal number system
 * @returns the equivalent character, in the hexadecimal number system
 */
char dec_to_hex(int dec)
{
	if(dec < 10) {
		return char(48 + dec);
	}
	else {
		return char(65 + dec - 10);
	}
}

/**
 * Generate a random kay of length equal to that of the plaintext
 * 
 * @param plaintext the plaintext, as a string in hexadecimal number system
 * @returns random key, as a string in hexadecimal number system
 */
string generate_key(string plaintext)
{
	string key = "";
	for(int i = 0; i < plaintext.length(); i++) {
		key += dec_to_hex(rand() % 16);
	}
	return key;
}