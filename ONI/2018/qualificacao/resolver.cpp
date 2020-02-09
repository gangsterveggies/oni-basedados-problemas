/*
  Modifica este ficheiro para fazer a tua solucao do Problema D.

  Nao modifiques mais nenhum ficheiro.
*/

#include "avaliador.h"

int min(int a, int b){
	if(a<b)return a;
	return b;
}
int resolver(int N, int Q)
{
	int index=1;
	int k=0;
	while(index<=N){	
		int lo=index;	
		int h2;	
		int hi=min(N+1,index+(1<<14)-1);	
		h2=hi;
		while(hi-lo>1){
			int mid=(lo+hi)/2;
			if(comparar(index,mid)){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		if(hi==h2 && hi!=N+1){
			if(comparar(index,h2)){
				index=hi;
			}else{
				index=hi;
				k++;
			}
		}else{
			index=hi;
			k++;
		}
	}
	
	return k;

}
/*
  Modifica este ficheiro para fazer a tua solucao do Problema D.

  Nao modifiques mais nenhum ficheiro.
*/
/*
#include "avaliador.h"
int solve(int a, int b){
	if(comparar(a,b))return 1;
	int mid=(a+b)/2;
	int p1=solve(a,mid);
	int p2=solve(mid+1,b);
	if(comparar(mid,mid+1))p2--;
	p2+=p1;
	return p2;
}
int resolver(int N, int Q)
{
	return solve(1,N);
}
*/
