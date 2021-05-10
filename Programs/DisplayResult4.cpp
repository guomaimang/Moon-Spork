#include <iostream>
#include <time.h>
#include <cstring>
#include <iomanip>
#include <string>
#include "dictionary.h"
#include "course.h"
#include "ReadData.cpp"
#include<stdio.h>
#include<string.h>
using namespace std;
void ShowContent(string a){
    FILE *fp;  //创建一个文件指针*fp
    char ch;
    string b=".txt";
    string c="./Data/Renamedtxt/";
    string d=c+a+b;
    char filename[100];
    strcpy(filename,d.c_str());
    cout<<filename;
    fp=fopen(filename,"r");   //以只读方式打开txt文件
    if(fp==NULL)
        cout<<" can not open!\n";  //如果fp指针指向为空，即文件为空，则输出can not open
    else{
        //读取字符：fscanf(fp,"%c",&ch)，ch=fgetc(fp);
        fscanf(fp,"%c",&ch);   //读取字符
        while(!feof(fp)){      //feof（）这个函数是用来判断指针是否已经到达文件尾部的,此处即如果没有到达末尾循环
            putchar(ch);           //输出
            fscanf(fp,"%c",&ch);   //再次读取字符
        }
        fclose(fp);   //关闭文件
    }
    cout<<endl;
}
void DisplayResult(float* scores){
    cout<<"------------- Search Results -------------"<<endl;
    cout<<endl;
    float original_score[81];
    for(int i=0;i<81;i++){
        original_score[i]=*(scores+i);
    }

    float t;
    for(int i=0;i<80;i++){
        int flag1=0;
        for(int j=0;j<80-i;j++){
            if((*(scores+j))< (*(scores+j+1))){
                t=*(scores+j);
                *(scores+j)=*(scores+j+1);
                *(scores+j+1)=t;
                flag1=1;
            }
        }
    }

    int count=0;
    float single_scores[81];
    for(int i=0;i<81;i++){
        int flag2=0;
        if(*(scores)==0){
            break;
        }
        if(i==0){
            single_scores[i]=*(scores+i);
            count++;
            continue;
        }
        for(int j=0;j<count;j++){
            if(*(scores+i)==single_scores[j] || *(scores+i)==0) {
                flag2 = 1;
            }
        }
        if(flag2==0){
           count++;
           single_scores[count-1]=*(scores+i);
        }
    };

    if(count==0){
        cout<<"Not Found"<<endl;
        return;
    }
    
    Course *data;
    data=ReadData();
    int order=0;
    int order_id[81];
    for(int i=0;i<count;i++){
        for(int j=0;j<81;j++){
            if(original_score[j]==single_scores[i]){
                order++;
                order_id[order-1]=j;
                cout<<setw(2)<<order<<". "<<data[j].GetCode()<<" "<<data[j].GetTitle()<<" "<<original_score[j]<<endl;
            }
        }
    }
    
    char input[100];
    int  input1;
    while(true) {
        cout<<endl;
        do {
            cout << "Enter the result number to show details(the number should between 1 and 81) and enter 0 to finish: ";
            cin >> input;
        } while ((!((strlen(input) == 2) && (input[0] >= 48) && (input[0] <= 56) && (input[1] >= 48) &&
                    (input[1] <= 57) && (((input[0] - 48) * 10 + input[1] - 48) >= 1) &&
                    (((input[0] - 48) * 10 + input[1] - 48) <= 81))) &&
                 (!((strlen(input) == 1) && (input[0] >= 48) && (input[0] <= 57))));
        cout << endl;
        if(strlen(input) == 1 && input[0] =='0' ){
            cout<<"Thanks for your using!"<<endl;
            return;
        }
        if (strlen(input) == 1) {
            input1 = input[0] - 48;
        } else if (strlen(input) == 2) {
            input1 = (input[0] - 48) * 10 + input[1]-48;
        }
        int index = order_id[input1 - 1];
        cout << data[index].GetCode() << " " << data[index].GetTitle() << endl;
        map<string,int> prerequisite=data[index].GetPreRequisite();
        map<string,int>::iterator preiterator;//define an interator
        for (preiterator = prerequisite.begin(); preiterator != prerequisite.end(); ++preiterator){
        cout<<preiterator->first<<" ";
        }
        cout << "Subject Level: " << data[index].GetLevel() << endl;
        cout << "Subject Credit: " << data[index].GetCredit() << endl;
        cout << endl;
        char choice[100];
        do {
            do {
                cout << "Enter 'c' to show content, 'd' to download the subject description form, 'e' to choose another relevant course: ";
                cin >> choice;
            } while (!((strlen(choice) == 1) && (choice[0] == 'c' || choice[0] == 'd' || choice[0] == 'e')));
            if (choice[0] == 'c') {
                ShowContent(data[index].GetCode());
                cout << endl;
            }
            if (choice[0] == 'd') {
                string http = "https://19040822.xyz/";
                string pdf = ".pdf";
                cout << "Please use this link to download the PDF: " << http << data[index].GetCode() << pdf << endl;
                cout << endl;
            }
        }while(choice[0] != 'e');
    }
}
int main(){
    float score[81];
    srand(time(0));
    for(int i=0;i<81;i++){
        score[i]=rand()%8;
    };
    float* scores=score;
    DisplayResult(scores);
    return 0;
}
