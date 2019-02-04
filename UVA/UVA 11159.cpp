/*
build bipartite graph set A on the left side and B on right side
there is and edge from element i in A to element j in B if B[j]=A[i]*K
for each edge one of two endpoints will be deleted, so this is the same
as finding min vertex cover which is equal to max matching
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=1e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n,m,aa[101],bb[101],mt[101];
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
    cin>>t;
    int cc=1;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(mt,-1,sizeof mt);
        cin>>n;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<n;i++)cin>>aa[i];
        cin>>m;
        for(int i=0;i<m;i++)cin>>bb[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bb[j]==0||(aa[i]!=0&&bb[j]%aa[i]==0))adj[i].push_back(j);
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof vis);
            if(dfs(i))mx++;
        }
        cout<<"Case "<<cc<<": "<<mx<<'\n';
        cc++;
    }
    return 0;
}

