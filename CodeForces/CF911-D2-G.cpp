/*
first solution (segtree):
complexity O(N*C*logN) where C is number of different colors=100
it's a segtree based solution, with every node we need to store 
for each color what is the color it's mapped to
in initial tree every color is mapped to itself.
in leaf nodes all colors mapped to only one color.
the tricky part is in applying lazy propagation, it's easy to see how to do it
in the code, first i think of it C*C but in a smarter way it's C
a lot of optimizations must be applied, not as a regular code i wrote for segtree.
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=2e5+3;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,aa[N],seg[N<<2][101];
int l,r,x,y;
void build(int p,int l,int r){
    if(l==r){
        for(int i=1;i<=100;i++)seg[p][i]=aa[l];
        return ;
    }
    for(int i=1;i<=100;i++)seg[p][i]=i;    
    int m=(l+r)>>1;
    build(p<<1,l,m),build(p<<1|1,m+1,r);
}
void prop(int p,int l,int r){
    if(l==r)return ;
    if(l!=r)for(int i=1;i<=100;i++)seg[p<<1][i]=seg[p][seg[p<<1][i]],seg[p<<1|1][i]=seg[p][seg[p<<1|1][i]];
    for(int i=1;i<=100;i++)seg[p][i]=i;
}
void upd(int p,int al,int ar){
    if(al>r||ar<l)return ;
    if(al>=l&&ar<=r){
        for(int i=1;i<=100;i++)if(seg[p][i]==x)seg[p][i]=y;
        return ;
    }
    prop(p,al,ar);
    int m=(al+ar)>>1;
    upd(p<<1,al,m),upd(p<<1|1,m+1,ar);
}
void get(int p,int l,int r,int at){
    if(l==at&&r==at){
        printf("%d ",seg[p][1]);
        return ;
    }
    if(l>at||r<at)return ;
    prop(p,l,r);    
    int m=(l+r)>>1;
    get(p<<1,l,m,at),get(p<<1|1,m+1,r,at);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&aa[i]);
    build(1,0,n-1);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d",&l,&r,&x,&y);
        l--,r--;
        upd(1,0,n-1);
    }
    for(int i=0;i<n;i++)get(1,0,n-1,i);
    return 0;
}
