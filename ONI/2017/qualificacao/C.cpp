#include<iostream>

using namespace std;
int valores[10000001];
int DP[10000001];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<10000001;i++){
		valores[i]=0;
		DP[i]=0;
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		valores[x]++;
	}
	int ans=0;
	for(int i=10000001;i>0;i--){
		if(valores[i]>0){
			for(int j=i;j<10000000;j+=i){
				//if(j<25)cout<<valores[i]<<" "<<DP[j]<<" "<<j<<endl;
				if(DP[i]<valores[i]+DP[j]){
					DP[i]=valores[i]+DP[j];
					//cout<<j<<endl;
				}
			}
			if(DP[i]>ans)ans=DP[i];
			//cout<<i<<" "<<DP[i]<<endl;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
