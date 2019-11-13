#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
int n;
int arr[1000000];
lld DP[2000000];
lld calc(lld i){
  if(DP[i]!=-1)return DP[i];
  DP[i]=0;
  DP[i]=calc(i-1)*i;
  DP[i]%=MOD;
  lld can=(i+1)/2;
  can*=(i-1);
  DP[i]+=can;
  DP[i]%=MOD;
  return DP[i];
}
class BIT{
  int tree[2000000];
public:
  void build(){
    rep(i,0,n+1)tree[i]=0;
  }
  void add(int pos){
    for(;pos<=n;pos+=(pos&(-pos))){
      tree[pos]++;
    }
  }
  int query(int pos){
    
    int ans=0;
    for(;pos>0;pos-=(pos&(-pos))){
      ans+=tree[pos];
    }
    return ans;
  }
};
int main(){
  scanf("%d",&n);
  rep(i,0,n){
    scanf("%d",&arr[i]);
  }
  rep(i,0,n+1)DP[i]=-1;
  DP[1]=0;
  DP[0]=0;
  BIT *B=new BIT();
  B->build();
  lld ans=0;
  for(int i=n-1;i>-1;i--){
    //cout<<i<<" "<<arr[i]<<endl;
    int sz=n-i;
    B->add(arr[i]);
    int pos=B->query(arr[i]);
    lld can=calc(sz-1)+(sz+1)/2;
    can%=MOD;
    can*=(pos-1);
    can%=MOD;
    ans+=can;
    ans%=MOD;
  }
  printf("%lld\n",ans);
  //cout<<calc(n)<<endl;
  return 0;
}
