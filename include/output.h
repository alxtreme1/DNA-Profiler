#ifndef OUTPUT
#define OUTPUT

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Output{
    public:
        void loadingDNA_DatabaseMessage(string file_name);
        void loadingSequenceDatabaseMessage(string file_name);
        void inputSuccessLoadedMessage();
        void someFilesDontExistMessage();
        void errorWithArgumentsMessage();
        void processingMessage();
};


#endif