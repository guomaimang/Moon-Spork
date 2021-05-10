/*
Written by Zhuchen WANG at May 8, 2021
Modified by Zhuchen WANG at May 10, 2021
This function is used for displaying the search result and offer some interactions.
It can receive the pointer of the float array which stores the relative score of each course
and print out the search result form the high relative to the low relative.
It can also allow users interact with files, such as choose to display the content, or choose to download the pdf file.
*/
#include <iostream>
#include <time.h>
#include <cstring>
#include <iomanip>
#include <string>
#include "dictionary.h"
#include "course.h"
#include "ReadData.cpp"
#include <stdio.h>
#include <string.h>
using namespace std;
// This function is to print the content of txt file of the course which is the user wants to know more about.
void ShowContent(string a)
{
    FILE *fp;
    char ch;
    string b = ".txt";
    string c = "./Data/Renamedtxt/";
    string d = c + a + b;
    char filename[100];
    strcpy(filename, d.c_str());
    cout << endl
         << filename;
    fp = fopen(filename, "r");
    if (fp == NULL)
        cout << " can not open!\n";
    else
    {
        fscanf(fp, "%c", &ch);
        while (!feof(fp))
        {
            putchar(ch);
            fscanf(fp, "%c", &ch);
        }
        fclose(fp);
    }
    cout << endl;
}
// This function is to display the search result by relative scores' order and offer some interactions.........................
void DisplayResult(int *scores)
{
    cout << "------------------------------------------------- Search Results ------------------------------------------------------" << endl << endl;
    cout << "--------------------------------------------- Subject Title ----------------------------------------------------| Index";
    cout << endl;
    int original_score[81];
    // original_score array is to keep the correspondence between score and course
    // (because the index of original_score array is the corresponding course_id)
    for (int i = 0; i < 81; i++)
    {
        original_score[i] = *(scores + i);
    }
    //This is to sort the 81 scores from high to low by using
    int t;
    for (int i = 0; i < 80; i++)
    {
        int flag1 = 0;
        for (int j = 0; j < 80 - i; j++)
        {
            if ((*(scores + j)) < (*(scores + j + 1)))
            {
                t = *(scores + j);
                *(scores + j) = *(scores + j + 1);
                *(scores + j + 1) = t;
                flag1 = 1;
            }
        }
    }

// If count==0 , that means all the scores are 0 , so there is no relative course.
    int count = 0;
    int single_scores[81];
    for (int i = 0; i < 81; i++)
    {
        int flag2 = 0;
        if (*(scores) == 0)
        {
            break;
        }
        if (i == 0)
        {
            single_scores[i] = *(scores + i);
            count++;
            continue;
        }
        for (int j = 0; j < count; j++)
        {
            if (*(scores + i) == single_scores[j] || *(scores + i) == 0)
            {
                flag2 = 1;
            }
        }
        if (flag2 == 0)
        {
            count++;
            single_scores[count - 1] = *(scores + i);
        }
    };

    // This part is to print the search results from the high relative to the low relative.
    if (count == 0)
    {
        cout << "Not Found" << endl;
        return;
    }

    //This part is to interact with users.
    int order = 0;
    int order_id[81];
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 81; j++)
        {
            if (original_score[j] == single_scores[i])
            {
                order++;
                order_id[order - 1] = j;
                cout << setw(2) << order << ". " << data[j].GetCode() << " " << left << setw(100) << data[j].GetTitle() << original_score[j] << endl;
            }
        }
    }
    char input[100];
    int input1;
    while (true)
    {
        cout << endl;
        while (true)
        {
            do
            {
                cout << "Enter the result number to show details(the number should fall within the range above) and enter 0 to finish: ";
                cin >> input;
            } while ((!((strlen(input) == 2) && (input[0] >= 48) && (input[0] <= 56) && (input[1] >= 48) &&
                        (input[1] <= 57) && (((input[0] - 48) * 10 + input[1] - 48) >= 1) &&
                        (((input[0] - 48) * 10 + input[1] - 48) <= 81))) &&
                     (!((strlen(input) == 1) && (input[0] >= 48) && (input[0] <= 57))));
            cout << endl;
            if (strlen(input) == 1 && input[0] == '0')
            {
                cout << "Thanks for your using!" << endl;
                return;
            }
            //Change the type of input (char to int by using ASCII) to calculate the order which represents the course that user wants to inquire.
            if (strlen(input) == 1)
            {
                input1 = input[0] - 48;
            }
            else if (strlen(input) == 2)
            {
                input1 = (input[0] - 48) * 10 + input[1] - 48;
            }
            // If input is not in the range which showed on the screen, that means it is a invalid input.
            if (input1 < 1 || input1 > order)
            {
                cout << "The number doesn't fall within the range above! Please enter again. " << endl;
            }
            else
            {
                break;
            }
        }

        // This part is to show some basic information of the course whose order is inputted by the user.
        int index = order_id[input1 - 1];
        cout << data[index].GetCode() << " " << data[index].GetTitle() << endl;
        cout << "Subject Pre-requisite: ";
        map<string, int> prerequisite = data[index].GetPreRequisite();
        map<string, int>::iterator preiterator; //define an interator
        for (preiterator = prerequisite.begin(); preiterator != prerequisite.end(); ++preiterator)
        {
            cout << preiterator->first << " ";
        }
        cout << endl;
        cout << "Subject Level: " << data[index].GetLevel() << endl;
        cout << "Subject Credit: " << data[index].GetCredit() << endl;
        cout << endl;

        //This part is to allow users interact with files, such as choose to display the content, or choose to download the pdf file.
        char choice[100];
        do
        {
            do
            {
                cout << "Enter 'c' to show content, 'd' to download the subject description form, 'e' to choose another relevant course: ";
                cin >> choice;
            } while (!((strlen(choice) == 1) && (choice[0] == 'c' || choice[0] == 'd' || choice[0] == 'e')));
            //Display the content
            if (choice[0] == 'c')
            {
                ShowContent(data[index].GetCode());
                cout << endl;
            }
            //Choose to download the pdf file
            if (choice[0] == 'd')
            {
                string http = "https://19040822.xyz/";
                string pdf = ".pdf";
                cout << "\nPlease use this link to download the PDF: " << http << data[index].GetCode() << pdf << endl;
                cout << endl;
            }
        } while (choice[0] != 'e');
    }
}
// Test function, which is only used to test whether DisplayResult function working.
/*
int main(){
    int score[81];
    srand(time(0));
    for(int i=0;i<81;i++){
        score[i]=rand()%8;
    };
    int* scores=score;
    DisplayResult(scores);
    return 0;
}
*/
