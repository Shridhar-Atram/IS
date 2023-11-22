#include <iostream>
#include <string>
using namespace std;
int main() {
 string msg, key, k, ct, pt;
 cout << "Enter Message: ";
 getline(cin, msg);
 cout << "Enter Key: ";
 getline(cin, key);
 int lenm = msg.length();
 int lenk = key.length();
 int j = 0;
 for (int i = 0; i < lenm; i++, j++) {
 if (j == lenk) {
 j = 0;
 }
 k.push_back(key[j]);
 }
 for (int i = 0; i < lenm; i++) {
 char encryptedChar = msg[i] + k[i];
 // Wrap around for all characters
 encryptedChar = (encryptedChar + 256) % 256;
 ct.push_back(encryptedChar);
 }
 for (int i = 0; i < lenm; i++) {
 char decryptedChar = ct[i] - k[i];
 // Wrap around for all characters
 decryptedChar = (decryptedChar + 256) % 256;
 pt.push_back(decryptedChar);
 }
 cout << "\nEncrypted Message: " << ct << endl;
 cout << "Decrypted Message: " << pt << endl;
 return 0;
}
