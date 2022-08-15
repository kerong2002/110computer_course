//HW3 2022-03-21 陳科融
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
#define MAX 99      //定義MAX最大值維99
struct student{     //名稱為student的結構
    char name[20];  //姓名為字元陣列
    char id[20];    //學號為整數型
    char sex[6];    //性別為字串型
    int score1;     //成績1
    int score2;     //成績2
    int score3;     //成績3
};
struct class_room{
	struct student st[MAX];	//定義多個學生
	int n;					//當前班級的人數
};
void add_student(struct class_room *kerong)
{
	scanf("%s",kerong->st[kerong->n].name);
	scanf("%s",kerong->st[kerong->n].id);
	scanf("%s",kerong->st[kerong->n].sex);
	scanf("%d",&kerong->st[kerong->n].score1);
	scanf("%d",&kerong->st[kerong->n].score2);
    scanf("%d",&kerong->st[kerong->n].score3);
    int total=kerong->st[kerong->n].score1+kerong->st[kerong->n].score2+kerong->st[kerong->n].score3;
    kerong->st[kerong->n].score1=total/3; //平均值
    for(int x=0;x<kerong->n;x++){
        if(strcmp(kerong->st[kerong->n].id,kerong->st[x].id)==0){
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
		printf("the %d student name is %s\n",i+1,kerong->st[i].name);
		printf("the %d student id is %s\n",i+1,kerong->st[i].id);
		printf("the %d student sex is %s\n",i+1,kerong->st[i].sex);
		printf("the %d student score1 is %d\n",i+1,kerong->st[i].score1);
		printf("the %d student score2 is %d\n",i+1,kerong->st[i].score2);
		printf("the %d student score3 is %d\n",i+1,kerong->st[i].score3);
	}
	printf("%d",kerong->n);
}
void sort_student(struct class_room *kerong){
    int max=-1;
    int min=999;
    for(int x=0;x<kerong->n;x++){
        if(max<kerong->st[x].score1){
            max=kerong->st[x].score1;   //成績平均最大值
        }
        if(min>kerong->st[x].score1){
            min=kerong->st[x].score1;   //成績平均最小值
        }
    }
    char data[99][99];                  //存儲姓名
    int english_and_average[99][2];     //存儲學號英文跟平均值
    for(int x=0;x<kerong->n;x++){
        strcpy(data[x],kerong->st[x].name);
        english_and_average[x][0]=kerong->st[x].id[0];
        english_and_average[x][1]=kerong->st[x].score1;
    }
//============<依照成績平均做一次排序>==========================
    for(int x=0;x<kerong->n;x++){
        for(int y=x+1;y<kerong->n;y++){
            if(english_and_average[y][0]<english_and_average[x][0]){
                int temp=english_and_average[x][0];
                english_and_average[x][0]=english_and_average[y][0];
                english_and_average[y][0]=temp;
                char set[999]={'\0'};
                strcpy(set,data[x]);
                strcpy(data[x],data[y]);
                strcpy(data[y],set);
                int set1=english_and_average[x][1];
                english_and_average[x][1]=english_and_average[y][1];
                english_and_average[y][1]=set1;
            }
        }
    }
//===========<按照學號英文字母從小到大輸出>========================
    for(int y=max;y>=min;y--){
        for(int x=0;x<kerong->n;x++){
            if(english_and_average[x][1]==y){
                printf("%s\n",data[x]);
            }
        }
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
            sort_student(&kerong); //排序學生
        }
        if(choose==3){
            break;                 //結束條件
        }
        if(choose==9){
            show_student(&kerong); //顯示學生(測試用)
        }
    }
    return 0;
}
/*
1 Roger C104152137 man 70 50 60
1 Alice C104152136  woman 75 60 80
1 Kenny F104152448 man 75 60 80
1 Josh A104152249 man 75 60 80
*/
