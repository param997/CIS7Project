#include <iostream>
#include <string>
using namespace std;

string encrypt(const std::string& plaintext, const std::string& keyword) {
    string ciphertext;
    int keywordLength = keyword.length();
    int plaintextLength = plaintext.length();

    for (int i = 0; i < plaintextLength; ++i) {
        char plainChar = plaintext[i];
        char keyChar = keyword[i % keywordLength];
        
        // Convert ASCII characters to 0-25 range
        int plainOffset = plainChar - 'A';
        int keyOffset = keyChar - 'A';
        
        // Encryption formula: Ei = (Pi + Ki) mod 26
        int encryptedOffset = (plainOffset + keyOffset) % 26;
        
        // Convert back to ASCII range
        char encryptedChar = encryptedOffset + 'A';
        
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

string decrypt(const std::string& ciphertext, const std::string& keyword) {
    string plaintext;
    int keywordLength = keyword.length();
    int ciphertextLength = ciphertext.length();

    for (int i = 0; i < ciphertextLength; ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[i % keywordLength];
        
        // Convert ASCII characters to 0-25 range
        int cipherOffset = cipherChar - 'A';
        int keyOffset = keyChar - 'A';
        
        // Decryption formula: Di = (Ei - Ki + 26) mod 26
        int decryptedOffset = (cipherOffset - keyOffset + 26) % 26;
        
        // Convert back to ASCII range
        char decryptedChar = decryptedOffset + 'A';
        
        plaintext += decryptedChar;
    }

    return plaintext;
}

int main() {
    string plaintext;
    string keyword;

    // Input plaintext and keyword from the user
    cout << "Enter plaintext: ";
    getline(std::cin, plaintext);
    cout << "Enter keyword: ";
    getline(std::cin, keyword);

    // Encrypt the plaintext
    string encryptedText = encrypt(plaintext, keyword);
    cout << "Encrypted text: " << encryptedText << std::endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(encryptedText, keyword);
    cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
