#include <iostream>
using namespace std;

int main (){
 	int x,y,z,k;
    for(int i = 0;i<3;i++){
    	k = 1;
    	cin>>x>>y>>z;
		while(1){
			if(k%x==0&k%y==0&k%z==0)
			break;
			else
			k++;
			cout<<k<<endl;
		} 
		cout<<k<<endl;   
	}
	return 0;
}
