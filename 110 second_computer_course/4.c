//HW4 2022-03-21 陳科融
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
#define MAX 99      //定義MAX最大值維99
struct student{     //名稱為student的結構
    int  id;        //索引
    char name[20];  //產品名稱
    char make[99];  //製造日期
    char end[99];   //有效期限
    int price;      //價格
};
struct class_room{
	struct student st[MAX];	//定義多個學生
	int n;					//當前班級的人數
};
void add_student(struct class_room *kerong){
	scanf("%d",&kerong->st[kerong->n].id);
	scanf("%s",kerong->st[kerong->n].name);
    scanf("%s",kerong->st[kerong->n].make);
    scanf("%s",kerong->st[kerong->n].end);
	scanf("%d",&kerong->st[kerong->n].price);
	if(strcmp(kerong->st[kerong->n].make,kerong->st[kerong->n].end)>=0){
	    printf("ErrorInput\n");//製造日期超過有效日期
        return;
	}
	if(strcmp(kerong->st[kerong->n].make,"2022/03/28")>=0){
	    printf("ErrorInput\n");//製造日期超過當日
        return;
	}
    for(int x=0;x<kerong->n;x++){
        if(kerong->st[kerong->n].id==kerong->st[x].id){
            printf("ErrorInput\n");
            kerong->n--;
            break;
        }
    }
    kerong->n++;
}
void show_student(struct class_room *kerong)
{
	int i;
	for(i=0;i<kerong->n;i++)//kerong->n為當前班级的人數
	{

		printf("the %d student id is %d\n",i+1,kerong->st[i].id);
		printf("the %d student name is %s\n",i+1,kerong->st[i].name);
		printf("the %d student name is %s\n",i+1,kerong->st[i].make);
		printf("the %d student name is %s\n",i+1,kerong->st[i].end);
		printf("the %d student score1 is %d\n",i+1,kerong->st[i].price);
	}
	printf("%d\n",kerong->n);
}
void sort_to_close(struct class_room *kerong){
    char max[999]={"0000/00/00"};
    char min[999]={"9999/99/99"};
    for(int x=0;x<kerong->n;x++){
        if(strcmp(max,kerong->st[x].make)<=0){
            strcpy(max,kerong->st[x].make);//製造日期最多
        }
        if(strcmp(min,kerong->st[x].make)>0){
            strcpy(min,kerong->st[x].make);//製造日期最少
        }
    }
    char data[99][99]={'\0'};
    char time[99][99]={'\0'};
    int index[99][2]={0};
    for(int x=0;x<kerong->n;x++){
        strcpy(data[x],kerong->st[x].name);
        strcpy(time[x],kerong->st[x].make);
        index[x][0]=kerong->st[x].id;
    }
    for(int x=0;x<kerong->n;x++){
        for(int y=x+1;y<kerong->n;y++){
            if(strcmp(time[x],time[y])>0){
                char save[99]={'\0'};
                strcpy(save,time[x]);
                strcpy(time[x],time[y]);
                strcpy(time[y],save);
                char set[99]={'\0'};
                strcpy(set,data[x]);
                strcpy(data[x],data[y]);
                strcpy(data[y],set);
                int temp=0;
                temp=index[x][0];
                index[x][0]=index[y][0];
                index[y][0]=temp;
            }
            else if(strcmp(time[x],time[y])==0){
                if(index[x][0]>index[y][0]){
                    char save[99]={'\0'};
                    strcpy(save,time[x]);
                    strcpy(time[x],time[y]);
                    strcpy(time[y],save);
                    char set[99]={'\0'};
                    strcpy(set,data[x]);
                    strcpy(data[x],data[y]);
                    strcpy(data[y],set);
                    int temp=0;
                    temp=index[x][0];
                    index[x][0]=index[y][0];
                    index[y][0]=temp;
                }
            }
        }
    }
    for(int x=0;x<kerong->n;x++){
        printf("%s\n",data[x]);
    }
}
void sort_to_far(struct class_room *kerong){
    char max[999]={"0000/00/00"};
    char min[999]={"9999/99/99"};
    for(int x=0;x<kerong->n;x++){
        if(strcmp(max,kerong->st[x].end)<=0){
            strcpy(max,kerong->st[x].end);//有效日期最多
        }
        if(strcmp(min,kerong->st[x].end)>0){
            strcpy(min,kerong->st[x].end);//有效日期最少
        }
    }
    char data[99][99]={'\0'};
    char time[99][99]={'\0'};
    int index[99][2]={0};
    int cnt=0;
    for(int x=0;x<kerong->n;x++){
        if(strcmp(kerong->st[x].end,"2022/03/28")<0){
            continue;
        }
        strcpy(data[cnt],kerong->st[x].name);
        strcpy(time[cnt],kerong->st[x].end);
        index[cnt][0]=kerong->st[x].id;
        cnt+=1;
    }
    for(int x=0;x<cnt;x++){
        for(int y=x+1;y<cnt;y++){
            if(strcmp(time[x],time[y])>0){
                char save[99]={'\0'};
                strcpy(save,time[x]);
                strcpy(time[x],time[y]);
                strcpy(time[y],save);
                char set[99]={'\0'};
                strcpy(set,data[x]);
                strcpy(data[x],data[y]);
                strcpy(data[y],set);
                int temp=0;
                temp=index[x][0];
                index[x][0]=index[y][0];
                index[y][0]=temp;
            }
            else if(strcmp(time[x],time[y])==0){
                if(index[x][0]>index[y][0]){
                    char save[99]={'\0'};
                    strcpy(save,time[x]);
                    strcpy(time[x],time[y]);
                    strcpy(time[y],save);
                    char set[99]={'\0'};
                    strcpy(set,data[x]);
                    strcpy(data[x],data[y]);
                    strcpy(data[y],set);
                    int temp=0;
                    temp=index[x][0];
                    index[x][0]=index[y][0];
                    index[y][0]=temp;
                }
            }
        }
    }
    for(int x=0;x<cnt;x++){
        printf("%s\n",data[x]);
    }
}
void sort_price(struct class_room *kerong){
    int max=-1;
    int min=99999;
    for(int x=0;x<kerong->n;x++){
        if(max<kerong->st[x].price){
            max=kerong->st[x].price;//錢最多
        }
        if(min>kerong->st[x].price){
            min=kerong->st[x].price;//錢最少
        }
    }
    char data[99][99]={'\0'};
    int price[99][2]={0};
    int index[99][2]={0};
    for(int x=0;x<kerong->n;x++){
        strcpy(data[x],kerong->st[x].name);
        price[x][0]=kerong->st[x].price;
        index[x][0]=kerong->st[x].id;
    }
    for(int x=0;x<kerong->n;x++){
        for(int y=x+1;y<kerong->n;y++){
            if(price[x][0]>price[y][0]){
                char set[99]={'\0'};
                strcpy(set,data[x]);
                strcpy(data[x],data[y]);
                strcpy(data[y],set);
                int temp=0;
                temp=index[x][0];
                index[x][0]=index[y][0];
                index[y][0]=temp;
                int temp1=0;
                temp1=price[x][0];
                price[x][0]=price[y][0];
                price[y][0]=temp1;
            }
            else if(price[x][0]==price[y][0]){
                if(index[x][0]>index[y][0]){
                    char set[99]={'\0'};
                    strcpy(set,data[x]);
                    strcpy(data[x],data[y]);
                    strcpy(data[y],set);
                    int temp=0;
                    temp=index[x][0];
                    index[x][0]=index[y][0];
                    index[y][0]=temp;
                    int temp1=0;
                    temp1=price[x][0];
                    price[x][0]=price[y][0];
                    price[y][0]=temp1;
                }
            }
        }
    }
    for(int x=0;x<kerong->n;x++){
        printf("%s\n",data[x]);
    }
}
//===================<主程式>=====================
int main(){
    struct class_room kerong;      //定義一个班级為kerong存儲學生
	kerong.n=0;                    //初始化，學生人數為0
    int choose;                    //定義動作選擇
    while(scanf("%d",&choose)!=EOF){
        if(choose==1){
            add_student(&kerong);  //添加學生
        }
        if(choose==2){
            sort_to_close(&kerong); //遠到近排序
        }
        if(choose==3){
            sort_to_far(&kerong); //近到遠排序
        }
        if(choose==4){
            sort_price(&kerong); //價錢排序
        }
        if(choose==5){
            break;                 //結束條件
        }
        if(choose==9){
            show_student(&kerong); //顯示學生(測試用)
        }
    }
    return 0;
}
/*
1 4 哈密瓜 1992/01/10 1992/07/22 30
1 9 葡萄乾 1981/12/27 1982/03/28 30
1 5 巧克力 2021/01/25 2022/03/28 40
1 5 水蜜桃 1995/10/03 1997/05/10 40
1 3 蘋果汁 2021/10/05 2021/03/05 50
1 1 水果茶 2023/01/01 2024/03/05 70
*/
//1 5 巧克力1 2021/01/25 2022/03/28 40
//1 1 巧克力2 2021/01/25 2022/03/28 40
//1 2 巧克力3 2021/01/25 2022/03/29 40
//1 3 巧克力4 2021/01/25 2022/03/29 40
//1 7 巧克力5 2021/01/25 2022/03/30 40
//1 8 巧克力6 2021/01/25 2022/03/30 40
