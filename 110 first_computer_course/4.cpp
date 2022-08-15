#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int z[10];
    int x;
     for(int y=0;y<3;y++)
    { 
    	 x=0;
         for(int i=0;i<9;i++){
             cin>>z[i];
         }
         sort(z,z+9);
        for(int i=0;i<9;i++){
        	x=x+z[i];
        }
        
        cout<<x<<" "<<z[4]<<endl;
    }
    return 0;
}
