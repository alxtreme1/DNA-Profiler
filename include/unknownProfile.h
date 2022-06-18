#ifndef UNKNOWN_PROFILE
#define UNKNOWN_PROFILE

#include "personProfile.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include "fstream"
using std::fstream;

#include "sstream"
using std::stringstream;

class UnknownProfile {
    private:
        const vector<string> EXPECTED_ARGUMENTS = {
            "-d",
            "-s"
        };
        map<string, string> file_names;
        vector<PersonProfile> peopleDatabase;
        bool isExecutionArgumentsValids(int argc, char *argv[]);
        void read_STR_Files();
        void processPeople_STRsData(fstream *file);
    public:
        UnknownProfile(int argc, char *argv[]);
};

#endif