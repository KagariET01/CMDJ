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
lang=json.loads(open("lang/ch.json","r",encoding="utf-8").read())

def printer(s):
	if(cfg["no_output"]):
		return
	if(cfg["only_1_line"]):
		print("													",end="\r")
		print(s,end="\r")
	else:
		print(s)

#讀取設定檔
print(Fore.LIGHTMAGENTA_EX+"OS:",platform.system())
print(lang["loadCFG"])
cfg=json.loads(open("config.json","r",encoding="utf-8").read())

if(platform.system()=="Windows"):
	cfg["path"]=cfg["path"].replace('/','\\')

def pathget(i,tpe):
	return cfg["path"]+("{:0>"+str(cfg["numlen"])+"d}").format(i+cfg["stnum"])+tpe


#編譯
printer(lang["build"])
os.system("rm run")
if(os.system("g++ -o run main.cpp")):
	printer(Fore.YELLOW+lang["CE"])
	exit()
os.system("g++ -o ans ans.cpp")
#print("\r",end="")

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
	result[i]["st"]=time.time()
	if(os.system("timeout "+str(cfg["tl"]+0.2)+" ./run < "+pathget(i,".in")+" > "+pathget(i,".out"))):
		result[i]["re"]=True
		result[i]["ac"]=False
	result[i]["ed"]=time.time()

def inputmaker(i):
	os.system("python3 test_maker.py > "+pathget(i,".in"))

def ansmaker(i):
	os.system("./ans < "+pathget(i,".in")+" > "+pathget(i,".ans"))


#執行
T=int(input("測資數量（-1代表使用自訂測資）："))
if(T>0):
	cfg["path"]=cfg["auto_case_path"]
	os.system("mkdir "+cfg["path"])

def judge(i):
	if(T>0):
		#測資生成
		run=threading.Thread(target=inputmaker,args=(i,))
		printer(Fore.LIGHTRED_EX+"測資生成中 "+str(i)+Fore.RESET)
		run.start()
		run.join()
		#答案生成
		run=threading.Thread(target=ansmaker,args=(i,))
		printer(Fore.LIGHTYELLOW_EX+"答案生成中 "+str(i)+Fore.RESET)
		run.start()
		run.join()
	#執行
	run=threading.Thread(target=coderunner,args=(i,))
	printer(Fore.LIGHTCYAN_EX+lang["run"]+" "+str(i)+Fore.RESET)
	run.start()
	run.join()
	#判斷
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
	printer(Fore.LIGHTGREEN_EX+lang["fin"]+" "+str(i))



i=0
while(i<T or T==-1):
	if(T==-1):
		if(not os.path.isfile(pathget(i,".in"))):#找不到檔案
			break
		if(open(pathget(i,".in"),"r",encoding="utf-8").read()==""):#檔案為空
			break
	if(i==cfg["ednum"]):
		break
	result.append(copy.copy(tmp))
	result[i]["runner"]=threading.Thread(target=judge,args=(i,))
	result[i]["runner"].start()
	if(not cfg["sync"] or cfg["only_1_line"]):
		result[i]["runner"].join()
	i+=1

if(cfg["sync"]):
	for i in range(len(result)):
		result[i]["runner"].join()

if(not cfg["sync"] or cfg["only_1_line"]):
	print("\r",end="")


#輸出結果
allAC=True
for i in range(0,len(result),1):
	if(result[i]["ac"]):
		if(cfg["case_result_output"]):
			print(Back.LIGHTGREEN_EX+Fore.BLACK+lang["test"],i,":",lang["AC"],end="")
		if(cfg["rm_file_after_AC"]):
			os.system("rm "+pathget(i,".in"))
			os.system("rm "+pathget(i,".out"))
			os.system("rm "+pathget(i,".ans"))
	elif(result[i]["re"]):
		if(cfg["case_result_output"]):
			print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["RE"],end="")
		allAC=False
	elif(result[i]["tl"]):
		if(cfg["case_result_output"]):
			print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["TLE"],end="")
		allAC=False
	elif(result[i]["wa"]):
		if(cfg["case_result_output"]):
			print(Back.LIGHTRED_EX+Fore.BLACK+lang["test"],i,":",lang["WA"],end="")
		allAC=False
	if(cfg["case_result_output"]):
		print(Back.BLACK+Fore.LIGHTYELLOW_EX+lang["time"],result[i]["ed"]-result[i]["st"])
if(cfg["rm_file"]):
	os.system("rm -r -f "+cfg["path"])

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