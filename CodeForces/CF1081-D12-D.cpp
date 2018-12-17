#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=1e5+1;
ll const OO=1e18;
int mod=998244353;
double const eps=1e-4,PI=acos(-1);

int n,m,k,aa[N],dsu[N],an[N],yy[N],cnt[N];
vector<pp > adj[N];
vector<pair<pp,int > > edg,ne;
int find(int u){
    if(u==dsu[u])return u;
    return dsu[u]=find(dsu[u]);
}
void dfs(int u,int p){
    cnt[u]=yy[u];
    for(auto v:adj[u]){
        if(v.first==p)continue;
        dfs(v.first,u);
        cnt[u]+=cnt[v.first];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)dsu[i]=i;
    for(int i=0;i<k;i++)cin>>aa[i],yy[aa[i]]=1;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edg.push_back({{c,a},b});
    }
    sort(edg.begin(),edg.end());
    for(int i=0;i<m;i++){
        int a=edg[i].first.second,b=edg[i].second;
        int c=edg[i].first.first;
        if(find(a)==find(b))continue;
        ne.push_back({{c,a},b});
        dsu[find(a)]=find(b);
    }
    for(int i=0;i<n-1;i++){
        int a=ne[i].first.second,b=ne[i].second;
        int c=ne[i].first.first;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0);
    int mx=0;
    for(int i=0;i<n-1;i++){
        int a=ne[i].first.second,b=ne[i].second;
        int c=ne[i].first.first;
        if(cnt[a]==0||cnt[b]==0)continue;
        if(cnt[a]==k&&cnt[b]==k)continue;
        mx=max(mx,c);
    }
    for(int i=0;i<k;i++)cout<<mx<<' ';
    return 0;
}
