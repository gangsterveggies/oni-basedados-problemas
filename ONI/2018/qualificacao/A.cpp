#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	long long int z;
	cin>>n>>z;
	long long int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		//cout<<z<<endl;
		z-=arr[i];
		if(z<=0){
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}
