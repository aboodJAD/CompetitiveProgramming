/*
it's a segtree solution..
first i think of the problem by using cumulative sum..or answering queries offline
but no one of them works..
then i think of changing state of a node in segtree...
a node represents a range [l,r],we need to save informations about this range in this node..
1)the max_subarray_sum;
2)max_prefix_sum;
3)max_suffix_sum;
4)sum of elements in this range;
for range [l,l] all infos stored in node will be arr[l];

now for range [l,r], let's update each information individually:

sum=sum_left_child+sum_right_child;

max_suffix_sum=max(
	max_suffix_sum_right_child,
	sum_right_child + max_suffix_sum_left_child);

max_prefix_sum=max(
	max_prefix_sum_left_child,
	sum_left_child + max_prefix_sum_right_child);

max_subarray_sum=max(
	max_subarray_sum_left,
	max_subarray_sum_right,
	max_suffix_sum_left + max_prefix_sum_right);

thus, after applying those updates we can answer each query in log(n)...
Complexity O(NlogN);
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=50000+10,oo=1e9,M=5e6+10;
int mod=oo+7;
double const eps=5e-6;

struct info{
    int sum,pre,suff,mx;
    info(int s,int p,int su,int m){
        sum=s;
        pre=p;
        suff=su;
        mx=m;
    }
    info(){}
};

info seg[N<<2];
int n,aa[N];

info merge(info r1,info r2){
    info res=info();
    res.sum=r1.sum+r2.sum;
    res.pre=max(r1.pre,r1.sum+r2.pre);
    res.suff=max(r2.suff,r2.sum+r1.suff);
    res.mx=max(r1.mx,r2.mx);
    res.mx=max(res.mx,r1.suff+r2.pre);    
    return res;
}
void build(int p,int l,int r){
    if(l==r){
        seg[p]=info(aa[l],aa[l],aa[l],aa[l]);
        return ;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);build(p<<1|1,m+1,r);
    seg[p]=merge(seg[p<<1],seg[p<<1|1]);
}
info get(int p,int l,int r,int lx,int rx){
    if(l>=lx&&r<=rx)return seg[p];
    int m=(l+r)>>1;
    info r1=info(-oo,-oo,-oo,-oo);
    info r2=r1;
    if(m>=lx)r1=get(p<<1,l,m,lx,rx);
    if(m+1<=rx&&m+1<=r)r2=get(p<<1|1,m+1,r,lx,rx);
    if(r1.sum==-oo)return r2;
    if(r2.sum==-oo)return r1;
    return merge(r1,r2);
}
int main(){
/*    ios::sync_with_stdio(0);
    cin.tie(0);*/
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&aa[i]);
    build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        info an=get(1,1,n,l,r);
        printf("%d\n",an.mx);
    }
    return 0;
}





