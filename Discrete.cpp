#include<bits/stdc++.h>
using namespace std;
//Discrete
template<
	typename T1,//輸入位置型別(指標)
	typename T2,//輸出位置型別(指標)
	typename T3=long long int,//編號型別
	typename I=long long int,//編號型別
	typename T=typename iterator_traits<T1>::value_type//輸入型別
> void Discrete(
	T1 ibegin,//初始位置
	T1 iend,//結束位置（此位置不處理）
	T2 out,//輸出的初始位置
	T3 st=1//第一項編號
){
	vector<pair<T,I>> v;
	I id=0;
	for(T1 i=ibegin;i!=iend;i++,id++){
		decltype(*i) val=*i;
		v.push_back({val,id});
	}
	sort(v.begin(),v.end());
	vector<T3>re;
	re.resize(v.size());
	re[v[0].second]=st;
	for(I i=1;i<v.size();i++){
		if(v[i].first==v[i-1].first){
			re[v[i].second]=re[v[i-1].second];
		}else{
			re[v[i].second]=re[v[i-1].second];
			re[v[i].second]++;
		}
	}
	for(T3 i:re){
		*out=i;
		out++;
	}
}

#ifndef EVAL

#define INT long long int
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
	re.resize(n);
	Discrete(v.begin(),v.end(),re.begin());
	for(INT i:re){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}

#endif