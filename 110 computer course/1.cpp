#include<stdio.h>

int main(){
	int s;
	int i;
	int j;
   
    for(s=1;s<18;s+=2)
    {
        for(i=1;i<10;i++)
        {
            j= s-i;
            if(j<10 && j> 0)
            {
            	printf("%dX%d=%d ",i,j,i*j);
            }
        }
    }
    
    for (int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			if(i%2!=0 and j%2!=0)
				printf("%dX%d=%d ",i,j,i*j);
			else if (i%2==0 and j%2==0)
				printf("%dX%d=%d ",i,j,i*j);
		}
	}
	
    return 0;
}
