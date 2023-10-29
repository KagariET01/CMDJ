#include<bits/stdc++.h>

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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=100000;
INT n,m;
INT a[mxn+1];
INT ans=0;
vector<pair<INT,PII>> tre[mxn+1];//node,(cost,get)

void dfs(INT nw=1,INT lst=-1){
	for(pair<INT,PII> i:tre[nw]){
		if(i.first==lst)continue;
		dfs(i.first,nw);
		INT mv=abs(a[i.first]-m);//move car
		ans-=mv*i.second.first;
		if(mv){
			ans+=i.second.second;
		}else if(i.second.first*2<i.second.second){
			ans+=i.second.second-i.second.first*2;
		}
		a[nw]+=a[i.first]-m;
	}
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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		if(!(cin>>n>>m))return -1;
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(INT i=0;i<=n;i++)tre[i].clear();
		for(INT i=1;i<n;i++){
			INT a,b,c,d;
			cin>>a>>b>>c>>d;
			d=min(d,150)*2+max(d-150,0);
			tre[a].push_back({b,{c,d}});
			tre[b].push_back({a,{c,d}});
		}
		dfs();
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
	string yes="Yes";
	string no="No";
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