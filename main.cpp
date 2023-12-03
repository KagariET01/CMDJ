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
bool ynans=0;
bool eof=1;
string yes="YES";
string no="NO";

INT mod=998244353;

function<int(INT)> solve=[](INT casenum){
	INT n,k,q;
	if(!(cin>>n>>k>>q))return -1;
	INT a[n+5];//原始資料
	INT hve[k+5][n+5];//子樹(或該節點)有沒有禮物i，如果有的話，距離多少
	for(INT i=0;i<=k;i++){
		for(INT j=0;j<=n;j++){
			hve[i][j]=1e9+7;
		}
	}
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	for(INT i=n;i>=1;i--){
		mins(a[i/2],a[i]);
	}
	for(INT i=n;i>=1;i--){
		hve[a[i]][i]=0;
	}
	for(INT i=n;i>=1;i--){
		for(INT j=0;j<=k;j++){
			mins(hve[j][i>>1],hve[j][i]+1);
		}
	}
	while(q--){
		INT d,p;
		cin>>d>>p;
		INT ans=1e9;
		INT nw=0;
		while(d){
			mins(ans,nw+hve[p][d]);
			nw++;
			d>>=1;
		}
		cout<<ans<<endl;
	}
	return 0;
};


#ifndef EVAL
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
		INT t=(one_case?1:read(int));
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
#endif
/**/