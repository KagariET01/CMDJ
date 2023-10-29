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
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=1e5;
INT lca[mxn+1][30];
INT n;
vector<INT> tre[mxn];
INT deep[mxn];

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

	cout<<1<<endl;
	cout<<100<<endl;
	for(INT i=1;i<=50;i++){
		if(i!=1)cout<<" ";
		cout<<i<<" "<<i;
	}
	cout<<endl;
	return 0;
}