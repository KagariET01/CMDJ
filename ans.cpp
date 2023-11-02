//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e6+5;

ll n, m, a[N], L[N], R[N], pos[N], tot, sz, buc[N], now, ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Query {
	ll l, r, id;
	Query(ll a=0, ll b=0, ll c=0) : l(a), r(b), id(c) {}
	~Query() {}
	friend bool operator < (const Query& a, const Query& b) {
		if(pos[a.l] == pos[b.l]) return a.r < b.r;
		return a.l < b.l;
	}
}q[N];
void ins(ll i) {
	if(buc[a[i]] & 1) ++now;
	++buc[a[i]];
}
void del(ll i) {
	--buc[a[i]];
	if(buc[a[i]] & 1) --now;
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sz = max((ll)sqrt(n), 1LL);
	while(++tot) {
		L[tot] = R[tot-1] + 1;
		R[tot] = min(n, tot*sz);
		rep(i, L[tot], R[tot]) pos[i] = tot;
		if(R[tot] == n) break; 
	}
	scanf("%lld", &m);
	rep(i, 1, m) {
		scanf("%lld%lld", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q+1, q+1+m);
	ll l = 1, r = 0;
	rep(i, 1, m) {
		while(l > q[i].l) ins(--l);
		while(r < q[i].r) ins(++r);
		while(r > q[i].r) del(r--);
		while(l < q[i].l) del(l++);
		ans[q[i].id] = now;
	}
	rep(i, 1, m) printf("%lld\n", ans[i]);
    return 0;
}