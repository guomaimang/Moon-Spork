//
// Created by 韩佳明 on 2021/5/8.
//

#include <iostream>
using namespace std;

string* inword(){
    string a;
    cin >> a;
    static string test1[50] = {};
    return test1;
}

int query_word_times(int id){
    int point = 0;
    // query if word_id is a title, need be filled with
    bool is_title = false;

    //TEST-BLOCK
    if (id == 7 or id == 9)
        point =  5;
    else{
        point =  1;
    }

    if (is_title){
        return 100*point;
    } else{
        return 5*point;
    }

}


int main() {

    // get the string array
    string target[50] = {"computer","organization"};

    // get the length of string array without empty
    int target_length = 0;
    for (auto & i : target){
        if (i.empty()){
            break;
        }
        target_length += 1;
    }

    // init the point = 1
    int point[81] = {};
    for(int & i : point){
        i = 1;
    }

    // The field was save in field_id,such as {{1,2,10},{1,6,7}}
    int* field_id[50] = {};

    // For each word, return the document that appears and calculate some points
    for(int i = 0; i< target_length;i++){

        // query field,need to be filled with
        int temp_array[81] = {};
        field_id[i] = temp_array;

        // get the length of the field array
        int field_length = sizeof(temp_array)/sizeof(int);

        // calculate point1: title *100 and content *5
        for(int g = 0;g < field_length;g++){
             int id = temp_array[g];
             point[id] = point[id]*query_word_times(id);
         }

    }

    // TEST-BLOCK: lets make a example
    int test3[5] = {1,7,11,19,53};
    int test4[7] = {6,9,11,19,25};
    field_id[0] = test3;
    field_id[1] = test4;

    //


    return 0;
}

