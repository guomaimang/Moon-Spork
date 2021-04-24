"""
Written by Yunfei LIU at April 24, 2021

It is used to convert pdf files to text
"""
import pdfplumber,os
files=os.listdir("../Data/pdfs/")
for item in files:
    pdf = pdfplumber.open('../Data/pdfs/'+item)
    content=[]
    for length in range(len(pdf.pages)):
        page = pdf.pages[length]
        text = page.extract_text()
        content.append(text)
    w=open("../Data/converted/"+item[0:-4]+'.txt','w',encoding='UTF-8')
    w.writelines(content)
    w.close()
    pdf.close()