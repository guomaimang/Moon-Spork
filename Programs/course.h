/*
Written by Yunfei LIU at April 25, 2021

This header including all the needed classes (Not Finished yet)
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <map>

//Create a class to save all course information
class Course
{
public:
    //Initializer
    Course() {this->Id=-1;};
    //Set Data
    void SetID(int id) {this->Id=id;};
    void SetCode(std::string code) {this->Code=code;};
    void SetTitle(std::string title) {this->Title=title;};
    void SetTitleMap(std::map<std::string, int> titleDict) {this->TitleDict=titleDict;};
    void SetLevel(std::string level) {this->Level=level;};
    void SetCredit(std::string credit) {this->Credit=credit;};
    void SetPreRequisite(std::map<std::string, int> preRequisite) {this->Prerequisite=preRequisite;};
    void SetContent(std::map<std::string, int> contentDict) {this->ContentDict=contentDict;};
    //Call Data
    int GetID();
    std::string GetCode() {return this->Code;};
    std::string GetTitle() {return this->Title;};
    std::map<std::string, int> GetTitleMap() {return this->TitleDict;};
    std::string GetLevel() {return this->Level;};
    std::string GetCredit() {return this->Credit;};
    std::map<std::string, int> GetPreRequisite() {return this->Prerequisite;};
    std::map<std::string, int> GetContent() {return this->ContentDict;};
private:
    int Id;
    std::string Level;
    std::string Credit;
    std::string Code;
    std::string Title;
    std::map<std::string, int> Prerequisite;
    std::map<std::string, int> TitleDict;
    std::map<std::string, int> ContentDict;
};
//Use a linked list to store pre-requisite

#endif