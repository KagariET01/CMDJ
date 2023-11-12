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
#define INT int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define ifif if
#define elif else if
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

struct str{
	INT lst[3][3]={};
};

str operator*(str a,str b){
	str re;
	for(INT i=0;i<3;i++){
		for(INT j=0;j<3;j++){
			for(INT k=0;k<3;k++){
				re.lst[i][j]+=a.lst[i][k]*b.lst[k][j];
			}
		}
	}
	return re;
}


template<typename T>T spow(T a,INT b){
	if(b==0){
		T re;
		return re;
	}
	T re=a;
	T xx=a;
	b--;
	while(b){
		if(b&1)re=re*xx;
		xx=xx*xx;
		b>>=1;
	}
	return re;
}



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

	function<int(INT)> solve=[](INT casenum){
		INT n=read(INT);
		ifif(n==1){
			cout<<0<<endl;
			return 0;
		}elif(n==2){
			cout<<1<<endl;
			return 0;
		}elif(n==3){
			cout<<3<<endl;
			return 0;
		}else{
			str a;
			a.lst[0][0]=0;
			a.lst[0][1]=1;
			a.lst[0][2]=2;
			str b;
			b.lst={
				{0,0,},
				{1,0,},
				{0,1,}
			};
		}

		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
	string yes="YES";
	string no="NO";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
/**/