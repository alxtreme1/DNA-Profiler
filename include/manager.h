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
    public:
        map<string, string> getFileNames(int argc, char *argv[], const vector<string> EXPECTED_ARGUMENTS);
        void read_STR_Files(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS, PeopleData people);
        bool isExecutionArgumentsValids(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS);
};

#endif