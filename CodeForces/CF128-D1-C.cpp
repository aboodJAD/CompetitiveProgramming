/*
after reading a hint..
http://codeforces.com/blog/entry/3193?#comment-64144
the dimensions are independent..let's consider a rect (R1,C1),(R2,C2)
then choosing R1,R2 is independent from choosing C1,C2;
so we have to choose K rect's each of them has two points in each dimension
so for each 2 points in R dimension(top-down) we can map them to two points in C dimension(left right) to creat a rect compatible with 
a valid distribution..
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 3e5 + 10,M=5e4+5, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;


int n,m,k,C[1001][1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    C[0][0]=1;
    for(int i=1;i<=1000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    }
    cin>>n>>m>>k;
    if(2*k>n-1||2*k>m-1){
        cout<<0;
        return 0;
    }
    cout<<C[n-1][2*k]*1LL*C[m-1][2*k]%mod;
    return 0;
}



