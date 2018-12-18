/*
we need to compare if two vectors are equal or not;
if node A has neighbours B,C,D
node D has A,B,C
then just compare the two vectors by adding A into it's adjacency vector and the same for D
if A,D are not connected just compare the vectors without adding the nodes A,D
i used polynomial hash for comparing vectors, with two different primes as power
Complexity O(NlogN) 
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e6+10,oo=1e9,M=2e5+3;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,m;
vector<int > adj[N];
map<pp,int > mp;
set<pair<pp,int > > st[N];
int p=43,p2=1234567,pr,pr2;
int hs(vector<int> &v,int p){
    int res=0,f=p;
    for(auto e:v){
        res=(e*1LL*f+res)%mod;
        f=f*1LL*p%mod;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
        int a=hs(adj[i],p),b=hs(adj[i],p2);
        mp[{a,b}]++;
        adj[i].push_back(i);
        sort(adj[i].begin(),adj[i].end());
        int hv1=hs(adj[i],p);
        int hv2=hs(adj[i],p2);
        mp[{hv1,hv2}]++;
    }
    ll an=0;
    for(auto v:mp)an+=(v.second-1)*1LL*v.second/2;
    mp.clear();
    cout<<an<<endl;
    return 0;
}
