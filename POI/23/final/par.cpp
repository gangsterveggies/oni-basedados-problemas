#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a:v)
#define INF 100000000000
int n;
vector<int>nei[200000];
bool visited[200000];
vector<int>child[200000];
lld deg[200000];
void DFS(int node){
  visited[node]=true;
  trav(a,nei[node]){
    if(!visited[a]){
      child[node].push_back(a);
      DFS(a);
    }
  }
}
lld answer[200000];
lld path[200000];

void calc(int node){
  answer[node]=-INF;
  path[node]=-INF;
  if(child[node].size()==0){
    
    return;
  }
  lld best=-INF;
  lld second=-INF;
  trav(a,child[node]){
    calc(a);
    lld can=max(path[a],deg[a]-2);
    if(can>best){
      second=best;
      best=can;
    }else{
      second=max(second,can);
    }
    path[node]=max(path[node],deg[node]-2+max(path[a],deg[a]-2));
  }
  
  answer[node]=path[node];
  if(child[node].size()>1){
    answer[node]=max(answer[node],best+second+nei[node].size()-2);
  }
  
}
int main(){
  
  scanf("%d",&n);
  rep(i,0,n-1){
    int x,y;
    scanf("%d %d",&x,&y);
    x--;y--;
    nei[x].push_back(y);
    nei[y].push_back(x);
  }
  rep(i,0,n){
    visited[i]=false;
    deg[i]=nei[i].size();
  }
  DFS(0);
  calc(0);
  lld ans=-2;
  rep(i,0,n){
    //cout<<answer[i]<<" "<<path[i]<<endl;
    ans=max(ans,answer[i]);
  }
  printf("%lld\n",ans+2);
  return 0;
}
