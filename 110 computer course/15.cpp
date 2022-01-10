#include <iostream>
using namespace std; 
void Numchange(int A, int B)
{
	int x=0;
	if(A>0)
	{
		Numchange(A / B, B);
		x = A % B;
		if (x < 10)
			printf("%d",x);           
		else
			printf("%c", x + 55);      
	}
}
//void pointchange(int A, int B)
//{
//	int x=0;
//	if(A>0)
//	{
//		Numchange(A / B, B);
//		x = A % B;
//		if (x < 10)
//			printf("%d",x);           
//		else
//			printf("%c", x + 55);      
//	}
//}
int main()
{ 
	double n,t,m;
    int i,j,k,r;
    char a[100];
    char c[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   	double N;
    int b,d;
    while(cin>>N>>b>>d){
        if(N<=0 || (b<=1 or b>36) || (d<0 or d>5))
        {
    		break;
        }
        else{
        	Numchange(N,b);
        	t=N-int(N);
        	r=b;
		    for(i=0; i<16; i++)
		    {
		        m= t*r;
		        b=(int) m;   	
		        if(b>=10)
		            a[i]=c[b-10];
		        else
		            a[i]=b+'0';
		        t=(m-b*1.0);
		        if(t==0)
		            break;
		
		    }
			if(d>0){
		    	printf(".");				
			}
			else{	
			}
		    for(i=0; i<d; i++)
		        printf("%c",a[i]);
        	printf("\n");
		}
	}
    return 0;
}
