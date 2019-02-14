#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=3e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin>>n;    
    int l=0,r=oo,mid,res=0;
    while(l<=r){
        mid=(l+r)>>1;
        cout<<"> "<<mid<<endl;
        fflush(stdout);
        int y;
        cin>>y;
        if(y==0){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    vector<int > v;
    for(int i=1;i<=n;i++)v.push_back(i);
    shuffle(v.begin(),v.end(),rng);
    int g=0,pre=-1;
    for(int i=0,a;i<min(30,n);i++){
        cout<<"? "<<v[i]<<endl;
        cin>>a;
        g=__gcd(g,res-a);
        if(pre!=-1)g=__gcd(g,abs(pre-a));
        pre=a;
    }
    cout<<"! "<<res-(n-1)*g<<' '<<g<<endl;
    return 0;
}
