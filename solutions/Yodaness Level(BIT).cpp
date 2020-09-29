#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
//using namespace std ;
typedef long long int ll ;

const int maxn = 30002 ;
const int tsize = 4 * maxn ;
const ll inf = -1e17 ;
ll Bit[maxn] ;
int n ;


void update(int index , int val )
{
     for( ; index  < n + 2 ; index += (index & -index) )
     {
         Bit[index] += val ;
     }
}

ll sum(int index )
{
     ll ans = 0 ;
     for( ; index > 0 ; index-=(index & -index ) )
     {
         ans += Bit[index];
     }
     return ans ;
}



int main()
{

      
      int t ;
      scanf("%d",&t);
      while(t--)
      {

         scanf("%d",&n) ;
         std::string a[n+1] ;
         for(int i = 0 ; i <= n+1 ; i++ )Bit[i] = 0 ;
         std::unordered_map<std::string,int>index;
         for(int i = 1 ; i <= n ; i++ )
         {
             std::cin>>a[i];
         }
         for(int i = 1 ; i <= n ; i++ )
         {
             std::string ss ;
             std::cin>>ss;
             index[ss] = i ;

         }
         
         ll ans = 0 ;
         for(int i = n ; i >= 1 ; i-- )
         {
             
             ans = ans + sum(index[a[i]]-1);
             update(index[a[i]],1);
         }
         printf("%lld\n",ans);
      }
 }
