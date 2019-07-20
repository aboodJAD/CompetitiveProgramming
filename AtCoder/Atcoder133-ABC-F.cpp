#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=5e5+10;

int n,q;
int dep[N],dp[N][20],cost[N],freq[N],cc[N];
vector<vector<int > > adj[N];
vector<vector<int > > qs;
set<int > pq[N];
map<int,pp > sv[N];
void dfs(int u,int p){
	dp[u][0]=p;
	for(auto v:adj[u]){
		if(v[0]==p)continue;
		dep[v[0]]=dep[u]+1;
		cost[v[0]]=cost[u]+v[2];
		dfs(v[0],u);
	}
}

void DFS(int u,int p){
	for(auto r:pq[u])sv[u][r] = {freq[r],cc[r]};
	for(auto v:adj[u]){
		if(v[0]==p)continue;
		freq[v[1]]++;
		cc[v[1]]+=v[2];
		DFS(v[0],u);
		freq[v[1]]--;
		cc[v[1]]-=v[2];
	}
}
int LCA(int a,int b){
	if(dep[b]<dep[a])swap(b,a);
	for(int i=18;i>-1;i--)if(dep[b]-(1<<i)>=dep[a])b=dp[b][i];
	if(a==b)return a;
	for(int i=18;i>-1;i--)if(dp[a][i]!=dp[b][i])b=dp[b][i],a=dp[a][i];
	return dp[b][0];
}
int getCost(int a,int b){
	return cost[a]+cost[b]-2*cost[LCA(a,b)];
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		adj[a].push_back({b,c,d});
		adj[b].push_back({a,c,d});		
	}
	dfs(1,0);
	for(int j=1;j<19;j++)for(int i=1;i<=n;i++)dp[i][j]=dp[dp[i][j-1]][j-1];
	for(int i=0;i<q;i++){
		int x,y,u,v;
		scanf("%d%d%d%d",&x,&y,&u,&v);
		qs.push_back({x,y,u,v});
		int lca=LCA(u,v);
		pq[lca].insert(x);
		pq[u].insert(x);
		pq[v].insert(x);				
	}
	DFS(1,0);
	for(int i=0;i<q;i++){
		int x=qs[i][0],y=qs[i][1],u=qs[i][2],v=qs[i][3],lca;
		lca=LCA(u,v);
		printf("%d\n",getCost(u,v)-(sv[u][x].second+sv[v][x].second-2*sv[lca][x].second)+
			(sv[u][x].first+sv[v][x].first-2*sv[lca][x].first)*y);
	}
    return 0;
}

