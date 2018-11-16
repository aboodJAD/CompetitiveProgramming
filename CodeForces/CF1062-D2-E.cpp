#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int > pp;
int const  N=5e5,oo=1e9,M=5e6+10;
int mod=oo+7;
double const eps=5e-6;

int n,q,in[N],lev[N],dp[N][19];
vector<int > adj[N];
pp seg[2][N<<1];
void dfs(int u){
    static int tim=0;
    in[u]=++tim;
    for(auto v:adj[u]){
        dp[v][0]=u;
        lev[v]=lev[u]+1;
        dfs(v);
    }
}

void build(int p,int l,int r){
    if(l==r){
        seg[0][p]={in[l],l};
        seg[1][p]={in[l],l};
        return ;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);build(p<<1|1,m+1,r);
    seg[0][p]=min(seg[0][p<<1],seg[0][p<<1|1]);
    seg[1][p]=max(seg[1][p<<1],seg[1][p<<1|1]);
}
pp get(int p,int l,int r,int lx,int rx,int ty){
    if(l>rx||r<lx){
        if(ty)return {-oo,0};
        return {oo,0};
    }
    if(l>=lx&&r<=rx)return seg[ty][p];
    int m=(l+r)>>1;
    if(ty)return max(get(p<<1,l,m,lx,rx,ty),get(p<<1|1,m+1,r,lx,rx,ty));
    return min(get(p<<1,l,m,lx,rx,ty),get(p<<1|1,m+1,r,lx,rx,ty));
}
int lca(int u,int v){
    if(lev[u]>lev[v])swap(u,v);
    for(int i=18;i>-1;i--)if(lev[v]-(1<<i)>=lev[u])v=dp[v][i];
    if(u==v)return u;
    for(int i=18;i>-1;i--){
        if(dp[v][i]!=dp[u][i]){
            v=dp[v][i];
            u=dp[u][i];
        }
    }
    return dp[u][0];
}
int getlca(int l,int r){
    if(l>r)return 0;
    pp g1=get(1,1,n,l,r,0),g2=get(1,1,n,l,r,1);
    return lca(g1.second,g2.second);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    build(1,1,n);
    for(int j=1;j<18;j++)for(int i=1;i<=n;i++)if(dp[i][j-1])dp[i][j]=dp[dp[i][j-1]][j-1];
    while(q--){
        int l,r;
        cin>>l>>r;
        pp g=get(1,1,n,l,r,0);
        int y=getlca(l,g.second-1),x=getlca(g.second+1,r);
        int res=-1,mx=0;
        if(y==0)mx=lev[x];
        else if(x==0)mx=lev[y];
        else mx=lev[lca(y,x)];
        res=g.second;
        g=get(1,1,n,l,r,1);
        y=getlca(l,g.second-1),x=getlca(g.second+1,r);
        int tr=0;
        if(y==0)tr=lev[x];
        else if(x==0)tr=lev[y];
        else tr=lev[lca(x,y)];
        if(tr>mx){
            mx=tr;
            res=g.second;
        }
        cout<<res<<' '<<mx<<'\n'; 
    }
	return 0;
}