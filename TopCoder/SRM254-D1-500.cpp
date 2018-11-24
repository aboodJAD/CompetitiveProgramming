/*
dp[msk]:vector of int for every occupied pos(1 in msk) the maximum time until it sandwiched..
imagine we have mask (msk) we need to insert pig in one of the empty pos (0 in msk)
we will try every position and try the mask that will return the maximum time for this choice
also we need to update for every occupied pos, still not sandwiched 1 every time...
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

class Piglets{
public:
    int n;
    string s;
    vector<int > dp[1<<15];
    vector<int > rec(int msk){
        if(msk==(1<<n)-1)return dp[msk]=vector<int>(n,0);
        if(dp[msk].size())return dp[msk];
        dp[msk]=vector<int>(n,0);
        int mx=-1;
        for(int i=0;i<n;i++){
            if((msk>>i)&1)continue;
            int nem=(msk|(1<<i));
            vector<int > vv=rec(nem);
            for(int j=0;j<n;j++)if((nem>>j)&1)if((j&&j<n-1)&&(!((nem>>(j-1))&1)||!((nem>>(j+1))&1)))vv[j]++;
            if(vv[i]>mx){
                mx=vv[i];
                dp[msk]=vv;
            }
        }
        return dp[msk];
    }
    int choose(string ss){
        n=ss.size();
        s=ss;
        if(s[0]=='-')return 0;
        if(s.back()=='-')return n-1;
        int ini=0;
        for(int i=0;i<n;i++)if(s[i]=='p')ini+=1<<i;
        if(ini==(1<<n)-1)return -1;
        vector<int > res=rec(ini);
        int mx=-1,wh=-3;
        for(int i=0;i<n;i++)if(s[i]=='-'&&res[i]>mx){
            mx=res[i];
            wh=i;
        }
        assert(wh!=-3);
        return wh;
    }
};
