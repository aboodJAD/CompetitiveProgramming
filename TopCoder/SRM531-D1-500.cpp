/*
lets treat Pinguos as nodes.
first we should draw some graphs, and try to find the cases that don't go to infinity...
the graph converges when we have one node dies and generate only one other node..
so it seems like there is a solution (not inf) if all paths starting from node 1 ends at a simple cycle
and those simple cycles should not have any outgoing edges which means and the out degree of each need in 
those cycles is equal to 1.
note:since each node should have outgoing edges then there exist cycles in the graph,which means the graph is not a tree.
now we transform the graph into DAG by replacing cycles by nodes.
we will use memoization to find number of nodes,starting from node,and the base case when we reach a cycle node we return 1.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=3e5+10,oo=1e9,M=5e6+10;
int mod=oo+7;
double const eps=5e-6;
class MonsterFarm{
public :
    int n,cmp,mat[51][51],vis[51],ind[51],out[51],rev[51][51],dp[52],inCyc[51],err,reach[51];
    stack<int > st;
    vector<int > strong[51];
    vector<int > parse(string s){
        vector<string > res;
        string tmp="";
        for(int i=0;i<(int)s.size();i++){
            if(s[i]==' '){
                res.push_back(tmp);
                tmp="";
            }else tmp+=s[i];
        }
        res.push_back(tmp);
        vector<int > ret;
        stringstream ss;
        for(int i=0;i<(int)res.size();i++){
            ss<<res[i];
            ss<<' ';
        }
        for(int i=0;i<(int)res.size();i++){
            int y;
            ss>>y;
            ret.push_back(y);
        }
        return ret;
    }
    void dfs1(int u,bool y){
        vis[u]=1;
        reach[u]=y;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&mat[u][i])dfs1(i,y);
        }
        st.push(u);
    }
    void dfs2(int u){
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(rev[u][i]&&!vis[i])dfs2(i);
        }
        strong[cmp].push_back(u);
    }
    int rec(int u){
        if(dp[u]!=-1)return dp[u];
        if(inCyc[u])return dp[u]=1;
        dp[u]=0;
        for(int i=1;i<=n;i++){
            if(mat[u][i])dp[u]+=rec(i)*1LL*mat[u][i]%mod;
            dp[u]%=mod;
        }
        return dp[u];
    }
    int numMonsters(vector<string > ss){
        n=(int)ss.size();
        for(int i=0;i<n;i++){
            vector<int > nxt=parse(ss[i]);
            for(auto v:nxt){
                mat[i+1][v]++;
                rev[v][i+1]++;
                ind[v]++;
                out[i+1]++;
            }
        }
        for(int i=1;i<=n;i++)if(!vis[i])dfs1(i,i==1);
        memset(vis,0,sizeof vis);
        while(!st.empty()){
            if(!vis[st.top()])dfs2(st.top()),cmp++;
            st.pop();
        }
    /*    for(int i=0;i<cmp;i++){
                for(auto v:strong[i]){
                    cout<<v<<' ';
                }
            cout<<endl;
        } */       
        for(int i=0;i<cmp;i++){
            if((int)strong[i].size()==1){
                int v=strong[i][0];
                if(mat[v][v]==1&&out[v]==1)inCyc[v]=1;
                else if(mat[v][v]&&reach[v]){
                    err=1;
                    break;
                }
                continue;
            }
            for(auto v:strong[i]){
                if(out[v]>1&&reach[v]){
                    err=1;
                    break;
                }
                inCyc[v]=1;
            }
        }
        if(err)return -1;
        memset(dp,-1,sizeof dp);
        return rec(1);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string > v={"3","4 1","3","4"};
    cout<<(new MonsterFarm())->numMonsters(v);
    return 0;
}



