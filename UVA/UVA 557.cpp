/*
convert the problem to new one.
given n/2 0's and n/2 zero's, put them in row.
what is the probability that last 2 digits are different, such that we start put digits one by one, with probablity 0.5 each time if there is still the two kinds of digits.
the answer for original problem is the complement(1.0 - answer for new problem)

first test case:
000111
since last 2 digits are different then it should looks like this
0011(01)
then for prefix 0011 get the summation of probablities of all permutations which is equal to 0.5^4 * 4!/(2!*2!)
keep calculations less than 1 so that we don't overflow or get zero as result.
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n;

int main(){
/*  ios::sync_with_stdio(0);
  cin.tie(0);*/
  scanf("%d",&t);
  while(t--){
      scanf("%d",&n);
      int m=n/2-1;
      double sub=1;
      int t2=m*2;
      for(int i=1,j=m+1;i<=m;i++,j++){
          sub*=1.0*j/i;
          while(sub>1&&t2){
              sub/=2;
              t2--;
          }
      }
      while(t2){
          sub/=2;
          t2--;
      }
      printf("%.4f\n",1.0-sub);
  }
  return 0;
}