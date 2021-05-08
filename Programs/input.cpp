#include <iostream>

using namespace std;
string* InputCleaning(string input) // 返回数组的指针
{
    string *processed_string = new string[50]();
    char input_array[50][100];
    int index=0; // the first char in input
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<100;j++)
        {
            if((48<=input[index]&&input[index]<=57)||(65<=input[index]&&input[index]<=90)||(97<=input[index]&&input[index]<=122))
            {
                input_array[i][j] = input[index];
                index++;
            }
            else if(input[index]==32)
            {
                input_array[i][j]='\0';
                index++;
                break;
            }
            else
            {
                j--;
                index++;
            }
        }
        processed_string[i].assign(input_array[i]);
        cout<<processed_string[i]<<endl;
        if(index>(input.size())-1)
        {
            break;
        }
    }
    for(int i=0;i<50;i++)
    {
        cout<<processed_string[i]<<endl;
    }
    return processed_string;
}

// cut by space tab and " "
// delete `~!@#$%^&*（）——-+=[]{}\|:;" ' <> ,. /?
// turn all the upper to lower



int main()
{
    string user_input = "Let's go to COMP1011 to have class %today.";
    // If longer than 100, input again.
    string *processed_input = InputCleaning(user_input);

    // find the vacabularies in the input
/*
    for(int i=0;i<50;i++)
    {
        cout<<processed_input[i]<<endl;
    }
    */
    return 0;
}