#include "peopleData.h"

void PeopleData::processPeople_STRsData(fstream *file) {
    string line, strsLine;
    stringstream ssSTR;
    output.processingMessage();
    // cout << "> Processing data, please wait..." << endl;
    getline(*file, line);
    strsLine = line;

    while(getline(*file, line)) {
        PersonProfile person;
        string strQuantitie, strName, personName;
        stringstream ssPerson(line), ssStr(strsLine);

        getline(ssPerson, personName, ',');
        getline(ssStr, strName, ',');
        person.setName(personName);

        while(getline(ssPerson, strQuantitie, ',') && getline(ssStr, strName, ',')) {
            person.addSTR(strName, stoi(strQuantitie));
            peopleDatabase.push_back(person);
        }

    }

}