import os
import requests
from urllib.parse import urljoin
from bs4 import BeautifulSoup

url = "https://www.comp.polyu.edu.hk/en-us/study/undergraduate-programmes/subject"

#If there is no such folder, the script will create one automatically
folder_location = r'C:/Users/Fei/OneDrive - The Hong Kong Polytechnic University/course/2020-2021 Semester 2/COMP1011 PROGRAMMING FUNDAMENTALS/pdfs'
if not os.path.exists(folder_location):os.mkdir(folder_location)

response = requests.get(url)
soup= BeautifulSoup(response.text, "html.parser")     
for link in soup.select("a[href$='.pdf']"):
    #Name the pdf files using the last portion of each link which are unique in this case
    filename = os.path.join(folder_location,link['href'].split('/')[-1])
    with open(filename, 'wb') as f:
        f.write(requests.get(urljoin(url,link['href'])).content)