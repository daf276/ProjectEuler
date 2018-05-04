#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int numberOfPrimes = 1;
    int thePrime = 0;
    bool isPrime;

    for (int i = 3; numberOfPrimes < 10001; i+=2) {
        isPrime = true;
        for (int j = 3; j <= sqrt(i); ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            numberOfPrimes++;
            thePrime = i;
        }
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << thePrime << std::endl;
    return 0;
}