/*
https://codeforces.com/contest/1153/problem/D?fbclid=IwAR3GlLRIbkZjAkY5W9TVZNvGBttjb8NdG_z-4moJ8QV19XqThncRgHjOg-o

*/

#include <bits/stdc++.h> 
using namespace std; 
#define int long long int 
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 3e5 + 5 ;
vector<int> g[N] ;
vector<int> child(N) ;
vector<int> operation(N) ;

int tchild = 0 , cnt = 0 ;

void dfs(int u )
{
      if(g[u].size() == 0 )
      {
           child[u] = 1; 
           tchild++;
           return ;
      }

      if(operation[u] == 0 )
      {
          for(auto & v : g[u])
          {
               dfs(v) ;
               child[u] += child[v] ; 
          }
      }
      else 
      {
          child[u] = 1e9 + 5 ;
          for(auto &v : g[u])
          {
             dfs(v) ;
             child[u] = min(child[u],child[v]) ;
          }
      }
}


int32_t main() 
{ 
  IOS;
  #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
  #endif 
  int n , x  ;
  cin >> n ;
  for(int i =1 ;i <= n ; i++ ) cin >> operation[i] ;
  for(int i = 2 ; i <= n ;i ++ )
  {
        cin >> x ;
        g[x].push_back(i) ;
  }

  dfs(1) ;
  cout<<tchild - child[1] +1 <<endl;
  
    return 0; 
} 
