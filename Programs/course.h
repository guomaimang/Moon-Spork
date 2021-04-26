/*
Written by Yunfei LIU at April 25, 2021

This header including all the needed classes (Not Finished yet)
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <map>

class PreRequisite {
public:
    PreRequisite();
    //Store the next position
    PreRequisite *next;
    //Read and save data
    void SetData(std::string);
    std::string GetData();
private:
    std::string data;
};
//Create a class to save all course information
class Course
{
public:
    //Initializer
    Course();
    //Set Data
    void SetID(int id) {this->Id=id;};
    void SetCode(std::string code) {this->Code=code;};
    void SetTitle(std::string title) {this->Title=title;};
    void SetTitleMap(std::map<std::string, int> titleDict) {this->TitleDict=titleDict;};
    void SetLevel(std::string level) {this->Level=level;};
    void SetCredit(std::string credit) {this->Credit=credit;};
    void SetPreRequisite(PreRequisite *preRequisite);
    void SetContent(std::map<std::string, int> contentDict);
    //Call Data
    int GetID();
    std::string GetCode();
    std::string GetTitle();
    std::map<std::string, int> GetTitleMap();
    std::string GetLevel();
    std::string GetCredit();
    PreRequisite GetPreRequisite();
    std::map<std::string, int> GetContent();
private:
    int Id;
    std::string Level;
    std::string Credit;
    std::string Code;
    std::string Title;
    PreRequisite *Prerequisite;
    std::map<std::string, int> TitleDict;
    std::map<std::string, int> ContentDict;
};
//Use a linked list to store pre-requisite

#endif