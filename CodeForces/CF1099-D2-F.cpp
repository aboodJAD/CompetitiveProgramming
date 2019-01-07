#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=3e5+10,oo=1e9,M=1e6+2;
ll const OO=1e18;
double const eps=1e-6,PI=acos(-1);
int mod=oo+7;

int n;
ll t;
int aa[N],bb[N];
pair<ll,ll > seg[(M+1)<<2];
vector<pp > adj[N];
ll an[N];
ll mx=0;
void upd(int p,int l,int r,int at,int a,int b){
    if(l>at||r<at)return ;
    if(l==at&&r==at){
        seg[p].first+=a*1LL*b;
        seg[p].second+=a;
        return ;
    }
    int m=(l+r)>>1;
    upd(p<<1,l,m,at,a,b);
    upd(p<<1|1,m+1,r,at,a,b);
    seg[p].first=seg[p<<1].first+seg[p<<1|1].first;
    seg[p].second=seg[p<<1].second+seg[p<<1|1].second;
}
ll get(int p,int l,int r,ll rem){
    if(rem>=seg[p].first)return seg[p].second;
    int m=(l+r)>>1;
    if(l==r)return rem/l;
    if(seg[p<<1].first>=rem)return get(p<<1,l,m,rem);
    rem-=seg[p<<1].first;
    ll ret=seg[p<<1].second;
    if(rem)ret+=get(p<<1|1,m+1,r,rem);
    return ret;
}
ll dfs(int u,ll tim){
    if(tim>t)return 0;
    upd(1,1,M,bb[u],aa[u],bb[u]);
    vector<ll > qq;
    ll cur=get(1,1,M,t-tim);
    for(auto v:adj[u])qq.push_back(dfs(v.first,tim+v.second*2));
    upd(1,1,M,bb[u],-aa[u],bb[u]);
    sort(qq.begin(),qq.end());
    if(u==1)return max(qq.back(),cur);
    if((int)qq.size()<=1)return cur;
    return max(qq[qq.size()-2],cur);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
    for(int i=2;i<=n;i++){
        int p,l;
        cin>>p>>l;
        adj[p].push_back({i,l});
    }
    cout<<dfs(1,0);
    return 0;
}
