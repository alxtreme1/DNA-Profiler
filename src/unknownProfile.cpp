#include "unknownProfile.h"

UnknownProfile::UnknownProfile(int argc, char *argv[]) {
    if(isExecutionArgumentsValids(argc, argv)) {
        cout << "> Loading the DNA database [" << file_names[EXPECTED_ARGUMENTS.at(0)] << "]..." << endl;
    }
    else
        cout << "Error with arguments in execution." << endl;
}

bool UnknownProfile::isExecutionArgumentsValids(int argc, char *argv[]) {
    if(argc >= int(EXPECTED_ARGUMENTS.size()) * 2) {
        for(auto args_it = EXPECTED_ARGUMENTS.begin(); args_it != EXPECTED_ARGUMENTS.end(); ++args_it) {
            for(int i = 0; i < argc - 1; i++) {
                if(argv[i] == *args_it && argv[i + 1][0] != '-') {
                    file_names.emplace(*args_it, argv[i + 1]);
                    break;
                }
            }
        }
    }
    if(file_names.size() == EXPECTED_ARGUMENTS.size())
        return true;
    return false;
}