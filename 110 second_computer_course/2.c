//大數運算 2022-03-01 陳科融
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
int carry=0;
int F_total;
int S_total;
//===================<翻轉>=====================
void reverse(char list[],char rev[]){
    int cnt=0;
    for(int x=strlen(list)-1;x>=0;x--){
        rev[cnt]=list[x];
        cnt+=1;
    }
}
//===================<加法>=====================
int add(char first[],char second[],int answer[]){
    int run=0;
    int f_size=strlen(first);
    int s_size=strlen(second);
    for(int x=0;x<9999;x++){
        if(first[x]=='\0' && second[x]=='\0' && carry ==0){
            return run;
        }
        else{
            if(first[x]>='0')  first[x]-='0';
            if(second[x]>='0') second[x]-='0';
            F_total+=first[x];
            S_total+=second[x];
            answer[x]=(first[x]+second[x]+carry)%10;
            carry=(first[x]+second[x]+carry)/10;
            run+=1;
        }
    }
}

//===================<主程式>=====================
int main(){
    char first[9999]={'\0'};
    char second[9999]={'\0'};
    char R_first[9999]={'\0'};
    char R_second[9999]={'\0'};
    while(scanf("%s%s",first,second)!=EOF){
        F_total=0;
        S_total=0;
        if(first[0]=='-') break;
        if(second[0]=='-') break;
        int *answer=(int *)calloc(9999,sizeof(int));
//==================<加法動作>=====================
        reverse(first,R_first);
        reverse(second,R_second);
        int run=add(R_first,R_second,answer);
//=================================================
        if(F_total==0) break;   //終止first==0
        if(S_total==0) break;   //終止second==0
        int ok=0;
        for(int x=run-1;x>=0;x--){
            if(answer[x]!=0){
                ok=1;
            }
            if(ok==1){
                printf("%d",answer[x]);
            }
        }
        printf("\n");
        memset(first,'\0',sizeof(char)*9999);   //清空
        memset(second,'\0',sizeof(char)*9999);  //清空
        memset(R_first,'\0',sizeof(char)*9999); //清空
        memset(R_second,'\0',sizeof(char)*9999);//清空
        free(answer);
    }
    return 0;
}
