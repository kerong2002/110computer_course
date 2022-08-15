//HW7 2022-03-21 陳科融
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
#define MAX 99      //定義MAX最大值維99
struct student{     //名稱為student的結構
    int  id;        //索引
    char name[99];  //姓名
    char space[99]; //地址
    char birth[99]; //生日
};
struct class_room{
	struct student st[MAX];	//定義多個學生
	int n;					//當前班級的人數
};
void add_student(struct class_room *kerong){
	scanf("%d",&kerong->st[kerong->n].id);
	scanf("%s",kerong->st[kerong->n].name);
    scanf("%s",kerong->st[kerong->n].space);
    scanf("%s",kerong->st[kerong->n].birth);
    kerong->n++;
}
void show_student(struct class_room *kerong)
{
	int i;
	for(i=0;i<kerong->n;i++)//kerong->n為當前班级的人數
	{

		printf("the %d student id is %d\n",i+1,kerong->st[i].id);
		printf("the %d student name is %s\n",i+1,kerong->st[i].name);
		printf("the %d student space is %s\n",i+1,kerong->st[i].space);
		printf("the %d student birth is %s\n",i+1,kerong->st[i].birth);
	}
	printf("%d\n",kerong->n);
}
int find_st(struct class_room *kerong)
{
	int id,i;
	int exist=0;
	scanf("%d",&id);
	for(i=0;i<kerong->n;i++)
	{
		if(id==kerong->st[i].id)
		{
		    exist=1;
//			printf("%d ",kerong->st[i].id);
			printf("%s ",kerong->st[i].name);
			printf("%s ",kerong->st[i].space);
			printf("%s",kerong->st[i].birth);
			printf("\n");
		}
	}
    if(exist==0){
        printf("None\n");
    }
	return -1;
}
int find_student(struct class_room *kerong)
{
	int id,i;
	scanf("%d",&id);
	for(i=0;i<kerong->n;i++)
	{
		if(id==kerong->st[i].id)
		{
			return i;
		}
	}
	printf("None\n");
	return -1;
}
void remove_student(struct class_room *kerong){
	int ret,i;
	ret=find_student(kerong);

	if(ret!=-1)
	{
		for(i=ret;i<kerong->n-1;i++)
		{
		    kerong->st[i].id=kerong->st[i+1].id;
			strcpy(kerong->st[i].name,kerong->st[i+1].name);
			strcpy(kerong->st[i].space,kerong->st[i+1].space);
			strcpy(kerong->st[i].birth,kerong->st[i+1].birth);
		}
		kerong->n--;
	}
}
void change_student(struct class_room *kerong)
{
	int ret,choose;
	ret=find_student(kerong);
	if(ret!=-1)
	{
        scanf("%d",&kerong->st[ret].id);
        scanf("%s",kerong->st[ret].name);
        scanf("%s",kerong->st[ret].space);
        scanf("%s",kerong->st[ret].birth);
	}
}
//===================<主程式>=====================
int main(){
    struct class_room kerong;      //定義一个班级為kerong存儲學生
	kerong.n=0;                    //初始化，學生人數為0
    char choose;                   //定義動作選擇
    while(scanf("%c",&choose)!=EOF){
        if(choose=='@'){
            add_student(&kerong);    //添加學生
        }
        if(choose=='#'){
            remove_student(&kerong); //刪除
        }
        if(choose=='!'){
            change_student(&kerong); //修改
        }
        if(choose=='$'){
            find_st(&kerong);        //查詢
        }
        if(choose=='*'){
            break;                   //終止
        }
//        if(choose=='-'){
//            show_student(&kerong); //顯示學生(測試用)
//        }
    }
    return 0;
}
