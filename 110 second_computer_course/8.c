//HW8 2022-05-16 陳科融
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 99      //定義MAX最大值維99
#define big(a,b) ((a>b)?(a):(b))
#define small(a,b) ((a>b)?(b):(a))
int classmate=0;
int course_int=0;
int grade_int=0;
int MAX_ID=-1;
int MIN_ID=9999;
int MAX_course_id=-1;
int MIN_course_id=9999;
int MAX_grade=-1;
int MIN_grade=9999;
int MAX_answer=-1;
int MIN_answer=9999;
/*=========<學生資料>============*/
typedef struct{     //名稱為student的結構
    int  id;        //索引
    char name[99];  //姓名
    char space[99]; //地址
    char birth[99]; //生日
}Student;
/*=========<課程資料>============*/
typedef struct{     //名稱為Course的結構
    int  id;        //課程ID
    char name[99];  //課程名稱
    int  time;      //課程時間
    int  score;     //課程學分
}Course;
/*=========<成績資料>============*/
typedef struct{      //名稱為Grade的結構
    int  course_id;  //課程ID
    int  student_id; //學生ID
    int  get_grade;  //獲取成績
}Grade;
/*=========<新增學生資料>============*/
void add_student(Student student[]){
    classmate+=1;
    int ID;
    char NAME[99]={'\0'};
    char SPACE[99]={'\0'};
    char BIRTH[99]={'\0'};
    scanf("%d",&ID);
    scanf("%s",NAME);
    scanf("%s",SPACE);
    scanf("%s",BIRTH);
    int find=0;
    for(int x=0;x<classmate-1;x++){
        if(ID==student[x].id){
            find=1;
            printf("Duplicated\n");
            break;
        }
    }
    if(find==0){
        student[classmate-1].id=ID;
        strcpy(student[classmate-1].name,NAME);
        strcpy(student[classmate-1].space,SPACE);
        strcpy(student[classmate-1].birth,BIRTH);
        MAX_ID=big(MAX_ID,student[classmate-1].id);
        MIN_ID=small(MIN_ID,student[classmate-1].id);
    }
    else{
        classmate-=1;
    }
}
/*=========<新增課程資料>============*/
void add_course(Course course[]){
    course_int+=1;
    int ID;
    char NAME[99]={'\0'};
    int TIME;
    int SCORE;
    scanf("%d",&ID);
    scanf("%s",NAME);
    scanf("%d",&TIME);
    scanf("%d",&SCORE);
    int find=0;
    for(int x=0;x<course_int-1;x++){
        if(ID==course[x].id){
            find=1;
            printf("Duplicated\n");
            break;
        }
    }
    if(find==0){
        MAX_course_id=big(MAX_course_id,ID);
        MIN_course_id=small(MIN_course_id,ID);
        course[course_int-1].id=ID;
        strcpy(course[course_int-1].name,NAME);
        course[course_int-1].time=TIME;
        course[course_int-1].score=SCORE;
    }
    else if(find==1){
        course_int-=1;
    }
}
/*=========<顯示學生資料>============*/
void show_student_info(Student student[]){
    for(int x=MIN_ID;x<=MAX_ID;x++){
        for(int i=0;i<classmate;i++){
            if(student[i].id==x){
                printf("%d %s %s %s\n",student[i].id,student[i].name,student[i].space,student[i].birth);
            }
        }
    }
}
/*=========<顯示課程資料>============*/
void show_course_info(Course course[]){
    for(int x=MIN_course_id;x<=MAX_course_id;x++){
        for(int i=0;i<course_int;i++){
            if(course[i].id==x){
                printf("%d %s %d %d\n",course[i].id,course[i].name,course[i].time,course[i].score);
            }
        }
    }
}
/*=========<添加學生成績>============*/
void add_grade(Grade grade[]){
    grade_int+=1;
    int COURSE_ID;
    int STUDENT_ID;
    int GET_GRADE;
    scanf("%d",&COURSE_ID);
    scanf("%d",&STUDENT_ID);
    scanf("%d",&GET_GRADE);
    int find=0;
    for(int x=0;x<grade_int-1;x++){
        if(COURSE_ID==grade[x].course_id && STUDENT_ID==grade[x].student_id){
            find=1;
        }
    }
    if(find==0){
        MAX_grade=big(MAX_grade,GET_GRADE);
        MIN_grade=small(MIN_grade,GET_GRADE);
        grade[grade_int-1].course_id=COURSE_ID;
        grade[grade_int-1].student_id=STUDENT_ID;
        grade[grade_int-1].get_grade=GET_GRADE;
    }
    else if(find==1){
        printf("Duplicated\n");
        grade_int-=1;
    }
}
/*=========<顯示該課程學生排名>============*/
void show_course_grade(Student student[],Grade grade[],Course course[]){
    int search;
    scanf("%d",&search);
    char course_name[1][99]={'\0'};
    for(int x=0;x<course_int;x++){
        if(course[x].id==search){
            strcpy(course_name[0],course[x].name);
        }
    }
    for(int x=MAX_grade;x>=MIN_grade;x--){
        for(int y=0;y<classmate;y++){
            for(int i=0;i<grade_int;i++){
                if(grade[i].course_id==search && student[y].id==grade[i].student_id && grade[i].get_grade==x){
                    printf("%s %s %s %d\n",course_name,student[y].name,student[y].space,grade[i].get_grade);
                }
            }
        }
    }
}
/*=========<總排名>============*/
void ranking(Student student[],Grade grade[],Course course[]){
    int grade_total[99][1]={0};
    char name_list[99][99]={'\0'};
    int get_course[99][1]={0};
    for(int x=0;x<classmate;x++){
        strcpy(name_list[student[x].id],student[x].name);
    }
    for(int x=0;x<grade_int;x++){
        int get=grade[x].get_grade;
        int get_id=grade[x].student_id;
        grade_total[get_id][0]+=get;
    }

    for(int x=0;x<grade_int;x++){
        get_course[grade[x].student_id][0]+=1;
    }
    int answer[99][1]={0};
    for(int x=0;x<99;x++){
        if(get_course[x][0]!=0){
            answer[x][0]=grade_total[x][0]/get_course[x][0];
            MAX_answer=big(MAX_answer,answer[x][0]);
            MIN_answer=small(MIN_answer,answer[x][0]);
        }
    }
    for(int y=MAX_answer;y>=MIN_answer;y--){
        for(int x=0;x<99;x++){
            if(answer[x][0]==y){
                printf("%s\n",name_list[x]);
            }
        }
    }
}
//===================<主程式>=====================
int main(){
    char choose[99]={'\0'};               //定義動作選擇
    Student *student=(Student *)malloc(MAX*sizeof(Student));
    Course *course=(Course *)malloc(MAX*sizeof(Course));
    Grade  *grade=(Grade *)malloc(MAX*sizeof(Grade));
    while(scanf("%s",&choose)!=EOF){
        if(strcmp(choose,"addstudent")==0){
            add_student(student);           //添加學生
        }
        if(strcmp(choose,"addcourse")==0){
            add_course(course);             //添加課程
        }
        if(strcmp(choose,"showstudinfo")==0){
            show_student_info(student);     //顯示學生
        }
        if(strcmp(choose,"showcourseinfo")==0){
            show_course_info(course);       //顯示課程
        }
        if(strcmp(choose,"addgrade")==0){
            add_grade(grade);               //添加成績
        }
        if(strcmp(choose,"showcoursegrade")==0){
            show_course_grade(student,grade,course);//顯示課程學生排名
        }
        if(strcmp(choose,"ranking")==0){
            ranking(student,grade,course);  //總排名
        }
        if(strcmp(choose,"exit")==0){
            free(student);                  //離開
            free(course);
            free(grade);
            break;
        }
    }
    return 0;
}
