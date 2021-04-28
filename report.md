# COMP1011 Group Report
### Authors
#### Yunfei LIU, Longling GENG, Jiaming HAN, Zhuchen WANG

## Table of Content
1. Introduction
2. Algorithm
3. Data Structure
4. Program Design
5. Data Process
    - Data Collection
    - Data Transform
    - Data Cleaning
6. Discussion
7. Challenges
8. Conclusion 
9. Appendix
    - Work Distribution
    - References

### Introduction
Nowadays, many messages, webpages are created everyday and it is impossible for us to read them one by one. To get data quickly and effectively, searching is of vital importance. Meanwhile, how to search the needed information at the shortest time, and how to find the correct webpages in numerous webpages on Internet, is a challenging question.

Searching algorithm is developed to save people's time of finding what they want, and it has a long history. Since the first search engine `WebCrawler` appeared on 1994, human have entered the information era. In this project, we revisited this part of history, and figured out how search engine is working. We developed our own data structures and algorithm to accelecrate the searching process. Although our method is not mature enough, it is a good start for us to improve our programming skills and learn some experiences.

### Algorithm
### Data Structure
### Program Design
### Data Process
#### Data Collection
As required in the project description, the data we need is on PolyU website `https://www.comp.polyu.edu.hk/en-us/study/undergraduate-programmes/subject`. The content of the website includes all course numbers, names, and description forms. To analyze them, we need to download them first then process them.

To download the files, the implementation of C++ of downloading files from a webpage is very complicated. Therefore, we use Python as an alternative method. Third-party libraries including `urllib` and `bs4` are used for processing the webpage and search for pdf files. The Python script is attached in **DataCollectionPythonScript** folder.

#### Data Transform
Of course, C++ cannot process pdf files directly because they are not plain text. To get rid of this problem, we need to transform the pdf files to plain text. Python are used again because of its convenience. Third-party library `pdfplumber` is used to transform the subject description forms to txt files.

#### Data Cleaning
The subject description forms in txt format are messy and cannot used by C++ programs directly, so we need to clean the useless characters, and extract features from the txt files. A Python script `getfeature.py` attached in **DataCollectionPythonScript** folder solve this problem. The script transform the **txt** files to **json** format with the features including subject code, title, level, credit, pre-requisite and content. The content are also transformed into json format to record each word and its appeared times. By cleaning data, C++ program can process it faster and more convenient.

### Discussion
### Challenges
### Conclusion
### Appendix
#### Work Distribution
| Student Name | Finished Work |
| ---- | ---- | 
| Jiaming HAN | |
| Longling GENG | |
| Yunfei LIU | |
| Zhuchen WANG | |
(Students are sorted by the first letter of their first name)

#### References