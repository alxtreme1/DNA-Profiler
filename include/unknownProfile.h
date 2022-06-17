#ifndef UNKNOWN_PROFILE
#define UNKNOWN_PROFILE

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

class UnknownProfile {
    private:
        const vector<string> EXPECTED_ARGUMENTS = {
            "-d",
            "-s"
        };
        map<string, string> file_names;
        string data_file_name, sequence_file_name;
        bool isExecutionArgumentsValids(int argc, char *argv[]);
    public:
        UnknownProfile(int argc, char *argv[]);
};

#endif