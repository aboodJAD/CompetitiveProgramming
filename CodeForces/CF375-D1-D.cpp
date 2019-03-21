/*
we need to use dsu on tree with segment tree;
for each node v, save the frequency of each color of the nodes 
in the subtree of v, then for each query use segment tree to 
get the number of colors that has frequency larger than or equal to ki.  
Complexity O(N.log^2(N));
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

int cnt[N],in[N],out[N],rev[N],seg[N<<2],an[N];
int n,q,cc[N],sz[N];
vector<int > adj[N];
vector<pp > ch[N];

void upd(int p,int l,int r,int at,int v){
    if(l>at||r<at)return ;
    if(l==at&&r==at){
        seg[p]+=v;
        return ;
    }
    int m=(l+r)>>1;
    upd(p<<1,l,m,at,v);
    upd(p<<1|1,m+1,r,at,v);
    seg[p]=seg[p<<1]+seg[p<<1|1];
}
int get(int p,int l,int r,int lx,int rx){
    if(l>=lx&&r<=rx)return seg[p];
    if(l>rx||r<lx)return 0;
    int m=(l+r)>>1;
    return get(p<<1,l,m,lx,rx)+get(p<<1|1,m+1,r,lx,rx);
}
void dfs(int u,int p){
    static int tim=0;
    in[u]=++tim;
    rev[tim]=u;
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    out[u]=tim;
}

void dfs(int u,int p,int ke){
    int mx=-1,who=-1;
    for(auto v:adj[u]){
        if(v==p)continue;
        if(sz[v]>mx){
            mx=sz[v];
            who=v;
        }
    }
    for(auto v:adj[u]){
        if(v==p||v==who)continue;
        dfs(v,u,0);
    }
    if(who!=-1)dfs(who,u,1);
    for(auto v:adj[u]){
        if(v==p||v==who)continue;
        for(int j=in[v];j<=out[v];j++){
            int col=cc[rev[j]];
            upd(1,0,N-1,cnt[col],-1);
            cnt[col]++;
            upd(1,0,N-1,cnt[col],1);
        }
    }
    upd(1,0,N-1,cnt[cc[u]],-1);
    cnt[cc[u]]++;
    upd(1,0,N-1,cnt[cc[u]],1);
    //cout<<u<<' '<<who<<' '<<mx<<' '<<ke<<endl;
    for(auto w:ch[u]){
        an[w.second]=get(1,0,N-1,w.first,N-1);
    }
    for(int j=in[u];j<=out[u]&&!ke;j++){
        int col=cc[rev[j]];
        upd(1,0,N-1,cnt[col],-1);
        cnt[col]--;
        upd(1,0,N-1,cnt[col],1);
    }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>cc[i];
  for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  for(int i=0;i<q;i++){
      int v,k;
      cin>>v>>k;
      ch[v].push_back({k,i});
  }
  dfs(1,-1);
  dfs(1,-1,0);
  for(int i=0;i<q;i++)cout<<an[i]<<'\n';
  return 0;
}