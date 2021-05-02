/*
Created by Yunfei at May 2, 2021

This header includes a class to store a word id, characters, appeared title and appeared content.

Data explanation
word --- store a string of how the word is spelled
wordID --- store the ID of the word
appearTitle --- store a list of the ID OF SUBJECTS that contain this word in subject title
appearDoc --- store a list of the ID OF SUBJECTS that contain this word in subject content

*/
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<string>
#include<set>
using namespace std;
class Dictionary {
    public:
        Dictionary(){this->wordID=-1;}; //Initialize the wordID to -1, preventing conflicts
        string word;
        int wordID;
        set<int> appearTitle;
        set<int> appearDoc;
};
#endif