#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    long max = 2000000;
    bool sieve[2000000] = {false};

    sieve[2] = true;
    sieve[3] = true;

    long primeSum = 0;

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
        if(sieve[i]) primeSum += i;
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << primeSum << std::endl;
    return 0;
}
