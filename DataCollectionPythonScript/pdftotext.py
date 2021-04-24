import pdfplumber,os
files=os.listdir("C:/Users/Fei/OneDrive - The Hong Kong Polytechnic University/course/2020-2021 Semester 2/COMP1011 PROGRAMMING FUNDAMENTALS/pdfs/")
for item in files:
    pdf = pdfplumber.open('C:/Users/Fei/OneDrive - The Hong Kong Polytechnic University/course/2020-2021 Semester 2/COMP1011 PROGRAMMING FUNDAMENTALS/pdfs/'+item)
    content=[]
    for length in range(len(pdf.pages)):
        page = pdf.pages[length]
        text = page.extract_text()
        content.append(text)
    w=open("C:/Users/Fei/OneDrive - The Hong Kong Polytechnic University/course/2020-2021 Semester 2/COMP1011 PROGRAMMING FUNDAMENTALS/converted/"+item[0:-4]+'.txt','w',encoding='UTF-8')
    w.writelines(content)
    w.close()
    pdf.close()