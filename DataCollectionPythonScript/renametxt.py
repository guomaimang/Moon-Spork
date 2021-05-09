"""
Written by Yunfei LIU at May 9, 2021

It is used to rename txt file names for display
"""
import os
files=os.listdir("../Data/converted/")
for item in files:
    os.rename("../Data/temp/"+item,"../Data/Renamedtxt/"+item[0:8]+".txt")