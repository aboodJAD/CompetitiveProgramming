#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=1e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,m,k,mt[101];
vector<vector<int > > adj;
bool vis[101];
int dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[mt[v]])continue;
        if(mt[v]==-1||dfs(mt[v])){
            mt[v]=u;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>n;
        if(!n)break;
        memset(mt,-1,sizeof mt);
        cin>>m>>k;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<k;i++){
            int r,x,y;
            cin>>r>>x>>y;
            if(!x||!y)continue;
            adj[x].push_back(y);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof vis);
            mx+=dfs(i);
        }
        cout<<mx<<'\n';
    }
    return 0;
}

