#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
using namespace std;
int segtree[200000];
void Build(int node, int a, int b){//cout<<a<<" "<<b<<endl;
	if(a==b){
		segtree[node]=1;
		return;
	}
	int mid=(a+b)/2;
	Build(2*node,a,mid);
	Build(2*node+1,mid+1,b);
	segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}
void build(int n){
	Build(1,0,n-1);
}
int query(int x, int y,int a, int b, int node){
	//cout<<a<<" "<<b<<endl;
	if(x<=a && b<=y){
		return segtree[node];
	}
	if(y<a || b<x)return 10000;
	int mid=(a+b)/2;
	int p1=query(x,y,a,mid,2*node);
	int p2=query(x,y,mid+1,b,2*node+1);
	return min(p1,p2);
}
int Query(int x, int y,int n){
	return query(x,y,0,n-1,1);
}
void update(int a, int b, int node, int x, int y){
	if(x<a || b<x)return;
	if(a==b){
		segtree[node]=y;
		return;
	}
	int mid=(a+b)/2;
	update(a,mid,2*node,x,y);
	update(mid+1,b,2*node+1,x,y);
	segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}
void Update(int x, int y, int n){
	update(0,n-1,1,x,y);
}
int main(){
	int l,c,d;
	scanf("%d %d %d",&l,&c,&d);
	char area[l*c];
	int towers=0;
	for(int i=0;i<l;i++){
		char s[c];
		scanf("%s",s);
		for(int j=0;j<c;j++){
			area[i*c+j]=s[j];
			if(s[j]=='T')towers++;
		}
	}
	int dist[l*c];
	for(int i=0;i<l*c;i++){
		dist[i]=1000000;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >dijkstra;
	int components[l*c];
	int color=1;
	for(int i=0;i<l*c;i++)components[i]=0;
	for(int i=0;i<l*c;i++){
		if(area[i]=='T' && components[i]==0){
		dist[i]=0;
		//queue<int> visited;
		dijkstra.push(pair<int,int>(0,i));
		components[i]=color;
		while(!dijkstra.empty()){
			pair<int,int> node=dijkstra.top();dijkstra.pop();
			int cell=node.second;int dd=node.first;
			//cout<<cell<<" "<<dd<<" "<<color<<endl;
			
			//visited.push(cell);
			if(dd>dist[cell])continue;
			if(dist[cell]>=d)continue;
			if(cell<l*c-c){
				int vizinho=cell+c;
				if(dist[vizinho]>1+dist[cell] && area[vizinho]!='#'){
					dist[vizinho]=1+dist[cell];
					if(area[vizinho]=='T'){
						dist[vizinho]=0;components[vizinho]=color;
					}
					dijkstra.push(pair<int,int>(dist[vizinho],vizinho));
				}
			}
			if(cell>=c){
				int vizinho=cell-c;
				if(dist[vizinho]>1+dist[cell] && area[vizinho]!='#'){
					dist[vizinho]=1+dist[cell];
					if(area[vizinho]=='T'){
						dist[vizinho]=0;components[vizinho]=color;
					}
					dijkstra.push(pair<int,int>(dist[vizinho],vizinho));
				}
			}
			if(cell%c!=0){
				int vizinho=cell-1;
				if(dist[vizinho]>1+dist[cell] && area[vizinho]!='#'){
					dist[vizinho]=1+dist[cell];
					if(area[vizinho]=='T'){
						dist[vizinho]=0;components[vizinho]=color;
					}
					dijkstra.push(pair<int,int>(dist[vizinho],vizinho));
				}
			}
			if((cell+1)%c!=0){
				int vizinho=cell+1;
				if(dist[vizinho]>1+dist[cell] && area[vizinho]!='#'){
					dist[vizinho]=1+dist[cell];
					if(area[vizinho]=='T'){
						dist[vizinho]=0;components[vizinho]=color;
					}
					dijkstra.push(pair<int,int>(dist[vizinho],vizinho));
				}
			}
		
		}color++;
		/*while(!visited.empty()){
			dist[visited.front()]=1000000;
			visited.pop();
		}*/
		}
		
	}
	/*for(int i=0;i<l*c;i++){if(i%c==0)cout<<endl;
		cout<<dist[i]<< " ";
	}*/
	/*for(int i=0;i<l*c;i++){if(i%c==0)cout<<endl;
		cout<<components[i]<< " ";
	}*/
	pair<int,int> towersper[towers];
	int count=0;
	for(int i=0;i<l*c;i++){
		if(components[i]>0){
			towersper[count]=pair<int,int>(components[i],count);
			count++;
		}
	}
	sort(towersper,towersper+towers);
	//for(int i=0;i<towers;i++)cout<<towersper[i].second<<" ";
	int invper[towers];
	for(int i=0;i<towers;i++){
		invper[towersper[i].second]=i;
	}
	long long int Cost=0;
	build(towers);
	int n=towers;
	int Q;
	scanf("%d",&Q);
	int begin[color-1];
	int end[color-1];
	for(int i=0;i<n;i++){
		if(towersper[i].first>0)end[towersper[i].first-1]=i;
	}
	for(int i=n-1;i>-1;i--){
		if(towersper[i].first>0)begin[towersper[i].first-1]=i;
	}
	for(int i=0;i<color-1;i++){
		//cout<<begin[i]<<" "<<end[i]<<endl;
		Cost+=Query(begin[i],end[i],n);
	}
	//cout<<Cost<<endl;
	while(Q--){
	int tower,cost;
	scanf("%d %d",&tower,&cost);
	tower=invper[tower-1];
	int antigo=Query(begin[towersper[tower].first-1],end[towersper[tower].first-1],n);
	Update(tower,cost,n);
	int novo=Query(begin[towersper[tower].first-1],end[towersper[tower].first-1],n);
	//cout<<begin[towersper[tower].first-1]<<" "<<end[towersper[tower].first-1]<<endl;
	//cout<<antigo<<" "<<novo<<endl;
	Cost+=novo-antigo;
	printf("%lld\n",Cost);
	
	}
	return 0;
	
}
