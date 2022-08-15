#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C,N,count,multiply;
    cin>>N;
    for(int y=0;y<N;y++)
    { 
    	cin>>A>>B>>C;
    	if(A==1){
    		count = 0;
    		if(B>C){
    			B=B^C;
    			C=B^C;
    			B=B^C;
			}
    		while(B<=C){			
        		count=count+B;
        		B=B+1;
    		}
    		cout<<count<<endl;
		}
		else if(A==2){
			multiply=1;
			if(B>C){
    			B=B^C;
    			C=B^C;
    			B=B^C;
			}
			while(B<=C){			
        		multiply=multiply*B;
        		B=B+1;
    		}
    		cout<<multiply<<endl;
		}
    }
    return 0;
}
