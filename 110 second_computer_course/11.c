#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
char all_table[200][999];
int all_table_cnt=0;
/*=========<存儲資料>============*/
typedef struct{                //名稱為student的結構
    char table_name[999];      //資料表名稱
    int  id;                   //索引
    char data_list[200][999];  //橫向標題
    char format[200][999];     //出入格式
    char document[200][200][999];   //資料
    int y_list;                //總共資料高度
    int x_list;                //總共長度
}table;
/*===============================*/
int main(){
    table *Table=(table *)malloc(MAX*sizeof(table));
    char active[1][999]={'\0'};
    while(scanf("%s",active[0])!=EOF){
        //建立
        if(strcmp(active[0],"createTable")==0){
            char name[999]={'\0'};
            scanf("%s",name);
            int not_ok=0;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(name,all_table[x])==0){
                    printf("Table name duplicated\n");
                    not_ok=1;
                    break;
                }
            }
            if(not_ok==1){
                continue;
            }
            if(not_ok==0){
                int N;
                scanf("%d",&N);
                char input[9999]={'\0'};
                scanf("%[^\n]%*c",input);
//                printf("%s",input);
                char **data=(char **)malloc(200*sizeof(char *));
                for(int x=0;x<200;x++){
                    data[x]=(char *)malloc(999*sizeof(char));
                }
                char *d=" ";
                char *pick = strtok(input, d);
                int data_cnt=0;
                while (pick != NULL) {
                    strcpy(data[data_cnt++],pick);
                    pick = strtok(NULL, d);
                }
                int not_command=0;
                if((data_cnt)!=2*N){
                    not_command=1;
                    printf("Incorrect command\n");
                    continue;
                }
                for(int x=1;x<2*N;x+=2){
//                    printf("%s ",data[x]);
                    int not_type=0;
                    if(strcmp(data[x],"INTEGER")==0){
                        not_type+=1;
                    }
                    if(strcmp(data[x],"STRING")==0){
                        not_type+=1;
                    }
                    if(strcmp(data[x],"FLOATING")==0){
                        not_type+=1;
                    }
                    if(not_type==0){
                        printf("Field type incorrect\n");
                        not_command=1;
                        break;
                    }
                }
                if(not_command==1){
                    continue;
                }
                for(int x=0;x<2*N;x+=2){
                    for(int y=x+2;y<2*N;y+=2){
//                        printf("%s,%s\n",data[x],data[y]);
                        if(strcmp(data[x],data[y])==0){
                            printf("Field name duplicated\n");
                            not_command=1;
                            break;
                        }
                    }
                    if(not_command==1){
                        break;
                    }
                }
                if(not_command==1){
                    continue;
                }
                if(not_command==0){
                    strcpy(Table[all_table_cnt].table_name,name);
                    strcpy(all_table[all_table_cnt],name);
                    Table[all_table_cnt].id=N;
                    int list_cnt=0;
                    for(int x=0;x<2*N;x+=2){
                        strcpy(Table[all_table_cnt].data_list[list_cnt],data[x]);
                        list_cnt+=1;
                    }
                    int format_cnt=0;
                    for(int x=1;x<2*N;x+=2){
                        if(strcmp(data[x],"INTEGER")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                        if(strcmp(data[x],"STRING")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                        if(strcmp(data[x],"FLOATING")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                    }
                    Table[all_table_cnt].x_list=N;
                    Table[all_table_cnt].y_list=0;
//                    /*===========<顯示>=========*/
//                    printf("%s\n",Table[all_table_cnt].table_name);
//                    for(int x=0;x<N;x++){
//                        for(int row=0;row<Table[x].x_list;row++){
//                            printf("%s %s\n",Table[x].data_list[row],Table[x].format[row]);
//                        }
//
//                    }
//                    printf("%d",Table[all_table_cnt].x_list);
//                    /*==========================*/
                    all_table_cnt+=1;
//                    printf("%d",all_table_cnt);
                }

                for(int x=0;x<200;x++){
                    free(data[x]);
                }
                free(data);
            }
        }
        //顯示
        if(strcmp(active[0],"showTableList")==0){
            for(int x=0;x<all_table_cnt;x++){
                printf("%s [",all_table[x]);
                for(int row=0;row<Table[x].x_list;row++){
                    printf("(%s, %s)",Table[x].data_list[row],Table[x].format[row]);
                }
                printf("]\n");
            }
        }
        if(strcmp(active[0],"insert")==0){
            char garbage[99]={'\0'};
            scanf("%s",garbage);
            if(strcmp(garbage,"into")!=0){
                continue;
            }
            char find[99]={'\0'};
            scanf("%s",find);
            char want_insert[9999]={'\0'};
            scanf("%[^\n]%*c",want_insert);
//            printf("@%s\n",want_insert);
            int ok=-1;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(all_table[x],find)==0){
                    ok=x;
                    break;
                }
            }
            if(ok==-1){
                printf("Table does not exist\n");
                continue;
            }
            if(ok>=0){
                char put[200][9999]={'\0'};
                int want_insert_cnt=0;
                char *d=" ";
                char *pick = strtok(want_insert, d);
                while (pick != NULL) {
                    strcpy(put[want_insert_cnt++],pick);
                    pick = strtok(NULL, d);
                }
                if(want_insert_cnt!=Table[ok].x_list){
                    printf("Number of fields is not consistent\n");
                    continue;
                }
                for(int x=0;x<=Table[ok].x_list;x++){
                    strcpy(Table[ok].document[Table[ok].y_list][x],put[x]);
                }
                Table[ok].y_list+=1;
//                printf("%d",Table[ok].y_list);
            }
        }
        if(strcmp(active[0],"showTableContent")==0){
            char find[999]={'\0'};
            scanf("%s",find);
            int ok=-1;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(all_table[x],find)==0){
                    ok=x;
                    break;
                }
            }
            if(ok==-1){
                printf("Table does not exist\n");
                continue;
            }
//            if(Table[ok].y_list==0){
//                printf("Table does not exist\n");
//                continue;
//            }
            if(ok>=0){
                for(int x=0;x<Table[ok].x_list;x++){
                    printf("%s\t",Table[ok].data_list[x]);
                }
                printf("\n");
                for(int y=0;y<Table[ok].y_list;y++){
                    for(int x=0;x<Table[ok].x_list;x++){
                        if(strcmp(Table[ok].format[x],"FLOATING")==0){
                            double float_thing=atof(Table[ok].document[y][x]);
                            printf("%.1f\t",float_thing);
                        }
                        else if(strcmp(Table[ok].format[x],"INTEGER")==0){
                            int  int_thing=atoi(Table[ok].document[y][x]);
                            printf("%d\t",int_thing);
                        }
                        else{
                            printf("%s\t",Table[ok].document[y][x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        if(strcmp(active[0],"exit")==0){
            break;
        }
        if(strcmp(active[0],"select")==0){
            getchar();
            char all_input[999]={'\0'};
            scanf("%[^\n]%*c",all_input);
            char all_active[999][999]={'\0'};
            char *d=" ";
            char *pick = strtok(all_input, d);
            int all_active_cnt=0;
            while (pick != NULL) {
                strcpy(all_active[all_active_cnt++],pick);
                pick = strtok(NULL, d);
            }
//            for(int x=0;x<all_active_cnt;x++){
//                printf("%s\n",all_active[x]);
//            }
            if(strcmp("into",all_active[1])==0 && strcmp("*",all_active[0])==0){
                if(all_active_cnt==5 && (strcmp("from",all_active[3])==0)){
                    int ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[4])==0){
                            ok=x;
                            break;
                        }
                    }
                    if(ok==-1){
                        printf("Table does not exist\n");
                        continue;
                    }
                    int new_ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[2])==0){
                            new_ok=x;
                            break;
                        }
                    }
                    if(new_ok!=-1){
                        printf("New Table is existed\n");
                        continue;
                    }
                    strcpy(Table[all_table_cnt].table_name,all_active[2]);
                    strcpy(all_table[all_table_cnt],all_active[2]);
                    Table[all_table_cnt].id=Table[ok].id;
                    for(int x=0;x<Table[ok].id;x++){
                        strcpy(Table[all_table_cnt].data_list[x],Table[ok].data_list[x]);
                    }
                    for(int x=0;x<Table[ok].id;x++){
                        strcpy(Table[all_table_cnt].format[x],Table[ok].format[x]);
                    }
                    Table[all_table_cnt].x_list=Table[ok].x_list;
                    Table[all_table_cnt].y_list=0;
                    for(int x=0;x<Table[ok].x_list;x++){
                        printf("%s\t",Table[all_table_cnt].data_list[x]);
                    }
                    printf("\n");
                    Table[all_table_cnt].y_list=Table[ok].y_list;
                    Table[all_table_cnt].x_list=Table[ok].x_list;
                    for(int y=0;y<Table[ok].y_list;y++){
                        for(int x=0;x<=Table[ok].x_list;x++){
                            strcpy(Table[all_table_cnt].document[y][x],Table[ok].document[y][x]);
                        }
                    }
                    for(int y=0;y<Table[all_table_cnt].y_list;y++){
                        for(int x=0;x<Table[all_table_cnt].x_list;x++){
                            if(strcmp(Table[all_table_cnt].format[x],"FLOATING")==0){
                                double float_thing=atof(Table[all_table_cnt].document[y][x]);
                                printf("%.1f\t",float_thing);
                            }
                            else if(strcmp(Table[all_table_cnt].format[x],"INTEGER")==0){
                                int  int_thing=atoi(Table[all_table_cnt].document[y][x]);
                                printf("%d\t",int_thing);
                            }
                            else{
                                printf("%s\t",Table[all_table_cnt].document[y][x]);
                            }
                        }
                        printf("\n");
                    }
                    all_table_cnt+=1;
                }
                else{
                    printf("Incorrect command\n");
                }
            }
            else if(strcmp("from",all_active[1])==0 && strcmp("*",all_active[0])==0){
                if(all_active_cnt==3){
                    int ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[2])==0){
                            ok=x;
                            break;
                        }
                    }
                    if(ok==-1){
                        printf("Table does not exist\n");
                        continue;
                    }
                    else{
                        for(int x=0;x<Table[ok].x_list;x++){
                            printf("%s\t",Table[ok].data_list[x]);
                        }
                        printf("\n");
                        for(int y=0;y<Table[ok].y_list;y++){
                            for(int x=0;x<Table[ok].x_list;x++){
                                if(strcmp(Table[ok].format[x],"FLOATING")==0){
                                    double float_thing=atof(Table[ok].document[y][x]);
                                    printf("%.1f\t",float_thing);
                                }
                                else if(strcmp(Table[ok].format[x],"INTEGER")==0){
                                    int  int_thing=atoi(Table[ok].document[y][x]);
                                    printf("%d\t",int_thing);
                                }
                                else{
                                    printf("%s\t",Table[ok].document[y][x]);
                                }
                            }
                            printf("\n");
                        }
                    }
                }
                else{
                    printf("Incorrect command\n");
                }
            }
            else{
                int off_set=0;
                if(strcmp("*",all_active[0])==0){
                    off_set=1;
                }
                int find_from=-1;
                int find_into=-1;
                for(int x=0+off_set;x<all_active_cnt;x++){
                    if(strcmp("from",all_active[x])==0){
                        find_from=x;
                    }
                    if(strcmp("into",all_active[x])==0){
                        find_into=x;
                    }
                }
                int set_find_from=-1;
                if(strcmp(all_active[all_active_cnt-2],"from")==0){
                    set_find_from=1;
                }
                if(find_from==-1 || set_find_from==-1){
                    printf("Incorrect command\n");
                    continue;
                }
                if(find_into==-1){
                    int pick=all_active_cnt-2;
                    int do_not=-1;
                    int ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[pick+1])==0){
                            ok=x;
                            break;
                        }
                    }
                    if(ok==-1){
                        printf("Table does not exist\n");
                        continue;
                    }
                    for(int y=0;y<pick;y++){
                        for(int x=y+1;x<pick;x++){
                        if(strcmp(all_active[x],all_active[y])==0){
                            printf("Field name is duplicated\n");
                            do_not=1;
                            break;
                        }
                        }
                        if(do_not==1){
                            break;
                        }
                    }
                    if(do_not==1){
                        continue;
                    }
                    int check=0;
                    int *list_find=(int *)calloc(pick+99,sizeof(int));
                    int list_find_cnt=0;
                    for(int y=0;y<pick;y++){
                        for(int x=0;x<Table[ok].x_list;x++){
                            if(strcmp(Table[ok].data_list[x],all_active[y])==0){
                                check+=1;
                                list_find[list_find_cnt++]=x;
                                continue;
                            }
                        }
                    }
                    if(check==pick){
                        for(int x=0;x<pick;x++){
                            printf("%s\t",Table[ok].data_list[list_find[x]]);
                        }
                        printf("\n");
                        for(int y=0;y<Table[ok].y_list;y++){
                            for(int x=0;x<pick;x++){
                                if(strcmp(Table[ok].format[list_find[x]],"FLOATING")==0){
                                    double float_thing=atof(Table[ok].document[y][list_find[x]]);
                                    printf("%.1f\t",float_thing);
                                }
                                else if(strcmp(Table[ok].format[list_find[x]],"INTEGER")==0){
                                    int  int_thing=atoi(Table[ok].document[y][list_find[x]]);
                                    printf("%d\t",int_thing);
                                }
                                else{
                                    printf("%s\t",Table[ok].document[y][list_find[x]]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    else{
                        free(list_find);
                        printf("Field name does not exist\n");
                        continue;
                    }
                }
                else if(find_into!=-1 && find_from ==all_active_cnt-2){
                    int pick=find_into;
                    int do_not=-1;
                    int ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[all_active_cnt-1])==0){
                            ok=x;
                            break;
                        }
                    }
                    if(ok==-1){
                        printf("Table does not exist\n");
                        continue;
                    }
                    int new_ok=-1;
                    for(int x=0;x<all_table_cnt;x++){
                        if(strcmp(all_table[x],all_active[find_into+1])==0){
                            new_ok=x;
                            break;
                        }
                    }
                    if(new_ok!=-1){
                        printf("New Table is existed\n");
                        continue;
                    }
                    for(int y=0;y<pick;y++){
                        for(int x=y+1;x<pick;x++){
                        if(strcmp(all_active[x],all_active[y])==0){
                            printf("Field name is duplicated\n");
                            do_not=1;
                            break;
                        }
                        }
                        if(do_not==1){
                            break;
                        }
                    }
                    if(do_not==1){
                        continue;
                    }
                    int check=0;
                    int *list_find=(int *)calloc(pick+99,sizeof(int));
                    int list_find_cnt=0;
                    for(int y=0;y<pick;y++){
                        for(int x=0;x<Table[ok].x_list;x++){
                            if(strcmp(Table[ok].data_list[x],all_active[y])==0){
                                check+=1;
                                list_find[list_find_cnt++]=x;
                                continue;
                            }
                        }
                    }
                    if(check==pick){
                        strcpy(Table[all_table_cnt].table_name,all_active[find_into+1]);
                        strcpy(all_table[all_table_cnt],all_active[find_into+1]);
                        for(int x=0;x<pick;x++){
                            strcpy(Table[all_table_cnt].data_list[x],Table[ok].data_list[list_find[x]]);
                        }
                        for(int x=0;x<pick;x++){
                            strcpy(Table[all_table_cnt].format[x],Table[ok].format[list_find[x]]);
                        }
                        Table[all_table_cnt].x_list=pick;
                        Table[all_table_cnt].y_list=0;
                        for(int x=0;x<pick;x++){
                            printf("%s\t",Table[all_table_cnt].data_list[x]);
                        }
                        printf("\n");
                        Table[all_table_cnt].y_list=Table[ok].y_list;
                        Table[all_table_cnt].x_list=pick;
                        for(int y=0;y<Table[ok].y_list;y++){
                            for(int x=0;x<=pick;x++){
                                strcpy(Table[all_table_cnt].document[y][x],Table[ok].document[y][list_find[x]]);
                            }
                        }
                        for(int y=0;y<Table[all_table_cnt].y_list;y++){
                            for(int x=0;x<Table[all_table_cnt].x_list;x++){
                                if(strcmp(Table[all_table_cnt].format[x],"FLOATING")==0){
                                    double float_thing=atof(Table[all_table_cnt].document[y][x]);
                                    printf("%.1f\t",float_thing);
                                }
                                else if(strcmp(Table[all_table_cnt].format[x],"INTEGER")==0){
                                    int  int_thing=atoi(Table[all_table_cnt].document[y][x]);
                                    printf("%d\t",int_thing);
                                }
                                else{
                                    printf("%s\t",Table[all_table_cnt].document[y][x]);
                                }
                            }
                            printf("\n");
                        }
                        all_table_cnt+=1;
                    }
                    else{
                        free(list_find);
                        printf("Field name does not exist\n");
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}
/*
createTable person 4 id INTEGER name STRING weight FLOATING birthday DATE
createTable person 4 id INTEGER name STRING weight FLOATING weight STRING
createTable person 3 id INTEGER name STRING weight FLOATING birthday STRING
createTable person 4 id INTEGER name STRING weight FLOATING birthday STRING
createTable person 4 id INTEGER name STRING weight FLOATING birthday STRING
showTableList
insert into Person 1 ABC 77.8 2000/01/09
insert into person 1 ABC 77.8 2000/01/09
insert into person 2 DEF 67.3 2001/02/19
insert into person 3 GH 66.6 2001/06/10
showTableContent person
select name id weight name id weight from person
select * name id weight from person
select name id weight from person
select * from person
select * from person2 into person
select * into person2 from person2
select * into person2 from person

*/
