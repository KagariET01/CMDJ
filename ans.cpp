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
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n,q;
		cin>>n>>q;
		INT a[n];
		vector<INT> x;
		x.reserve(q);
		for(INT i=0;i<n;i++){cin>>a[i];}
		for(INT i=0;i<q;i++){INT inin=read(INT);if(x.empty() || inin<x.back())x.push_back(inin);}
		for(INT i=0;i<n;i++){
			for(INT j:x){
				DBG cout<<"a[i]="<<a[i]<<",j="<<j<<endl;
				if(!(a[i]%(1<<j))){
					a[i]+=1<<(j-1);
				}
			}
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
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