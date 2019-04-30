#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,m,dsu[N];
ll cnt[N];
vector<pp > adj[N];
vector<vector<int > > edg;

bool comp(vector<int > a,vector<int > b){
	return a[2]<b[2];
}
int find(int a){
	if(dsu[a]==a)return a;
	return dsu[a]=find(dsu[a]);
}
int dfs(int u,int p){
	int ret=1;
	for(auto v:adj[u]){
		if(v.first==p)continue;
		int r=dfs(v.first,u);
		ret+=r;
		cnt[v.second]+=(n-r)*1LL*r;
	}
	return ret;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)dsu[i]=i;
  for(int i=0;i<m;i++){
	  int a,b,c;
	  cin>>a>>b>>c;
	  edg.push_back({a,b,c});
  }
  sort(edg.begin(),edg.end(),comp);
  for(int i=0;i<m;i++){
	  int a=edg[i][0],b=edg[i][1],c=edg[i][2];
	  if(find(a)==find(b))continue;
	  adj[a].push_back({b,c});
	  adj[b].push_back({a,c});
	  dsu[find(a)]=find(b);
  }
  dfs(1,0);
  vector<int > an;
  for(int i=0;i<m;i++){
	  an.push_back(cnt[i]&1);
	  cnt[i+1]+=cnt[i]/2;
  }
  if(cnt[m]){
	  ll c=cnt[m];
	  while(c){
		  an.push_back(c&1);
		  c/=2;
	  }
  }
  while(an.back()==0)an.pop_back();
  reverse(an.begin(),an.end());
  for(auto v:an)cout<<v;
  return 0;
}
