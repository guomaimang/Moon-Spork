/*
Written by Yunfei LIU at April 25, 2021
Modified by Yunfei LIU at April 26, 2021

This function is used for read data from .json file in the "Data" folder.
It can read the files and process it in memory for future use.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <map>
//Use this MIT license third-party header to process json files
#include "../ThirdPartyHeaders/json.hpp"
//Use this header written by Yunfei to call Course objects
#include "course.h"
//Setting the namespaces
using json = nlohmann::json;
using namespace std;

//This function read data from files and will return a pointer to a Course object array.
//For how to use it, please refers to the test main function at the end of this cpp file.
Course* ReadData() {
    //Read file names from a csv file
    ifstream names("./Data/fileNames.csv",ios::in);
    string fileName[100];
    int count=0;
    if (!names) cout<<"Error\n"; //Print 'ERROR' when cannot open the target file
    getline(names,fileName[count]);
    while (fileName[count]!="") { //Start reading the file names
        count++;
        getline(names,fileName[count]);
    }

    ifstream courseJson;
    //Create an array to store all the Course objects
    Course *subject = new Course[count]();
    for (int i=0;i<count;i++) {
        //Add the relative path
        string jsonName="./Data/pre-processed2/";
        json fileData;
        jsonName+=fileName[i];
        //Open and read the file
        courseJson.open(jsonName,ios::in);
        fileData << courseJson;
        courseJson.close();
        //Save data to course object
        subject[i].SetCode(fileData["Subject Code"]);
        subject[i].SetID((int) fileData["Subject ID"]);
        subject[i].SetLevel(fileData["Subject Level"]);
        subject[i].SetCredit(fileData["Subject Credit"]);
        subject[i].SetTitle(fileData["Subject Title"]);
        map<string,int> title,content,pre;
        title=fileData.at("Subject Title Words List").get<map<string,int>>();
        subject[i].SetTitleMap(title);
        content=fileData.at("Subject Content").get<map<string,int>>();
        subject[i].SetContent(content);
        pre=fileData.at("Subject Pre-requisite").get<map<string,int>>();
        subject[i].SetPreRequisite(pre);
    }
    //Return the array address
    return subject;
}

//Test function, which is only used to test whether ReadData function working.
int main() {
    Course *data;
    data=ReadData();
    for (int i=1;i<10;i++) {
        cout<<data[i].GetCode()<<"   "<< data[i].GetID()<<endl;
    }
    delete[] data;
    return 0;
}
