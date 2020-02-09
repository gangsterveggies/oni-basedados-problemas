#include<bits/stdc++.h>

using namespace std;
char arr[100000];
vector<int> nei[100000];
int parent[1000000];
int comprimento[1000000];
int parent_dist[1000000][2][2];
int calcula(int node){
  if(comprimento[node]!=-1)return comprimento[node];
  if(arr[node]=='U'){
    comprimento[node]=0;
    
  }
  if(arr[node]=='S'){
    comprimento[node]=calcula(nei[node][0])+calcula(nei[node][1])+1;
    
  }
  if(arr[node]=='P'){
    comprimento[node]=min(calcula(nei[node][0]),calcula(nei[node][1]))+2;
    
  }return comprimento[node];
}
vector<pair<int ,int> > v1;
vector<int> path1;
void fill1(int node){
  path1.push_back(node);
  if(node==-1 || parent[node]==-1)return;
  int p=parent[node];
  pair<int,int> ans;
  if(arr[p]=='S'){
    if(nei[p][0]==node){
      ans.first=v1[v1.size()-1].first;
      ans.second=v1[v1.size()-1].second+1+comprimento[nei[p][1]];
    }else{
      ans.second=v1[v1.size()-1].second;
      ans.first=v1[v1.size()-1].first+1+comprimento[nei[p][0]];     
    }
  }else{
    if(nei[p][0]==node){
      ans.first=min(v1[v1.size()-1].first+1,3+comprimento[nei[p][1]]+v1[v1.size()-1].second);
      ans.second=min(v1[v1.size()-1].second+1,3+comprimento[nei[p][1]]+v1[v1.size()-1].first);
    }else{
      ans.first=min(v1[v1.size()-1].first+1,3+comprimento[nei[p][0]]+v1[v1.size()-1].second);
      ans.second=min(v1[v1.size()-1].second+1,3+comprimento[nei[p][0]]+v1[v1.size()-1].first);   
    }
  }//cout<<ans.first<<" "<<ans.second<<endl;
  v1.push_back(ans);
  fill1(p);
}
vector<pair<int ,int> > v2;
vector<int> path2;
void fill2(int node){
  path2.push_back(node);
  if(node==-1 || parent[node]==-1)return;
  int p=parent[node];
  pair<int,int> ans;
  if(arr[p]=='S'){
    if(nei[p][0]==node){
      ans.first=v2[v2.size()-1].first;
      ans.second=v2[v2.size()-1].second+1+comprimento[nei[p][1]];
    }else{
      ans.second=v2[v2.size()-1].second;
      ans.first=v2[v2.size()-1].first+1+comprimento[nei[p][0]];     
    }
  }else{
    if(nei[p][0]==node){
      ans.first=min(v2[v2.size()-1].first+1,3+comprimento[nei[p][1]]+v2[v2.size()-1].second);
      ans.second=min(v2[v2.size()-1].second+1,3+comprimento[nei[p][1]]+v2[v2.size()-1].first);
    }else{
      ans.first=min(v2[v2.size()-1].first+1,3+comprimento[nei[p][0]]+v2[v2.size()-1].second);
      ans.second=min(v2[v2.size()-1].second+1,3+comprimento[nei[p][0]]+v2[v2.size()-1].first);   
    }
  }//cout<<ans.first<<" "<<ans.second<<endl;
  v2.push_back(ans);
  fill2(p);
}
int main(){
  int n,q;
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++)parent[i]=-1;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]!='U'){
      int x,y;
      cin>>x>>y;
      x--;y--;
      parent[x]=i;
      parent[y]=i;
      nei[i].push_back(x);
      nei[i].push_back(y);
    }
  }
  for(int i=0;i<n;i++)comprimento[i]=-1;
  for(int i=0;i<n;i++)calcula(i);
  while(q--){
    int x,y;
    cin>>x>>y;
    x--;y--;
    v1.push_back(pair<int,int>(0,0));
    fill1(x);
    v2.push_back(pair<int,int>(0,0));
    fill2(y);
    /* for(int i=0;i<path1.size();i++){
      cout<<path1[i]<<" "<<v1[i].first<<" "<<v1[i].second<<endl;
      }cout<<v1.size()<<" "<<path1.size()<<endl;*/
    int ans=100000000;
    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    /*for(int i=0;i<path1.size();i++){
      cout<<path1[i]<<" "<<v1[i].first<<" "<<v1[i].second<<endl;
    }cout<<v1.size()<<" "<<path1.size()<<endl;
    for(int i=0;i<path1.size();i++){
      cout<<path2[i]<<" "<<v2[i].first<<" "<<v2[i].second<<endl;
    }cout<<v2.size()<<" "<<path2.size()<<endl;*/
    for(int i=0;i<(int)path1.size() && i<(int)path2.size();i++){
      if(path1[i]==path2[i]){
	ans=min(ans,v1[i].first+v2[i].first);
	ans=min(ans,v1[i].second+v2[i].second);
	if(path1[i+1]!=path2[i+1] && arr[path1[i]]=='S'){
	  //cout<<i<<" "<<nei[path1[i]][0]<<" "<<path1[i+1]<<endl;
	  if(nei[path1[i]][0]==path1[i+1])ans=min(ans,v1[i+1].second+v2[i+1].first+1);
	  else ans=min(ans,v1[i+1].first+v2[i+1].second+1);
	}
      }
    }
    cout<<ans<<endl;
    path1.clear();
    v1.clear();
    path2.clear();
    v2.clear();
  }
  
  return 0;
}
