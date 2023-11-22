#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// Function to remove non-alphabetic characters and convert to uppercase
std::string cleanMessage(const std::string& message) {
    std::string cleanedMessage;
    for (char c : message) {
        if (std::isalpha(c)) {
            cleanedMessage += std::toupper(c);
        }
    }
    return cleanedMessage;
}

// Function to create a Playfair key table from a given key
std::vector<std::vector<char>> createPlayfairTable(const std::string& key) {
    std::vector<std::vector<char>> table(5, std::vector<char>(5, 0));
    std::string keyTable = cleanMessage(key);

    // Fill the keyTable with the key
    int row = 0, col = 0;
    for (char c : keyTable) {
        table[row][col] = c;
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }

    // Fill the remaining cells with the alphabet (excluding 'J')
    char letter = 'A';
    for (int i = 0; i < 26; i++) {
        if (letter != 'J' && keyTable.find(letter) == std::string::npos) {
            table[row][col] = letter;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
        letter++;
    }

    return table;
}

// Function to find the positions of two letters in the key table
void findPositions(const std::vector<std::vector<char>>& keyTable, char letter1, char letter2, int& row1, int& col1, int& row2, int& col2) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyTable[i][j] == letter1) {
                row1 = i;
                col1 = j;
            }
            if (keyTable[i][j] == letter2) {
                row2 = i;
                col2 = j;
            }
        }
    }
}

// Function to encrypt a message using Playfair cipher
std::string encryptPlayfair(const std::string& message, const std::vector<std::vector<char>>& keyTable) {
    std::string encryptedMessage;
    std::string cleanedMessage = cleanMessage(message);

    for (size_t i = 0; i < cleanedMessage.length(); i += 2) {
        char letter1 = cleanedMessage[i];
        char letter2 = (i + 1 < cleanedMessage.length()) ? cleanedMessage[i + 1] : 'X'; // Use 'X' for single letters
        int row1, col1, row2, col2;

        findPositions(keyTable, letter1, letter2, row1, col1, row2, col2);

        // Handle the same row, same column, and other cases
        if (row1 == row2) {
            encryptedMessage += keyTable[row1][(col1 + 1) % 5];
            encryptedMessage += keyTable[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            encryptedMessage += keyTable[(row1 + 1) % 5][col1];
            encryptedMessage += keyTable[(row2 + 1) % 5][col2];
        } else {
            encryptedMessage += keyTable[row1][col2];
            encryptedMessage += keyTable[row2][col1];
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using Playfair cipher
std::string decryptPlayfair(const std::string& encryptedMessage, const std::vector<std::vector<char>>& keyTable) {
    std::string decryptedMessage;

    for (size_t i = 0; i < encryptedMessage.length(); i += 2) {
        char letter1 = encryptedMessage[i];
        char letter2 = encryptedMessage[i + 1];
        int row1, col1, row2, col2;

        findPositions(keyTable, letter1, letter2, row1, col1, row2, col2);

        // Handle the same row, same column, and other cases
        if (row1 == row2) {
            decryptedMessage += keyTable[row1][(col1 + 4) % 5];
            decryptedMessage += keyTable[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            decryptedMessage += keyTable[(row1 + 4) % 5][col1];
            decryptedMessage += keyTable[(row2 + 4) % 5][col2];
        } else {
            decryptedMessage += keyTable[row1][col2];
            decryptedMessage += keyTable[row2][col1];
        }
    }

    return decryptedMessage;
}

int main() {
    std::string key, message;

    std::cout << "Enter the Playfair key: ";
    std::cin >> key;
    std::cin.ignore();  // Clear the newline character

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::vector<std::vector<char>> keyTable = createPlayfairTable(key);

    std::string encrypted = encryptPlayfair(message, keyTable);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    std::string decrypted = decryptPlayfair(encrypted, keyTable);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
