//
// Created by 韩佳明 on 2021/5/8.
//
#include <iostream>
#include <set>
#include <map>
#include <utility>
#include "../ThirdPartyHeaders/json.hpp"
#include "./ReadData.cpp"
#include "course.h"
#include "dictionary.h"
#include "LoadDictionary.cpp"
using namespace std;
using json = nlohmann::json;

Course *data = ReadData();

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

int search(string *inword) {

    // get the string array
    string target[50] = {};
    for(int i = 0;i<50;i++){
        target[i] = inword[i];
    }

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
    for (int & i : target_id) i=-1;
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