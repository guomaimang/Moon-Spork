//
// Created by 韩佳明 on 2021/5/8.
//

#include <iostream>
using namespace std;

string* inword(){
    string a;
    cin >> a;
    auto* test1 = new string;
    return test1;
}
int query_field(){

};

int main() {

    // get the string array
    string target[100] = {"computer","organization"};

    // get the length of string array without empty
    int target_length = 0;
    for (auto & i : target){
        if (i.empty()){
            cout << "end";
        }
        target_length += 1;
    }

    // For each word, return the document that appears
    for(int i = 0; i< target_length;i++){
        target[i] =
    }
    return 0;
}

