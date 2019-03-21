/*
we should note that constructing MST is enough to find the minimum cost.
sort the edges by gi, then by si in increasing order. then for each edge find the MST contructed by all previous edges s.t si is the maximum among all edges in the tree. for this we need to keep connected components and for an edge a-b find the path between a,b then replace maximum s(silver) on this path by current si if current si is smaller. 
when we have tree of n-1 edges minimze the cost.
complexity O(M.N.log(N));
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

int n,m,s,g,dsu[201],a,b,c,d,cnt;
ll an=OO+1;
vector<vector<int > > e;
set<int > adj[201];
int sv[201][201];
bool comp(vector<int > a,vector<int > b){
    if(a[2]==b[2])return a[3]<b[3];
    return a[2]<b[2];
}
int find(int u){
    if(dsu[u]==u)return u;
    return dsu[u]=find(dsu[u]);
}

int dfs(int u,int p){
    int an=0;
    for(auto v:adj[u]){
        if(v==p)continue;
        an=max(an,dfs(v,u));
        an=max(an,sv[v][u]);
    }
    return an;
}
void check(){
    queue<int > q;
    int par[201],vis[201]={};
    fill(par,par+n+1,-1);
    q.push(a);
    vis[a]=1;
    while(!q.empty()){
        int y=q.front();q.pop();
        for(auto v:adj[y]){
            if(!vis[v]){
                q.push(v);
                par[v]=y;
                vis[v]=1;
            }
        }
    }
    int ra,rb,rd=0,cur=b;
    while(par[cur]!=-1){
        int we=sv[cur][par[cur]];
        if(we>rd){
            rd=we;
            ra=cur;
            rb=par[cur];
        }
        cur=par[cur];
    }
    if(rd>d){
        adj[ra].erase(rb);
        adj[rb].erase(ra);
        sv[ra][rb]=0;
        sv[rb][ra]=0;
        adj[a].insert(b);
        adj[b].insert(a);
        sv[a][b]=d;
        sv[b][a]=d;
    }
}
void uni(){
    int p1=find(a),p2=find(b);
    sv[a][b]=d;
    sv[b][a]=d;
    dsu[p1]=p2;
    adj[a].insert(b);
    adj[b].insert(a);
    cnt++;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>g>>s;
  for(int i=0;i<m;i++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      e.push_back({a,b,c,d});
  }
  sort(e.begin(),e.end(),comp);
  for(int i=1;i<=n;i++)dsu[i]=i;
  for(int i=0;i<m;i++){
      vector<vector<int > > r;
      int j=i;
      while(j<m&&e[j][2]==e[i][2]){
          r.push_back(e[j]);
          j++;
      }
      for(int j=0;j<sz(r);j++){
          a=r[j][0],b=r[j][1],c=r[j][2],d=r[j][3];
          if(find(a)==find(b))check();
          else uni();
      }
      if(cnt==n-1)an=min(an,dfs(1,-1)*1LL*s+e[i][2]*1LL*g);
      i=j-1;
  }
  if(cnt!=n-1)cout<<-1<<'\n';
  else cout<<an<<'\n';
  return 0;
}