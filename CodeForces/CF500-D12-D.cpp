/*
first caluclate the expected value before any query, for each
edge add the expected value of traversing this edge, 
then for each query subtract the old expected value then add the new one;
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

int n,sz[N],par[N];
vector<pp > adj[N];
vector<vector<int > > edg;
ll d;
void dfs(int u,int p){
    par[u]=p;
    for(auto v:adj[u]){
        if(v.first==p)continue;
        dfs(v.first,u);
        sz[u]+=sz[v.first];
    }
    sz[u]++;
}
double calc(vector<int > v){
    int a=v[0],b=v[1],c=v[2];
    if(par[a]==b)swap(a,b);
    double ret=0;
    int out=n-sz[b];
    if(sz[b]>=2)ret+=(out*1LL*(sz[b]-1)*1LL*sz[b]*1.0/d)*(1LL*c*6);
    if(out>=2)ret+=(sz[b]*1LL*(out-1)*1LL*out*1.0/d)*(1LL*c*6);
    return ret;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  d=(n-2)*1LL*(n-1)*1LL*n;
  for(int i=0;i<n-1;i++){
      int a,b,c;
      cin>>a>>b>>c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
      edg.push_back({a,b,c});
  }
  dfs(1,0);
  double res=0;
  for(auto e:edg)res+=calc(e);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
      int idx,c;
      cin>>idx>>c;
      idx--;
      res-=calc(edg[idx]);
      edg[idx][2]=c;
      res+=calc(edg[idx]);
      cout<<fixed<<setprecision(7)<<res<<'\n';
  }
  return 0;
}