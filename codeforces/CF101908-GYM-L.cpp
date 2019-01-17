/*
the common nodes form a simple path let's denote it p.
suppose lca(A,B) is ancestor of all nodes.
suppose node on path p that is the lca(A,C), it's the start of path p
then for path p to exist lca(C,D) should be either on the path p from lca(A,C) to lca(A,B) 
or lca(B,D)!=lca(A,B) and lca(lca(B,D),lca(A,C))=lca(A,B)
for any path of common nodes this is how it will looks
then we permute the nodes of a query and take longest path amonge all permutations
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=10;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,q,dep[N],sp[N][19];
vector<int > adj[N];

void dfs(int u,int p){
    sp[u][0]=p;
    for(auto v:adj[u]){
        if(v==p)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int lca(int a,int b){
    if(dep[a]>dep[b])swap(a,b);
    for(int i=18;i>-1;i--)if(dep[b]-(1<<i)>=dep[a])b=sp[b][i];
    if(a==b)return a;
    for(int i=18;i>-1;i--)if(sp[a][i]!=sp[b][i])a=sp[a][i],b=sp[b][i];
    return sp[a][0];
}
int dist(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
int solve(int a,int b,int c,int d){
    int ac=lca(a,c),ab=lca(a,b),cd=lca(c,d),bd=lca(b,d);
    if(lca(ac,cd)==cd&&lca(cd,ab)==ab){
        if(bd==ab)return dist(ac,cd)+1;
        return dist(ac,bd)+1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int j=1;j<19;j++)for(int i=1;i<=n;i++)if(sp[i][j-1])sp[i][j]=sp[sp[i][j-1]][j-1];
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int an1=0,an2=0;
        an1=max(max(solve(a,b,c,d),solve(a,b,d,c)),max(solve(b,a,c,d),solve(b,a,d,c)));
        an2=max(max(solve(c,d,a,b),solve(c,d,b,a)),max(solve(d,c,a,b),solve(d,c,b,a)));
        cout<<max(an1,an2)<<'\n';
    }
    return 0;
}
