/*
hint: note that 100001*100001-100000*100000>200000
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=2e5+3;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n;
ll aa[N];
ll psq[M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<M;i++)psq[i]=i*1LL*i;
    cin>>n;
    for(int i=2;i<=n;i+=2)cin>>aa[i];
    ll sum=0;
    for(int i=2,at=1;i<=n;i+=2){
        sum+=aa[i];
        while(at<M){
            if(psq[at]-sum>0&&binary_search(psq+1,psq+M,psq[at]-aa[i])){
                aa[i-1]=psq[at]-sum;
                sum=psq[at];
                at++;
                break;
            }
            at++;
        }
        if(aa[i-1]==0||aa[i-1]>ll(1e13)){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)cout<<aa[i]<<' ';
    return 0;
}