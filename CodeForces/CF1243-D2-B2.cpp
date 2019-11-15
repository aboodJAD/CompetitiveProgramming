#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;
 
string s,t;
int n;
void solve(){
	cin>>n;
	cin>>s>>t;
	vector<int > df;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i])df.push_back(i);
	}
	if(sz(df)==0){
		cout<<"Yes\n";
		cout<<1<<'\n';
		cout<<1<<' '<<1<<'\n';
	}else if(sz(df)==1){
		cout<<"No\n";
	}else{
		vector<pp > an;
		for(int i=0;i<n;i++){
			if(s[i]==t[i])continue;
			bool no=1;
			for(int j=0;j<n;j++){
				if(s[j]!=t[j]&&t[j]==t[i]&&j!=i){
					an.push_back({i,j});
					swap(s[i],t[j]);
					no=0;
					break;
				}
			}
			if(no){
				for(int j=0;j<n;j++){
					if(s[j]==t[i]&&s[j]!=t[j]&&j!=i){
						an.push_back({j,j});
						swap(s[j],t[j]);
						an.push_back({i,j});
						swap(t[j],s[i]);
						no=0;
						break;
					}
				}
			}
		}
		if(s==t){
			cout<<"Yes\n";
			cout<<an.size()<<'\n';
			for(auto v:an)cout<<v.first+1<<' '<<v.second+1<<'\n';
		}else cout<<"No\n";
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
	cin>>t;
	while(t--)solve();
	
	return 0;
}