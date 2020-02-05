/*
Diâmetro da árvore
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
Escolhemos um vértice arbitrário, encontramos o vértice mais longe, seja u
De u, encontramos o vértice mais longe, seja v
O diâmetro é a distância entre u e v
Prova-se que a distância entre  e v é a maior das distâncias entre vértices do grafo.
*/
int BFS(int s){//retorna o vertice mais longe de s
	rep(i,0,n)dist[i]=-1;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	int ans=s;
	while(!q.empty()){
		int u=q.front();q.pop();
		ans=u;
		trav(v,nei[u]){
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return ans;
}
int diam(){
	int u=BFS(0);
	int v=BFS(u);
	return dist[v];
}
int main() {
	cin>>n;
	rep(i,0,n-1){
		int x,y;
		cin>>x>>y;
		x--;y--;
		nei[x].push_back(y);
		nei[y].push_back(x);
	}
	cout<<diam()<<endl;
	return 0;
}
