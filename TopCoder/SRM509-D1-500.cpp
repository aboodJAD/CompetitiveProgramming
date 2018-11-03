/*
DP with floydW..
it's a regular dp problem but when adding the floyd to it become harder..
nice trick exist in adding empty char as a node..
*/

#include <bits/stdc++.h>
using namespace std;

class PalindromizationDiv1 {
public:
	int const oo=2e9,zer=26;
	long long dp[51][51];
	long long ch[27][27];
	string s;
	int getMinimumCost(string, vector <string>);
	long long rec(int,int);
};

long long PalindromizationDiv1::rec(int l,int r){
    if(r-l<=1)return 0;
    long long &ret=dp[l][r];
    if(ret!=-1)return ret;
    int a=s[l]-'a',b=s[r-1]-'a';
    ret=oo;
    if(a==b)ret=rec(l+1,r-1);
    for(int i=0;i<27;i++)ret=min(ret,rec(l+1,r-1)+ch[a][i]+ch[b][i]);
    ret=min(ret,rec(l+1,r)+ch[a][zer]);
    ret=min(ret,rec(l,r-1)+ch[b][zer]);
    return ret;
}
int PalindromizationDiv1::getMinimumCost(string word, vector <string> operations) {
	s=word;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<27;i++)for(int j=0;j<27;j++)ch[i][j]=i==j?0:oo;
	for(auto ev:operations){
	    istringstream ss(ev);
	    string op;
	    ss>>op;
	    char c1,c2;
	    ss>>c1;
	    if(op=="add"){
	        ss>>ch[zer][c1-'a'];
	    }else if(op=="erase"){
	        ss>>ch[c1-'a'][zer];
	    }else{
	        ss>>c2;
	        ss>>ch[c1-'a'][c2-'a'];
	    }
	}
	for(int k=0;k<27;k++)for(int i=0;i<27;i++)for(int j=0;j<27;j++){
	    if(ch[i][j]>ch[i][k]+ch[k][j])ch[i][j]=ch[i][k]+ch[k][j];
	}
	long long res=rec(0,s.size());
	if(res>=oo)res=-1;
	return (int)res;
}
