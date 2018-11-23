/*
first if we of a brute force solution it will take O(Q.N.logN)(sorting in every query)
so if we can get rid of N from complexity then we are done..
if we think of every position individually then after sorting a segment every char will occupy
subsegment of the result segment, then using counting sort we can know the boundary of subsegment 
for each char...what last is how we can update a range by one value,it's easy to do it using segtree with lazy..
total complexity O(Q.logN.26) where 26 is size of alphabet
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

int n,q,cnt[27],seg[N][27],laz[N][27];
string s;

void prob(int p,int l,int r,int c){
    if(laz[p][c]==-1)return ;
    if(l!=r){
        laz[p<<1][c]=laz[p][c];
        laz[p<<1|1][c]=laz[p][c];
    }
    if(laz[p][c]==0)seg[p][c]=0;
    else seg[p][c]=r-l+1;
    laz[p][c]=-1;
}
void upd(int p,int l,int r,int lx,int rx,int v,int c){
    prob(p,l,r,c);
    if(l>rx||r<lx)return ;    
    if(l>=lx&&r<=rx){
        if(l!=r){
            laz[p][c]=v;
            prob(p,l,r,c);
        }else {
            seg[p][c]=v;
            laz[p][c]=-1;
        }
        return ;
    }
    int m=(l+r)>>1;
    upd(p<<1,l,m,lx,rx,v,c);
    upd(p<<1|1,m+1,r,lx,rx,v,c);
    seg[p][c]=seg[p<<1][c]+seg[p<<1|1][c];
}
int get(int p,int l,int r,int lx,int rx,int c){
    prob(p,l,r,c);
    if(l>=lx&&r<=rx)return seg[p][c];
    if(l>rx||r<lx)return 0;
    int m=(l+r)>>1;
    return get(p<<1,l,m,lx,rx,c)+
    get(p<<1|1,m+1,r,lx,rx,c);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(laz,-1,sizeof laz);
    cin>>n>>q;
    cin>>s;
    for(int i=0;i<n;i++)upd(1,0,n-1,i,i,1,s[i]-'a'+1);
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<27;i++){
            cnt[i]=get(1,0,n-1,l,r,i);
            cnt[i]+=cnt[i-1];
        }
        int at=0;
        if(k)at=l;
        else at=r;
        for(int i=1;i<27;i++){
            int cc=cnt[i]-cnt[i-1];
            if(!cc)continue;
            upd(1,0,n-1,l,r,0,i);
            if(k)upd(1,0,n-1,at,at+cc-1,1,i),at+=cc;
            else upd(1,0,n-1,at-cc+1,at,1,i),at-=cc;
        }
    }
    string an;
    for(int i=0;i<n;i++){
        int who=-1;
        for(int j=1;j<27;j++){
            if(get(1,0,n-1,i,i,j)){
                assert(who==-1);
                who=j-1;
            }
        }
        assert(who!=-1);
        an+=char(who+'a');
    }
    cout<<an;
    return 0;
}




