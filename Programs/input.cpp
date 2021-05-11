/*
// PART1: Input Cleaning By GENG Longling
// Modified by Yunfei LIU at May 11, adding initial input function

// Clean the user input and store them into a strings array (by each words)
// 1. cut words by space
// 2. delete `~!@#$%^&*（）——-+=[]{}\|:;" ' <> ,. /? by using ascii code
// 3. turn all the upper to lower
*/

#include <iostream>

using namespace std;
string *InputCleaning(string input) // return the pointer to the array of input strings
{
    string *string_list = new string[50]();
    char input_array[50][100];
    int index = 0; // the first char in input
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if ((48 <= input[index] && input[index] <= 57) || (65 <= input[index] && input[index] <= 90) || (97 <= input[index] && input[index] <= 122))
            { // 48 to 57 is 0 to 9; 65 to 90 is uppercase; 97 to 122 is lowercase
                if (65 <= input[index] && input[index] <= 90)
                {
                    input_array[i][j] = input[index] + 32; // turn the uppercase to lowercase
                }
                else
                {
                    input_array[i][j] = input[index]; // store the character if it is number of lowercase
                }
                index++;
                //cout<<index<<endl;  // for check use
            }
            else if (input[index] == 32)
            {
                input_array[i][j] = '\0'; // add a NULL character to each word
                index++;
                //cout<<index<<endl;
                break;
            }
            else
            {
                j--; // if it is the unformal character, do not change the position of new array
                index++;
                //cout<<index<<endl;
            }
            if (index == input.size() - 1) // if the index reaches the size of input, then skip the inner loop
            {
                input_array[i][j + 1] = '\0';
                break;
            }
        }
        string_list[i].assign(input_array[i]); // assign the new word to the string array
        //cout<<string_list[i]<<endl;
        if (index == input.size() - 1) // if the index reaches the size of input, then skip the outer loop
        {
            break;
        }
    }

    // print to show it store the input correctly
    /*
    for(int i=0;i<50;i++)
    {
        cout<<string_list[i]<<endl;
        if(string_list[i].empty())  // skip the empty part
        {
            break;
        }
    }
    */
    return string_list;
}

/*
void Input()
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

}
*/

//Written by Yunfei LIU on May 10
//Print copyright text and allows input
string InitialInput()
{
    cout << "SUBJECT SEARCH ENGINE\n\nCopyright 2021 Yunfei LIU, Jiaming HAN, Zhuchen WANG, Longling GENG\n\nPermission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n\nThe above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n\n\nWritten by COMP1011 Group 8, Yunfei LIU, Jiaming HAN, Zhuchen WANG, Longling GENG\n\n\n\n\n";
    cout << "Welcome to use this program, we can found the information in the undergraduate subjects for you. Please feel free to type any keywords you know (subject code or any related words): ";
    string keywords;
    getline(cin, keywords);
    keywords.append(" ");
    return keywords;
}