#ifndef SEQUENCE_DATA
#define SEQUENCE_DATA

#include <string>
using std::string;

#include <fstream>
using std::fstream;

#include <iostream>
using std::cout;
using std::endl;

class SequenceData {
    private:
        string sequence;
    public:
        void proccessSequenceData(fstream *file);
        void printSequence();
        string getSequence();
};

#endif