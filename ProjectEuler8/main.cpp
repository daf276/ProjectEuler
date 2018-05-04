#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int y = 1000;
    int a, b, c;
    bool solutionFound = false;

    for (a = 1; a < y/3; a++) {
        for (b = 1; b < y/2; b++) {
            double potentialC = sqrt(pow(a, 2) + pow(b, 2));
            if ((int) potentialC == potentialC) {
                c = (int) potentialC;
                if (a + b + c == y) {
                    solutionFound = true;
                    break;
                }
            }
        }
        if (solutionFound) break;
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
    std::cout << a * b * c << std::endl;
    return 0;
}