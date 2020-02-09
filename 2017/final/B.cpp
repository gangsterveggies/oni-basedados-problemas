#include<iostream>

using namespace std;
long long int max(long long int A, long long int B){
	if(A>B)return A;
	return B;
}
int main(){
	int n;
	long long int a,b;
	int I;
	cin>>n>>a>>b>>I;
	I--;
	long long int prize[n];
	for(int i=0;i<n;i++)cin>>prize[i];
	int zona[n];
	for(int i=0;i<n;i++){
		cin>>zona[i];
		zona[i]--;
	}
	int z=zona[n-1];
	z++;
	long long int Zpremio[z];
	for(int i=0;i<z;i++)Zpremio[i]=0;
	for(int i=0;i<n;i++){
		if(i==I)Zpremio[zona[i]]+=prize[i];
		else Zpremio[zona[i]]+=max(prize[i]-b-a,0);
	}
	int zonai=zona[I];
	long long int A1=0;
	long long int A2=0;
	long long int B1=0;
	long long int B2=0;
	long long int cumm=0;
	for(int i=zonai+1;i<z;i++){
		cumm-=2*b;
		cumm+=Zpremio[i];
		A1=max(A1,cumm);
	}
	cumm=0;
	for(int i=zonai-1;i>-1;i--){
		cumm-=2*b;
		cumm+=Zpremio[i];
		A2=max(A2,cumm);
	}
	cumm=0;
	for(int i=zonai+1;i<z;i++){
		cumm-=b;
		cumm+=Zpremio[i];
		B1=max(B1,cumm);
	}cumm=0;
	for(int i=zonai-1;i>-1;i--){
		cumm-=b;
		cumm+=Zpremio[i];
		B2=max(B2,cumm);
	}
	long long int ans=0;
	ans=max(A1+B2,B1+A2);//cout<<ans<<endl;
	ans+=Zpremio[zonai];
	cout<<ans<<endl;
	
	
}
