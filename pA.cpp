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
#define PIPII pair<INT,PII>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=1;
bool ynans=0;
bool eof=0;
string yes="Yes";
string no="No";


INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};

function<int(INT)> solve=[](INT casenum){
	INT n,m;
	if(!(cin>>n>>m))return -1;
	INT mp[n][m];
	struct cmp{
		bool operator()(PIPII a,PIPII b){
			return a>b;
		}
	};
	priority_queue<PIPII,vector<PIPII>,cmp> pq;
	for(INT i=0;i<n;i++){
		string str=read(string);
		for(INT j=0;j<m;j++){
			mp[i][j]=1e9+7;
			if(str[j]=='-'){
				pq.push({-1,{i,j}});
				mp[i][j]=-1;
			}
		}
	}
	while(!pq.empty()){
		PIPII nw=pq.top();
		pq.pop();
		INT id=nw.first;
		INT x=nw.second.first;
		INT y=nw.second.second;
		if(mp[x][y]!=id)continue;
		for(INT i=0;i<4;i++){
			INT nx=x+mx[i];
			INT ny=y+my[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
			if(mp[nx][ny]>id+1){
				mp[nx][ny]=id+1;
				pq.push({id+1,{nx,ny}});
			}
		}
	}
	INT p=read(INT);
	INT ans[p]={};
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			if(mp[i][j]==-1)continue;
			ans[mp[i][j]%p]++;
		}
	}
	for(INT i=0;i<p;i++){
		if(i)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
};



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
