#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  	int a,b,c,d;
    for(int i = 0;i<3;i++){
    	cin>>a>>b>>d;
    	c = a%b;
    	while( c > 0 ){
        	a = b;
        	b = c;
        	c = a%b;
    	}
    	a = d;
    	c = a%b;
    	while( c > 0 ){
        	a = b;
        	b = c;
        	c = a%b;
    	}
    	cout<<b<<endl;
	}
    
	
	return 0;
} 
