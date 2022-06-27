#ifndef PEOPLE_DATA
#define PEOPLE_DATA

#include "personProfile.h"
#include "output.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

class PeopleData {
    private:
        Output output;
        vector<PersonProfile> peopleDatabase;
        PersonProfile idenfiedProfile;
    public:
        void proccessPeopleData(fstream *file);
        void printPeopleData();
        vector<PersonProfile> getPeopleDatabase();
        void setIdentifiedProfile(PersonProfile p);
};

#endif