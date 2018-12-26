/*
just do some math on euqlidean distance formula 
and then realize the need to cumulative arrays
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 20, N2 = 1e6 + 10;
typedef long long ll;
int n;
pair<int,int> aa[N];
ll cumx[N],cumy[N],cumxx[N],cumyy[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&aa[i].first,&aa[i].second);
    for(int i=0;i<n;i++){
        cumx[i+1]+=cumx[i];
        cumx[i+1]+=aa[i].first;
        cumy[i+1]+=cumy[i];
        cumy[i+1]+=aa[i].second;        
        cumxx[i+1]+=cumxx[i];
        cumxx[i+1]+=1LL*aa[i].first*aa[i].first;
        cumyy[i+1]+=cumyy[i];
        cumyy[i+1]+=1LL*aa[i].second*aa[i].second;
    }
    ll an=0;
    for(int i=0;i<n;i++){
        an+=1LL*(n-i-1)*aa[i].first*aa[i].first-
        2*1LL*aa[i].first*(cumx[n]-cumx[i+1])+(cumxx[n]-cumxx[i+1]);
        an+=1LL*(n-i-1)*aa[i].second*aa[i].second-
        2*1LL*aa[i].second*(cumy[n]-cumy[i+1])+(cumyy[n]-cumyy[i+1]);        
    }
    printf("%lld\n",an);
    return 0;
}