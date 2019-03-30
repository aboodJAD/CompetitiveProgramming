#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,m,desc[1001],low[1001],vis[1001],tim;
vector<vector<int > > adj;
set<pp> br, pr;
void dfs1(int u,int p){
    vis[u]=1;
    desc[u]=low[u]=tim++;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs1(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>desc[u]){
                br.insert({v,u});
                br.insert({u,v});
            }
        }else if(p!=v)low[u]=min(low[u],desc[v]);
    }
}
void dfs2(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(br.count({v,u})){
            cout<<u<<' '<<v<<'\n';
            continue;
        }
        if(vis[v]){
            if(pr.count({v,u}))continue;
            pr.insert({u,v});
            cout<<u<<' '<<v<<'\n';
            continue;
        }
        pr.insert({u,v});
        cout<<u<<' '<<v<<'\n';
        dfs2(v);
    }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  while(1){
      cin>>n>>m;
      if(n==0&&m==0)break;
      memset(low,0,sizeof low);
      memset(desc,0,sizeof desc);
      memset(vis,0,sizeof vis);
      pr.clear();
      br.clear();
      tim=0;
      adj.clear();
      adj.resize(n+1);
      for(int i=0;i<m;i++){
          int a,b;
          cin>>a>>b;
          adj[a].push_back(b);
          adj[b].push_back(a);
      }
      dfs1(1,0);
      memset(vis,0,sizeof vis);
      cout<<t<<"\n\n";
      for(int i=1;i<=n;i++)if(!vis[i])dfs2(i);
      t++;
      cout<<"#\n";
  }
  return 0;
}