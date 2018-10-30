/*
my solution is not the best or the most efficient one...
first i think of a dp solution that has a state i,j..where i the index and j is amount of cards previous has taken..
it gets TLE because i do a loop inside the the recursion..
then i think of another state..let's fix left and right border the cur player will take dp[l,r], then obviously the next player
can take up to amount=2*(r-l+1) cards..so for the cur player the answer is the maximum sum the next player can take if the cur player take segment[l,r]
so the answer exists in the solution of the maximum sum the next player can obtain if he takes one of the segment of cards [r+1,r+1] or [r+1,r+2]...[r+1,r+amount]
so we need a tool that tells us this value..i used sparse table with O(nlogn) constuction and O(1) query..this sparse table is constructed for each index..
i start fixing segment from right to left( [n,n],[n-1,n-1],[n-1,n],[n-2,n-2],[n-2,n-1],[n-2,n]..)and the solution for each of them using sparse table..
then the answer is either max(dp[0][0] , dp[0][1])..
time comlexity O(n^2*Logn)
note:in my implementation i used dp[l][r] to denote segment [l,r-1]..
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 3e5 + 10,M=5e4+5, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

int n,aa[2002],lg[2002],cum[2002];
pp dp[2002][2002];
pp sp[2002][2002][12];
pp getmx(int id,int l,int r){
    int len=r-l+1;
    return max(sp[id][l][lg[len]],sp[id][l+len-(1<<lg[len])][lg[len]]);
}
int main() {
/*    ios::sync_with_stdio(0);
    cin.tie(0);*/
    lg[1]=0;
    for(int i=2;i<2002;i++)lg[i]=lg[i>>1]+1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&aa[i]),cum[i+1]=cum[i]+aa[i];
    for(int i=n-1;i>-1;i--){
        for(int j=i+1;j<=n;j++){
           pp r=getmx(j,j+1,min(j+2*(j-i),n));
           r.second+=cum[j]-cum[i];
           swap(r.first,r.second);
           dp[i][j]=r;
        }
        for(int j=i+1;j<=n;j++)sp[i][j][0]=dp[i][j];
        for(int j=1;(1<<j)<=n-i;j++)for(int k=i+1;k+(1<<(j-1))<=n;k++)sp[i][k][j]=max(sp[i][k][j-1],sp[i][k+(1<<(j-1))][j-1]);
    }
    printf("%d\n",max(dp[0][1].first,dp[0][2].first));
    return 0;
}

