#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>




typedef long long int ll ;
const int maxn = 2001 ;
int w[maxn][maxn] ;
std::vector<std::pair<int,int>>g[maxn] ;
int parent[maxn] ;
std::vector<std::pair<int,std::pair<int,int> > >st ;


void preprocess( int n )
{
	 for(int i = 0 ; i < n ; i++ )
	 {
	 	 parent[i] = i ;
	 }
}
int f_parent(int n) { return n == parent[n] ? n : parent[n] = f_parent(parent[n]); }
void dfs(int u , int papa , ll cost  , int Root)
{
	 if(cost != w[Root][u])
	 {
	 	 puts("NO");
	 	 exit(0) ;
	 }

	 for( auto &c:g[u])
	 {
	 	 int v = c.first ;
	 	 int w = c.second ;
	 	 if(w == 0 )
	 	 {
	 	 	puts("NO");
	 	 	exit(0);
	 	 }
	 	 if(v != papa)
	 	 {
	 	 	 dfs(v,u,cost + w , Root);
	 	 }
	 }
}


int main()
{

	 #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	 #endif 
	 int n ,  m ;
	 scanf("%d",&n) ;
	 for(int i = 0 ; i < n ; i++ )
	 {
	 	 for(int j = 0 ; j < n ; j++ )
	 	 {
	 	 	 scanf("%d",&w[i][j]);
	 	 	 if(j < i )
	 	 	 st.push_back({w[i][j],{i,j}});
	 	 }
	 }
	 preprocess(n);
	 std::sort(st.begin() ,st.end());
	 int size = st.size();
	 for(int i = 0 ; i < size  ; i ++ )
	 {
	 	  int u = st[i].second.first ;
	 	  int v = st[i].second.second ;
	 	  int w = st[i].first ;
	 	  int p1 = f_parent(u) ; 
	 	  int p2 = f_parent(v) ;
	 	  if(  p1 != p2 )
	 	  {
             parent[p1] = p2 ;
             g[u].push_back({v,w}) ;
             g[v].push_back({u,w});
	 	  }
	 }

	for(int i = 0 ; i < n ; i++ )
	 {
	 	 dfs(i,-1, 0 , i);
	 }
	 puts("YES");
	 
}
