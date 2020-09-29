//# knightL-on-a-chessboard
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<utility>
#include<queue>
using namespace std;
vector<int>a[25];
void func(int n)
    {
    for(int i=0;i<n;i++)
      a[i].resize(n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         a[i][j]=0;
           
}
void dfs(int k,int l,int n)
{
     int p=n*n;
     vector<bool>visit(p);
     vector<int>dist(p);
     for(int i=0;i<p;i++)
         visit[i]=false;
     for(int i=0;i<p;i++)
          dist[i]=-1;
     visit[0]=true;
     dist[0]=0;
     queue<int>q;
     q.push(0);
    while(!q.empty())
        {
          int flag=0;
          int m=q.front();
          //cout<<m<<":";
          q.pop();
          int z[8];
          for(int i=0;i<8;i++)
              z[i]=-1;
          int x=m%n;
          int x1=m/n;
          int y=(m+1)%n;//cout<<x<<" "<<y<<endl;
          if(y)
            {
             if(l<(x1+1)*n-m)
             {
              z[1]=m-k*n+l; 
              z[3]=m+k*n+l; 
             }
            if(k<(x1+1)*n-m)
            {
             z[5]=m-l*n+k; 
             z[7]=m+l*n+k; 
            }
          }
          if(x)
          {
          if(l<=m-(x1)*n)
           {
          z[0]=m-k*n-l;
          z[2]=m+k*n-l;
          }
          if(k<=m-x1*n)
          {
          z[4]=m-l*n-k; 
          z[6]=m+l*n-k; 
          }
          }
          //cout<<z[0]<<" "<<z[1]<<" "<<z[2]<<" "<<z[3]<<" "<<z[4]<<" "<<z[5]<<" "<<z[6]<<" "<<z[7]<<" "<<endl;
           for(int i=0;i<8;i++)
               {
                if((z[i]>0)&&(z[i]<p))
                    {
                      dist[z[i]]=dist[m]+1;
                      if(z[i]==(p-1))
                          {flag=1;
                           break;}
                       else if(!visit[z[i]])
                           {
                           visit[z[i]]=true;
                           q.push(z[i]);
                         
                       }
                }
                    
           }
        if(flag)break;
    }
   a[k][l]=dist[p-1];
   a[l][k]=dist[p-1];
   cout<<dist[p-1]<<" ";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
     func(n);
     for(int i=1;i<n;i++)
         for(int j=1;j<n;j++)
           a[i][j]=0;
         a[1][1]=n-1;
         a[n-1][n-1]=1;//dfs(1,4,5);
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)
            {
              if(a[i][j]!=0)
                  {
                   cout<<a[i][j]<<" ";
              }
             else 
              {
                  dfs(i,j,n);
             }
        }
        cout<<endl;
    }
           
    return 0;
}
