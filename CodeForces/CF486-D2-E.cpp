/*
first find lis ending at each position i using segtree
save for each length indeces that belongs to it;
then fix length from maximum length-1(LIS-1) to 1
and for each index belong to the fixed length
determine if it's  part of any LIS;
if for a fixed length there is only one valid(belong to LIS) index then 
this index is of type 3, otherwise all valid indeces are of type 2
Complexity O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e5+10,oo=1e9,M=1e5+1;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

vector<int > typ[N];
int n,aa[N],seg[N<<2],mx[N],an[N];
void upd(int p,int l,int r,int at,int v){
    if(l>=at&&r<=at){
        seg[p]=v;
        return ;
    }
    if(l>at||r<at)return ;
    int m=(l+r)>>1;
    upd(p<<1,l,m,at,v);upd(p<<1|1,m+1,r,at,v);
    seg[p]=max(seg[p<<1],seg[p<<1|1]);
}
int get(int p,int l,int r,int lx,int rx){
    if(l>=lx&&r<=rx)return seg[p];
    if(l>rx||r<lx)return 0;
    int m=(l+r)>>1;
    return max(get(p<<1,l,m,lx,rx),get(p<<1|1,m+1,r,lx,rx));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int len=0;
    for(int i=0;i<n;i++){
        cin>>aa[i];
        mx[i]=get(1,0,M,0,aa[i]-1)+1;
        upd(1,0,M,aa[i],mx[i]);
        len=max(len,mx[i]);
        typ[mx[i]].push_back(i);
    }
    memset(seg,0,sizeof seg);
    int cnt=typ[len].size();
    if(cnt==1)an[typ[len][0]]=3;
    else for(auto v:typ[len])an[v]=2;
    for(int i=len-1;i>0;i--){
        vector<int > valid;
        for(auto v:typ[i+1])upd(1,0,M,aa[v],v);
        for(auto v:typ[i])if(get(1,0,M,aa[v]+1,M)>v)valid.push_back(v);
        for(auto v:typ[i+1])upd(1,0,M,aa[v],0);
        if((int)valid.size()==1)an[valid[0]]=3;
        else for(auto v:valid)an[v]=2;
        typ[i]=valid;
    }
    for(int i=0;i<n;i++){
        if(an[i]==0)an[i]=1;
        cout<<an[i];
    }
    return 0;
}


