#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e5+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int t,n,m;
vector<int > laz,fr;
vector<pp > seg;
vector<set<pp > > rng;
void prob(int p,int l,int r){
    if(!laz[p])return ;
    if(l!=r){
        laz[p<<1]+=laz[p];
        laz[p<<1|1]+=laz[p];
    }
    seg[p].first+=laz[p];
    laz[p]=0;
}
void build(int p,int l,int r){
    if(l==r){
        seg[p]={fr[l],l};
        return ;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);
    if(seg[p<<1].first<seg[p<<1|1].first)seg[p]=seg[p<<1];
    else seg[p]=seg[p<<1|1];
}
void upd(int p,int l,int r,int lx,int rx,int v){
    prob(p,l,r);
    if(l>=lx&&r<=rx){
        laz[p]+=v;
        prob(p,l,r);
        return ;
    }
    if(l>rx||r<lx)return ;
    int m=(l+r)>>1;
    upd(p<<1,l,m,lx,rx,v);upd(p<<1|1,m+1,r,lx,rx,v);
    if(seg[p<<1].first<seg[p<<1|1].first)seg[p]=seg[p<<1];
    else seg[p]=seg[p<<1|1];    
}
pp get(){
    prob(1,1,n);
    return seg[1];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        fr=vector<int >(n+1,0);
        laz=vector<int>(n*4+10,0);
        seg.clear();
        seg.resize(n*4+10);
        rng.clear();
        rng.resize(n+1);
        for(int i=1;i<=n;i++){
            fr[i]=i-1;
            if(i!=n)rng[i].insert({i+1,n});
        }
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            fr[b]--;
            auto y=rng[a].upper_bound({b,n});
            y--;
            int l=y->first,r=y->second;
            rng[a].erase(y);
            if(l!=b)rng[a].insert({l,b-1});
            if(r!=b)rng[a].insert({b+1,r});
        }
        build(1,1,n);
        vector<int > an;
        while((int)an.size()<n){
            pp g=get();
            assert(g.first==0);
            an.push_back(g.second);
            upd(1,1,n,g.second,g.second,oo);
            for(auto v:rng[g.second])upd(1,1,n,v.first,v.second,-1);
        }
        bool s=0;
        for(auto v:an){
            if(s)printf(" ");
            printf("%d",v);
            s=1;
        }
        puts("");
    }
    return 0;
}
