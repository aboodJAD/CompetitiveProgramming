/*
for every edge from node 1 or to node n it's capacity is 1,other edges have capacity infinity
then just apply maxflow algo
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=10;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,g[201][201];
int bfs(){
    int par[202],vis[202];
    fill(vis,vis+n+1,0);
    queue<int > q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=1;i<=n;i++){
            if(g[cur][i]&&!vis[i]){
                vis[i]=1;
                q.push(i);
                par[i]=cur;
            }
        }
    }
    if(!vis[n])return 0;
    int now=n;
    while(now!=1){
        int p=par[now];
        g[p][now]--;
        g[now][p]++;
        now=p;
    }
    return 1;
}
int maxflow(){
    int res=0;
    while(1){
        int y=bfs();
        if(y==0)break;
        res++;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(g,0,sizeof g);
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                int v;
                scanf("%d",&v);
                if(i==1||v==n)g[i][v]=1;
                else g[i][v]=oo;
            }
        }
        printf("%d\n",maxflow());
    }
    return 0;
}

