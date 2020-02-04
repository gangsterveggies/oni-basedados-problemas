#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a:v)
 
int n,k;
lld a[1000000];
lld b[1000000];
lld d[1000000];
int main() {
	cin>>n>>k;
	rep(i,0,n)cin>>a[i];
	rep(i,0,n)cin>>b[i];
	rep(i,0,n)d[i]=a[i]-b[i];
	sort(d,d+n);
	lld ans=1e16;
	lld left=0;
	lld right=0;
	k=n-k;
	if(k==0){
		cout<<0<<endl;
		return 0;
	}
	rep(i,0,k){
		if(2*i<k){
			left+=d[i];
		}else right+=d[i];
	}
	ans=min(ans,right-left+d[k/2]*(k%2));
	
	for(int i=0;k+i<n;i++){
		left-=d[i];
		left+=d[(k+1)/2+i];
		right-=d[(k+1)/2+i];
		right+=d[k+i];
		ans=min(ans,right-left+d[k/2+i+1]*(k%2));
	}
	cout<<ans<<endl;
	return 0;
}
