//
// Created by 韩佳明 on 2021/4/28.
//

#ifndef PROGRAMS_ENTRY_H
#define PROGRAMS_ENTRY_H
#include <iostream>
using namespace std;

class Entry {

private:
    static int get_id(){
        static int number = 0;
        number += 1;
        return number;
    }

public:
    Entry *next = nullptr;
    Entry *prev = nullptr;

    int id = get_id();
    char word[16] = "znotinitialized";
    int field[4] = {};

};

#endif //PROGRAMS_ENTRY_H
