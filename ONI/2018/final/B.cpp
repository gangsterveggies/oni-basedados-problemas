#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
lld p[1000000];
int main(){
  int n,k;
  lld q;
  scanf("%d %d %lld",&n,&k,&q);
  for(int i=0;i<n;i++){
    scanf("%lld",&p[i]);
  }
  lld lo,hi;
  lo=-1;
  hi=1;
  for(int i=0;i<12;i++)hi*=10;        
  while(hi-lo>1){
    lld mid=(lo+hi)/2;
    int problems=k;
    lld time=mid;
    bool b=true;
    for(int i=0;i<n;i++){
      lld max_verify=(time-problems*q)/(p[i]-q);
      max_verify=min(max_verify,(lld)problems);
      // cout<<max_verify<<" "<<mid<<" "<<time<<endl;
      if(max_verify>=0){
	problems-=max_verify;
	if(problems>0)time-=q;
      }else{
	b=false;
      }
    }
    if(b && problems==0){
      hi=mid;
    }else lo=mid;
  }
  printf("%lld\n",hi);
  return 0;
}
