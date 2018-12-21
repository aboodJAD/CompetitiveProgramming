/*
https://codeforces.com/blog/entry/63877
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=3e5+10,oo=1e9,M=2e5+3;
ll const OO=1e18;
int mod=998244353;
double const eps=1e-4,PI=acos(-1);

int n,k,seg[2][N<<2][33];
int lx,rx,ch[5];
void upd(int p,int l,int r,int msk,int at){
    if(l>at||r<at)return ;
    if(l==at&&r==at){
        int sum=0;
        for(int i=0;i<k;i++){
            if((msk>>i)&1)sum-=ch[i];
            else sum+=ch[i];
        }
        seg[0][p][msk]=seg[1][p][msk]=sum;
        return ;
    }
    int m=(l+r)>>1;
    upd(p<<1,l,m,msk,at);
    upd(p<<1|1,m+1,r,msk,at);    
    seg[0][p][msk]=min(seg[0][p<<1][msk],seg[0][p<<1|1][msk]);  
    seg[1][p][msk]=max(seg[1][p<<1][msk],seg[1][p<<1|1][msk]);
}
int get(int p,int l,int r,int msk,int md){
    if(l>=lx&&r<=rx)return seg[md][p][msk];
    if(l>rx||r<lx){
        if(md)return -oo;
        return oo;
    }
    int m=(l+r)>>1;
    int r1=get(p<<1,l,m,msk,md),r2=get(p<<1|1,m+1,r,msk,md);
    if(md)return max(r1,r2);
    return min(r1,r2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<(N<<2);i++)for(int j=0;j<(1<<k);j++)seg[0][i][j]=oo,seg[1][i][j]=-oo;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)cin>>ch[j];
        for(int j=0;j<(1<<k);j++)upd(1,0,n-1,j,i);
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int at;
            cin>>at;
            at--;
            for(int i=0;i<k;i++)cin>>ch[i];
            for(int i=0;i<(1<<k);i++)upd(1,0,n-1,i,at);
        }else{
            cin>>lx>>rx;
            lx--,rx--;
            int res=0;
            for(int i=0;i<(1<<k);i++){
                int mn=get(1,0,n-1,i,0);
                int mx=get(1,0,n-1,i,1);
                res=max(res,mx-mn);
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}