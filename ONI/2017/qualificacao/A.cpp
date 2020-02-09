#include"stdio.h"
#include<iostream>
using namespace std;

int main(){
	int n,b,m;
	cin>>n>>b>>m;
	//scanf("%d %d %d\n",&n, &b, &m);
	int tesouros[n];
	b--;
	for(int i=0;i<n;i++){
		char c;
		//scanf("%c",&c);
		cin>>c;
		if(c=='T')tesouros[i]=1;
		if(c=='V')tesouros[i]=0;
		//printf("%c",c);
	}
	//scanf("\n");
	int lo=b;
	int hi=b;
	for(int i=0;i<m;i++){
		char c;
		int passos;
		//scanf("%c %d\n",&c,&passos);
		cin>>c>>passos;
		if(c=='D') b+=passos;
		else b-=passos;
		
		if(lo>b)lo=b;
		if(hi<b)hi=b;

	}
	int ans=0;
	for(int j=lo;j<=hi;j++){
		ans+=tesouros[j];
	}
	printf("%d\n",ans);
	return 0;
}
