"""
Written by Yunfei LIU at April 24, 2021

It is used to convert necessary features from txt file and tranform it to json file
"""
import os
import json
flist=[flist for flist in os.listdir("../Data/converted/")]
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
            wordListDict[word]+=1
        except KeyError:
            wordListDict[word]=1
    #Process the title to plain text
    titleList=re.split(" |\n|'",subjectTitle)
    for item in range(len(titleList)):
        titleList[item]=''.join(list(filter(str.isalpha,titleList[item]))).lower()
    titleList=list(filter(None,titleList))
    titleListDict=dict()
    for word in titleList:
        try:
            titleListDict[word]+=1
        except KeyError:
            titleListDict[word]=1
    titleListDict[subjectCode]=1
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
    #Transform data to json
    dataJson=json.dumps(dataDict)
    writeFile=open("../Data/pre-processed3/"+subjectCode+".json",'w',encoding='UTF-8')
    writeFile.write(dataJson)
    writeFile.close()
