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

int lv[1000001];

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

	INT nw=1;
	for(INT i=1;;i++){
		for(INT j=0;j<i;j++,nw++){
			lv[nw]=i;
			if(nw==1000000)break;
		}
		if(nw==1000000)break;
	}
	function<int(INT)> solve=[](INT casenum){
		unsigned INT n=read(INT);
		bool hve[n+1]={};
		queue<unsigned INT> que;
		que.push(n);
		unsigned ans=0;
		while(!que.empty()){
			if(que.front()<=0 || hve[que.front()]){
				que.pop();
				continue;
			}
			INT nw=que.front();
			que.pop();
			hve[nw]=1;
			ans+=nw*nw;
			DBG cout<<"a+="<<nw*nw<<endl;
			if(lv[nw]==lv[nw-1]){
				que.push(nw-lv[nw]);
			}
			if(lv[nw]==lv[nw+1]){
				que.push(nw-lv[nw]+1);
			}
		}
		//cout<<ans<<endl;
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
/**/