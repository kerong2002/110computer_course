#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char list[9999]={'\0'};
    scanf("%[^\n]%*c",list);
    for(int x=0;x<strlen(list);x++){
        if(list[x]<65 || list[x]>90 && list[x]<97 || list[x]>122){
            list[x]=' ';
        }
    }
    int max_appear=-1;
    char *d=" ";
    char *pick = strtok(list, d);
    char data[999][999]={'\0'};
    int count=0;
    while (pick != NULL) {
        strcpy(data[count],pick);
        pick = strtok(NULL, d);
        count+=1;
    }
    //處裡一樣
    char same_list[999][999]={'\0'};
    int appear[999][1]={0};
    int same_cnt=0;
    int check_run=0;
    for(int x=0;x<count;x++){
        strcpy(same_list[check_run],data[x]);
        int do_not=0;
        for(int y=0;y<same_cnt;y++){
            if(strcmp(same_list[y],data[x])==0){
                appear[y][0]+=1;
                do_not=1;
            }
        }
        if(do_not==0){
            appear[check_run][0]+=1;
            same_cnt+=1;
            check_run+=1;
        }
    }
    //最長
    for(int x=0;x<check_run;x++){
        if(max_appear<appear[x][0]){
             max_appear=(max_appear,appear[x][0]);
        }
    }
    //排序
    for(int y=0;y<check_run;y++){
        for(int x=y+1;x<check_run;x++){
            if(appear[x][0]==appear[y][0]){
                if(strcmp(same_list[y],same_list[x])>0){
                    int tmp=appear[y][0];
                    appear[y][0]=appear[x][0];
                    appear[x][0]=tmp;
                    char string_tmp[999]={'\0'};
                    strcpy(string_tmp,same_list[y]);
                    strcpy(same_list[y],same_list[x]);
                    strcpy(same_list[x],string_tmp);
                }
            }
        }
    }
    int done_run=0;
    int break_for=0;
    for(int x=max_appear;x>=0;x--){
        for(int y=0;y<check_run;y++){
            if(appear[y][0]==x){
                if(done_run<5){
                    printf("%s %d\n",same_list[y],appear[y][0]);
                    done_run+=1;
                }
                else{
                    break_for=1;
                    break;
                }

            }
        }
        if(break_for==1){
            break;
        }
    }
    return 0;
}
/*
The development goal of the National Kaohsiung University of Science and Technology (NKUST) is to become a pro-  industry university of science and technology. To comply with and implement the development goal of NKUST, the research  and development goal of this department has been defined as "Research and Development of Industrial Technology with 30%  forward-looking vision and 70% practical application." The human and physical resources devoted to research in this  department are divided into three major groups: electronics, communications, and information.

*/
