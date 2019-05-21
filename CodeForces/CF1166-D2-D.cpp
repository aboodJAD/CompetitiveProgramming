#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e6+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

void solve(ll a,ll b,ll m){
    if(a==b){
        cout<<1<<' '<<a<<'\n';
        return ;
    }
    if(b-a<=m){
        cout<<2<<' '<<a<<' '<<b<<'\n';
        return ;
    }
    for(int i=3;i<=50;i++){
        vector<ll > tr;
        tr.push_back(a);
        for(int j=1;j<i;j++){
            tr.push_back(a*(1LL<<(j-1))+(1LL<<(j-1)));
        }
        ll rem=b-tr.back();
        if(rem<0)break;
/*        for(auto v:tr)cout<<v<<' ';
        cout<<endl;        
        cout<<rem<<endl;*/
        for(int j=1;j<sz(tr);j++){
            ll ad=rem/(1LL<<(i-j-1-(j!=sz(tr)-1)));
            //cout<<j<<' '<<ad<<endl;
            ad=min(ad,m-1);
            tr[j]+=ad;
            for(int k=j+1;k<sz(tr);k++){
                if(OO/(1LL<<(k-j-1))<ad)break;
                tr[k]+=ad*(1LL<<(k-j-1));
                if(k==sz(tr)-1)rem-=ad*(1LL<<(k-j-1));
            }
        }
/*        cout<<"#"<<a<<' '<<b<<' '<<m<<' '<<i<<' '<<rem<<endl;
        for(auto v:tr)cout<<v<<' ';
        cout<<endl;*/
        if(tr.back()==b){
            cout<<i;
            for(int j=1;j<sz(tr);j++){
                ll sum=0;
                for(int k=0;k<j;k++){
                    sum+=tr[k];
                }
               if(tr[j]-sum>m){
                   cout<<' '<<tr[j]-sum<<endl;
                   assert(0);
               }
            }
            for(auto v:tr)cout<<' '<<v;
            cout<<'\n';
            return ;
        }
    }
    cout<<-1<<'\n';
}
int main() {
    int q;
    cin>>q;
    while(q--){
        ll a,b,m;
        cin>>a>>b>>m;
        solve(a,b,m);
    }
    return 0;
}