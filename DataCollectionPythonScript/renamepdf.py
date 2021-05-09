"""
Written by Yunfei LIU at May 9, 2021

It is used to rename pdf name for download
"""
import os
files=os.listdir("../Data/pdfs/")
for item in files:
    os.rename("../Data/temp/"+item,"../Data/Renamedpdfs/"+item[0:8]+".pdf")