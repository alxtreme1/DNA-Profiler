#include "manager.h"
#include "peopleData.h"
#include "output.h"

Manager::Manager(PeopleData *p) {
    people = p;
}

map<string, string> Manager::getFileNames(int argc, char *argv[], const vector<string> EXPECTED_ARGUMENTS) {
    map<string, string> file_names;

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
    isExecutionArgumentsValids = ExecutionArgumentsValidation(file_names, EXPECTED_ARGUMENTS);
    return file_names;
}

bool Manager::ExecutionArgumentsValidation(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS) {

    if(file.size() == EXPECTED_ARGUMENTS.size())
        return true;
    return false;

}

void Manager::proccessData() {
    if(isExecutionArgumentsValids) {
        if(data_file.is_open() && sequence_file.is_open()) {
            output.inputSuccessLoadedMessage();
            people->proccessPeopleData(&data_file);
        }
        else
            output.someFilesDontExistMessage();

        data_file.close();
        sequence_file.close();
    }
    else
        output.errorWithArgumentsMessage();
}

void Manager::openFiles(map<string, string> file_names, const vector<string> EXPECTED_ARGUMENTS) {
    data_file.open("../"+ file_names[EXPECTED_ARGUMENTS.at(0)]);
    sequence_file.open("../"+ file_names[EXPECTED_ARGUMENTS.at(1)]);
        
    output.loadingDNA_DatabaseMessage(file_names[EXPECTED_ARGUMENTS.at(0)]);
    output.loadingSequenceDatabaseMessage(file_names[EXPECTED_ARGUMENTS.at(1)]);
}

void Manager::closeFiles() {
    data_file.close();
    sequence_file.close();
}