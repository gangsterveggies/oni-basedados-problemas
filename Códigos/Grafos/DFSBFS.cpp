/*
DFS/BFS
Memória:O(n)
Tempo:O(n)
Writer: KLPP 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a:v)
typedef long long int lld;
int n,m;
vector<int> nei[1000000];
bool visited[1000000];
int dist[1000000];
/*
Para cada vértice, vemos se há algum vizinho que não está marcado
Se houver, vmos recursivamente para o vizinho
É mais simples que o BFS e consegue determinar componentes fortemente conexas, pontes e pontos de articulaçõ(com algumas variações)
*/
void DFS(int node){
	cout<<node<<endl;
	visited[node]=true;
	trav(a,nei[node]){
		if(!visited[a])DFS(a);
	}
}
/*
Visitar os vértices por ordem de distância
usamos uma queue para manter os vértices em ordem
Conseguimos calcular as distâncias para todos os vértices(não acontece no DFS)
*/
void BFS(int s){
	rep(i,0,n)dist[i]=-1;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		trav(v,nei[u]){
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		x--;y--;
		nei[x].push_back(y);
		nei[y].push_back(x);
	}
	rep(i,0,n)visited[i]=false;
	DFS(0);
	BFS(0);
	rep(i,0,n)cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}
