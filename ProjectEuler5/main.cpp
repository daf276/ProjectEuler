#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int numbers[] = {9699690, 20, 18, 16, 12};
    bool numberDivisible;
    int finalNumber = 0;

    do{
        finalNumber+=9699690;
        numberDivisible = true;
        for (int number : numbers) {
            if(finalNumber % number != 0) {
                numberDivisible = false;
                break;
            }
        }
    } while(!numberDivisible);

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << finalNumber << std::endl;
    return 0;
}