#include<bits/stdc++.h>
<<<<<<< HEAD
=======
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
>>>>>>> 848e5f134734a5c7774a9a8344fcd67a17e92fbd

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
<<<<<<< HEAD
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
=======
#define ifif if
#define elif else if
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
>>>>>>> 848e5f134734a5c7774a9a8344fcd67a17e92fbd

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

<<<<<<< HEAD
	unsigned INT ans[1000005]={};
	int nw=1;
	int row=1;
	int lv[1000005]={};
	DBG cout<<"start"<<endl;
	for(row=1;;row++){
		for(int i=0;i<row;i++,nw++){
			if(i==row-1){
				ans[nw]=nw*nw;
=======
	function<int(INT)> solve=[](INT casenum){
		INT n,m;
		cin>>n>>m;
		vector<INT> vec;
		vec.reserve(n*m);
		for(INT i=0;i<n*m;i++){
			vec.push_back(read(INT));
		}
		sort(vec.begin(),vec.end());
		INT a=
			(vec[n*m-1]-vec[0])*(max(n,m)-1)+
			(vec[n*m-1]-vec[1])*(min(n,m)-1)+
			(vec[n*m-1]-vec[0])*(n-1)*(m-1);
		INT b=
			(vec[n*m-1]-vec[0])*(max(n,m)-1)+
			(vec[n*m-2]-vec[0])*(min(n,m)-1)+
			(vec[n*m-1]-vec[0])*(n-1)*(m-1);
		cout<<max(a,b)<<endl;
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
>>>>>>> 848e5f134734a5c7774a9a8344fcd67a17e92fbd
			}else{
				ans[nw]=ans[nw-row+1]+nw*nw;
			}
			if(i)lv[nw]=row;
			DBG cout<<ans[nw]<<" ";
			if(nw==1000000)break;
		}
		DBG cout<<endl;
		if(nw==1000000)break;
	}
	int t=read(INT);
	while(t--){
		int inin=read(INT);
		INT a=0;
		while(inin){
			a+=ans[inin];
			if(lv[inin])inin-=lv[inin];
			else break;
		}
		cout<<a<<endl;
	}
	return 0;
}
/**/