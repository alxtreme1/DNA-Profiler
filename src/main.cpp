#include <iostream>
using std::cout;
using std::endl;

#include "manager.h"
#include "peopleData.h"
#include "sequenceData.h"

int main(int argc, char *argv[]) {
    cout << "DNA Profiler" << endl;
    cout << "Identify the person on the DNA base. Enter the following command to test as an example: " << endl;
    cout << "./dnaprofiler.exe -d data/data.csv -s data/sequence_alice.txt"  << endl;

    PeopleData people;
    SequenceData sequence;
    // Manager manager(&people, argc, argv);
    Manager manager(&people, &sequence, argc, argv);
    map<string, string> file_names;

    manager.openFiles();
    manager.proccessData();
    sequence.printSequence();
    people.printPeopleData();
    
    return 0;
}