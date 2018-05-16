#include <iostream>
#include <chrono>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primeArray(int max);

int main() {
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    int n = 3;
    int dn = 2;
    int counter = 0;

    int n1, dn1, j, exponent;
    vector<int> primes = primeArray(200000);

    while (counter < 500) {
        n = n + 1;
        n1 = n;

        if (n1 % 2 == 0) n1 = n1 / 2;
        dn1 = 1;

        for (j = 0; j < primes.size(); ++j) {
            if (primes.at(j) * primes.at(j) > n1) {
                dn1 *= 2;
                break;
            }

            exponent = 1;
            while (n1 % primes.at(j) == 0) {
                exponent++;
                n1 /= primes.at(j);
            }

            if (exponent > 1) dn1 *= exponent;
            if (n1 == 1) break;
        }

        counter = dn * dn1;
        dn = dn1;
    }

    end = chrono::system_clock::now();
    long elapsed_millis = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Elapsed Milliseconds: " << elapsed_millis << endl;

    cout << (n * (n - 1) / 2) << endl;
    return 0;
}

vector<int> primeArray(int max) {
    vector<int> primevector;
    bool sieve[2000000] = {false};

    sieve[2] = true;
    sieve[3] = true;

    for (int x = 1; x < sqrt(max); ++x) {
        for (int y = 1; y < sqrt(max); ++y) {

            long n = (4 * x * x) + (y * y);
            if (n <= max && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;

            n = (3 * x * x) + (y * y);
            if (n <= max && n % 12 == 7) sieve[n] ^= true;

            n = (3 * x * x) - (y * y);
            if (x > y && n <= max && n % 12 == 11) sieve[n] ^= true;
        }
    }

    for (int r = 5; r < sqrt(max); r++) {
        if (sieve[r]) {
            for (int i = r * r; i < max; i += r * r) sieve[i] = false;
        }
    }

    for (int i = 0; i < max; ++i) {
        if (sieve[i]) {
            primevector.push_back(i);
        }
    }

    return primevector;
}