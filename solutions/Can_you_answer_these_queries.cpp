#include <iostream>
#include <stdio.h>
#include <string>

typedef long long int ll ;

inline ll Max(ll a, ll b )
{
      if(a > b ) return a ;
      return b ;
}
inline ll Min(ll a , ll b )
{
     if( a < b ) return a ;
     return b ;
}

const int maxn = 30002 ;
const int tsize = 4 * maxn ;
const ll inf = -1e17 ;


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


struct data 
{
   ll sum , presum , suffsum , maxsum ;
};

data tree[tsize];
ll   a[maxn] ;

data makedata(int val )
{
  data New ;
  New.sum = New.presum = New.suffsum = New.maxsum = val ;
  return New ;

}

data merge(data l , data r )
{
     data New ;
     New.sum = l.sum + r.sum ;
     New.presum = Max(l.presum , l.sum + r.presum );
     New.suffsum= Max(r.suffsum , r.sum + l.suffsum );
     New.maxsum = Max(Max(l.maxsum,r.maxsum),l.suffsum + r.presum );
     return New ;
}


void build(int si , int l , int r )
{

     if(l > r )return ;
     if(l == r )
     {
         tree[si] = makedata(a[l]) ;
         return ;
     }
     int mid = ( l + r ) / 2 ;

     build(si*2+1 , l , mid ) ;
     build(si*2+2, mid+1, r );
     tree[si] = merge(tree[si*2+1],tree[si*2+2]);
} 

data querry(int si , int l , int r , int sl , int sr )
{
     
     if(l > r || sl > sr  ) return makedata(inf);
     if( l == sl && r == sr )
     {
         return tree[si];
     }

     int mid = (l+r)/2 ;

     return merge(querry(si*2+1,l,mid,sl,Min(sr,mid)) , querry(si*2+2,mid+1,r,Max(mid+1,sl),sr));
}

void update

int main()
{

      int t ;
      cin >> n ;

     int n ;
     scanf("%d",&n);

     for(int i = 0 ; i < n ; i++ )
     {
        scanf("%lld", &a[i]) ;
     }

     build(1,0,n-1) ;
     int m ;
     scanf("%d",&m) ;
     while(m--)
     {
         int  x , y ;
         scanf("%d %d",&x,&y);
         x--;y--;
         ll ans = querry(1,0,n-1,x,y).maxsum ;
         printf("%lld\n",ans);

     }
     return 0 ;
 }
