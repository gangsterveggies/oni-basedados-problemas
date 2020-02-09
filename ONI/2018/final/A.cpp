#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
int k;
lld a,b;
vector<int> A;
lld DP[20][1024][2][2];

lld compute(int pos, int mask,int cmp,int leading_zero){
  //cout<<pos<<" "<<mask<<" "<<cmp<<endl;
  if(pos==-1){
    if(mask==0)return 1;
    return 0;
  }
  if(DP[pos][mask][cmp][leading_zero]!=-1)return DP[pos][mask][cmp][leading_zero];
  DP[pos][mask][cmp][leading_zero]=0;
  if(cmp==1){
    if(leading_zero==1){
      DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,(A[pos]==0),1);
      for(int digit=1;digit<=A[pos];digit++){
	if((mask&(1<<digit))>0){
	  DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask-(1<<digit),(A[pos]==digit),0);
	  DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,(A[pos]==digit),0);
	}
      }
      return DP[pos][mask][cmp][leading_zero];
    }
    for(int digit=0;digit<=A[pos];digit++){
	if((mask&(1<<digit))>0){
	  DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask-(1<<digit),(A[pos]==digit),0);
	  DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,(A[pos]==digit),0);
	}
      }
    return DP[pos][mask][cmp][leading_zero];
  }
  if(leading_zero==1){
    DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,0,1);
    for(int digit=1;digit<=9;digit++){
      if((mask&(1<<digit))>0){
	DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,0,0);
	DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask-(1<<digit),0,0);
      }
    }
    return DP[pos][mask][cmp][leading_zero];
  }
  for(int digit=0;digit<=9;digit++){
    if((mask&(1<<digit))>0){
	DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask,0,0);
	DP[pos][mask][cmp][leading_zero]+=compute(pos-1,mask-(1<<digit),0,0);
    }
  }
  return DP[pos][mask][cmp][leading_zero];
}
int main(){
  int t;
  cin>>t;
  while(t--){
  cin>>a>>b>>k;
  a--;
  for(int i=0;i<20;i++){
    for(int j=0;j<1024;j++){
      DP[i][j][0][0]=-1;
      DP[i][j][0][1]=-1;
      DP[i][j][1][0]=-1;
      DP[i][j][1][1]=-1;
      
    }
  }A.clear();
  for(int i=0;i<20;i++){
    A.push_back(a%10);
    a/=10;
  }
  /*lld sum=0;
  for(int i=0;i<1024;i++){
    sum+=compute(19,i,1,1);
    
  }
  cout<<sum<<endl;*/
  lld sum_A=0;
  for(int mask=0;mask<1024;mask++){
    int count=0;
    for(int j=0;j<10;j++){
      if((mask&(1<<j))>0){
	count++;
      }
    }
    if(count>=1 && count<=k){
      sum_A+=compute(19,mask,1,1);
    }
  }
  for(int i=0;i<20;i++){
    for(int j=0;j<1024;j++){
      DP[i][j][0][0]=-1;
      DP[i][j][0][1]=-1;
      DP[i][j][1][0]=-1;
      DP[i][j][1][1]=-1;
      
    }
  }A.clear();
  for(int i=0;i<20;i++){
    A.push_back(b%10);
    b/=10;
  }
  /*lld sum=0;
  for(int i=0;i<1024;i++){
    sum+=compute(19,i,1,1);
    
  }
  cout<<sum<<endl;*/
  lld sum_B=0;
  for(int mask=0;mask<1024;mask++){
    int count=0;
    for(int j=0;j<10;j++){
      if((mask&(1<<j))>0){
	count++;
      }
    }
    if(count>=1 && count<=k){
      sum_B+=compute(19,mask,1,1);
    }
  }
  cout<<sum_B-sum_A<<endl;
  }
  return 0;
}
