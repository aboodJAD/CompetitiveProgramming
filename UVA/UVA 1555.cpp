/*
if we binary search second point height then we can get all other points heights
if some point went down zero then we should increase height of second point else we should decrease it to get minimum height of last point
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e6+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

int main(){
    double a;
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%lf",&a);
        double l=0,r=a-1e-5,mid,res=0;
        for(int i=0;i<100;i++){
            mid=(l+r)/2;
            //mid=9;
            double hp=a,hc=mid,tmp;
            bool no=0;
            for(int j=2;j<n;j++){
                tmp=2*(hc+1)-hp;
  //              cout<<hc<<' '<<hp<<' '<<tmp<<endl;
                hp=hc;
                hc=tmp;
                if(hc+(1e-9)<0){
                    no=1;
                    break;
                }
            }
//            cout<<mid<<' '<<no<<endl;
            if(no)l=mid;
            else {
                r=mid;
                res=hc;
            }
        }
        printf("%.2lf\n",fabs(res));
    }
    return 0;
}


