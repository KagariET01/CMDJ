#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=500000;

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
		INT q,m;
		cin>>q>>m;
		function<bool(PII,PII)> vser=[](PII a,PII b){
			if(a.first!=b.first) return a.first<b.first;
			else return a.second>b.second;
		};
		vector<PII> vec1;
		vector<PII> vecm;
		while(q--){
			INT l,r;
			cin>>l>>r;
			r++;
			if(l!=1){
				vec1.push_back({l,1});
				vec1.push_back({r,-1});
			}
			if(r!=m+1){
				vecm.push_back({l,1});
				vecm.push_back({r,-1});
			}
		}
		sort(vec1.begin(),vec1.end());
		sort(vecm.begin(),vecm.end());
		INT lstn=1;
		INT mx=0;
		INT nw=0;
		for(PII i:vec1){
			//cout<<"nw={"<<i.first<<","<<i.second<<"}"<<endl;
			if(i.first!=lstn){
				mx=max(mx,nw);
			}
			lstn=i.first;
			nw+=i.second;
		}
		nw=0;
		lstn=1;
		//cout<<"=============="<<endl;
		for(PII i:vecm){
			//cout<<"nw={"<<i.first<<","<<i.second<<"}"<<endl;
			if(i.first!=lstn){
				mx=max(mx,nw);
			}
			lstn=i.first;
			nw+=i.second;
		}
		cout<<mx<<endl;
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