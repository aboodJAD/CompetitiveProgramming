#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=2e9+1;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

ll dist[2002];
int n,m;
vector<vector<pair<int,ll >> > adj;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<=n;i++)dist[i]=oo;
        ll mne=oo;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            mne=min(mne,c*1LL);
        }
        for(int i=0;i<n-1;i++)for(int j=1;j<=n;j++)for(auto v:adj[j])if(dist[j]+v.second<dist[v.first])dist[v.first]=dist[j]+v.second;
        bool inf=0;
        for(int j=0;j<=n;j++)for(auto v:adj[j])if(dist[j]+v.second<dist[v.first])inf=1;
        if(inf)cout<<"-inf\n";
        else {
            if(mne<0)for(int i=1;i<=n;i++)mne=min(mne,dist[i]-oo);
            cout<<mne<<'\n';
        }
    }
    return 0;
}
