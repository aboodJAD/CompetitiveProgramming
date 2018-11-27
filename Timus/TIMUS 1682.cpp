/*
first thing to notice is after writing number a,
if the graph contains cycle then it will contain this cycle after writing number a+1
and thus we can do binary search for answer
but what is the limit for R value of binary search ?
we need to set it to 3*k, why?
let's consider numbers k,2k,3k they are all connected and form a cycle 
so we don't need to consider numbers beyond 3k
since they are all equal zero modulo k
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

vector<vector<int > > adj;
bool vis[N];
int now=0,id[N],in[N];
bool dfs(int u,int p=0){
    vis[u]=1;
    id[u]=now;
    for(auto v:adj[u]){
        if(!vis[v]){
            if(dfs(v,u))return 1;
            in[v]=u;
        }else if(v!=p&&id[v]==now&&in[v]!=u)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    int l=1,r=3*k,mid,res=-1;
    while(l<=r){
        mid=(l+r)>>1;
//        mid=11;
        adj=vector<vector<int> >(mid+1);
        for(int i=1;i<=mid;i++){
            int y=i*1LL*i%k;
            int need=k-y;
            if(need<=mid&&need&&need!=i){
                adj[i].push_back(need);
                adj[need].push_back(i);
            }
            need+=k;
            if(need<=mid&&need!=i){
                adj[i].push_back(need);
                adj[need].push_back(i);
            }
            need+=k;
            if(need<=mid&&need!=i){
                adj[i].push_back(need);
                adj[need].push_back(i);
            }
            vis[i]=0;
        }
        bool y=0;
        for(int i=1;i<=mid;i++){
            if(!vis[i]){
                if(dfs(i)){
                    y=1;
                    break;
                }
                now++;
            }
        }
        if(y){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<'\n';
    return 0;
}


