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