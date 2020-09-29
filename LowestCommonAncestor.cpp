https://www.codechef.com/submit/complete/20341784
#include <bits/stdc++.h>

using namespace std ;

const int maxn = 2e5 + 5 ;

vector<int>g[maxn] ;
int parent[maxn][21];
int h[maxn];

void dfs(int u , int papa)
{
	 h[u] = h[papa] + 1 ;
	 parent[u][0] = papa;
	 for(int i = 1 ; i < 21 ; i++ )
	 {
	 	 if(parent[u][i-1]!=0)
	 	 {
	 	 	 parent[u][i] = parent[parent[u][i-1]][i-1];
	 	 }
	 }

	 for(int i = 0 ; i  < g[u].size() ; i++ )
	 {
	 	 int v = g[u][i] ;
	 	 if(v == papa )continue ;
	 	 dfs(v,u);
	 }
}

int lca ( int u , int v )
{
	 if(h[u] > h[v])
	 {
	 	 swap(u,v);
	 }

	 int diff = h[v] - h[u];

	 for(int i = 20 ; i >= 0 ; i-- )
	 {
	 	 if( diff >= (1 << i) )
	 	 {
	 	 	 v = parent[v][i] ;
	 	 	 diff = diff - (1 << i) ;
	 	 }
	 }
	 if(v == u )return u ;

	 for(int i = 20 ; i >= 0 ; i--)
	 {
	 	 if(parent[u][i] != parent[v][i])
	 	 {
	 	 	 v = parent[v][i] ;
	 	 	 u = parent[u][i] ;
	 	 }
	 }

	 return parent[u][0];
}

int caldis(int u , int v )
{
  int Lca = lca(u,v);
  return h[u] + h[v] - 2*h[Lca] ; 
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	 int n ;
	 cin >> n ;
	 for(int i = 1 ; i < n  ; i ++ )
	 {
	 	 int x ,y ;
	 	 cin >> x >> y ;
	 	 g[x].push_back(y);
	 	 g[y].push_back(x);
	 }
     dfs(1,0);
	 int q ;
	 cin >> q ;

	 while(q--)
	 {
	 	 int r , u ,v , sum  ;
	 	 cin >> r >> u >> v ;
	 	 int aa[] = {r,r,u};
	 	 int bb[] = {u,v,v};
	 	 sum = u + v + r ;
	 	 int dist = 1e9 , Lca = -1 ;
	 	 for(int i = 0 ; i < 3 ; i++ )
	 	 {
	 	 	 int dLca = lca(aa[i],bb[i]);
	 	 	 u = aa[i] ;
	 	 	 v = bb[i] ;
	 	 	 r = sum - (u+v) ;
	 	 	 int Distance = caldis(u,dLca) + caldis(v,dLca) + caldis(r,dLca);
	 	 	 if(Distance< dist)
	 	 	 {
	 	 	 	 dist = Distance;
	 	 	 	 Lca = dLca ;
	 	 	 }

	 	 }
	 	 cout<<Lca<<endl;
	 }
}
