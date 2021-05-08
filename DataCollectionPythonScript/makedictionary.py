from __future__ import print_function
import json,os,nltk
"""Because C++ lacks of NLP libraries, so we abandoned this improvement, which can transform different tenses"""
#from nltk.stem import *
#from nltk.stem.snowball import SnowballStemmer
#stemmer = SnowballStemmer("english")

wordList=dict()
flist=[flist for flist in os.listdir("../Data/pre-processed2/")]

#Import all the words and construct a dictionary represents words and its appearance
for item in flist:
    f=open("../Data/pre-processed2/"+item,'r',encoding='UTF-8')
    data=json.loads(f.read())
    for word in data['Subject Content'].keys():
        try:
            wordList[word]+=data['Subject Content'][word]
        except KeyError:
            wordList[word]=data['Subject Content'][word]
    for word in data['Subject Title Words List'].keys():
        try:
            wordList[word]+=data['Subject Title Words List'][word]
        except KeyError:
            wordList[word]=data['Subject Title Words List'][word]
    f.close()
sortedDict=sorted(wordList.items(), key=lambda k: k[1],reverse=True)

#Delete useless words such as "are", "and", "it" to improve the correctness
newWordList=dict()
for word in sortedDict:
    wordType=nltk.pos_tag(nltk.word_tokenize(word[0]))
    if wordType[0][1]!='CC' and wordType[0][1]!='DT' and wordType[0][1]!='EX' and wordType[0][1]!='IN' and wordType[0][1]!='LS' and wordType[0][1]!='MD' and wordType[0][1]!='SYM'and wordType[0][1]!='PRP' and wordType[0][1]!='TO' and wordType[0][1]!='VBP' and wordType[0][1]!='PRP$' and len(wordType[0][0])>2:
        newWordList[word[0]]=word[1]

#Construct a csv file to save the word->id dictionary
output=[]
idDict=dict()
id=0
for word in newWordList:
    output.append(word+','+str(newWordList[word])+','+str(id)+'\n')
    idDict[word]=id
    id+=1
output.insert(0,'word,frequency,id\n')
writeFile=open("../Data/dictionary.csv",'w',encoding="UTF-8")
writeFile.writelines(output)
writeFile.close()

#Copy and move the word->id to another list to find the word has shown in which documents
wordAppearList=[]
for item in idDict:
    wordAppearList.append([idDict[item],item,[],[]])


#Copy getfeature.py, to modify the json files, change the dictionary word->appearance to id->appearance
flist=[flist for flist in os.listdir("../Data/converted/")]
subjectid=0
for item in flist:
    f=open("../Data/converted/"+item,'r',encoding='UTF-8')
    fdata=f.readlines()
    for line in range(len(fdata)):
        fdata[line]=fdata[line].strip()
    string=' '.join(fdata)
    #Find subject code
    subjectCodePos=string[string.index("Subject Code"):].index("COMP")
    subjectCode=(string[string.index("Subject Code"):])[subjectCodePos:subjectCodePos+8]
    #Special case process
    if (subjectCode.find(' ')!=-1):
        subjectCode=(string[string.index("Subject Code"):])[subjectCodePos:subjectCodePos+4]+(string[string.index("Subject Code"):])[subjectCodePos+5:subjectCodePos+9]
    #Find subject title
    subjectTitle=string[string.index("Subject Title")+15:string.index("Credit")]
    #Special case process
    if (subjectTitle.find('Industrial Placement')!=-1):
        subjectTitle='Industrial Placement'
    #Find Pre-requisite
    try:
        preRequisite=string[string.index("Pre-requisite"):string.index("Exclusion")]
    except ValueError:
        preRequisite=string[string.index("Pre-requisite"):string.index("Pre-requisite")+150]
    import re
    #Find pre-requ subject code position
    preSubjectPos=[substr.start() for substr in re.finditer('COMP', preRequisite)]
    #preSubjectPos.extend(substr.start() for substr in re.finditer('AMA', preRequisite))
    #Find pre-requ subject code number
    preSubjectNumber=[preRequisite[item:item+9] for item in preSubjectPos]
    #Special case process
    for sub in range(len(preSubjectNumber)):
        if preSubjectNumber[sub][4]==' ':
            preSubjectNumber[sub]=preSubjectNumber[sub][0:4]+preSubjectNumber[sub][5:9]
        else:
            preSubjectNumber[sub]=preSubjectNumber[sub][0:8]
    if subjectCode=='COMP4434':
        preSubjectNumber=['AMA1104', 'COMP1011', 'COMP2011', 'COMP2411']
    #Find credit value
    try:
        for char in string[string.index("Credit Value"):string.index("Credit Value")+20]:
            if ord(char)>47 and ord(char)<58:
                subjectCredit=char
                break
    #Special case for COMP4000
    except ValueError:
        subjectCredit="24 Training"
    #Find subject code
    subjectLevel=subjectCode[4]
    #Process the content to plain text
    wordList=re.split(" |\n|'",string)
    for item in range(len(wordList)):
        wordList[item]=''.join(list(filter(str.isalpha,wordList[item]))).lower()
    wordList=list(filter(None,wordList))
    wordListDict=dict()
    #Tranform list to dictionary
    for word in wordList:
        try:
            wordListDict[idDict[word]]+=1
        except KeyError:
            try:
                wordListDict[idDict[word]]=1
            except KeyError:
                pass
    #Process the title to plain text
    titleList=re.split(" |\n|'",subjectTitle)
    for item in range(len(titleList)):
        titleList[item]=''.join(list(filter(str.isalpha,titleList[item]))).lower()
    titleList=list(filter(None,titleList))
    titleListDict=dict()
    for word in titleList:
        try:
            titleListDict[idDict[word]]+=1
        except KeyError:
            try:
                titleListDict[idDict[word]]=1
            except KeyError:
                pass
    #Process pre-requisite to dictionary
    preRequisiteDict=dict()
    for item in preSubjectNumber:
        preRequisiteDict[item]=1
    #Finalize the data
    dataDict=dict()
    dataDict['Subject Code']=subjectCode
    dataDict['Subject Level']=subjectLevel
    dataDict['Subject Credit']=subjectCredit
    dataDict['Subject Title']=subjectTitle
    dataDict['Subject Title Words List']=titleListDict
    dataDict['Subject Pre-requisite']=preRequisiteDict
    dataDict['Subject Content']=wordListDict
    dataDict['Subject ID']=subjectid
    #Transform data to json
    dataJson=json.dumps(dataDict)
    writeFile=open("../Data/pre-processed2/"+subjectCode+".json",'w',encoding='UTF-8')
    writeFile.write(dataJson)
    writeFile.close()

    
    #This part can show whether a word appeared in a document and save the document id to each word
    for word in titleListDict:
        try:
            wordAppearList[word][2].append(subjectid)
        except KeyError:
            pass
    
    for word in wordListDict:
        try:
            wordAppearList[word][3].append(subjectid)
        except KeyError:
            pass
    subjectid+=1
    
#Construct a json to save the list
wordShownDict=dict()
for item in wordAppearList:
    wordShownDict[item[0]]=dict()
    wordShownDict[item[0]]['Word ID']=item[0]
    wordShownDict[item[0]]['Word']=item[1]
    wordShownDict[item[0]]['Shown in title']=item[2]
    wordShownDict[item[0]]['Shown in content']=item[3]
wordShownJson=json.dumps(wordShownDict)

writeFile=open("../Data/wordShownDocument.json",'w',encoding='UTF-8')
writeFile.write(wordShownJson)
writeFile.close()



