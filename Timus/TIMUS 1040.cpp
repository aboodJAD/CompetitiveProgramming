#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=64;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);
vector<int > adj[55];
int cnt=1,vis[55];
map<pp,int > ind;
int an[50*50];
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(ind.find({u,v})==ind.end()&&ind.find({v,u})==ind.end())continue;
        if(ind.find({u,v})==ind.end())an[ind[{v,u}]]=cnt;
        else an[ind[{u,v}]]=cnt;
        ind.erase({u,v});
        ind.erase({v,u});
        cnt++;
        if(vis[v])continue;
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ind[{a,b}]=i;
        adj[a].push_back(b);
        adj[b].push_back(a);        
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    cout<<"YES\n";
    for(int i=0;i<m;i++){
        cout<<an[i];
        if(i+1!=m)cout<<' ';
    }
    cout<<endl;
    return 0;
}
