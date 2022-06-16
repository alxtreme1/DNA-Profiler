#include "unknownProfile.h"

UnknownProfile::UnknownProfile(int argc, char *argv[]) {
    if(isExecutionArgumentsValids(argc, argv))
        cout << "> Loading the DNA database [" << "data_file_name" << "]..." << endl;
    else
        cout << "Error with arguments in execution." << endl;
}

bool UnknownProfile::isExecutionArgumentsValids(int argc, char *argv[]) {
    bool isDatabaseArgumentNameFound, isSequenceArgumentNameFound;
    if(argc >= 4) {
        for(int i=0; i < argc - 1; i++) {
            if(argv[i] == DATABASE_ARGUMENT_NAME)
                isDatabaseArgumentNameFound = true;
            if(argv[i] == SEQUENCE_ARGUMENT_NAME)
                isSequenceArgumentNameFound = true;
        }
    }
    if(isDatabaseArgumentNameFound && isSequenceArgumentNameFound)
        return true;
    return false;
}