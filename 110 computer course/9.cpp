#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int N;
	while(1){
		cin>>N;
		if(N>0){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					cout<<i<<"*"<<j<<"="<<i*j<<" ";
				}	
				cout<<endl;
			}
		}
		else{
			break;
		}

	}


	return 0;
}
