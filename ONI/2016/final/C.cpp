#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int num[1000000];
int low2[1000000];
bool visited[1000000];
int counter;
vector<int> nei[1000000];
int sizes[1000000];
vector<int>DAG[1000000];
int DP[1000000];
stack<int>S;
int low[1000000];

void SCC(int u){
	low2[u]=num[u]=counter++;
	visited[u]=true;
	S.push(u);
	for(int i=0;i<(int)nei[u].size();i++){
		int v=nei[u][i];
		if(num[v]==-1)SCC(v);
		if(visited[v])low2[u]=min(low2[u],low2[v]);
	}
	if(low2[u]==num[u]){
		//cout<<"SCC:";
		while(true){
			int v=S.top();
			S.pop();visited[v]=false;//cout<<v<<" ";
			low[v]=low[u]=low2[u];
			if(v==u)break;
		}
		//cout<<endl;
	}
}
int trabalha(int i){
	if(DP[i]!=-1)return DP[i];
	DP[i]=sizes[i];
	for(int j=0;j<(int)DAG[i].size();j++){
		int v=DAG[i][j];
		DP[i]=max(DP[i],trabalha(v)+sizes[i]);
	}
	//cout<<"DP: "<<i<<" "<<DP[i]<<endl;
	return DP[i];
}
int main(){
	int g;cin>>g;
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		nei[x-1].push_back(y-1);
	}
	for(int i=0;i<n;i++){
		num[i]=-1;
		low2[i]=0;
		visited[i]=false;	
	}
	counter=0;
	for(int i=0;i<n;i++){
		if(num[i]==-1)SCC(i);
	}
	//for(int i=0;i<n;i++)cout<<"SCC:"<<i<<" "<<low[i]<<endl;
	for(int i=0;i<n;i++)sizes[i]=0;
	for(int i=0;i<n;i++){
		sizes[low[i]]++;
		for(int j=0;j<(int)nei[i].size();j++){
			int v=nei[i][j];
			if(low[i]!=low[v]){
				DAG[low[i]].push_back(low[v]);
				//cout<<low[i]<<" "<<low[v]<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)DP[i]=-1;
	int answer=0;
	for(int i=0;i<n;i++){
		int j=low[i];
		//cout<<"Size: "<<j<<" "<<sizes[j]<<endl;
		if(DP[j]==-1){
			trabalha(j);
			answer=max(answer,trabalha(j));
		}
	}
	cout<<answer<<endl;
	return 0;
}
