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
    Course();
    //Set Data
    void SetID(int id);
    void SetCode(std::string code);
    void SetTitle(std::string title);
    void SetTitleMap(std::map<std::string, int> titleDict);
    void SetLevel(int level);
    void SetCredit(int credit);
    void SetPreRequisite(PreRequisite *preRequisite);
    void SetContent(std::map<std::string, int> contentDict);
    //Call Data
    int GetID();
    std::string GetCode();
    std::string GetTitle();
    std::map<std::string, int> GetTitleMap();
    int GetLevel();
    int GetCredit();
    PreRequisite GetPreRequisite();
    std::map<std::string, int> GetContent();
private:
    int id;
    int level;
    int credit;
    std::string code;
    std::string title;
    PreRequisite *prerequisite;
    std::map<std::string, int> titleDict;
    std::map<std::string, int> contentDict;
};
//Use a linked list to store pre-requisite
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
#endif