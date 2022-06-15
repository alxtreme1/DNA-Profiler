#include <iostream>
using std::cout;
using std::endl;

#include "unknownProfile.h"

int main(int argc, char *argv[]) {
    cout << "DNA Profiler" << endl;
    cout << "Identify the person on the DNA base. Enter the following command to test as an example: " << endl;
    cout << "./dnaprofiler.exe -d data/data.csv -s data/sequence_alice.txt"  << endl;
    UnknownProfile profile(argc, argv);
    return 0;
}