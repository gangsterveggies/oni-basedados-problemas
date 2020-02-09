#include<iostream>

using namespace std;
int arr[900][900];
bool test(int L,int C,int x,int y,int mid){
	//cout<<"MID:"<<mid<<endl;
	int arr2[L][C];
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			if(arr[i][j]>=mid)arr2[i][j]=1;
			else arr2[i][j]=0;
		}
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			if(i>0)arr2[i][j]+=arr2[i-1][j];
			if(j>0)arr2[i][j]+=arr2[i][j-1];
			if(i>0 && j>0)arr2[i][j]-=arr2[i-1][j-1];
			//cout<<arr2[i][j]<<" ";
		}//cout<<endl;
	}
	for(int i=x-1;i<L;i++){
		for(int j=y-1;j<C;j++){
			int ans=arr2[i][j];
			if(i>x-1)ans-=arr2[i-x][j];
			if(j>y-1)ans-=arr2[i][j-y];
			if(i>=x && j>=y)ans+=arr2[i-x][j-y];
			//cout<<ans<<" ";
			if(ans==0)return true;
		}//cout<<endl;
	}
	return false;
}
int main(){
	int L,C;
	cin>>L>>C;
	
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			cin>>arr[i][j];
		}
	}
	int R;
	cin>>R;
	while(R--){
		int x,y;
		cin>>x>>y;
		int lo,hi;
		lo=-1;
		hi=1000000;
		while(hi-lo>1){
			//cout<<lo<<" "<<hi<<endl;
			int mid=(hi+lo)/2;
			bool b=test(L,C,x,y,mid);
			if(b)hi=mid;
			else lo=mid;
		}
		cout<<hi<<endl;
	}
	
	return 0;
}
