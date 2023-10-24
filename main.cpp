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
		struct dta{
			INT h;
			INT i;//實際位置
			INT mini;//左界
		};
		INT n;
		cin>>n;
		vector<INT> h(n);
		for(INT i=0;i<n;i++){
			cin>>h[i];
		}
		h.push_back(1e9+7);
		INT mp[n+5];//mp[距離]=高
		for(INT i=0;i<=n;i++){
			mp[i]=1e9+7;
		}
		stack<dta> st;
		for(INT i=0;i<=n;i++){
			DBG{
				if(st.empty()){
					cerr<<"st empty"<<endl;
				}else{
					cerr<<"st top= h:"<<st.top().h<<" i:"<<st.top().i<<" mini:"<<st.top().mini<<endl;
				}
			}
			while(!st.empty()){
				if(st.top().h<h[i]){
					INT hh=i-st.top().mini;//最大距離
					mp[hh]=min(mp[hh],st.top().h);
					st.pop();
				}else if(st.top().h==h[i]){
					st.top().i=i;
					break;
				}else break;
			}
			if(st.empty()){
				dta pp;
				pp.h=h[i];
				pp.i=i;
				pp.mini=0;
				st.push(pp);
			}else if(st.top().h==h[i])continue;
			else{
				dta pp;
				pp.h=h[i];
				pp.i=i;
				pp.mini=st.top().i+1;
				st.push(pp);
			}
		}
		INT nw=mp[n];
		DBG cerr<<"mp: ";
		for(INT i=n;i>=0;i--){
			nw=min(nw,mp[i]);
			mp[i]=nw;
			DBG cerr<<mp[i]<<" ";
		}
		INT q=read(INT);
		while(q--){
			cout<<mp[read(INT)]<<endl;
		}
		return 0;
	};
	bool one_case=1;
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