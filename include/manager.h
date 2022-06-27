#ifndef MANAGER
#define MANAGER

#include "peopleData.h"
#include "sequenceData.h"

#include "output.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <fstream>
using std::fstream;

#include <sstream>
using std::stringstream;

class Manager {
    private:
        const vector<string> EXPECTED_ARGUMENTS = {
            "-d",
            "-s"
        };
        map<string, string> file_names;
        Output output;
        PeopleData *people;
        SequenceData *sequence;
        fstream data_file;
        fstream sequence_file;
        bool isExecutionArgumentsValids;
    public:
        Manager(PeopleData *p, SequenceData *s, int argc, char *argv[]);
        void setFileNames(int argc, char *argv[]);
        void proccessData();
        bool ExecutionArgumentsValidation();
        bool isFilesOpen();
        void openFiles();
        void closeFiles();
        void DNA_Profiling();
};

#endif