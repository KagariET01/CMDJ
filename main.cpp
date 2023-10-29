#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],s[100001],g[10],f=0;
		memset(s,0,sizeof(s));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[a[i]]++;
		}
		for(int i=1;i<=100000;i++){
			if(s[i]>0){
				f++;
				g[f]=s[i];
			}
		}
		if(f==1||f<=2&&abs(g[1]-g[2]<=1))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}