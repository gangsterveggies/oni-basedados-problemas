/*
Segment tree de máximos com lazy propagation
Memória:O(n)
Updates,Queries=O(log(n))
Writer: KLPP 
*/
#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
class ST{
	/*
	arr guarda o máximo para um certo range, sabendo que ainda não propagamos os nós acima dele
	lazy guarda a operação que temos de fazer no nó
	Os nós são numerados de maneira a que os filhos de um nó x são 2x e 2x+1
	Para o lazy propagation funcionar a operação tem de ser stackable e temos de poder dar update em O(1)
	+a+b=+(a+b) Stackable
	max(x+a,y+a)=max(x,y)+a update em O(1)
	*/
	lld arr[1000000];
	lld lazy[1000000];
	public:
	/*
	Esta unção constrói a segment tree
	Inicizlizamos os arrays com zeros uma vez que não plicamos operações
	Nestas funções a e b são os limites do intervalo(fechado)
	Node é o indice do nó(para podermos guardar a árvore como um array)
	*/
	void build(int a, int b, int node){
		arr[node]=0;
		lazy[node]=0;
		if(a==b){
			return;
		}
		int mid=(a+b)/2;
		build(a,mid,2*node);
		build(mid+1,b,2*node+1);
	}
	/*
	Esta função propaga um nó
	Uma vez que somamos lazy[node] a todos os valores de [a,b], ao máximo também será adicionad lazy[node]
	Depois propagamos o lazy pelos filhos(uma vez que os filhos ainda não foram updated)
	*/
	void propagate(int a, int b, int node){
		arr[node]+=lazy[node];
		if(a!=b){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	/*
	Sempre a começar o update temos de propagar o nó, para ter a certeza que não fazemos operaçoes em nós desatualizados
	Se a primeira linha desta função for trocada de sítio muito provavelmente vão ter WA
	Só paramos quando os intervalos [a,b] e [x,y] forem disjuntos
	Ou quando [a,b] estiver dentro de [x,y] (Chegamos num range que o intervalo vai ser todo updated e conseguimos faze-lo em O(1))
	*/
	void update(int a, int b, int node, int x, int y, lld val){
		propagate(a,b,node);
		if(b<x || y<a)return;
		if(x<=a && b<=y){
			lazy[node]+=val;
			propagate(a,b,node);
			return;
		}
		int mid=(a+b)/2;
		update(a,mid,2*node,x,y,val);
		update(mid+1,b,2*node+1,x,y,val);
		arr[node]=max(arr[2*node],arr[2*node+1]);
	}
	/*
	As queries são feitas como os updates, só que sem mudar nada no array e retornando os valores que se encontra pelo caminho
	*/
	lld query(int a, int b, int node, int x, int y){
		propagate(a,b,node);
		if(b<x || y<a)return -1e16;
		if(x<=a && b<=y){
			return arr[node];	
		}
		int mid=(a+b)/2;
		return max(query(a,mid,2*node,x,y),query(mid+1,b,2*node+1,x,y));
	}
};
ST S;
int n;
int main() {
	n=10;
	/*
	Antes de usar a segtree devemos chamar build
	*/
	S.build(0,n-1,1);
	S.update(0,n-1,1,1,2,1);
	S.update(0,n-1,1,1,4,-1);
	cout<<S.query(0,n-1,1,0,n-1)<<endl;
	return 0;
}
