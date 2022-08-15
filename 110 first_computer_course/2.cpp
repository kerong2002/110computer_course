#include<stdio.h>

int main(){
	
    int S=0;
	int A=0;
	int B=0;
	int C=0;
	int D=0;
	int E=0;
    int n;
    for(int y=0;y<10;y++){
        scanf("%d",&n);
        if(n==100){
   		 	S++;
		}
		else if(n>=90 && n<100){
    		A++;
		}
		else if(n>=80 && n<90){
    		B++;
		}
		else if(n>=70 && n<80){
    		C++;
		}
		else if(n>=60 && n<70){
    		D++;
		}
		else if(0<=n<60){
   			E++;
		}
    }
    
    if(S>=1){
    	printf("%dS\n",S);
    }
    if(A>=1){
        printf("%dA\n",A);
    }
    if(B>=1){
        printf("%dB\n",B);
    }
    if(C>=1){
        printf("%dC\n",C);
    }
    if(D>=1){
        printf("%dD\n",D);
    }
    if(E>=1){
        printf("%dE\n",E);
    }

    return 0;
}
