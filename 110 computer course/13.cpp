#include<algorithm>
#include <iostream>
using namespace std;

int main(){
	int o,N,x,y;
    while (1){
        cin>>o>>N;
        if(N>0 and (o>=1 and o<=2)){
			if(o==1){
            	for (y = 1; y < 2*N; y++) {
                	for (x = 1; x < 2 * N; x++) {
                		if(x==N and y==N){
                			cout<<"*";
						}
						else if(y==1 or y==2*N-1){
							cout<<"-";
						}
						else if(x==1 or x==2*N-1){
							cout<<"|";
						}
						else if(x!=y and x<y and (x+y)<=(2*N-1)){
							cout<<"@";
						}
						else if(x!=y and x<y and(x+y)>=(2*N+1)){
							cout<<"%";
						}
						else if(x!=y and x>y and (x+y)<=(2*N-1)){
							cout<<"&";
						}
						else if(x!=y and x>y and (x+y)>=(2*N+1)){
							cout<<"$";
						}
						else if((abs(x-N)+abs(y-N))%2==0 and x==y){
							cout<<"\\";
						}
						else if((abs(x-N)+abs(y-N))%2==0 and  x!=y){
							cout<<"/";
						}


						else{
							cout<<"#";
						}
					}
					cout<<endl;
				}
			}
			if (o==2){
					for(int i=1;i<=N;i++){
						for(int j=0;j<=(3*N-1)-i;j++){
	     					printf("^");
						}
					for(int k=1;k<=2*i;k++){
						if(k%2==1){
							printf("*");
						}
						else{
							printf(" ");
						}
		  		
					}
					printf("\n");
					}
					for(int i=1;i<=2*N;i++){
						for(int j=0;j<=(3*N-1)-i;j++){
	     					printf("^");
						}
					for(int k=1;k<=2*i;k++){
						if(k%2==1){
							printf("*");
						}
						else{
							printf(" ");
						}
		  		
					}
					printf("\n");
					}
						for(int i=1;i<=3*N;i++){
						for(int j=0;j<=(3*N-1)-i;j++){
	     					printf("^");
						}
					for(int k=1;k<=2*i;k++){
						if(k%2==1){
							printf("*");
						}
						else{
							printf(" ");
						}
		  		
					}
					printf("\n");
					}
        	}
    	}
        else{
            break;
        }
    }
    return 0;
}
