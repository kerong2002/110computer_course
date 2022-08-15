#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char answer[99]={'\0'};
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<=0) break;
        int found[6]={0};
        getchar();
        scanf("%[^\n]%*c",answer);
        int cnt=0;
        char *d=", ";
        char *pick = strtok(answer, d);
        while (pick != NULL) {
            answer[cnt]=atoi(pick);
            pick = strtok(NULL, d);
            cnt+=1;
        }
        for(int x=0;x<5;x++){
            for(int y=x+1;y<5;y++){
                if(answer[x]>answer[y]){
                    int temp=answer[x];
                    answer[x]=answer[y];
                    answer[y]=temp;
                }
            }
        }
        char list[99]={'\0'};
        for(int s=0;s<n;s++){
            int input[5]={0};
            scanf("%[^\n]%*c",list);
            int cnt=0;
            char *d=", ";
            char *pick = strtok(list, d);
            while (pick != NULL) {
                input[cnt]=atoi(pick);
                pick = strtok(NULL, d);
                cnt+=1;
            }
            for(int x=0;x<5;x++){
                for(int y=x+1;y<5;y++){
                    if(input[x]>input[y]){
                        int temp=input[x];
                        input[x]=input[y];
                        input[y]=temp;
                    }
                }
            }
            int run=0;
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    if(answer[x]==input[y]){
                        run+=1;
                    }
                }
            }
            if(run!=0){
                found[run]+=1;
            }
        }
        int take=0;
        for(int x=5;x>=1;x--){
            if(found[x]!=0){
                take=1;
                printf("%d %d\n",found[x],x);
            }
        }
        if(take==0){
            printf("None\n");
        }
    }
    return 0;
}
