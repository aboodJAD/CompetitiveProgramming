/*
it's a simple counting number of components problem
for each peiece find all connected peices which directly connected to it using binary search
then build edges to them and find number of components then.
we need to use coordinate compression for this problem(spoj -.-)
Complexity O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=3e5+10,oo=1e9,M=64;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n;
vector<pair<pp,int > >  yy[N];
vector<int > aa[N],adj[N],coo;
bool vis[N];
map<int,int > mp;
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u])if(!vis[v])dfs(v);
}
void here(){
    cout<<"wrong";
    exit(0);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int xb,yb,xh,yh;
        scanf("%d%d%d%d",&xb,&yb,&xh,&yh);
        aa[i]={xb,yb,xh,yh};
        coo.push_back(yb);
    }
    sort(coo.begin(),coo.end());
    coo.resize(unique(coo.begin(),coo.end())-coo.begin());
    for(int i=0;i<n;i++){
        int yb=aa[i][1];
        aa[i][1]=lower_bound(coo.begin(),coo.end(),yb)-coo.begin();
        mp[yb]=aa[i][1];
        yy[aa[i][1]].push_back({{aa[i][2],aa[i][0]},i});
    }
    for(int i=0;i<(int)coo.size();i++)sort(yy[i].begin(),yy[i].end());
    for(int i=0;i<n;i++){
        int xb=aa[i][0],xh=aa[i][2],yh=aa[i][3];
        if(mp.find(yh)==mp.end())continue;
        yh=mp[yh];
        auto ab=lower_bound(yy[yh].begin(),yy[yh].end(),make_pair(make_pair(xb+1,0),0));
        while(ab!=yy[yh].end()){
            if(ab->first.second<xh){
                adj[i].push_back(ab->second);
                adj[ab->second].push_back(i);
            }else break;
            ab++;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    printf("%d\n",cnt);
    return 0;
}

