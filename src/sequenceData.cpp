#include "sequenceData.h"

void SequenceData::proccessSequenceData(fstream *file) {
    getline(*file, sequence);
}

void SequenceData::printSequence() {
    cout << sequence << endl;
}