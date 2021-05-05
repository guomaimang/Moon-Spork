# Work Distribution
This is a group project of COMP1011, so works should be distributed to each of group members. Consider it is difficult to design data structure together, therefore, tasks are scheduled to distribute after the data structure is created.
## Planning Functions
1. Input cleaning
    - Ask user to type the keywords, and then remove the unnecessary characters such as `,`,`'`,`123`, etc. Transform all uppercase letters to lowercase.  
    - **string\* InputCleaning()**: should return a pointer pointing to a string array, which needs to contain processed words user typed
    - Example: "Let's go hiking tomorrow noon 12:00, call 3333-3333" -> "lets, go, hiking, tomorrow, noon, call"
2. Relevance Calculation
    - This function should integrate with the third function, and it should calculate the relevant score of each document.
    - A algorithm which can represent the relevance of documents, you have this information: word input by users, how many times the word appear in the title of each document and how many times the word appear in the content of each document.
    - Example: 
        - Input: "problem", appeared in title 1 times in form 1, 0 times in form 2, 0 times in form 3; in content 4 times in form 1, 3 times in form 2, 2 times in form 2
        - Output: the relevant score {5.433,4.322,0.985}
3. Dictionary Lookup
    - This function receives parameters including the return value of the previous function InputCleaning() and dictionaries, and should search in the dictionary with the method of ElasticSearch. 
    - **float\* ScoreCalculate(string *input, Dictionary wordDictionary, Course subjects)**: should return a pointer pointing to an integer array. the array contains the scores of each subject description form
    - Example: Assume there are three description forms 1,2,3. For the input of "lets, go, hiking, tomorrow, noon, call", each form should have a relevant score, so the function should return an array like this {1.333,3.444,2.543}
    - IT SHOULD USE THE FUNCTIONS ABOVE
4. Result Display
    - After calculation, the search documents should be displayed in order, and the program should allow users interact with files, such as choose to display the content, or choose to download the pdf file.
    - **void DisplayResult(float *scores)**: display the search result and offer some interactions.
    - Example:
        - `----------Search Results----------`
        - `1. COMP2011 Data Structures 6.433`
        - `2. COMP2322 Computer Networking 4.221`
        - `3. COMP3122 Information Systems Development 3.231`
        - 
        - `Enter the result number to show details: 3`
        - 
        - `COMP3122 Information Systems Development`
        - `Subject Pre-requisite: COMP2411`
        - `Subject Level: 3, Subject Credit: 3`
        - 
        - `Enter 'c' to show content, 'd' to download the subject description form, 'e' to return: `
## Needed Roles
### Programmers
1. Implement function 1
2. Implement function 2-3
3. Implement function 4
### Writer
1. Write Report