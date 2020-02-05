/*
Fenwick Tree
Memória:O(n)
Updates,Queries=O(log(n))
Writer: KLPP 
*/
#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
 
class FT{
	/*
	A fenwick tree é muito mais simples que a segtree
	arr denota a soma dos valores entre ]i-2^v2(i),i]
	O array tem tamanho N+1
	Ter um arraycom tamanho exatamente N pode dar problemas
	*/
	lld arr[1000001];
	int n;
	public:
	void init(int N){
		n=N;
		rep(i,0,n+1)arr[i]=0;
	}
	/*
	A fenwick tree é 1-indexed
	Para fazer mais rapidamente as contas
	*/
	void update(int pos,lld val){
		pos++;
		for(;pos<=n;pos+=(pos&(-pos))){
			arr[pos]+=val;
		}
	}
	lld query(int pos){
		pos++;
		lld ans=0;
		for(;pos>0;pos-=(pos&(-pos))){
			ans+=arr[pos];
		}
		return ans;
	}
};
FT F;
int n;
int main() {
	n=10;
	F.init(n);
	F.update(0,1);
	F.update(1,2);
	F.update(2,-1);
	cout<<F.query(1)<<endl;
	return 0;
}
