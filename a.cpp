//code by Bbic
//tioj 2172

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
 
//#define int long long
typedef long long ll;
//typedef unsigned long long ull;
#define elif else if
#define O_O ios::sync_with_stdio(0), cin.tie(0)
#define m_p make_pair
#define p_b push_back
#define pp_b pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define st first
#define nd second
//const short dxy[] = {0, 1, 0, -1, 0};

const int N = 1e5 + 5;
//const int MOD = 998244353;

int t, L;
int deep[N], in[N], out[N], ac[N][25];
vector<int> eg[N];//tree



void dfs(int x, int pa){
	deep[x] = deep[pa] + 1;
	in[x] = ++t;
	ac[0][x] = pa;
	for(int i = 1; i <= L; ++i) ac[i][x] = ac[i - 1][ac[i - 1][x]];
	for(int i : eg[x]) if(i != pa) dfs(i, x);
	out[x] = ++t;
}

bool ancestor(int a, int b){
	return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b){
	if(ancestor(a, b)) return a;
	if(ancestor(b, a)) return b;
	for(int i = L; i >= 0; --i)
		if(!ancestor(ac[i][a], b)) a = ac[i][a];
	return ac[0][a];
}

signed main(int argc,char** argv){
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
	O_O;
	int n, m, a, b;
	cin >> n >> m;
	L = ceil(log10(n) / log10(2));
	for(int i = 1; i < n; ++i){
		cin >> a >> b;
		eg[a].push_back(b);
		eg[b].push_back(a);
	}
	dfs(0, 0);
	DBG{
		cout<<"Deep:";
		for(INT i=0;i<n;i++){
			cout<<" "<<deep[i];
		}
		cout<<endl;
	}
	
	/*
	while(m--){
		cin >> a >> b;
		cout << 0ll + deep[a] + deep[b] - deep[lca(a, b)] * 2 << '\n';
	}*/
}


/**/