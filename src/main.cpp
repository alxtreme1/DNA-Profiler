#include <iostream>
using std::cout;
using std::endl;

#include "manager.h"
#include "peopleData.h"

int main(int argc, char *argv[]) {
    cout << "DNA Profiler" << endl;
    cout << "Identify the person on the DNA base. Enter the following command to test as an example: " << endl;
    cout << "./dnaprofiler.exe -d data/data.csv -s data/sequence_alice.txt"  << endl;
    const vector<string> EXPECTED_ARGUMENTS = {
        "-d",
        "-s"
    };
    Manager manager;
    PeopleData people;
    map<string, string> file_names = manager.getFileNames(argc, argv, EXPECTED_ARGUMENTS);
    manager.read_STR_Files(file_names, EXPECTED_ARGUMENTS, people);
    
    return 0;
}