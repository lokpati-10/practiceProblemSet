//# Sherlock-and-Coast
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    int a1_1,a1_b,ab_1,ab_b;
    cin>>t;
    int n;
    while(t--)
        {
            cin>>n;
            vector<int>b(n);
            for(int i=0;i<n;i++)
                cin>>b[i];
           a1_1=0;a1_b=0;ab_1=0;ab_b=0;//base case when n==1;
            for(int i=1;i<n;i++)  //each iteration indicates the ith gap which is inbetween b[i-1] and b[i] elements;
                {/* for  i_th  gap there is only four possibility
                  (1) b[i-1]=1 and b[i]=1 i.e a1_1 case;
                  (2) b[i-1]=1 and b[i]=b[i] i.e a1_b case;
                  (3) b [i-1]=b[i-1] and b[i]=b[i] i.e ab_b case;
                  (4) b [i-1]=b[i-1] and b[i]=b1 i.e ab_1 case;
                   because optimal maximal can be only obtained when each element a[i] is either equal to b[i] or 1;
                  */
                  /*
                   case 1:
                    now suppose for i_th gap b[i-1]=1 and b[i]=1 is optimal case then previous gap can be only of two type
                    (a) b[i-2]=b[i-2] and b[i-1]=1;//elemnt of gap before ith gap i.e of ab_1 type ;
                    (b) b[i-2]=1 and b[i-1]=1; //element of previous gap before ith gap i.e of a1_1 type;
                    now for maximal case  we can select max(ab_1,a1_1) i.e max(case a, case b) and add 0 in it because it is b[i]
                    -b[i-1]=0; i.e 1-1=0;
                    and hence we store it in the variable y1_1 and after all posibilty we update a1_1 by y1_1;
                   */
                    
                    
                  int y1_1=max(a1_1,ab_1);   //case 1
                  /*
                   case 2:
                    now suppose for i_th gap b[i-1]=1 and b[i]=b[i] is optimal case then previous gap can be only of two type
                    (a) b[i-2]=b[i-2] and b[i-1]=1;//elemnt of gap before ith gap i.e of ab_1 type ;
                    (b) b[i-2]=1 and b[i-1]=1; //element of previous gap before ith gap i.e of a1_1 type;
                    noe for maximal case  we can select max(ab_1,a1_1) i.e max(case a, case b) and add abs(b[i]-b[i-1]) 
                    and hence we store it in the variable y1_b and after all posibilty we update a1_1 by y1_b;
                   */
                  int y1_b=max(ab_1,a1_1)+b[i]-1;//case 2
                  /*
                   case 3:
                    now suppose for i_th gap b[i-1]=b[i-1] and b[i]=1 is optimal case then previous gap can be only of two type
                    (a) b[i-2]=b[i-2] and b[i-1]=b[i-1];//elemnt of gap before ith gap i.e of ab_b type ;
                    (b) b[i-2]=1 and b[i-1]=b[i-1]; //element of previous gap before ith gap i.e of a1_b type;
                    noe for maximal case  we can select max(ab_b,a1_b) i.e max(case a, case b) and add abs(b[i]-b[i-1] in it 
                    and hence we store it in the variable yb_1 and after all posibilty we update ab_1 by yb_1;
                   */
                  int  yb_1=max(a1_b,ab_b)+b[i-1]-1;//case 3
                   int yb_b=max(ab_b,a1_b)+abs(b[i]-b[i-1]);//case 4;
                   a1_1=y1_1;a1_b=y1_b;ab_1=yb_1;ab_b=yb_b;//updation of old values by new one becase for each gap we only have
                   //need of previous gap 
              }
        int max=a1_b;//select max from ab_1,a1_1,ab_b,a1_b
        if(ab_1>max)
            max=ab_1;
         if(ab_b>max)
             max=ab_b;
        cout<<max<<endl;
        
    }
    return 0;
}
