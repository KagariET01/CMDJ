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
string yes="YES";
string no="NO";

function<int(INT)> solve=[](INT casenum){
	INT n,m;
	if(!(cin>>n>>m))return -1;
	INT mp[n+1][m+1]={};
	for(INT i=1;i<=n;i++){
		for(INT j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	INT dp[n+m+5][m+5][m+5]={};
	for(INT i=0;i<=n+m;i++){
		for(INT j=0;j<=m;j++){
			for(INT k=0;k<=m;k++){
				dp[i][j][k]=-1e9;
			}
		}
	}
	dp[2][1][1]=(mp[1][1]==1);
	if(mp[1][1]==-1){
		cout<<0<<'\n';return 0;
	}
	for(INT i=3;i<=n+m;i++){
		for(INT j=1;j<=min(m,i-1);j++){
			INT ii=i-j;
			if(ii<1 || m<ii)continue;
			for(INT y=1;y<=min(m,i-1);y++){
				INT x=i-y;
				if(y<1 || m<y)continue;
				if(mp[ii][j]==-1 || mp[x][y]==-1)continue;
				maxs(dp[i][j][y],dp[i-1][j][y]);
				maxs(dp[i][j][y],dp[i-1][j][y-1]);
				maxs(dp[i][j][y],dp[i-1][j-1][y]);
				maxs(dp[i][j][y],dp[i-1][j-1][y-1]);
				dp[i][j][y]+=mp[ii][j]+mp[x][y]-(j==y?mp[ii][j]:0);
			}
		}
	}
	cout<<max(dp[n+m][m][m],0)<<'\n';
	if(0)DBG{
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=m;j++){
				cout<<dp[i+j][j][j]<<" ";
			}
			cout<<endl;
		}
	}
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
