/*
first we should know that to solve tower of hanoi with n disks we need 2^n-1 steps.
now the process of solving hanoi problem will guide us to solve this new virsion of the problem.
if disk number i(at peg A) will go to peg B,then we need to move disks (1...i-1) to C then move i to B, this will take 2^(i-1)
steps and we create a subproblem for moving disk i-1 to C.
always try to place current disk on it's peg(given string) to minimize the number of steps.
there are some cases to consider when writing code.

useful links to understand tower of hanoi:
https://www.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/a/towers-of-hanoi

*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e5+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

class HanoiState{
public:
    int pos[33],m,n;
    string tar;
    int getE(int a,int b){
        for(int i=0;i<3;i++)if(a!=i&&b!=i)return i;
        return 0;
    }
    void solve(int n,int f,int t,int y){
        if(n==1){
        	if(m)pos[1]=t;
            return ;
        }
        if(t==f){
            pos[n]=t;
            solve(n-1,f,tar[n-2]-'A',y);
            return ;
        }
        int e=getE(f,t);
        if(m<(1<<(n-1))-1){
            pos[n]=f;
            solve(n-1,f,e,1);
            return ;
        }
        for(int i=1;i<=n-1;i++)pos[i]=e;
        m-=(1<<(n-1))-1;
        if(!m)return ;
        m--;
        pos[n]=t;
        if(!m)return ;
        if(!y)solve(n-1,e,tar[n-2]-'A',y);
        else solve(n-1,e,t,y);
    }
    string partwayState(string s,int mo){
        m=mo;
        tar=s;
        n=s.size();
        solve(n,0,tar[n-1]-'A',0);
        string res;
        for(int i=1;i<=n;i++)res+=char(pos[i]+'A');
        return res;
    }
};
