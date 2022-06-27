#include "manager.h"
#include "peopleData.h"
#include "output.h"

Manager::Manager(PeopleData *p, SequenceData *s, int argc, char *argv[]) {
    people = p;
    sequence = s;
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
            sequence->proccessSequenceData(&sequence_file);
        }
        else
            output.someFilesDontExistMessage();

        closeFiles();
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

void Manager::DNA_Profiling() {
    
    map<string, int> str_quantity;

    vector<PersonProfile> people_ = people->getPeopleDatabase();
    map<string, int> strs_ = people->getPeopleDatabase().begin()->getSTRs();
    string sequence_ = sequence->getSequence();

    output.DNA_ProfilingMessage();

    for(map<string, int>::iterator strs_it = strs_.begin(); strs_it != strs_.end(); ++strs_it) {

        int count_max = 0;
        int count = 0;

        for(int seq_it = 3; seq_it < int(sequence_.length()); seq_it++) {
            
            if(sequence_[seq_it - 3] == strs_it->first[0] &&
            sequence_[seq_it - 2] == strs_it->first[1] &&
            sequence_[seq_it - 1] == strs_it->first[2] &&
            sequence_[seq_it] == strs_it->first[3]) {
                seq_it += strs_it->first.size() - 1;
                count++;
                if(count > count_max) {
                    count_max = count;
                    str_quantity[strs_it->first] = count_max;
                }
            }
            else {
                count = 0;
            }
        }
        count_max = 0;
        count = 0;
    }

    for(auto people_it = people_.begin(); people_it != people_.end(); ++people_it) {
        int count_equal = 0;
        auto strs_person = people_it->getSTRs();

        for(auto strs_it = strs_person.begin(); strs_it != strs_person.end(); ++strs_it) {
            if(strs_it->second == str_quantity[strs_it->first])
                count_equal++;
        }
        if(count_equal == signed(str_quantity.size())) {
            people->setIdentifiedProfile(*people_it);
            output.foundPersonMessage(people_it->getName());
            return;
        }
    }

    output.notFoundPersonMessage();

}