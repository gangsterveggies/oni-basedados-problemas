/*
  Modifiqa este ficheiro para fazerem a vossa solucao do Problema C.

  Nao modifiques mais nenhum ficheiro.
*/

#include "avaliador.h"
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n0;
void solve(vector<int> nei[], int start){
	queue<int>q;
	q.push(start);
	int dist[100000];
	for(int i=0;i<n0;i++)dist[i]=-1;
	dist[start]=0;
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int i=0;i<(int)nei[v].size();i++){
			int u=nei[v][i];
			if(dist[u]==-1){
				dist[u]=dist[v]+1;
				q.push(u);
			}
		}
	}
	int DD=-1;
	int maximo=-1;
	for(int i=0;i<n0;i++){
		//cout<<"DIST:"<<i<<" "<<dist[i]<<endl;
		if(dist[i]>maximo){
			DD=i;
			maximo=dist[i];
		}
	}
	q.push(DD);
	for(int i=0;i<n0;i++)dist[i]=-1;
	dist[DD]=0;
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int i=0;i<(int)nei[v].size();i++){
			int u=nei[v][i];
			if(dist[u]==-1){
				dist[u]=dist[v]+1;
				q.push(u);
			}
		}
	}
	DD=-1;
	maximo=-1;
	for(int i=0;i<n0;i++){
		if(dist[i]>maximo){
			DD=i;
			maximo=dist[i];
		}
	}
	int dists=maximo;
	while(dists*2>maximo){
		for(int i=0;i<(int)nei[DD].size();i++){
			int v=nei[DD][i];
			if(dist[v]<dist[DD]){
				DD=v;
				break;
			}
		}
		dists--;
	}
	int G=analisar(DD+1);
	//cout<<DD<<endl;
	if(G==-1){
		return;
	}
	G--;
	for(int i=0;i<(int)nei[G].size();i++){
		if(nei[G][i]==DD){
			nei[G].erase(nei[G].begin()+i);
		}
	}
	solve(nei,G);
}
void resolver(int N, int D, int Es[MAXN], int Et[MAXN])
{
	vector<int>nei[N];
	for(int i=0;i<N-1;i++){
		nei[Es[i]-1].push_back(Et[i]-1);
		nei[Et[i]-1].push_back(Es[i]-1);
	}
	n0=N;
	solve(nei,0);
}
