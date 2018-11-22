/*
let's solve it using dp
dp[i][j][k]:minimum number of servers needed in subtree of node i;
if j is 1 means that node should be set as server;
if k is 1 then node i is covered by it's parent;
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;
int const N=1e5+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

int n;
vector<vector<int> > nxt,adj;
int dp[N][2][2];
void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p)continue;
        nxt[u].push_back(v);
        dfs(v,u);
    }
}
int rec(int u,int st,int cov){
    int &ret=dp[u][st][cov];
    if(ret!=-1)return ret;
    if(nxt[u].empty()){
        if(cov)return ret=0;
        return ret=oo;
    }
    ret=0;
    if(st){
        for(auto v:nxt[u]){
            ret+=min(rec(v,1,1)+1,rec(v,0,1));
            ret=min(ret,oo);
        }
    }else{
        if(cov)for(auto v:nxt[u]){
            ret+=rec(v,0,0);
            ret=min(ret,oo);
        }else{
            ll sum=0;
            for(auto v:nxt[u])sum+=rec(v,0,0);
            ret=oo;
            for(auto v:nxt[u])ret=min(1LL*ret,sum+rec(v,1,1)+1-rec(v,0,0));
        }
    }
    return ret=min(ret,oo);
}
int main(){
/*    ios::sync_with_stdio(0);
    cin.tie(0);*/
    while(scanf("%d",&n)){
        nxt=adj=vector<vector<int> >(n+1);
        for(int i=0;i<=n;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=-1;
        for(int i=0,a,b;i<n-1;i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,0);
        printf("%d\n",min(rec(1,0,0),rec(1,1,1)+1));
        scanf("%d",&n);
        if(n==-1)break;
    }
    return 0;
}
