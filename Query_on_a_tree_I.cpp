https://www.spoj.com/problems/QTREE2/
#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
using namespace std ; 

typedef long long int ll ;

const int maxn = 1e4 + 5 ;
const int size = 16 ;

std::unordered_map<int,std::unordered_map<int,int> > g ;
int parent[maxn][size];
int  h[maxn];
ll dist[maxn] ;

void dfs(int u , int papa)
{
	 parent[u][0] = papa;
	 for(int i = 1 ; i < 16 ; i++ )
	 {
	 	 if(parent[u][i-1]!=0)
	 	 {
	 	 	 parent[u][i] = parent[parent[u][i-1]][i-1];
	 	 }
	 }

	 for(auto &c:g[u] )
	 {
	 	 int v = c.first ;
	 	 int w = c.second ;
	 	 if(v == papa )continue ;
	 	 h[v] = h[u] + 1 ;
	 	 dist[v] = dist[u] + w ;
	 	 dfs(v,u);
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

	 for(int i = 15 ; i >= 0 ; i-- )
	 {
	 	 if( diff >= (1 << i) )
	 	 {
	 	 	 v = parent[v][i] ;
	 	 	 diff = diff - (1 << i) ;
	 	 }
	 }
	 if(v == u )return u ;

	 for(int i = 15 ; i >= 0 ; i--)
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

void test()
{

	int n ;
	 scanf("%d",&n);
	 for(int i = 1 ; i < n  ; i ++ )
	 {
	 	 int x ,y , w ;
	 	 scanf("%d %d %d",&x,&y,&w);
	 	 g[x][y] = w ;
	 	 g[y][x] = w ;
	 }
     dfs(1,0);

	while(true)
	 {
	 	 std::string type ;

	 	 int r , u ,v , sum  ;
	 	 std::cin >> type;
	 	 if(type == "DONE")
	 	 {
	 	 	 break;
	 	 }
	 	 scanf("%d %d",&u,&v);
	 	 int Lca = lca(u,v);
	 	 if(type == "DIST")
	 	 {
	 	 	 ll Dist = dist[u] + dist[v] - 2 * dist[Lca];
	 	 	 printf("%lld\n",Dist);
	 	 }
	 	 else 
	 	 {
	 	 	 scanf("%d",&r);
             int diff = h[u] - h[Lca] ;
             if(diff+1 >= r )
             {
             	 diff = r - 1  ;
             	 for(int k = 15 ; k >= 0 ; k-- )
             	 {
             	 	  int dis = int(1 << k );
             	 	  if(dis <= diff )
             	 	  {
             	 	  	 u = parent[u][k] ;
             	 	  	 diff = diff - dis ;
             	 	  }
             	 }
             	 printf("%d\n",u);
             }
             else 
             {
             	int left = r - (diff + 1 );
             	int down = (h[v] - h[Lca] + 1 ) - (left+1) ;
             	diff = down;
             	for(int k = 15 ; k >= 0 ; k-- )
             	{
             		 int dis = int(1 << k );
             		 if(dis <= diff )
             		 {
             		 	 v = parent[v][k] ;
             		 	 diff -= dis ;
             		 }
             	}
             	printf("%d\n",v);
             }
	 	 }
	 	 
	 }
	for(int i = 0 ; i <= n ; i++ )
	 {
	 	 g[i].clear();
	 	 h[i] = 0 ;
	 	 dist[i] = 0 ;
	 	 for(int j = 0 ; j < 16 ; j++ )
	 	 {
	 	 	 parent[i][j] = 0 ;
	 	 }
	  }
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	 
	int t ;
	scanf("%d",&t);
	while(t--)
	{
		test();
	}
}
