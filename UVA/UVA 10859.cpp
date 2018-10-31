/*
first create a rooted trees..then for each node in the tree calculate optimal value of pair(a,b) 
where a is the minimum number of lit nodes and b is max number of edges having two lights..
a simple dp indicating the state of parent node(lit or not) we can minimize the first value and maximize the second one
http://blog.csdn.net/shuangde800/article/details/9899265 this solution is a great one
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 3e5 + 10,M=5e4+5, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

int t,vis[1001];
pp dp[1001][3];
vector<vector<int > > adj,nxt;
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v])continue;
        nxt[u].push_back(v);
        dfs(v);
    }
}
pp rec(int u,int t){
    pp &ret=dp[u][t];
    if(ret.first!=-1)return ret;
    if(t==0){
        pp r1={1,0},r2={0,0};
        for(auto v:nxt[u]){
            pp r=rec(v,2);
            r1.first+=r.first;
            r1.second+=r.second;
        }
        for(auto v:nxt[u]){
            pp r=rec(v,1);
            r2.first+=r.first;
            r2.second+=r.second;
        }
        if(r1.first==r2.first)return ret=max(r1,r2);
        return ret=min(r1,r2);
    }else if(t==1){
        ret={1,0};
        for(auto v:nxt[u]){
            pp r=rec(v,2);
            ret.first+=r.first;
            ret.second+=r.second;
        }
        return ret;
    }else{
        pp r1={0,0},r2={1,1};
        for(auto v:nxt[u]){
            pp r=rec(v,1);
            r1.first+=r.first;
            r1.second+=r.second;
        }
        for(auto v:nxt[u]){
            pp r=rec(v,2);
            r2.first+=r.first;
            r2.second+=r.second;
        }
        if(r1.first==r2.first)return ret=max(r1,r2);
        return ret=min(r1,r2);
    }
}
int main() {
/*    ios::sync_with_stdio(0);
    cin.tie(0);*/
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        int n,m;
        scanf("%d%d",&n,&m);
        adj.clear();
        nxt.clear();
        adj.resize(n);
        nxt.resize(n);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int > root;
        for(int i=0;i<n;i++)if(!vis[i])dfs(i),root.push_back(i);
        for(int i=0;i<n;i++)dp[i][0]=dp[i][1]=dp[i][2]={-1,-1};
        int an=0,two=0;
        for(auto v:root){
            pp r=rec(v,0);
            an+=r.first;
            two+=r.second;
        }
        cout<<an<<' '<<two<<' '<<m-two<<'\n';
    }
    return 0;
}

