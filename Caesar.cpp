#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using Caesar cipher
std::string encryptCaesarCipher(const std::string& message, int shift) {
    std::string encrypted = "";

    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encrypted += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            // Encrypt special symbols and spaces
            if (isalnum(ch) || ch == ' ' || ispunct(ch)) {
                char base = ' '; // Set the base to space for symbols and spaces
                encrypted += static_cast<char>((ch - base + shift) % 127 + base);
            } else {
                encrypted += ch; // Preserve other characters
            }
        }
    }

    return encrypted;
}

// Function to decrypt a message encrypted with Caesar cipher
std::string decryptCaesarCipher(const std::string& encryptedMessage, int shift) {
    std::string decrypted = "";

    for (char ch : encryptedMessage) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decrypted += static_cast<char>((ch - base - shift + 26) % 26 + base);
        } else {
            // Decrypt special symbols and spaces
            if (isalnum(ch) || ch == ' ' || ispunct(ch)) {
                char base = ' '; // Set the base to space for symbols and spaces
                decrypted += static_cast<char>((ch - base - shift + 127) % 127 + base);
            } else {
                decrypted += ch; // Preserve other characters
            }
        }
    }

    return decrypted;
}

int main() {
    std::string message;
    int shift;

    cout << "Vishal Kamble 20141234" << endl;
    cout << "Caesar Cipher program for encryption" << endl;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the shift value: ";
    std::cin >> shift;

    std::string encrypted = encryptCaesarCipher(message, shift);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    std::string decrypted = decryptCaesarCipher(encrypted, shift);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
