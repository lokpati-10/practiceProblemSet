#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
using namespace std ; 

typedef long long int ll ;

const int maxn = 1e5 + 5 ;
const int size = 21 ;

std::unordered_map<int,std::unordered_map<int,int> > g ;
int parent[maxn][size], mini[maxn][size], maxi[maxn][size];
int  h[maxn];
int Maxi , Mini ;

void dfs(int u , int papa)
{
	 parent[u][0] = papa;
	 for(auto &c:g[u] )
	 {
	 	 int v = c.first ;
	 	 int w = c.second ;
	 	 if(v == papa )continue ;
	 	 h[v] = h[u] + 1 ;
	 	 maxi[v][0] = w ;
	 	 mini[v][0] = w ;
	 	 dfs(v,u);
	 }
}


void lca ( int u , int v )
{

     Mini = (1e9 + 1)*1LL , Maxi = -1*1LL ;
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
	 	 	 Mini = min(Mini,mini[v][i]);
	 	 	 Maxi = max(Maxi,maxi[v][i]) ;
	 	 	 v = parent[v][i] ;
	 	 	 diff = diff - (1 << i) ;
	 	 }
	 }
	 if(v == u )
	 {
	 	 if(Mini == 1e9+1 and Maxi == -1 )
	 	 {
	 	 	 Mini = Maxi = 0 ;
	 	 }
	 	 return ;
	 }

	 for(int i = 20 ; i >= 0 ; i--)
	 {
	 	 if(parent[u][i] != parent[v][i])
	 	 {
	 	 	 int mini1 = mini[v][i] , mini2 = mini[u][i] ;
	 	 	 int maxi1 = maxi[v][i] , maxi2 = maxi[u][i] ;
	 	 	 Maxi = max(Maxi,max(maxi1,maxi2));
	 	 	 Mini = min(Mini,min(mini1,mini2));
	 	 	 v = parent[v][i] ;
	 	 	 u = parent[u][i] ;
	 	 }
	 }
	 Maxi = max(Maxi,maxi[u][0]);
	 Maxi = max(Maxi,maxi[v][0]);
	 Mini = min(Mini,mini[u][0]);
	 Mini = min(Mini,mini[v][0]);

}


void preprocess(int n )
{
	for(int j = 1 ; j < 21 ; j++ )
	{
		 
		 for(int i = 2; i <= n ; i++ )
		 {
		 	 if(parent[i][j-1] > 1  )
		 	 {
		 	 	 parent[i][j]= parent[parent[i][j-1]][j-1] ;
		 	 	 maxi[i][j] = max(maxi[i][j-1],maxi[parent[i][j-1]][j-1]) ;
		 	 	 mini[i][j] = min(mini[i][j-1],mini[parent[i][j-1]][j-1]);
		 	 }
		 }
	}
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
		 int x , y , w ;
		 cin >> x >> y >> w ;
		 g[x][y] = w ;
		 g[y][x] = w ;
	}
    dfs(1,0) ;
    preprocess(n);
	int k ;
	cin >> k ;
	while(k--)
	{
		 int u , v ;
		 cin >> u >> v ;
		 lca(u,v) ;
		 cout << Mini <<" "<< Maxi <<endl ; 
	}
}

