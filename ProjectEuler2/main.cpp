#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int prevFibNum = 1;
    int curFibNum = 2;
    int sum = 0;

    while(curFibNum < 4000000){
        if(curFibNum % 2 == 0) sum += curFibNum;

        int temp = curFibNum;
        curFibNum += prevFibNum;
        prevFibNum = temp;
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << sum << std::endl;
    return 0;
}