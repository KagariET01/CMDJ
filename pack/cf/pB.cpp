#include<bits/stdc++.h>

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
#define F first
#define S second
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=0;
bool ynans=0;
bool eof=1;
string yes="YES";
string no="NO";
template<typename T1,typename T2>istream& operator>>(istream &cn,pair<T1,T2> &p){
	return cn>>p.first>>p.second;
}
template<typename T1,typename T2>ostream& operator<<(ostream &cn,pair<T1,T2> p){
	return (cn<<"{"<<p.first<<","<<p.second<<"}");
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

function<int(INT)> solve=[](INT casenum){
	INT n;
	if(!(cin>>n))return -1;

	vector<INT> vec;
	vec.reserve(n);
	INT mn=1e18;
	for(INT i=0;i<n;i++){
		vec.push_back(read(INT));
		mins(mn,vec.back());
	}
	for(INT ans=2;1;ans+=ans){
		set<INT> se;
		for(INT i=0;i<n && se.size()<=2;i++){
			se.insert(vec[i]%ans);
		}
		if(se.size()==2){
			cout<<ans<<endl;
			return 0;
		}
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