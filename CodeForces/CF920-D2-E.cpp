#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

int n,m,siz=0;
set<int > rem,adj[N];

void dfs(int u){
	int nxt=0;
	siz++;
	while(1){
		auto v = rem.upper_bound(nxt);
		if(v==rem.end())break;
		nxt=*v;
		if(adj[u].count(nxt))continue;
		rem.erase(nxt);
		dfs(nxt);
	}
}
void solve(){
	cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	for(int i=1;i<=n;i++){
		rem.insert(i);
	}
	int an=0;
	vector<int > res;
	for(int i=1;i<=n;i++){
		if(rem.count(i)){
			an++;
			rem.erase(i);
			dfs(i);
			res.push_back(siz);
			siz=0;
		}
	}
	cout<<an<<'\n';
	sort(res.begin(),res.end());
	for(auto v:res)cout<<v<<' ';
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	
	return 0;
}