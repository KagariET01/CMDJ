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

	unsigned INT ans[1000005]={};
	int nw=1;
	int row=1;
	int lv[1000005]={};
	DBG cout<<"start"<<endl;
	for(row=1;;row++){
		for(int i=0;i<row;i++,nw++){
			if(i==row-1){
				ans[nw]=nw*nw;
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