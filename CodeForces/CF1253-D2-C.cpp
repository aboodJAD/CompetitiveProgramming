#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=1e6+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

int n,m,aa[N];
ll cum[N],cum2[N];
void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>aa[i];
	sort(aa,aa+n);
	for(int i=1;i<=n;i++){
		cum[i]=cum[i-1]+aa[i-1];
		if(i>=m)cum2[i]=cum2[i-m]+cum[i];
	}
	for(int i=1;i<=n;i++){
		if(i<=m){
			cout<<cum[i]<<' '; 
		}else {
			cout<<cum2[i]+cum[i%m]<<' ';
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	
	return 0;
}