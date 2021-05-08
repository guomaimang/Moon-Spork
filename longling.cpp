// PART1: Input Cleaning By GENG Longling
// Clean the user input and store them into a strings array (by each words)
// 1. cut words by space 
// 2. delete `~!@#$%^&*（）——-+=[]{}\|:;" ' <> ,. /? by using ascii code
// 3. turn all the upper to lower

#include <iostream>
#include <cstring>

using namespace std;
string* InputCleaning(string input) // return the pointer to the array of input strings
{
    string *string_list = new string[50]();
    char input_array[50][100];
    int index=0; // the first char in input
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<100;j++)
        {
            if((48<=input[index]&&input[index]<=57)||(65<=input[index]&&input[index]<=90)||(97<=input[index]&&input[index]<=122))
            {// 48 to 57 is 0 to 9; 65 to 90 is uppercase; 97 to 122 is lowercase
                if(65<=input[index]&&input[index]<=90)
                {
                    input_array[i][j] = input[index]+32;  // turn the uppercase to lowercase
                }
                else
                {
                    input_array[i][j] = input[index];  // store the character if it is number of lowercase
                }
                index++;
                //cout<<index<<endl;  // for check use
            }
            else if(input[index]==32)
            {
                input_array[i][j]='\0';   // add a NULL character to each word
                index++;
                //cout<<index<<endl;
                break;
            }
            else
            {
                j--;   // if it is the unformal character, do not change the position of new array
                index++;
                //cout<<index<<endl;
            }
        if(index==input.size()-1)  // if the index reaches the size of input, then skip the inner loop
        {
            input_array[i][j+1]='\0';
            break;
        }
        }
        string_list[i].assign(input_array[i]);  // assign the new word to the string array 
        cout<<string_list[i]<<endl;
        if(index==input.size()-1)   // if the index reaches the size of input, then skip the outer loop
        {
            break;
        }
    }

    // print to show it store the input correctly 
    for(int i=0;i<50;i++)
    {
        cout<<string_list[i]<<endl;
        if(string_list[i].empty())  // skip the empty part
        {
            break;
        }
    }
    return string_list;
}


int main()
{
    string user_input = "Let's go to COMP1011 to have class %today.";  // for test
    // If longer than 100, input again.
    string *processed_input = InputCleaning(user_input);

    // find the vacabularies in the input
    // print to show the function has returned the pointer correctly
    for(int i=0;i<50;i++)
    {
        cout<<processed_input[i]<<endl;
        if(processed_input[i].empty())
        {
            break;
        }
    }

    return 0;
}