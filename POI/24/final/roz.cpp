#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a:v)
int n,m;
int edge[1000000][2];
int parity[1000000];
int num[1000000];
lld k;
vector<int> repl;
vector<pair<int,int> > tree[1000000];
class DSU{
	int p[1000000];
	int sz[1000000];
	public:
	void init(){
		rep(i,0,n){
			p[i]=i;
			sz[i]=1;
		}
	}
	int root(int x){
		if(p[x]==x)return x;
		p[x]=root(p[x]);
		return p[x];
	}
	bool merge(int a, int b){
		a=root(a);
		b=root(b);
		if(a==b)return false;
		if(sz[a]<sz[b])swap(a,b);
		sz[a]+=sz[b];
		p[b]=a;
		return true;
	}
};
DSU D;
bool visited[1000000];
vector<int> ET;
int L[1000000];
int R[1000000];
int vertex[1000000];
int prt[1000000];
void DFS(int node){
	visited[node]=true;
	L[node]=ET.size();
	ET.push_back(node);
	trav(a,tree[node]){
		if(!visited[a.first]){
			vertex[a.second]=a.first;
			//cout<<a.first<<" B "<<node<<endl;
			prt[a.first]=node;
			DFS(a.first);
		}
	}
	R[node]=ET.size()-1;
}
vector<int> acc[1000000];
void add(int node,int idx){
	//cout<<node<<" "<<idx<<endl;
	if(acc[node].size()==0 || acc[node][acc[node].size()-1]!=idx)acc[node].push_back(idx);
	else acc[node].pop_back();
	//acc[node].push_back(idx);
	if(node==0)return;
	add(prt[node],idx);
}
int FT[1000001];
void build(){
	rep(i,0,n+1)FT[i]=0;
}
void update(int x, int val){
	x++;
	for(;x<=n;x+=(x&(-x))){
		FT[x]+=val;
	}
}
int query(int x){
	x++;
	int ans=0;
	for(;x>0;x-=(x&(-x))){
		ans+=FT[x];
	}
	return ans;
}
int queryV(int x){
	return query(R[x])-query(L[x]-1);
}
int arr[60];
int LOG;
void modify(lld k){
	LOG=0;
	rep(i,0,60){
		if(k>0)LOG++;
		arr[i]=k%2;
		k/=2;
		
	}
}
int main() {
	cin>>n>>m;
	rep(i,0,m){
		rep(j,0,2){
			cin>>edge[i][j];
			edge[i][j]--;
		}
	}
	rep(i,0,n)cin>>parity[i];
	cin>>k;
	k--;
	modify(k);
	D.init();
	int cnt=0;
	rep(i,0,m){
		if(D.merge(edge[i][0],edge[i][1])){
			
			tree[edge[i][0]].push_back(pair<int,int>(edge[i][1],i));
			tree[edge[i][1]].push_back(pair<int,int>(edge[i][0],i));
			num[i]=-1;
		}else{
			num[i]=cnt;
			repl.push_back(i);
			cnt++;
		}
	}
	rep(i,0,n)visited[i]=false;
	DFS(0);
	rep(i,0,m){
		if(num[i]>=0 && num[i]<60){
			add(edge[i][0],num[i]);
			add(edge[i][1],num[i]);
		}
	}
	build();
	rep(i,0,n){
		update(L[i],parity[i]);
	}
	rep(i,0,m){
		//cout<<num[i]<<endl;
		if(num[i]==-1){
			//cout<<vertex[i]<<" "<<L[vertex[i]]<<endl;
			int ans=queryV(vertex[i])%2;
			rep(j,0,acc[vertex[i]].size()){
				//cout<<acc[vertex[i]][j]<<"B"<<endl;
				ans+=arr[acc[vertex[i]][j]];
			}
			ans%=2;
			cout<<ans<<" ";
		}else{
			if(num[i]<60)cout<<arr[num[i]]<<" ";
			else cout<<0<<" ";
		}
	}
	cout<<endl;
	int q;
	cin>>q;
	while(q--){
		char c;
		cin>>c;
		if(c=='D'){
			int x;
			cin>>x;
			x--;
			//cout<<query(n-1)<<" ";
			//cout<<LOG<<" "<<repl.size()<<endl;
			if(LOG>repl.size())cout<<-1<<endl;
			else{
			if(query(n-1)%2!=0)cout<<-1<<endl;
			else{
				if(num[x]==-1){
				int ans=queryV(vertex[x])%2;
				rep(j,0,acc[vertex[x]].size()){
				//cout<<acc[vertex[i]][j]<<"B"<<endl;
					ans+=arr[acc[vertex[x]][j]];
				}
				ans%=2;
				cout<<ans<<endl;
				}else{
					if(num[x]<60)cout<<arr[num[x]]<<endl;
					else cout<<0<<endl;
				}
			}
			}
		}
		if(c=='M'){
			int x;
			cin>>x;
			x--;
			parity[x]++;
			update(L[x],1);
		}
		if(c=='K'){
			cin>>k;
			k--;
			modify(k);
		}
	}
	return 0;
}
