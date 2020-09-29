#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
typedef long long int ll ;

const int maxn = 30002 ;
const int tsize = 4 * maxn ;
const ll inf = -1e17 ;

struct data  
{
    std::vector<int>a;
    ll ans  ;

};

data tree[tsize] ;
int aa[maxn];
int n ;

data merge(int l , int r )
{

     std::vector<int>result ;
     int size1 = tree[l].a.size(), i , j ;
     int size2 = tree[r].a.size();
     ll ans = 0 ;

     for(i = 0 , j = 0 ; i < size1 && j < size2 ; )
     {
         int p = tree[l].a[i] , q = tree[r].a[j] ;
         if(p <= q )
         {
            result.push_back(p);
            i++;
         }
         else 
         {
            ans+=(size1-i) ;j++;
            result.push_back(q);

         }
     }
     while(i < size1 )
     {
        result.push_back(tree[l].a[i]);
        i++;
     }
     while(j < size2 )
     {
         result.push_back(tree[r].a[j]);
         j++;
     }
     data New ;
     New.ans = ans + tree[l].ans + tree[r].ans;
     New.a = result ;
    // std::cout<<New.ans<<"\n";
     return New;

}


void build(int si , int l , int r )
{
     if(l > r )return ;
     if(l == r)
     {
        tree[si].ans = 0 ;
        tree[si].a.push_back(aa[l]);
        return ;
     }
     int mid = (l+r) / 2 ;
     build(si*2+1,l,mid);
     build(si*2+2,mid+1,r);
    tree[si] = merge(si*2+1,si*2+2);
}

int main()
{
      int t ;
      scanf("%d",&t);
      while(t--)
      {

         scanf("%d",&n) ;
         std::string a[n+1] ;
         std::unordered_map<std::string,int>index;
         for(int i = 0 ; i <= 4*n ; i++ )
         {
            tree[i].a.clear();
            tree[i].ans = 0 ;
         }

         for(int i = 0 ; i < n ; i++ )
         {
             std::cin>>a[i];
         }
         for(int i = 0 ; i <  n ; i++ )
         {
             std::string ss ;
             std::cin>>ss;
             index[ss] = i ;

         }
         for(int i = 0 ; i < n; i++ )
         {
             aa[i] = index[a[i]];
         }
         build(0,0,n-1);
         std::cout<<tree[0].ans<<"\n";
      }
 }
