/*
build a graph from device's type to corresponding outlet it can connect to using adapters,
this edge has inf capacity
then connect adapters outlets that can connect to each other , also inf capacity.

add a source node for each device's type with capacity equal to count of devices with this type
then connect adapters outlets to the sink node with capacity equal to count of recepticals with this type.

ans=m-maxflow
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=1e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n,m,k,g[500][500];
vector<int > adj[1000]; 
int src,sink;
int bfs(){
    bool vis[500]={};
    int par[500];
    memset(par,-1,sizeof par);
    queue<int > q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto v:adj[cur]){
            if(g[cur][v]&&!vis[v]){
                vis[v]=1;
                par[v]=cur;
                q.push(v);
            }
        }
    }
    if(!vis[sink])return 0;
    vector<pp > p;
    int mn=oo,cur=sink;
    while(par[cur]!=-1){
        p.push_back({par[cur],cur});
        mn=min(mn,g[par[cur]][cur]);
        cur=par[cur];
    }
    for(auto e:p){
        g[e.first][e.second]-=mn;
        g[e.second][e.first]+=mn;        
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
int solve(){
    cin>>n;
    map<string,int > ids,rc,dv,ke;
    vector<pair<string,string > > edg;
    for(int i=0;i<n;i++){
        string r;
        cin>>r;
        rc[r]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string s,t;
        cin>>s>>t;
        dv[t]++;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        string a,b;
        cin>>a>>b;
        edg.push_back({a,b});
    }
    memset(g,0,sizeof g);
    src=0,sink=1;
    int cnt=2;
    for(auto v:dv){
        adj[src].push_back(cnt);
        adj[cnt].push_back(src);
        ids[v.first]=cnt;
        g[src][cnt]=v.second;
        cnt++;
    }
    for(auto v:dv){
        for(int i=0;i<k;i++){
            string a=edg[i].first,b=edg[i].second;
            if(v.first==a){
                if(ke.find(b)==ke.end()){
                    ke[b]=cnt;
                    cnt++;
                }
                adj[ids[v.first]].push_back(ke[b]);
                adj[ke[b]].push_back(ids[v.first]);
                g[ids[v.first]][ke[b]]=oo;
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            string a=edg[i].first,b=edg[i].second,c=edg[j].first,d=edg[j].second;
            if(b==c){
                if(ke.find(b)==ke.end()){
                    ke[b]=cnt;
                    cnt++;
                }
                if(ke.find(d)==ke.end()){
                    ke[d]=cnt;
                    cnt++;
                }
                adj[ke[b]].push_back(ke[d]);
                adj[ke[d]].push_back(ke[b]);                
                g[ke[b]][ke[d]]=oo;
            }
        }
    }

    for(auto v:rc){
        if(ke.find(v.first)!=ke.end()){
        }else{
            ke[v.first]=cnt;
            cnt++;
        }
        adj[ke[v.first]].push_back(sink);
        adj[sink].push_back(ke[v.first]);        
        g[ke[v.first]][sink]=v.second;
        if(dv.find(v.first)!=dv.end()){
            adj[ids[v.first]].push_back(ke[v.first]);
            adj[ke[v.first]].push_back(ids[v.first]);
            g[ids[v.first]][ke[v.first]]=oo;
        }
    }
    int an=m-maxflow();
    for(int i=0;i<cnt;i++)adj[i].clear();
    return an;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    bool b=0;
    while(t--){
        if(b)cout<<'\n';
        cout<<solve()<<'\n';
        b=1;
    }
    return 0;
}

