#include "manager.h"
#include "peopleData.h"
#include "output.h"

map<string, string> Manager::getFileNames(int argc, char *argv[], const vector<string> EXPECTED_ARGUMENTS) {
    map<string, string> file;

    if(argc >= int(EXPECTED_ARGUMENTS.size()) * 2) {

        for(auto args_it = EXPECTED_ARGUMENTS.begin(); args_it != EXPECTED_ARGUMENTS.end(); ++args_it) {
            for(int i = 0; i < argc - 1; i++) {
                if(argv[i] == *args_it && argv[i + 1][0] != '-') {
                    file[*args_it] = argv[i + 1];
                    break;
                }
            }
        }

    }
    return file;
}

bool Manager::isExecutionArgumentsValids(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS) {

    if(file.size() == EXPECTED_ARGUMENTS.size())
        return true;
    return false;

}

void Manager::read_STR_Files(map<string, string> file, const vector<string> EXPECTED_ARGUMENTS, PeopleData people) {
    if(isExecutionArgumentsValids(file, EXPECTED_ARGUMENTS)) {

        output.loadingDNA_DatabaseMessage(file[EXPECTED_ARGUMENTS.at(0)]);
        fstream data_file("../" + file[EXPECTED_ARGUMENTS.at(0)]);
        output.loadingSequenceDatabaseMessage(file[EXPECTED_ARGUMENTS.at(1)]);
        fstream sequence_file("../" + file[EXPECTED_ARGUMENTS.at(1)]);

        if(data_file.is_open() && sequence_file.is_open()) {
            output.inputSuccessLoadedMessage();
            cout << endl;
            people.processPeople_STRsData(&data_file);
        }
        else
            output.someFilesDontExistMessage();

        data_file.close();
        sequence_file.close();
    }
    else
        output.errorWithArgumentsMessage();
}