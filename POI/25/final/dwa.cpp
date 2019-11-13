#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
typedef pair<lld,lld> pii;
#define rep(i,a,b) for(int i=a;i<b;i++)
lld abs(lld x){
	if(x>0)return x;
	return -x;
}
pii Swap(pii a){
  return pii(-a.first,-a.second);
}
bool cmp(pii A, pii B){
  if(A.first*B.second<A.second*B.first)return true;
  return false;
}
int main(){
  int n;
  cin>>n;
  if(n<=20){
    lld x[n];
	lld y[n];
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
	}
	lld ans=0;
	for(int i=0;i<(1<<n);i++){
		lld X,Y;
		X=0;
		Y=0;
		for(int j=0;j<n;j++){
			if((i&(1<<j))>0){
				X+=x[j];
				Y+=y[j];
			}else{
				X-=x[j];
				Y-=y[j];				
			}
		}
		ans=max(ans,X*X+Y*Y);
	}
	printf("%lld\n",ans);
	return 0;
  }
  pii arr[n];
  rep(i,0,n){
    cin>>arr[i].first>>arr[i].second;
    if(arr[i].second<0)arr[i]=Swap(arr[i]);
    if(arr[i].second==0 && arr[i].first<0)arr[i]=Swap(arr[i]);
  }
  sort(arr,arr+n,cmp);
  lld X=0;
  lld Y=0;
  rep(i,0,n){
    //cout<<arr[i].first<<" "<<arr[i].second<<endl;
    X+=arr[i].first;
    Y+=arr[i].second;
  }
  lld ans=X*X+Y*Y;
  rep(i,0,n){
    X-=2*arr[i].first;
    Y-=2*arr[i].second;
    ans=max(ans,X*X+Y*Y);
  }
  cout<<ans<<endl;
  return 0;
}
