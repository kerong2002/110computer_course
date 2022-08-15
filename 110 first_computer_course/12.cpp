#include<algorithm>
#include <iostream>
using namespace std;
int o,N,i,j, k,s,x;
int main(){
    while (1){
        cin>>o;
        cin>>N;
        if(N>0 and o>=1 and o<=26){	   
            for (i = 1; i < 2 * N; i++){
                for (j = 1; j < 2 * N; j++){
					x=min(abs(N-i),abs(N-j));
                    k=x;				
	            	if(N>o){
	                	s=k%o;
	              	}
	              	else if (N<=o){
	              		s=k;
					}
					s=s+65;
	             	cout<<char(s);
	            }
	            cout <<endl;
            }
        }
        else{
        	break;
		}
    }
    return 0;
}
