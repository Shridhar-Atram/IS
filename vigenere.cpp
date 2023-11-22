#include <iostream>
#include <string>
#include <cctype>

// Function to clean the input message (remove non-alphabetic characters and convert to uppercase)
std::string cleanMessage(const std::string& message) {
    std::string cleanedMessage;
    for (char c : message) {
        if (std::isalpha(c)) {
            cleanedMessage += std::toupper(c);
        }
    }
    return cleanedMessage;
}

// Function to perform Vigenère cipher encryption
std::string encryptVigenere(const std::string& message, const std::string& key) {
    std::string encryptedMessage;
    std::string cleanedMessage = cleanMessage(message);
    std::string cleanedKey = cleanMessage(key);

    for (size_t i = 0, j = 0; i < cleanedMessage.length(); ++i) {
        char messageChar = cleanedMessage[i];
        char keyChar = cleanedKey[j % cleanedKey.length()];

        char encryptedChar = 'A' + (messageChar + keyChar - 2 * 'A') % 26;
        encryptedMessage += encryptedChar;

        if (std::isalpha(cleanedMessage[i])) {
            j++;
        }
    }

    return encryptedMessage;
}

// Function to perform Vigenère cipher decryption
std::string decryptVigenere(const std::string& encryptedMessage, const std::string& key) {
    std::string decryptedMessage;
    std::string cleanedMessage = cleanMessage(encryptedMessage);
    std::string cleanedKey = cleanMessage(key);

    for (size_t i = 0, j = 0; i < cleanedMessage.length(); ++i) {
        char encryptedChar = cleanedMessage[i];
        char keyChar = cleanedKey[j % cleanedKey.length()];

        char decryptedChar = 'A' + (encryptedChar - keyChar + 26) % 26;
        decryptedMessage += decryptedChar;

        if (std::isalpha(cleanedMessage[i])) {
            j++;
        }
    }

    return decryptedMessage;
}

int main() {
    std::string key, message;

    std::cout << "Enter the Vigenere key: ";
    std::cin >> key;
    std::cin.ignore();  // Clear the newline character

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::string encrypted = encryptVigenere(message, key);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    std::string decrypted = decryptVigenere(encrypted, key);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
