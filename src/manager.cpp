#include "manager.h"
#include "peopleData.h"
#include "output.h"

Manager::Manager(PeopleData *p, int argc, char *argv[]) {
    people = p;
    setFileNames(argc, argv);
}

void Manager::setFileNames(int argc, char *argv[]) {

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
    isExecutionArgumentsValids = ExecutionArgumentsValidation();
}

bool Manager::ExecutionArgumentsValidation() {

    if(file_names.size() == EXPECTED_ARGUMENTS.size())
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
}

void Manager::openFiles() {
    if(isExecutionArgumentsValids) {
        data_file.open("../"+ file_names[EXPECTED_ARGUMENTS.at(0)]);
        sequence_file.open("../"+ file_names[EXPECTED_ARGUMENTS.at(1)]);
            
        output.loadingDNA_DatabaseMessage(file_names[EXPECTED_ARGUMENTS.at(0)]);
        output.loadingSequenceDatabaseMessage(file_names[EXPECTED_ARGUMENTS.at(1)]);
    }
    else
        output.errorWithArgumentsMessage();
}

void Manager::closeFiles() {
    data_file.close();
    sequence_file.close();
}