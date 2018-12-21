/*
Complexity O(Nlog^2N)
for parent vp all it's childrens are vc=k*vp+d, where d is from [-k+2,1]
for a fixed k and fixed vp we can find the range of childs of vp
then we need to find how many elements in this range less than a[vp]
if k=1 then we need to process n-1 nodes,k=2:n/2,k=3:n/3
it's a harmonic series with complexity logN
so for fixing k and vp the complexity is NlogN
now to find how many elements less than a number in a range, if use online version of segtree
it will take log^2N for every query which will get TLE, if we can make it logN then the problem is solved

we can answer each query offline, first sort values of queries and values in original array in increasing order
then process them from smaller to larger, if current element is from original array then just mark it's position 
as 1 in the segment tree,else if it's a query element find the sum of marked elements in the range of the query
and thus we can answer each query in LogN.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=4e6+10,oo=1e9,M=2e5+3;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,aa[M],seg[M<<2],an[M];
pp mdf[N];
vector<pair<pp,pp > > query;
void go(int at,int k){
    int fr=at*k-k+2,to=min(n*1LL,at*1LL*k+1);
    query.push_back({{fr,to},{aa[at],k}});
    for(int i=fr;i<=to;i++){
        if(i*1LL*k-k+2>n)break;
        go(i,k);
    }
}
void upd(int p,int l,int r,int at){
    if(l==r&&l==at){
        seg[p]++;
        return ;
    }
    if(l>at||r<at)return ;
    int m=(l+r)>>1;
    upd(p<<1,l,m,at);upd(p<<1|1,m+1,r,at);
    seg[p]=seg[p<<1]+seg[p<<1|1];
}
int get(int p,int l,int r,int lx,int rx){
    if(l>rx||r<lx)return 0;
    if(l>=lx&&r<=rx)return seg[p];
    int m=(l+r)>>1;
    return get(p<<1,l,m,lx,rx)+get(p<<1|1,m+1,r,lx,rx);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i],mdf[i]={aa[i],-i};
    for(int k=1;k<n;k++)go(1,k);
    int org=n;
    for(int j=0;j<(int)query.size();j++,n++)mdf[n+1]={query[j].second.first,j};
    n++;
    sort(mdf+1,mdf+n);
    for(int i=1;i<n;){
        int j=i;
        while(j<=n&&mdf[j].first==mdf[i].first)j++;
        for(int r=i;r<j;r++){
            if(mdf[r].second>-1){
                int idx=mdf[r].second;
                an[query[idx].second.second]+=get(1,1,org,query[idx].first.first,query[idx].first.second);
            }
        }
        for(int r=i;r<j;r++)if(mdf[r].second<0)upd(1,1,org,-mdf[r].second);
        i=j;
    }
    for(int i=1;i<org;i++)cout<<an[i]<<' ';
    return 0;
}
