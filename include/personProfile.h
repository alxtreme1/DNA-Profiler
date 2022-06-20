#ifndef PERSON_PROFILE
#define PERSON_PROFILE

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

class PersonProfile {
    private:
        string name;
        map<string, int> strsDatabase;
    public:
        void setName(string name_);
        void addSTR(string name_, int quantitie);
        string getName();
        int get_STR_quantitieByName(string strName);
        map<string, int> getSTRs();
};

#endif