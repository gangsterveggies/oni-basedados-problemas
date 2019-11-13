#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
int n,m;
vector<pair<lld,pair<lld,lld> > >V;
lld cnt[50][50][2500];
lld DP[50][50][2501];
lld Count(int i, int j, int k){
  if(i<0)return 0;
  if(j>=n)return 0;
  if(i>j)return 0;
  return cnt[i][j][k];
}
lld calc(int i, int j, int k){
  
  if(i<0)return 0;
  if(j>=n)return 0;
  if(i>j)return 0;
  if(DP[i][j][k]!=-1)return DP[i][j][k];
  
  
  DP[i][j][k]=calc(i,j,k+1);
  rep(mid,i,j+1){
    
    DP[i][j][k]=max(DP[i][j][k],calc(i,mid-1,k)+calc(mid+1,j,k)+V[k].first*(Count(i,j,k)-Count(i,mid-1,k)-Count(mid+1,j,k)));
  }
  //cout<<i<<" "<<j<<" "<<k<<" "<<DP[i][j][k]<<endl;
  return DP[i][j][k];
}
lld ANS[1000];
void build(int i, int j, int k){
  if(i>j)return;
  rep(mid,i,j+1){
    if(DP[i][j][k]==calc(i,mid-1,k)+calc(mid+1,j,k)+V[k].first*(Count(i,j,k)-Count(i,mid-1,k)-Count(mid+1,j,k))){
      ANS[mid]=k;
      build(i,mid-1,k);
      build(mid+1,j,k);
      return;
    }
  }
  build(i,j,k+1);
}
int main(){
  scanf("%d %d",&n,&m);
  
  rep(i,0,m){
    lld x,y,z;
    scanf("%lld %lld %lld",&x,&y,&z);
    V.push_back(pair<lld,pair<lld,lld> >(z,pair<lld,lld>(x-1,y-1)));
  }
  sort(V.begin(),V.end());
  rep(k,0,m){
    rep(i,0,n){
      rep(j,0,n)cnt[i][j][k]=0;
    }
  }
  rep(i,0,m){
    rep(j,0,i+1){
      cnt[V[i].second.first][V[i].second.second][j]++;
      
    }
    //cout<<V[i].first.first<<" "<<V[i].first.second<<endl;
  }
  /*rep(i,0,n){
    rep(j,0,n)cout<<cnt[i][j]<<" ";
    cout<<endl;
  }*/
  rep(k,0,m+1){
    rep(i,0,n){
      rep(j,0,n){
	DP[i][j][k]=-1;
	//cout<<cnt[i][j][k]<<" ";
      }//cout<<endl;
    }//cout<<endl;
  }
  rep(k,0,m){
  for(int i=n-1;i>-1;i--){
    rep(j,0,n){
      if(i<n-1)cnt[i][j][k]+=cnt[i+1][j][k];
      if(j>0)cnt[i][j][k]+=cnt[i][j-1][k];
      if(i<n-1 && j>0)cnt[i][j][k]-=cnt[i+1][j-1][k];
    }
  }
  }
  rep(k,0,m+1){
    rep(i,0,n){
      rep(j,0,n){
	DP[i][j][k]=-1;
	//cout<<cnt[i][j][k]<<" ";
      }//cout<<endl;
    }//cout<<endl;
  }
  rep(i,0,n){
    rep(j,0,n)DP[i][j][m]=0;
  }
  /*rep(k,m-2,m+1){
    rep(i,0,n){
      rep(j,0,n)cout<<calc(i,j,k)<<" ";
      cout<<endl;
    }cout<<endl;
  }*/
  printf("%lld\n",calc(0,n-1,0));
  /*rep(i,0,n){
    rep(j,0,n)cout<<cnt[i][j]<<" ";
    cout<<endl;
  }*/
  build(0,n-1,0);
  rep(i,0,n)cout<<V[ANS[i]].first<<" ";
  cout<<endl;
  return 0;
}
