/*
suppose a bipertite graph with left side nodes as programs and right side as computers
if program p can run on computer c then there is an edge between p and c has capacity 1.
add dummy node has edges to all left side nodes and the capacity of each edge is the number of users need to run this program.
add another dummy node has edges from all right side nodes and the capacity of each edge is 1, then find maxflow between the two dummy nodes, if it's equal sum of all users then there is an answer.
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=10;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int g[50][50];
int n=40;
int bfs(){
    bool vis[50]={};
    int par[50];
    memset(par,-1,sizeof par);
    queue<int > q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<n;i++){
            if(g[cur][i]&&!vis[i]){
                vis[i]=1;
                par[i]=cur;
                q.push(i);
            }
        }
    }
    if(!vis[n-1])return 0;
    vector<pp > p;
    int mn=oo,cur=n-1;
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
int main(){
    while(!cin.eof()){
        memset(g,0,sizeof g);
        string c,pre="";
        int sum=0;
        while(1){
            getline(cin,c);
            if(c.empty()||c==pre)break;
            pre=c;
            int cur=c[0]-'A'+1;
            int cnt=c[1]-'0';
            sum+=cnt;
            g[0][cur]=cnt;
            for(int i=3;i<(int)c.size()-1;i++){
                int d=c[i]-'0';
                g[cur][d+26+1]=1;
            }
        }
        for(int i=27;i<27+10;i++)g[i][n-1]=1;
        if(maxflow()!=sum)cout<<"!\n";
        else{
            for(int i=27;i<27+10;i++){
                int who=0;
                for(int j=1;j<27;j++){
                    if(g[i][j]){
                        who=j;
                        break;
                    }
                }
                if(who){
                    who--;
                    cout<<char(who+'A');
                }else cout<<'_';
            }
            cout<<'\n';
        }
    }
    return 0;
}

