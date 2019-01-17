/*
https://math.stackexchange.com/questions/48682/maximization-with-xor-operator
**here we just do a forward elemination
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=2e5+2,oo=1e9,M=1e6;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n;
ll aa[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>aa[i];
    sort(aa,aa+n,greater<ll>());
    n=unique(aa,aa+n)-aa;
    int idx=0;
    for(int j=63;j>-1;j--){
        int fn=-1;
        for(int i=idx;i<n;i++){
            if((aa[i]>>j)&1){
                fn=i;
                break;
            }
        }
        if(fn==-1)continue;
        swap(aa[fn],aa[idx]);
        for(int i=idx+1;i<n;i++)if((aa[i]>>j)&1)aa[i]^=aa[idx];
        idx++;
    }
    ll res=0;
    for(int i=0;i<n;i++)res=max(res,res^aa[i]);
    cout<<res<<'\n';
    return 0;
}

