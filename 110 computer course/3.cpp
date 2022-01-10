#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int z[4]={0,0,0,0};
     for(int y=0;y<5;y++)
    { 
         for(int i=0;i<4;i++){
             cin>>z[i];
         }
        sort(z+1,z+4);
        if(z[0]==0)
        {     
            cout<<z[1]<<endl;
        }
        if(z[0]==1)
        {
            sort(z+1,z+4);
            cout<<z[3]<<endl;

        }
    }
    return 0;
}
