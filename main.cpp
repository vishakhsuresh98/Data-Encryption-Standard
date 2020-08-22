#include<time.h>

#include "encrypt.h"
#include "decrypt.h"
#include "generate_key.h"
#include "get_round_keys.h"

// Driver program to test the above functions 
int main() 
{  
    srand(time(NULL));
    ifstream in_ptr;
    ofstream out_ptr;

    cout << "Data Encryption Standard" << endl;
    cout << "------------------------\n\n" << endl;

    // encryption process
    cout << "Encryption process :\n" << endl;
    string plaintext;
    in_ptr.open("plaintext.txt"); 
    getline(in_ptr, plaintext);
    cout << "Plaintext - " << plaintext << endl;
    string key = generate_key(plaintext);
    // string key = "AABB09182736CCDD"; // GeeksForGeeks sample 
    cout << "Key - " << key << endl;
    string* round_keys = get_round_keys(key);
    
    string ciphertext = encrypt(plaintext, round_keys); 
    cout << "Ciphertext - " << ciphertext << endl; 
    cout << "\n\n";
    in_ptr.close();

    // decryption process
    cout << "Decryption process :\n" << endl;
    cout << "Ciphertext - " << ciphertext << endl; 
    plaintext = decrypt(ciphertext, round_keys); 
    cout << "Plaintext - " << plaintext << endl; 
    cout << "\n";
    in_ptr.close();

    return 0; 
} 
