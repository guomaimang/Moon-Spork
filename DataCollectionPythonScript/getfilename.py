"""
Written by Yunfei LIU at April 26, 2021
This script is used to collect all file names of the data
"""
import os
names=os.listdir("../Data/pre-processed/")
names='\n'.join(names)
writeFile=open("../Data/fileNames.csv",'w')
writeFile.write(names)
writeFile.close()