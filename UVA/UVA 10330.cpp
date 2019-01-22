/*
the trick is to duplicate the number of nodes
so for each node create a new node and edge between
them with capacity of original node
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=10;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,g[301][301];
int bfs(){
    bool vis[301]={};
    int par[301];
    fill(par,par+n,-1);
    queue<int > q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int nxt=0;nxt<n;nxt++){
            if(nxt==cur)continue;
            if(g[cur][nxt]&&!vis[nxt]){
                vis[nxt]=1;
                par[nxt]=cur;
                q.push(nxt);
            }
        }
    }
    if(!vis[n-1])return 0;
    vector<pp > path;
    int now=n-1,mn=oo;
    while(par[now]!=-1){
        path.push_back({par[now],now});
        mn=min(mn,g[par[now]][now]);
        now=par[now];
    }
    
    for(auto v:path){
        g[v.first][v.second]-=mn;
        g[v.second][v.first]+=mn;
    }
    return mn;
}
int maxflow(){
    int res=0;
    while(1){
        int b=bfs();
        if(!b)break;
        res+=b;
    }
    return res;
}
int main(){
    while(scanf("%d",&n)!=-1){
        memset(g,0,sizeof g);
        int nn=n;
        for(int i=1;i<=n;i++){
            int b;
            scanf("%d",&b);
            g[i][++nn]=b;
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a+n][b]=c;
        }
        int b,d;
        scanf("%d%d",&b,&d);
        for(int i=0,c;i<b;i++){
            scanf("%d",&c);
            g[0][c]=oo;
        }
        for(int i=0,c;i<d;i++){
            scanf("%d",&c);
            g[c+n][nn+1]=oo;
        }
        n=nn+2;
        printf("%d\n",maxflow());
    }
    return 0;
}

