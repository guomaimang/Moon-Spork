import json,os
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
print(len(sortedDict))
newWordList=dict()
for word in sortedDict:
    if word[1] > 5:
        newWordList[word[0]]=word[1]
print(len(newWordList))