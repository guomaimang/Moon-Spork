/*
Written by Yunfei LIU at April 25, 2021
Modified by Yunfei LIU at April 26, 2021

This header including a new class represent each subjects. If call data is needed, please use the "Get" functions.
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <map>

//Create a class to save all course information
//With the features shown as following
class Course
{
public:
    //Initializer
    //Initialize the id to -1, preventing conflicts
    Course() {this->Id=-1;};
    //Set Data
    //It store data in the object
    void SetID(int id) {this->Id=id;};
    void SetCode(std::string code) {this->Code=code;};
    void SetTitle(std::string title) {this->Title=title;};
    void SetTitleMap(std::map<std::string, int> titleDict) {this->TitleDict=titleDict;};
    void SetLevel(std::string level) {this->Level=level;};
    void SetCredit(std::string credit) {this->Credit=credit;};
    void SetPreRequisite(std::map<std::string, int> preRequisite) {this->Prerequisite=preRequisite;};
    void SetContent(std::map<std::string, int> contentDict) {this->ContentDict=contentDict;};
    //Call Data
    //If you want to call data, please use the following functions
    int GetID();
    std::string GetCode() {return this->Code;};
    std::string GetTitle() {return this->Title;};
    std::map<std::string, int> GetTitleMap() {return this->TitleDict;};
    std::string GetLevel() {return this->Level;};
    std::string GetCredit() {return this->Credit;};
    std::map<std::string, int> GetPreRequisite() {return this->Prerequisite;};
    std::map<std::string, int> GetContent() {return this->ContentDict;};
private:
    int Id; //Represent the ID
    std::string Level; //Represent the level
    std::string Credit; //Represent the credit
    std::string Code; //Represent the subject code
    std::string Title; //Represent the subject title
    std::map<std::string, int> Prerequisite; //Use a map to represent the pre-requisite
    std::map<std::string, int> TitleDict; //Use a map to represent the title word list
    std::map<std::string, int> ContentDict; //Use a map to represent the content word list
};
#endif