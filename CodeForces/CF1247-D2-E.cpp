/*
cum sum over dp for both dimensions seperately
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int > pp;

 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=1e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

int n,m,dp[2010][2010][2],tor[2011][2011],tod[2011][2011],cum[2010][2010][2];
char aa[2001][2001];
int add(int a,int b){
	return (a+b)%mod;
}
void solve(){
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1;
		return ;
	}
	for(int i=0;i<n;i++)cin>>aa[i];
	for(int i=0;i<n;i++){
		int em=0;
		for(int j=m-1;j>-1;j--){
			tor[i][j]=em;
			em+=aa[i][j]=='.';
		}
	}
	for(int j=0;j<m;j++){
		int em=0;
		for(int i=n-1;i>-1;i--){
			tod[i][j]=em;
			em+=aa[i][j]=='.';
		}
	}
	if(aa[n-1][m-1]=='#'){
		cout<<0;
		return ;
	}
	dp[n-1][m-1][0]=dp[n-1][m-1][1]=1;
	for(int i=n-1;i>-1;i--){
		for(int j=m-1;j>-1;j--){
			if(tod[i][j])dp[i][j][0]=add(cum[i+1][j][0],-cum[i+tod[i][j]+1][j][0]+mod);
			if(tor[i][j])dp[i][j][1]=add(cum[i][j+1][1],-cum[i][j+tor[i][j]+1][1]+mod);
			cum[i][j][0]=add(dp[i][j][1],cum[i+1][j][0]);
			cum[i][j][1]=add(dp[i][j][0],cum[i][j+1][1]);
		}
	}
	cout<<add(dp[0][0][0],dp[0][0][1])<<'\n';
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	// cin>>t;
	t=1;
	while(t--)solve();
	
	return 0;
}


