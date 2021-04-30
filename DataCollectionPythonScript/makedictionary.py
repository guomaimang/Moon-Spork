import json,os,nltk
wordList=dict()
flist=[flist for flist in os.listdir("../Data/pre-processed/")]
for item in flist:
    f=open("../Data/pre-processed/"+item,'r',encoding='UTF-8')
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
newWordList=dict()
for word in sortedDict:
    wordType=nltk.pos_tag(nltk.word_tokenize(word[0]))
    if wordType[0][1]!='CC' and wordType[0][1]!='DT' and wordType[0][1]!='EX' and wordType[0][1]!='IN' and wordType[0][1]!='LS' and wordType[0][1]!='MD' and wordType[0][1]!='SYM'and wordType[0][1]!='PRP' and wordType[0][1]!='TO' and wordType[0][1]!='VBP' and wordType[0][1]!='PRP$' and len(wordType[0][0])>2:
        newWordList[word[0]]=word[1]

