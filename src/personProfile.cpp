#include "personProfile.h"

void PersonProfile::setName(string name_) {
    name = name_;
}

void PersonProfile::addSTR(string name_, int quantitie) {
    strsDatabase.emplace(name_, quantitie);
}

string PersonProfile::getName() {
    return name;
}

int PersonProfile::get_STR_quantitieByName(string strName) {
    return strsDatabase[strName];
}

map<string, int> PersonProfile::getSTRs() {
    return strsDatabase;
}