#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2020;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

vector<int > adj[N];
int n,aa[N],cc[N];

int dfs(int u){
	int cnt=0;
	for(auto v:adj[u]){
		cnt+=dfs(v);
	}
	if(cc[u]>cnt){
		cout<<"NO";
		exit(0);
	}
	return cnt+1;
}
vector<pp > dfs_b(int u){
	vector<pp> al;
	int sh=0;
	for(auto v:adj[u]){
		auto ret=dfs_b(v);
		for(auto p:ret){
			al.push_back({p.first+sh,p.second});
		}
		sh=al.back().first;
	}
	if(al.empty()){
		return {{1,u}};
	}
	
	cout<<u<<endl;

	for(auto r:al){
		cout<<r.first<<' '<<r.second<<endl;
	}
	al.insert(al.begin()+cc[u],{cc[u]+1,u});
	for(int i=cc[u]+1;i<sz(al);i++)al[i].first++;
	return al;
}
void solve(){
	cin>>n;
	int root=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>cc[i];
		if(a==0)root=i;
		else adj[a].push_back(i);
	}
	dfs(root);
	auto res=dfs_b(root);
	for(auto r:res){
		aa[r.second]=r.first;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<aa[i]<<' ';
	cout<<endl;
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