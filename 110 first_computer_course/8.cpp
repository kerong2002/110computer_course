#include<iostream>
#include <algorithm>
using namespace std;
int main(){
	int z[99];
	int N;
	int a,b;
	while(1){
		cin>>N;
		if(N<=0){
			break;
		}
		else if(N>0){
		for(int i=0;i<=N;i++){
			cin>>z[i];
		}

		sort(z+1,z+N+1);
		if(z[0]==1){
			cout<<z[1]<<" ";
			a=z[1];
			for(int i=0;i<a;i++){
				cout<<"*";
			}
		cout<<endl;
		}
		else if(z[0]==2){
			cout<<z[N]<<" ";
			b=z[N];
			for(int i=0;i<b;i++){
				cout<<"*";
			}
		cout<<endl;		
		}	
		}	
	}
	
	return 0;
}
