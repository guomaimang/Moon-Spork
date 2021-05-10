#include <iostream>
#include <time.h>
#include <cstring>
#include <string>
#include "dictionary.h"
#include "course.h"
#include "ReadData.cpp"
using namespace std;
void DisplayResult(float* scores){
    cout<<"------------- Search Results -------------"<<endl;
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
    
    Course *data;
    data=ReadData();
    int order=0;
    int order_id[81];
    for(int i=0;i<count;i++){
        for(int j=0;j<81;j++){
            if(original_score[j]==single_scores[i]){
                order++;
                order_id[order-1]=j;
                cout<<order<<". "<<data[j].GetCode()<<" "<<data[j].GetTitle()<<" "<<original_score[j]<<endl;
            }
        }
    }
    
    char input[100];
    int  input1;
    do{
    cout<<"Enter the result number to show details(the number should between 1 and 81): ";
    cin>>input;
    }while( (!((strlen(input)==2)&&(input[0]>=48)&&(input[0]<=56)&&(input[1]>=48)&&(input[1]<=57)&&(((input[0]-48)*10+input[1]-48)>=1)&&(((input[0]-48)*10+input[1]-48)<=81))) &&
            (!((strlen(input)==1)&&(input[0]>48)&&(input[0]<=57))) );

    cout<<endl;
    if(strlen(input)==1) {
        input1 = input[0] - 48;
    }else if(strlen(input)==2){
        input1 = (input[0] - 48)*10+input[1];
    }
    int index=order_id[input1-1];
    cout<<data[index].GetCode()<<" "<<data[index].GetTitle()<<endl;
    map<string,int> prerequisite=data[index].GetPreRequisite();
    map<string,int>::iterator preiterator;//define an interator
    for (preiterator = prerequisite.begin(); preiterator != prerequisite.end(); ++preiterator) {
        cout<<preiterator->first<<" ";
    }
    cout<<"Subject Level: "<<data[index].GetLevel()<<endl;
    cout<<"Subject Credit: "<<data[index].GetCredit()<<endl; 
    cout<<endl;
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