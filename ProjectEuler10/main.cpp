#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::vector<int> primes = {2, 3};
    long primeSum = 5;

    int potentialPrime1, potentialPrime2;
    bool number1isPrime, number2isPrime;

    for (int i = 6; i < 2000000; i += 6) {
        potentialPrime1 = i - 1;
        potentialPrime2 = i + 1;

        number1isPrime = true;
        number2isPrime = true;

        for (int number : primes) {
            if (number > sqrt(potentialPrime1)) break;
            else if (potentialPrime1 % number == 0) {
                number1isPrime = false;
                break;
            }
        }

        for (int number : primes) {
            if (number > sqrt(potentialPrime2)) break;
            else if (potentialPrime2 % number == 0) {
                number2isPrime = false;
                break;
            }
        }

        if (number1isPrime) {
            primes.push_back(potentialPrime1);
            primeSum += potentialPrime1;
        }
        if (number2isPrime) {
            primes.push_back(potentialPrime2);
            primeSum += potentialPrime2;
        }
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << primeSum << std::endl;
    return 0;
}