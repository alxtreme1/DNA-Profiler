#include "unknownProfile.h"

UnknownProfile::UnknownProfile(int argc, char *argv[]) {
    argumentValidation(argc, argv);
}

void UnknownProfile::argumentValidation(int argc, char *argv[]) {
    string data_file_name, sequence_file_name;
    if(argc >= 4) {
        for(int i=0; i < argc - 1; i++){
            if(argv[i] == DATABASE_ARGUMENT_NAME)
                data_file_name = argv[i+1];
            else if(argv[i] == DATABASE_SEQUENCE_NAME)
                sequence_file_name = argv[i+1];
        }
    }
    if(data_file_name.size() > 0 && sequence_file_name.size() > 0) {
        cout << "> Loading the DNA database [" << data_file_name << "]..." << endl;
    }
    else{
        cout << "The argument [" << DATABASE_ARGUMENT_NAME << "] or [" << DATABASE_SEQUENCE_NAME << "] is missing in execution." << endl;
    }
}