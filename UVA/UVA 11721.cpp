/*
adding a dummy node and reverse the edges
then do bellmanford from the dummy node.
*/
#include <bits/stdc++.h>

using namespace std;

int const oo=1e9;
vector<vector<pair<int,int > > > rev;
vector<int > an,f,vis;
void dfs(int u){
    vis[u]=1;
    an.push_back(u);
    for(auto v:rev[u])if(!vis[v.first])dfs(v.first);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        an.clear();
        f.clear();
        int g[1001];
        int n,m;
        cin>>n>>m;
        g[n]=0;
        for(int i=0;i<n;i++)g[i]=oo;
        rev.clear();
        rev.resize(n+1);
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            rev[b].push_back(make_pair(a,c));            
        }
        for(int i=0;i<n;i++)rev[n].push_back({i,0});
        for(int k=0;k<n;k++){
            for(int i=0;i<=n;i++){
                for(auto v:rev[i]){
                    if(g[v.first]>g[i]+v.second)g[v.first]=g[i]+v.second;
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(auto v:rev[i])if(g[v.first]>g[i]+v.second)f.push_back(v.first);
        }
        vis.clear();
        vis.resize(n+1,0);
        for(auto v:f){
            if(vis[v])continue;
            dfs(v);
        }
        sort(an.begin(),an.end());
        cout<<"Case "<<tt++<<":";
        if(an.empty())cout<<" impossible";
        else for(auto v:an)cout<<' '<<v;
        cout<<'\n';
    }
    return 0;
}