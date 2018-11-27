#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

int t,d,n;
string s;
ll calc(int n,int k){
    ll res=1;
    for(int i=k+1;i<=n;i++){
        res*=i;
        if(res>100*1LL*oo)break;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>s;
        cin>>d;
        n=s.size();
        string an="";
        an+=s[0];
        int k=2,at=1;
        while(at<n){
            for(int i=1;i<=(int)an.size()+1;i++){
               // cout<<at<<' '<<calc(n,k)<<' '<<k<<endl;
                if(calc(n,k)<d)d-=calc(n,k);
                else{
                    an.insert(an.begin()+i-1,s[at]);
                    at++;
                    break;
                }
            }
            k++;
        }
        cout<<an<<'\n';
    }
    return 0;
}


