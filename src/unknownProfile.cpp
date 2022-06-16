#include "unknownProfile.h"

UnknownProfile::UnknownProfile(int argc, char *argv[]) {
    if(isArgumentsValids(argc, argv))
        cout << "> Loading the DNA database [" << data_file_name << "]..." << endl;
    else
        cout << "The argument [" << DATABASE_ARGUMENT_NAME << "] or [" << DATABASE_SEQUENCE_NAME << "] is missing in execution." << endl;
}

bool UnknownProfile::isArgumentsValids(int argc, char *argv[]) {
    if(argc >= 4) {
        for(int i=0; i < argc - 1; i++){
            if(argv[i] == DATABASE_ARGUMENT_NAME)
                data_file_name = argv[i+1];
            else if(argv[i] == DATABASE_SEQUENCE_NAME)
                sequence_file_name = argv[i+1];
        }
    }
    if(data_file_name.size() > 0 && sequence_file_name.size() > 0)
        return true;
    else
        return false;
}