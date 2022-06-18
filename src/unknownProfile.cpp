#include "unknownProfile.h"

UnknownProfile::UnknownProfile(int argc, char *argv[]) {
    if(isExecutionArgumentsValids(argc, argv)) {
        read_STR_Files();
    }
    else
        cout << "Error with arguments in execution." << endl;
}

bool UnknownProfile::isExecutionArgumentsValids(int argc, char *argv[]) {
    if(argc >= int(EXPECTED_ARGUMENTS.size()) * 2) {
        for(auto args_it = EXPECTED_ARGUMENTS.begin(); args_it != EXPECTED_ARGUMENTS.end(); ++args_it) {
            for(int i = 0; i < argc - 1; i++) {
                if(argv[i] == *args_it && argv[i + 1][0] != '-') {
                    file_names[*args_it] = argv[i + 1];
                    break;
                }
            }
        }
    }
    if(file_names.size() == EXPECTED_ARGUMENTS.size())
        return true;
    return false;
}

void UnknownProfile::read_STR_Files() {
    fstream data_file("../" + file_names[EXPECTED_ARGUMENTS.at(0)]), sequence_file("../" + file_names[EXPECTED_ARGUMENTS.at(1)]);
    cout << "> Loading the DNA database [" << file_names[EXPECTED_ARGUMENTS.at(0)] << "]..." << endl;
    cout << "> Loading the unknown DNA sequence [" << file_names[EXPECTED_ARGUMENTS.at(1)] << "]..." << endl;
    if(data_file.is_open() && sequence_file.is_open())
        cout << "> Input files successfully loaded." << endl;
    else
        cout << "> A input file don't exist." << endl;
    data_file.close();
    sequence_file.close();
}