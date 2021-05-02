#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<string>
#include<set>
using namespace std;
class Dictionary {
    public:
        Dictionary(){this->wordID=-1;};
        string word;
        int wordID;
        set<int> appearDoc;
};
#endif