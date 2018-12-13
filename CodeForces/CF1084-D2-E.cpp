#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=1e5+1;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,k;
string s,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    cin>>s>>t;
    ll an=0;
    if(k==1){
        cout<<n;
        return 0;
    }
    for(int i=0,ad=1;i<n;i++){
        if(s[i]==t[i])an+=ad;
        else{
            ad++;
            ad=min(ad,k);
            an+=ad;
            for(int j=i+1;j<n;j++){
                ad<<=1;
                if(s[j]=='b')ad--;
                if(t[j]=='a')ad--;
                ad=min(ad,k);
                an+=ad;
            }
            break;
        }
    }
    cout<<an;
    return 0;
}

