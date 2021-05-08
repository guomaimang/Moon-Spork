#include <iostream>

using namespace std;

string *te(string input)
{
    string *test_input = new string[2]();
    test_input[0]="hahah";
    test_input[1]="bobob";
    return test_input;
}
int main()
{
    string input="hello";
    cout<<input[0]<<endl;
    cout<<input[1]<<endl;
    string* after=te(input);
    cout<<after[0]<<endl;
    cout<<after[1]<<endl;


    return 0;
}