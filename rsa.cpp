#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the modular multiplicative inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

int main() {

    // Input prime numbers
    int num1, num2;
    cout << "Enter two prime numbers:\n";
    cin >> num1 >> num2;

    int n = num1 * num2;
    int phi = (num1 - 1) * (num2 - 1);
    int e = 7; // You can choose another suitable value for e

    // Ensure that e and phi are coprime
    while (gcd(e, phi) != 1) {
        e++;
    }

    int d = modInverse(e, phi); // Calculate the private key

    // Input message
    int message;
    cout << "Enter message: ";
    cin >> message;

    // Encryption
    int c = static_cast<int>(fmod(pow(message, e), n));

    // Decryption
    int decryptedMessage = static_cast<int>(fmod(pow(c, d), n));

    // Output results
    cout << "Original Message = " << message << endl;
    cout << "p = " << num1 << endl;
    cout << "q = " << num2 << endl;
    cout << "n = pq = " << n << endl;
    cout << "phi = " << phi << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Encrypted message = " << c << endl;
    cout << "Decrypted message = " << decryptedMessage << endl;

    return 0;
}