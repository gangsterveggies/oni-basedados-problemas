#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
int zeta[20];
vector<int> v;
void build(){
  zeta[0]=-1;
  int j=-1;
  for(int i=0;i<(int)v.size();i++){
    while(j>=0 && v.at(i)!=v.at(j)){
      j=zeta[j];
    }
    j++;
    zeta[i+1]=j;
  }
}
int main(){
  lld A;
  cin>>A;
  while(A>0){
    v.push_back(A%10);
    A/=10;
  }reverse(v.begin(),v.end());
  build();
  /*for(int i=0;i<=v.size();i++)cout<<zeta[i]<<" ";
    cout<<endl;*/
  int Q;
  cin>>Q;
  while(Q--){
    lld B;
    cin>>B;
    vector<int> b;
    for(int i=0;i<20;i++){
      b.push_back(B%10);
      B/=10;
    }
    lld DP[20][20][2];//pos,KMP,cmp
      for(int i=0;i<20;i++){
	for(int j=0;j<20;j++){
	  DP[i][j][0]=0;
	  DP[i][j][1]=0;
	}
      }
    DP[19][0][1]=1;
    for(int i=19;i>0;i--){
      for(int j=0;j<20;j++){
	for(int digit=0;digit<10;digit++){
	  if(DP[i][j][0]!=0){
	  int next_j=j;
	  while(digit!=v[next_j] && next_j>=0){
	    next_j=zeta[next_j];
	  }
	  next_j++;
	  if(next_j<(int)v.size())DP[i-1][next_j][0]+=DP[i][j][0];
	  }
	}
	for(int digit=0;digit<=b[i-1];digit++){
	  if(DP[i][j][1]!=0){
	  int next_j=j;
	  //cout<<next_j<<" "<<v.size()<<endl;
	  while(digit!=v[next_j] && next_j>=0){
	    next_j=zeta[next_j];
	  }
	  next_j++;
	  int next_cmp=(digit==b[i-1]);
	  if(next_j<(int)v.size())DP[i-1][next_j][next_cmp]+=DP[i][j][1];
	  }
	}
	//cout<<DP[i][j][0]<<" "<<DP[i][j][1]<<" "<<j<<endl;
      }
    }
    
    lld ans=0;
    for(int i=0;i<20;i++){
      //cout<<DP[0][i][0]<<" "<<DP[0][i][1]<<" "<<i<<endl;
      ans+=DP[0][i][0]+DP[0][i][1];
    }cout<<ans-1<<endl;
  }
  return 0;
}
