from queue import Queue
import time
import os
import json
import colorama
from colorama import Fore, Style, Back
import threading
import sys
import copy
import platform

print(Back.BLACK)

DBG=0
lang=json.loads(open("lang/en.json","r",encoding="utf-8").read())

#讀取設定檔
print(Fore.LIGHTMAGENTA_EX+"OS:",platform.system())
print(lang["loadCFG"])
cfg=json.loads(open("config.json","r",encoding="utf-8").read())

if(platform.system()=="Windows"):
	cfg["path"]=cfg["path"].replace('/','\\')

def pathget(i,tpe):
	return cfg["path"]+("{:0>"+str(cfg["numlen"])+"d}").format(i+cfg["stnum"])+tpe


#編譯
print(lang["build"],end="")
os.system("rm run")
if(os.system("g++ -o run main.cpp")):
	print(Fore.YELLOW+lang["CE"])
	exit()
print("\r",end="")

result=[]
tmp={
	"st":0,
	"ed":0,
	"ac":1,
	"tl":0,
	"wa":0,
	"re":0
}


def coderunner(i):#執行
	result[i]["st"]=0
	if(platform.system()=="Windows"):
		#print("> type \""+pathget(i,".in")+"\" | .\\run > "+pathget(i,".out")+" & timeout /NOBREAK /T "+str(cfg["tl"])+" > \"DBG\" & taskkill /f /im run.exe > \"DBG\"")
		nwtm=os
		result[i]["st"]=time.time()
		if(DBG):
			print("> type \""+pathget(i,".in")+"\" | .\\run > "+pathget(i,".out"))
		nwtm.system("type \""+pathget(i,".in")+"\" | .\\run > "+pathget(i,".out"))
		result[i]["ed"]=time.time()
	else:
		result[i]["st"]=time.time()
		if(os.system("timeout "+str(cfg["tl"]+0.2)+" ./run < "+pathget(i,".in")+" > "+pathget(i,".out"))):
			result[i]["re"]=True
			result[i]["ac"]=False
		result[i]["ed"]=time.time()

def judge(i):
	run=threading.Thread(target=coderunner,args=(i,))
	print(Fore.LIGHTCYAN_EX+lang["run"],i,end="")
	run.start()
	run.join()
	outf=open(pathget(i,".out"),"r",encoding="utf-8").read().lower()
	ansf=open(pathget(i,".ans"),"r",encoding="utf-8").read().lower()
	if(not result[i]["ed"]):
		result[i]["st"]=False
		result[i]["ed"]=cfg["tl"]
		result[i]["tl"]=True
		result[i]["ac"]=False
		return
	if(result[i]["ed"]-result[i]["st"]>cfg["tl"]):
		result[i]["tl"]=True
		result[i]["ac"]=False
		return
	if(outf==ansf):
		result[i]["wa"]=0
		result[i]["ac"]=1
	else:
		result[i]["wa"]=1
		result[i]["ac"]=0
	if(cfg["sync"]):
		print()
		print(lang["fin"],i)
	else:
		print("\b\b\r",end="")


#執行
i=0
while(True):
	if(DBG):
		print("now case",i)
		print("finding file",pathget(i,".in"))
	if(not os.path.isfile(pathget(i,".in"))):
		if(DBG):
			print("file",i,"not found")
		break
	if(open(pathget(i,".in"),"r",encoding="utf-8").read()==""):
		break
	result.append(copy.copy(tmp))
	result[i]["runner"]=threading.Thread(target=judge,args=(i,))
	result[i]["runner"].start()
	if(not cfg["sync"]):
		result[i]["runner"].join()
	i+=1

if(cfg["sync"]):
	for i in range(len(result)):
		result[i]["runner"].join()

if(not cfg["sync"]):
	print("\r",end="")


#輸出結果
allAC=True
for i in range(0,len(result),1):
	if(result[i]["ac"]):
		print(Back.LIGHTGREEN_EX+Fore.BLACK+lang["test"],i,":",lang["AC"],end="")
	elif(result[i]["re"]):
		print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["RE"],end="")
		allAC=False
	elif(result[i]["tl"]):
		print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["TLE"],end="")
		allAC=False
	elif(result[i]["wa"]):
		print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["WA"],end="")
		allAC=False
	print(Back.BLACK+Fore.LIGHTYELLOW_EX+lang["time"],result[i]["ed"]-result[i]["st"])

if(allAC):
	print(Back.LIGHTGREEN_EX+Fore.BLACK+lang["allAC"]+Back.RESET+Fore.RESET)
	exit()
else:
	print(Back.LIGHTRED_EX+Fore.BLACK+Fore.LIGHTRED_EX+lang["nopass"]+Back.RESET+Fore.RESET)
	sys.exit(0)
	exit()

'''
config.json
{
	"tl":1,
	"path":"io/",
	"numlen":1,
	"stnum":0,
	"sync":true
}

lang/en.json
{
	"loadCFG":"Loading Config File.",
	"build":"Building Your Code.",
	"run":"Running:",
	"fin":"finished:",
	"TLE":"TLIE!",
	"WA":"WANS!",
	"RE":"RTER!",
	"AC":"PASS!",
	"CE":"COMPILER ERROR!",
	"time":"Time:",
	"test":"Test",
	"allAC":"ALL EXAMPLE TEST PASSED!",
	"nopass":"NO PASS!"
}
'''