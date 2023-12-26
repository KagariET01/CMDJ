// [AC]

#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#include<string>
//#include<sstream>
//#include<vector>
//#include<queue>
//#include<deque>
//#include<map>
//#include<set>
//#include<cstring>
//#include<iomanip>
//#include<ctime>
//#include<list>

using namespace std;
#define INT long long int
#define FINT long double
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=1;
bool ynans=1;
bool eof=0;
string yes="YES";
string no="NO";
template<typename T1,typename T2>istream& operator>>(istream &cn,pair<T1,T2> &p){
	return cn>>p.first>>p.second;
}
template<typename T1,typename T2>ostream& operator<<(ostream &cn,pair<T1,T2> p){
	return (cn<<"{"<<p.first<<","<<p.second<<"}");
}

bool cbk(string str){
	string str2="";
	for(char c:str){
		str2=c+str2;
	}
	DBG cout<<"str="<<str<<"\nstr2="<<str2<<endl;
	return (str2==str);
}

function<int(INT)> solve=[](INT casenum){
	string str;
	if(!(cin>>str))return -1;
	for(int i=0;i<str.size();i++){
		string nw="";
		for(int j=0;j<str.size();j++){
			if(i==j)continue;
			nw+=str[j];
		}
		if(cbk(nw))return 1;
	}
	return (int)cbk(str);
};

//#ifndef EVAL
int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	do{
		INT t=1;
		if(!one_case && !(cin>>t)){
			eof=0;
			break;
		}
		for(INT i=0;i<t;i++){
			INT re=solve(i);
			if(re==-1)return 0;
			if(ynans){
				if(re==1){
					cout<<yes<<endl;
				}else if(re==0){
					cout<<no<<endl;
				}
			}
		}
	}while(eof);
	return 0;
}
//#endif
/**/