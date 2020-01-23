#include<iostream>
#include<stdio.h>
using namespace std;
int arr[1000000];
int diff[1000000];
int count[4000000];
int sum[4000000];
int Min[4000000];
int n,z;
void build(int a, int b, int node){
  if(a==b){
    Min[node]=diff[a];
    sum[node]=diff[a];
    count[node]=1;
    //cout<<a<<" "<<b<<" "<<Min[node]<<" "<<sum[node]<<" "<<count[node]<<endl;
    return;
  }
  int mid=(a+b)/2;
  build(a,mid,2*node);
  build(mid+1,b,2*node+1);
  Min[node]=min(Min[2*node],Min[2*node+1]+sum[2*node]);
  sum[node]=sum[2*node]+sum[2*node+1];
  count[node]=0;
  if(Min[node]==Min[2*node])count[node]+=count[2*node];
  if(Min[node]==Min[2*node+1]+sum[2*node])count[node]+=count[2*node+1];
  //cout<<a<<" "<<b<<" "<<Min[node]<<" "<<sum[node]<<" "<<count[node]<<endl;
}
void UPD(int a, int b, int node, int pos){
  if(pos<a || b<pos)return;
  if(a==b){
    Min[node]=diff[a];
    sum[node]=diff[a];
    count[node]=1;
    //cout<<a<<" "<<b<<" "<<Min[node]<<" "<<sum[node]<<" "<<count[node]<<endl;
    return;
  }
  int mid=(a+b)/2;
  UPD(a,mid,2*node,pos);
  UPD(mid+1,b,2*node+1,pos);
  Min[node]=min(Min[2*node],Min[2*node+1]+sum[2*node]);
  sum[node]=sum[2*node]+sum[2*node+1];
  count[node]=0;
  if(Min[node]==Min[2*node])count[node]+=count[2*node];
  if(Min[node]==Min[2*node+1]+sum[2*node])count[node]+=count[2*node+1];
}
void update(int pos){
  if(pos<1 || pos>n)return;
  int ans=0;
  ans+=1-2*(arr[pos]>arr[pos-1]);
  ans+=1-2*(arr[pos]>arr[pos+1]);
  diff[arr[pos]]=ans;
  UPD(1,n,1,arr[pos]);
}
int main(){
  
  scanf("%d %d",&n,&z);
  arr[0]=0;
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i+1]);
  }
  arr[n+1]=n+1;
  //for(int i=0;i<=n+1;i++)printf("%d ",arr[i]);
  for(int i=0;i<n;i++){
    update(i+1);
  }
  build(1,n,1);
  printf("%d\n",count[1]);
  //printf("0\n");
  z--;
  while(z--){
    int x,y;
    scanf("%d %d",&x,&y);
    swap(arr[x],arr[y]);
    update(x);
    update(x-1);
    update(x+1);
    update(y);
    update(y-1);
    update(y+1);
    printf("%d\n",count[1]);
    //printf("0\n");
  }
  //for(int i=0;i<=n;i++)printf("%d ",arr[i]);
  //for(int i=1;i<=n;i++)printf("%d ",diff[i]);
  return 0;
}
