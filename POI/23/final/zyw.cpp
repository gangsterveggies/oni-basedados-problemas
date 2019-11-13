#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
class DSU{
  int parent[2000000];
  int size[2000000];
public:
  void init(int n){
    rep(i,0,n){
      parent[i]=i;
      size[i]=1;
    }
  }
  int root(int a){
    if(parent[a]==a)return a;
    parent[a]=root(parent[a]);
    return parent[a];
  }
  bool merge(int a, int b){
    a=root(a);
    b=root(b);
    if(a==b)return false;
    if(size[b]>size[a])swap(a,b);
    size[a]+=size[b];
    parent[b]=a;
    return true;
  }
};
int edges[2000000][2];
int cnt;
bool used[2000000];
int main(){
  int n,m;
  scanf("%d %d",&m,&n);
  vector<pair<int,int > >edgelist;
  cnt=0;
  rep(i,0,m){
    string s;
    cin>>s;
    rep(j,0,n-1){
      if(s[j]=='C'){
	edgelist.push_back(pair<int,int>(1,cnt));
      }else{
	edgelist.push_back(pair<int,int>(0,cnt));
      }
      edges[cnt][0]=(n+1)*i+j+1;
      edges[cnt][1]=(n+1)*(i+1)+j+1;
      cnt++;
    }
  }
  rep(i,0,m-1){
    string s;
    cin>>s;
    rep(j,0,n){
      if(s[j]=='C'){
	edgelist.push_back(pair<int,int>(1,cnt));
      }else{
	edgelist.push_back(pair<int,int>(0,cnt));
      }
      edges[cnt][0]=(n+1)*(i+1)+j;
      edges[cnt][1]=(n+1)*(i+1)+j+1;
      cnt++;
    }
  }
  rep(i,0,cnt){
    used[i]=false;
  }
  sort(edgelist.begin(),edgelist.end());
  reverse(edgelist.begin(),edgelist.end());
  DSU *D=new DSU();
  D->init((n+1)*(m+1));
  rep(i,0,n){
    D->merge(i,i+1);
    D->merge((n+1)*m+i,(n+1)*m+i+1);
  }
  rep(j,0,m){
    D->merge((n+1)*j,(n+1)*(j+1));
    D->merge((n+1)*j+n,(n+1)*(j+1)+n);
  }
  int Trees=0;
  int Cyp=0;
  rep(i,0,edgelist.size()){
    int idx=edgelist[i].second;
    if(D->merge(edges[idx][0],edges[idx][1])){
      used[idx]=true;
      Trees++;
      Cyp+=edgelist[i].first;
    }
  }
  printf("%d %d\n",Trees,Cyp);
  cnt=0;
  rep(i,0,m){
    rep(j,0,n-1){
      if(used[cnt]){
	printf("Z");
      }else printf(".");
      cnt++;
    }
    printf("\n");
  }
  rep(i,0,m-1){
    rep(j,0,n){
      if(used[cnt]){
	printf("Z");
      }else printf(".");
      cnt++;
    }
    printf("\n");
  }
  return 0;
}
