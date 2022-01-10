#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
using namespace std; 

int assume(string N,int start_count,int end_count)
{
	string saveN=N;							
	string NEW_N=N.erase(start_count,1);	
	if(start_count==end_count){				
		return 0;
	}
	else{
		int find =saveN[start_count];		
		if(stoi(NEW_N)%(find-48)==0){		
			start_count=start_count+1;		
			find=find+1;					 
			printf("T");
			return assume(saveN,start_count,end_count); 
		}
		else{
			start_count=start_count+1;			
			find=find+1;					
			printf("F");
			return assume(saveN,start_count,end_count);
		}

	}
}


int main()
{ 	
	int find=0;
	string N;
	int start_count=0;						
	int end_count=0;							
	while(1){
		cin>>N;
		if(stoi(N)>0 and stoi(N)<10){
			printf("T\n");					
		}
		else if(stoi(N)>=10){		   		
			end_count=N.size();		   			
			assume(N,start_count,end_count);	
			printf("\n");						 
		}
		else{
			break;
		}	
	}

    return 0;
}

