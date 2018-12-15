/*
first imagine there is no cycle in the graph then just
connect node 0 to each node  has indegree = 0;
now if there are cycles, then just convert the graph into 
DAG, and then connect node 0 to nodes(in DAG) with indegree 0
we canvert the graph into DAG by finding SCC's then connect them togother
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=1e5+1;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,m,id[1003],ind[1003],cur;
vector<vector<int > > adj,rev,scc;
bool vis[1003];
stack<int >st;
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u])if(!vis[v])dfs(v);
    st.push(u);
}
void dfs2(int u){
    vis[u]=1;
    for(auto v:rev[u])if(!vis[v])dfs2(v);
    id[u]=cur;
    scc[cur].push_back(u);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n&&!cin.eof()){
        adj.clear();rev.clear();scc.clear();
        adj=rev=scc=vector<vector<int> > (n+1);
        cin>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(a==b)continue;
            adj[a].push_back(b);
            rev[b].push_back(a);
        }
        fill(vis,vis+n+1,0);
        for(int i=0;i<=n;i++)if(!vis[i])dfs(i);
        fill(vis,vis+n+1,0);
        while(!st.empty()){
            int t=st.top();
            if(!vis[t]){
                dfs2(t);
                cur++;
            }
            st.pop();
        }
        while(!st.empty())st.pop();
        fill(ind,ind+cur+1,0);
        for(int i=0;i<cur;i++)
            for(auto c:scc[i])
                for(auto v:adj[c])
                    if(id[v]!=i)ind[id[v]]++;
        int an=0;
        for(int i=0;i<cur;i++){
            if(ind[i]||i==id[0])continue;
            an++;
        }
        cur=0;
        cout<<an<<'\n';
    }
    return 0;
}


