#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=3e5+10,oo=1e9,M=5e6+10;
int mod=oo+7;
double const eps=5e-6;

int n,sz[N],dp[N][19],dep[N];
vector<int > adj[N];
void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p)continue;
        dp[v][0]=u;
        dep[v]=dep[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    sz[u]++;
}
int lca(int a,int b){
    if(dep[a]>dep[b])swap(a,b);
    for(int i=18;i>-1;i--){
        if(dep[b]-(1<<i)>=dep[a])b=dp[b][i];
    }
    if(b==a)return a;
    for(int i=18;i>-1;i--){
        if(dp[a][i]!=dp[b][i]){
            b=dp[b][i];
            a=dp[a][i];
        }
    }
    return dp[a][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int j=1;j<19;j++)for(int i=1;i<=n;i++)if(dp[i][j-1])dp[i][j]=dp[dp[i][j-1]][j-1];
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<n<<'\n';
            continue;
        }
        int lc=lca(a,b);
        int d=dep[a]+dep[b]-2*dep[lc];
        if(d&1){
            cout<<0<<'\n';
            continue;
        }
        d/=2;
        int u;
        if(d<=dep[a]-dep[lc])u=a;
        else u=b;
        int wh=u;
        d--;
        for(int i=18;i>-1;i--){
            if((1<<i)<=d){
                u=dp[u][i];
                d-=1<<i;
            }
        }
        int an=sz[dp[u][0]]-sz[u];
        if(dp[u][0]==lc){
            if(wh==a)u=b;
            else u=a;
            d=dep[u]-dep[lc];
            d--;
            for(int i=18;i>-1;i--){
                if((1<<i)<=d){
                    u=dp[u][i];
                    d-=1<<i;
                }
            }
            an-=sz[u];
            if(lc!=a&&lc!=b)an+=n-sz[lc];
        }
        cout<<an<<'\n';
    }
    return 0;
}



