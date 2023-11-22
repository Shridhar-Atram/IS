#include <iostream>
#include <cmath>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1], int messageLength) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < messageLength; j++) {
            cipherMatrix[i][j] = 0;
            for (int x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void HillCipher(string message, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageLength = message.length();
    int messageVector[3][1];
    
    // Generate vector for the message
    for (int i = 0; i < messageLength; i++)
        messageVector[i % 3][0] = (message[i]) % 65;

    int cipherMatrix[3][1];

    // Generate the encrypted vector
    encrypt(cipherMatrix, keyMatrix, messageVector, messageLength);

    string CipherText;

    // Generate the encrypted text from the encrypted vector
    for (int i = 0; i < messageLength; i++)
        CipherText += cipherMatrix[i % 3][0] + 65;

    // Finally print the ciphertext
    cout << "Ciphertext: " << CipherText << endl;
}

int main() {
    // Get the message to be encrypted
    string message = "ACT";

    // Get the key
    string key = "GYBNQKURP";

    HillCipher(message, key);

    return 0;
}
