#include<bits/stdc++.h>
using namespace std;
#define INT long long int
//Discrete
void Discrete(
	vector<INT>::iterator L,//初始位置
	vector<INT>::iterator R,//結束位置（此位置不處理）
	vector<INT>::iterator out//輸出的初始位置
){
	INT st=1;
	vector<pair<INT,INT>> v;
	INT id=0;
	for(vector<INT>::iterator i=L;i!=R;i++,id++){
		INT val=*i;
		v.push_back({val,id});
	}
	sort(v.begin(),v.end());
	vector<INT>re;
	re.resize(v.size());
	re[v[0].second]=st;
	for(INT i=1;i<v.size();i++){
		if(v[i].first==v[i-1].first){
			re[v[i].second]=re[v[i-1].second];
		}else{
			re[v[i].second]=re[v[i-1].second];
			re[v[i].second]++;
		}
	}
	for(INT i:re){
		*out=i;
		out++;
	}
}

#ifndef EVAL
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
int main(){
	INT n;
	cin>>n;
	vector<INT> v;
	v.reserve(n);
	for(INT i=0;i<n;i++){
		INT a;
		cin>>a;
		v.push_back(a);
	}
	vector<INT> re;
	iterator_traits<vector<INT>::iterator>::value_type a=*v.begin();
	cout<<a<<endl;
	re.resize(n);
	Discrete(v.begin(),v.end(),re.begin());
	for(INT i:re){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
#endif