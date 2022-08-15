#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char set[1001];             //輸入的陣列
    char list[1001];            //去0的陣列
    while(scanf("%s",set)!=EOF){//讀到end of file 停止
        int not_const=0;        //偵測是否為0
        int exit=0;             //終止條件一，全為0
        int count=0;
        int size=0;
        int exit1=0;            //終止條件二，負數
        for(int x=0;x<strlen(set);x++){
            if(set[x]=='-'){
                exit1=1;//判斷是否為負號
            }
            if(set[x]=='0'){
                exit+=1;//判斷全部是否為0
            }
            if(set[x]!='0'){
                not_const=1;//判斷是否讀到0
            }
            if(not_const==1){   //開始寫入陣列
                size+=1;        //判斷正數長度
                list[count]=set[x];
                count+=1;       //計數
            }

        }
//================<終止條件>=========================
        if(exit1==1) break;         //負數離開
        if(exit==strlen(set)) break;//全部都是零離開
//===================================================
        char reverse[size];//反轉表
        int total=0;       //加總
        for(int x=size-1,y=0;x>=0;x--,y++){
            total += list[x]-'0';
            reverse[y]=list[x];
        }
        int ok=0;
        for(int x=0;x<size;x++){
            if(reverse[x]!='0'){
                ok=1;//判斷輸出第一位是否為0
            }
            if(ok==1){
                printf("%c",reverse[x]);
            }
        }
        printf(" %d\n",total);
    }
    return 0;
}
