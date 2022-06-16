#ifndef UNKNOWN_PROFILE
#define UNKNOWN_PROFILE

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class UnknownProfile {
    private:
        const string DATABASE_ARGUMENT_NAME = "-d";
        const string DATABASE_SEQUENCE_NAME = "-s";
        string data_file_name, sequence_file_name;
        bool isArgumentsValids(int argc, char *argv[]);
    public:
        UnknownProfile(int argc, char *argv[]);
};

#endif