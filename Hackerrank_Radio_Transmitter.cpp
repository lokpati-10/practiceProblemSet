# Hackerrank-Radio-Transmitters
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int>d(n);
    for(int i=0;i<n;i++)
         cin>>d[i];
     int sum=0;
    sort(d.begin(),d.end());//sort the houses according to their position;
    //find the best place for planting the tower and ignore all the house which come in range of this range 
    //iterate this upto nth house ;
    // if the left gap and right gap of house is greater than k it must have tower on it's roof .
     for(int i=0;i<n;i++)
          {
             if(d[i+1]-d[i]>k && i+1< n)
             {
             sum++;//if distance between the current house and next house is greater than range it must have tower on it's roof
               continue;
             }
              int limit=0,j,m;//if the gap is less than range find the sutable roof where tower will be planted;
              for( j=i+1;j<n;j++)
                   {
                       limit=limit+d[j]-d[j-1];
                       if(limit>k)
                        {
                         // j-1 th house is best house where tower can be planted;
                            break;
                            }
              }
          // j-1 the house will be the appropriate house where tower will planted because it will cover all the house from the 
         // ith to (j-1)the house ;
         //NOW  ignore  all the house which is next (j-1)th house and come in range of tower which is at (j-1)th house ; 
          limit=0;
        for(m=j;m < n ;m++)
              {
               limit=limit+d[m]-d[m-1];
                if(limit>k)
                  {
                    //jth house is out of range;
                     break;
                     }
          }
         sum++;
         // Now finally from i to m-1 we need only one tower which is at (j-1)the house 
           i=m-1;//jump the value of  to the last house  in right of tower which is in range of tower.
     }
    
    cout<<sum;
    return 0;
}
