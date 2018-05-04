#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    long sumofsquares = 0;
    long squaresofsum = 0;

    for (int i = 1; i <= 100; ++i) {
        sumofsquares += i*i;
        squaresofsum += i;
    }

    squaresofsum *= squaresofsum;

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << squaresofsum-sumofsquares << std::endl;
    return 0;
}