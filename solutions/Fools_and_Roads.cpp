#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
using namespace std ; 

typedef long long int ll ;

const int maxn = 1e5 + 5 ;
const int size = 21 ;

std::unordered_map<int,std::unordered_map<int,int> > g ;
int parent[maxn][size] ;
int  h[maxn] , E[maxn] , node[maxn];
void dfs(int u , int papa)
{
	 //cout<<u<<" "<<papa<<endl;
	 parent[u][0] = papa;
	 for(int i = 1;  i < 21 ; i++ )
	 {
	 	 if(parent[u][i-1] == 0 )break ;
	 	 parent[u][i] = parent[parent[u][i-1]][i-1] ;
	 }
	 for(auto &c:g[u] )
	 {
	 	 int v = c.first ;
	 	 int w = c.second ;
	 	 if(v == papa )continue ;
	 	 h[v] = h[u] + 1 ;
	 	 dfs(v,u);
	 }
}

void dfs1(int u , int papa)
{
	for(auto &c:g[u] )
	{
		 int v = c.first ;
		 if(v == papa )continue ;
		 dfs1(v,u) ;
		 int ed = c.second ;
		 E[ed] += node[v] ;
		 node[u]+=node[v] ; 
	}
}


int lca ( int u , int v )
{

	 if(h[u] > h[v])
	 {
	 	 int temp  = u ;
	 	 u = v ;
	 	 v = temp ;
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
	 if(v == u )
	 {
	 	 return  u ;
	 }

	 for(int i = 20 ; i >= 0 ; i--)
	 {
	 	 if(parent[u][i] != parent[v][i])
	 	 {
	 	 	 v = parent[v][i] ;
	 	 	 u = parent[u][i] ;
	 	 }
	 }
	 return parent[u][0] ;
}


int main()

{

	#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n ;
	cin >> n ;
	for(int i =1 ; i < n ; i++ )
    {
		 int x , y ;
		 cin >> x >> y ;
		 g[x][y] = i ;
		 g[y][x] = i ;
	}
    dfs(1,0) ;
	int k ;
	cin >> k ;
   while(k--)
	{
		 int u , v ;
		 cin >> u >> v ;
		 int p = lca(u,v) ;
		 node[u] += 1 ;
		 node[v] += 1 ;
		 node[p] -= 2 ;
		 
	}
	dfs1(1,0);
	for(int i = 1;  i < n ; i++ )
	{
		cout<<E[i]<<" ";
	}cout<<endl;
}

