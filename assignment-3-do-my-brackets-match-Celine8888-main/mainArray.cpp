#include <iostream>
#include <algorithm>
#include <chrono>

#include "DSList.h"
#include "DSStack.h"
#include "bracketTesterList.cpp"
#include "bracketTesterArray.cpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{
    argc++;

    auto start = high_resolution_clock::now();

    int result = bracketTesterArray(argv[1]);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nChecking all files took " << duration.count() << " milliseconds" << endl;

    // A return code != 0 tells the operating system that there is an issue.
    return result;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`