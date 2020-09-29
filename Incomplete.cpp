}
#include <vector>
#include <stdio.h>


typedef long long int ll ;
const int maxn = 2e4;
const int  tsize = 8e4;
ll a[maxn] ;
ll tree[tsize];

inline ll max(ll a, ll b )
{
    if(a > b )return a ;
    return b ;
}
inline ll min(ll a , ll b )
{
    if(a < b ) return a ;
    return b ;
}

void build(int si , int l , int r )
{
    if(l > r ) return ;
    if( l == r )
    {
        tree[si] = a[l] ;
        return ;
    }
    int mid = (l+r)/2 ;
    int left = si * 2 + 1;
    int right = si * 2 + 2;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[si] = tree[left] & tree[right] ;
}

ll query(int si , int l , int r , int sl , int sr )
{
    if(sl > sr || l  > r ) 
    {
        return - 1 ;
    }
    if( l == sl && r == sr )
    {
        return tree[si];
    }
    int mid = (l  + r ) / 2 ;
    int leftq = query(si*2+1,l,mid,sl,min(mid,sr));
    int rightq = query(si*2+2,mid+1,r,max(sl,mid+1),sr);
    if(leftq == -1 && rightq == -1 ) return -1 ;
    if(leftq == -1 ) return rightq ;
    if(rightq == -1 ) return leftq ;
    return leftq & rightq ;
}

int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
         int n , k ;
         scanf("%d %d",&n,&k);
        for(int i = 0 ; i < n  ; i++ )
        {
            scanf("%lld",&a[i]);
        }
        if(k >= n-2 )
        {
            ll leftsum = a[0];
            for(int i = 1 ; i< n ;i++ )
            {
                leftsum = leftsum &  a[i];
            }
             for(int i = 0 ; i < n ; i++ )
            {
                printf("%lld ",leftsum);
            }printf("\n");
        }
        else 
        {
            build(0,0,n-1);
            ll ans = 0 ;
            for(int i = 0 ; i< n ;i++)
            {
               int l1 = ( i - k + n ) % n ;
               int r1 = (i+k)%n;
                ans = 0 ;
               if(l1 > i )
               {
                   ans = query(0,0,n-1,0,i) & query(0,0,n-1,l1,n-1);
               }
               else 
               {
                   ans = query(0,0,n-1,l1,i);
               }
               if(r1 < i ) 
               {
                    ans = ans & query(0,0,n-1,0,r1) & query(0,0,n-1,i,n-1) ;
               }
                else 
                {
                    ans = ans & (query(0,0,n-1,i,r1));
                }
                a[i] = ans ;
            }
            for(int i = 0 ; i < n ; i++ )
            {
                printf("%lld ",a[i]);
            }printf("\n");
        }
        
        
    }
}
