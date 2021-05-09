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
        if(i==0){
            single_scores[i]=*(scores+i);
            count++;
            continue;
        }
        for(int j=0;j<count;j++){
            if(*(scores+i)==single_scores[j]){
                flag2=1;
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
            if(*(scores+j)==single_scores[i]){
                order++;
                order_id[order-1]=j;
                cout<<order<<". "<<data[j].GetCode()<<" "<<data[j].GetTitle()<<" "<<*(scores+j)<<endl;
            }
        }
    }
    
    int input;
    do{
    cout<<"Enter the result number to show details(the number should between 1 and 81)";
    cin>>input;
    }while(input<1 || input>81);
    cout<<endl;
    int index=order_id[input-1];
    cout<<data[index].GetCode()<<" "<<data[index].GetTitle()<<endl;
    //cout<<"Subject Pre-requisite: " <<data[index].GetPreRequisite()<<endl;
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