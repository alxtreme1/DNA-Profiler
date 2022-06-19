#ifndef MANAGER
#define MANAGER

#include "peopleData.h"

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
        Output output;
        PeopleData *people;
        fstream data_file;
        fstream sequence_file;
        bool isExecutionArgumentsValids;
    public:
        Manager(PeopleData *p);
        map<string, string> getFileNames(int argc, char *argv[], const vector<string> EXPECTED_ARGUMENTS);
        void proccessData();
        bool ExecutionArgumentsValidation(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS);
        bool isFilesOpen();
        void openFiles(map<string, string> file_names, const vector<string> EXPECTED_ARGUMENTS);
        void closeFiles();
};

#endif