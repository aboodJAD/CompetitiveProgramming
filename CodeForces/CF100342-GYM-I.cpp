/*
if the node is not articulation node, then result for it equal n-1
else find number of nodes in each component resulted from removing an articulation node using dfs and calculate the result. 
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,m,vis[N],desc[N],low[N],tim,isa[N];
ll an[N];
vector<int > adj[N];

void dfs(int u,int p){
	desc[u]=low[u]=tim++;
	vis[u]=1;
	int cnt=0;
	for(auto v:adj[u]){
		if(!vis[v]){
			cnt++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=desc[u])isa[u]=1;
		}else if(v!=p)low[u]=min(low[u],desc[v]);		    
		
	}
	if(p==0)isa[u]=cnt>1;
}

int dfs2(int u){
	vis[u]=1;
	int ret=1,sm=0;
	vector<int > cc;
	for(auto v:adj[u]){
		if(vis[v])continue;
		int y=dfs2(v);
		if(low[v]>=desc[u])cc.push_back(y);else sm+=y;
		ret+=y;
	}
	an[u]=2*(n-1);
	cc.push_back(n-ret+sm);
	if(isa[u])for(auto q:cc)an[u]+=q*1LL*(n-q-1);
	return ret;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);  
  cin>>n>>m;
  for(int i=0;i<m;i++){
	  int a,b;
	  cin>>a>>b;
	  adj[a].push_back(b);
	  swap(a,b);
	  adj[a].push_back(b);
  }
  dfs(1,0);
  memset(vis,0,sizeof vis);
  dfs2(1);
  for(int i=1;i<=n;i++)cout<<an[i]/2<<'\n';
  return 0;
}