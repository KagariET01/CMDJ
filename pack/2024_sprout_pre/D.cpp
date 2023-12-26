#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define FINT long double
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define F first
#define S second
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=1;
bool ynans=0;
bool eof=0;
string yes="YES";
string no="NO";
template<typename T1,typename T2>istream& operator>>(istream &cn,pair<T1,T2> &p){
	return cn>>p.first>>p.second;
}
template<typename T1,typename T2>ostream& operator<<(ostream &cn,pair<T1,T2> p){
	return (cn<<""<<p.first<<" "<<p.second<<"");
}

template<typename T1,typename T2>void operator+=(T1 &a,T2 &b){
	a=a+b;
}
template<typename T1,typename T2>void operator-=(T1 &a,T2 &b){
	a=a-b;
}

PII operator+(PII &a,PII &b){
	return make_pair(a.F+b.F,a.S+b.S);
}
PII operator-(PII &a,PII &b){
	return make_pair(a.F-b.F,a.S-b.S);
}

PII mv[]={
	{0,-1},
	{-1,0},
	{0,1},
	{1,0}
};

function<int(INT)> solve=[](INT casenum){
	INT n;
	if(!(cin>>n))return -1;
	char mp[n+5][n+5];
	for(INT i=0;i<n;i++){
		cin>>mp[i];
	}
	INT l;
	cin>>l;
	string str;
	cin>>str;
	vector<PII> ans;
	for(INT x=0;x<n;x++){
		for(INT y=0;y<n;y++){
			PII nw={x,y};
			INT op=0;
			INT mvc=0;
			INT nmv=1;
			bool a=true;
			DBG cout<<"nw in "<<nw<<endl;
			for(char c:str){
				if(nw.F<0 || n<=nw.F ||
					nw.S<0 || n<=nw.S ||
					c!=mp[nw.F][nw.S]){
					a=false;
					break;
				}
				nw+=mv[op];
				mvc++;
				if(mvc==nmv){
					mvc=0;
					op++;
					op%=4;
					if(!(op&1)){
						nmv++;
					}
				}
			}
			if(a){
				ans.push_back({x+1,y+1});
			}
			DBG cout<<endl;
		}
	}
	cout<<ans.size()<<endl;
	for(PII i:ans){
		cout<<i<<endl;
	}
	return 0;
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