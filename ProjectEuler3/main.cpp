#include <iostream>
#include <chrono>
#include <cmath>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    long number = 600851475143;

    for (int i = 2; i <= sqrt(number); ++i)
    {
        if(number % i == 0) {
            number /= i;
            i--;
        }
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << number << std::endl;
    return 0;
}