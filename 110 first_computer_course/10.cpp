#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int O;
	int N;
	while(1){
		cin>>O;
		cin>>N;
		if(O==1 and N>0){
			for(int i=0;i<N;i++){
				for(int j=1;j<=i;j++){
					printf(" ");
				}
				for(int n=0;n<N-i;n++){
		   			printf("*");
				}
				printf("\n");
			}
		}
		else if(O==2 and N>0){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N-i;j++){
	     			printf(" ");
				}
				for(int k=1;k<=i;k++){
		  			printf("* ");
				}
			printf("\n");
			}
		}
		else{
			break;
		}
    }

	return 0;
}
