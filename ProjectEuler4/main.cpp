#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>


bool isPalindrom(int potentialPalindrom);

int main(int argc, char const *argv[])
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int largestPalindrom = 0;

    for (int i = 100; i < 1000; ++i)
    {
        for (int j = i; j < 1000; ++j)
        {
            if(isPalindrom(i*j) && i*j > largestPalindrom) largestPalindrom = i*j;
        }
    }

    end = std::chrono::system_clock::now();
    long elapsed_millis = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Milliseconds: " << elapsed_millis << std::endl;

    std::cout << largestPalindrom << std::endl;
    return 0;
}

bool isPalindrom(int potentialPalindrom)
{
    auto potentialPalindromString = std::to_string(potentialPalindrom);
    auto reversedString = potentialPalindromString;
    std::reverse(reversedString.begin(), reversedString.end());

    return potentialPalindromString == reversedString;
}