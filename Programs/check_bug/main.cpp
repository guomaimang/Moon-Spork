#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <utility>
#include "./json.hpp"

using namespace std;
using json = nlohmann::json;

class Dictionary {
public:
    Dictionary(){this->wordID=-1;}; //Initialize the wordID to -1, preventing conflicts
    string word;
    int wordID;
    set<int> appearTitle;
    set<int> appearDoc;
};
class Course
{
public:
    //Initializer
    //Initialize the id to -1, preventing conflicts
    Course() {this->Id=-1;};
    //Set Data
    //It store data in the object
    void SetID(int id) {this->Id=id;};
    void SetCode(std::string code) {this->Code=std::move(code);};
    void SetTitle(std::string title) {this->Title=std::move(title);};
    void SetTitleMap(std::map<std::string, int> titleDict) {this->TitleDict=std::move(titleDict);};
    void SetLevel(std::string level) {this->Level=std::move(level);};
    void SetCredit(std::string credit) {this->Credit=std::move(credit);};
    void SetPreRequisite(std::map<std::string, int> preRequisite) {this->Prerequisite=std::move(preRequisite);};
    void SetContent(std::map<std::string, int> contentDict) {this->ContentDict=std::move(contentDict);};
    //Call Data
    //If you want to call data, please use the following functions
    int GetID() const {return this->Id;};
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

Course* ReadData() {
    //Read file names from a csv file
    ifstream names("./Data/fileNames.csv",ios::in);
    string fileName[100];
    int count=0;
    if (!names) cout<<"Error\n"; //Print 'ERROR' when cannot open the target file
    getline(names,fileName[count]);
    while (!fileName[count].empty()) { //Start reading the file names
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

Course *data = ReadData();

Dictionary* LoadDictionary() {
    Dictionary *wordList = new Dictionary[5000]();

    //Read the json to get where the word has appeared
    json appearList;
    ifstream shown("./Data/wordShownDocument.json",ios::in);
    appearList << shown;
    shown.close();
    for (int i=0;i<appearList.size();i++) {
        wordList[i].appearTitle=appearList[to_string(i)]["Shown in title"].get<set<int>>();
        wordList[i].appearDoc=appearList[to_string(i)]["Shown in content"].get<set<int>>();
        wordList[i].word=appearList[to_string(i)]["Word"];
        wordList[i].wordID=appearList[to_string(i)]["Word ID"];
    }

    return wordList;
}

map<string,int> WordToID(Dictionary *words) {
    int i=0;
    map<string,int> hashTable;
    while (words[i].wordID!=-1){
        hashTable[words[i].word]=words[i].wordID;
        i++;
    }
    return hashTable;
}

string* inword(){
    string a;
    cin >> a;
    static string test1[50] = {};
    return test1;
}

int query_word_times(bool is_title, int word_id, int doc_id){
    map<string,int> title,content;

    if(is_title){
        title=data[doc_id].GetTitleMap();
        return title[to_string(word_id)];
    } else{
        content=data[doc_id].GetContent();
        return content[to_string(word_id)];
    }

}

int main() {

    // get the string array
    string target[50] = {"comp1411"};

    // get the length of string array without empty
    int target_length = 0;
    for (string & i : target){
        if (i.empty()){
            break;
        }
        target_length += 1;
    }
    cout<<target_length<<endl;

    // word to word_id
    int target_id[50] = {};
    for (int i=0;i<50;i++) target_id[i]=-1;
    Dictionary *dict=LoadDictionary(); //
    map<string,int> wordHashTable=WordToID(dict);
    map<string,int> ::iterator object;
    for(int i = 0;i<target_length;i++){
        object=wordHashTable.find(target[i]);
        if(object!=wordHashTable.end()) {
            target_id[i] = object->second;
        }
        else {
            target_id[i] = -1;
        }
    }

    // init the point = 1
    int point[81] = {};
    for(int & i : point){
        i = 0;
    }

    // For each wordid, calculate points
    for(int i = 0; i< target_length;i++){
        
        //get wordid
        int wordid = target_id[i];
        if (wordid==-1) continue;

        // get the content_field of word
        int content_array[81] = {};
        for(int & g : content_array){
            content_array[g] = -1;
        }
        set<int> contentSet=dict[wordid].appearDoc;
        int content_array_count=0;
        for(int it : contentSet){
            content_array[content_array_count]=it;
            content_array_count++;
        }

        // calculate doc point
        for(int g = 0;g < content_array_count;g++){
            int docid = content_array[g];
            point[docid] = point[docid] + query_word_times(false,wordid,docid)*5;
        }

        // get the title_array of word
        int title_array[81] = {};
        for(int & g : title_array){
            title_array[g] = -1;
        }
        set<int> titleSet=dict[wordid].appearTitle;
        int title_array_count=0;
        for(int it : titleSet){
            title_array[title_array_count]=it;
            title_array_count++;
        }

        // calculate title point
        for(int g = 0;g < title_array_count;g++){
            int docid = title_array[g];
            point[docid] = point[docid] + query_word_times(true,wordid,docid)*100;
        }

    }

    // TEST-BLOCK cout point
    for(int i : point){
        cout << i << " ";
    }
    return 0;
}