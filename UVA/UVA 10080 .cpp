#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=10;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

pair<double,double > cc[2][100];
int n,m,s,v,mt[101];
vector<vector<int > > adj;
bool vis[101];
int dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(mt[v]==-1){
            mt[v]=u;
            return 1;
        }
        if(vis[mt[v]])continue;
        if(dfs(mt[v])){
            mt[v]=u;
            return 1;
        }
    }
    return 0;
}
double dist(pair<double ,double > a,pair<double ,double > b){
    return sqrt(pow((a.first-b.first),2.0)+pow((a.second-b.second),2.0));
}
int main(){
    while(scanf("%d",&n)!=-1){
        scanf("%d%d%d",&m,&s,&v);
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<n;i++)scanf("%lf%lf",&cc[0][i].first,&cc[0][i].second);
        for(int i=0;i<m;i++)scanf("%lf%lf",&cc[1][i].first,&cc[1][i].second);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(dist(cc[0][i],cc[1][j])/v<=s)adj[i].push_back(j);
        memset(mt,-1,sizeof mt);
        int an=0;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof vis);
            an+=dfs(i);
        }
        printf("%d\n",n-an);
    }
    return 0;
}

