#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 5e5 + 10,M=1e6+1, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

int n,m,q,now;
set<int > has[2][N];
set<int > adj[N];
bool vis[N];
void dfs(int u){
    vis[u]=1;
    for(auto v:has[0][u])has[0][now].insert(v);
    for(auto v:adj[u]){
        if(vis[v])continue;
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        int r,c;
        cin>>r>>c;
        has[0][r].insert(c);
        has[1][c].insert(r);
    }
    for(int i=1;i<=n;i++){
        for(auto v:has[0][i]){
            auto y=has[1][v].upper_bound(i);
            if(y==has[1][v].end())continue;
            adj[i].insert(*y);
            adj[*y].insert(i);
        }
    }
    int an=0,mn=m,wh=-1;
    vector<int > cmp;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        now=i;
        dfs(i);
        if(m-(int)has[0][i].size()<mn)mn=m-(int)has[0][i].size(),wh=i;
        cmp.push_back(i);
    }
    an=mn;
    if(mn==m)an+=n-1;
    else for(auto i:cmp)if(has[0][i].empty())an++;else if(i!=wh)an-=has[0][i].size()-1;
    cout<<an;
    return 0;
}
