#include <iostream>
#include <cmath>

using namespace std;

long long int power(long long int base, long long int exponent, long long int mod) {
    if (exponent == 1)
        return base;
    else
        return (static_cast<long long int>(pow(base, exponent)) % mod);
}

int main() {
    long long int P, G, a, b, x, y, ka, kb;

    P = 23; // A prime number P is taken
    G = 9;  // A primitive root for P, G is taken

    cout << "The value of P: " << P << endl;
    cout << "The value of G: " << G << endl;

    a = 4; // Alice's chosen private key
    b = 3; // Bob's chosen private key

    cout << "Private key for Alice: " << a << endl;
    cout << "Private key for Bob: " << b << endl;

    // Calculate public keys
    x = power(G, a, P); // Public key for Alice
    y = power(G, b, P); // Public key for Bob

    // Calculate secret keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    cout << "Public key for Alice: " << x << endl;
    cout << "Public key for Bob: " << y << endl;

    cout << "Secret key for Alice: " << ka << endl;
    cout << "Secret key for Bob: " << kb << endl;

    return 0;
}
