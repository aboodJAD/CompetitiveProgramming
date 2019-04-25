#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=3e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n,m;
vector<vector<int > > adj;
int aa[N],bb[N],cc[N],desc[401],low[401],stmem[401],id[401],tim=1;
stack<int > st;
int gv=0;
void dfs(int u){
    desc[u]=low[u]=tim++;
    st.push(u);
    stmem[u]=1;
    for(auto v:adj[u]){
        if(!desc[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(stmem[v])low[u]=min(low[u],desc[v]);
    }
    if(low[u]!=desc[u])return ;
    gv++;
    while(st.top()!=u){
        id[st.top()]=gv;
        stmem[st.top()]=0;
        st.pop();
    }
    id[st.top()]=gv;
    stmem[st.top()]=0;
    st.pop();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0,a,b,c;i<m;i++){
            cin>>a>>b>>c;
            a<<=1;
            b<<=1;
            aa[i]=a;
            bb[i]=b;
            cc[i]=c;
        }
        int l=0,r=m-1,mid,res=0;
        while(l<=r){
            adj.clear();
            adj.resize(2*n+1);
            memset(desc,0,sizeof desc);
            memset(low,0,sizeof low);
            while(!st.empty())st.pop();
            tim=1;
            gv=0;            
            mid=(l+r)>>1;
            for(int i=0;i<=mid;i++){
                int a=aa[i],b=bb[i],c=cc[i];
                if(c==0){
                    adj[a|1].push_back(b);
                    adj[b|1].push_back(a);
                }else if(c==1){
                    adj[a|1].push_back(b|1);
                    adj[b].push_back(a);
                    adj[a].push_back(b);
                    adj[b|1].push_back(a|1);
                }else{
                    adj[a].push_back(b|1);
                    adj[b].push_back(a|1);
                }                
            }
            for(int i=0;i<n*2;i++)if(!desc[i])dfs(i);
            bool no=0;
            for(int i=0;i<2*n;i+=2){
                if(id[i]==id[i+1]){
                    no=1;
                    break;
                }
            }
            if(no)r=mid-1;
            else l=res=mid+1;
        }
        cout<<res<<'\n';
    }
    return 0;
}
