#include<iostream>

using namespace std;
typedef long long int lld;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int VA=0;
	int VT=0;
	for(int i=0;i<n;i++){
		if(s.at(i)!='A')VA++;
	}
	int index=0;
	for(int i=0;i<n;i++){
		if(s.at(i)!='A'){
			VA--;
		}
		//cout<<VA<<" "<<VT<<endl;
		if(VA>=VT)index=i;
		if(s.at(i)!='T'){
			VT++;
		}
	}
	string S="";
	for(int i=0;i<n;i++){
		if(s.at(i)=='?'){
			if(i>index)S+='T';
			else S+='A';
		}else S+=s.at(i);
	}
	//cout<<S<<endl;
	lld numerodeA=0;
	lld ans=0;
	for(int j=0;j<n;j++){
		if(S.at(j)=='A')numerodeA++;
		else ans+=numerodeA;
	}
	cout<<ans<<endl;
	return 0;
}
