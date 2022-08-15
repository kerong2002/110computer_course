#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include <ctype.h>
char *str_replace (char *source, char *find,  char *rep){
    int find_L=strlen(find);    // 搜尋文字的長度
    int rep_L=strlen(rep);      // 替換文字的長度
    int length=strlen(source)+1;// 結果文字的長度
    int gap=0;                  // 最終的定位偏移量
    char *result = (char *)malloc(sizeof(char) * length);// 建立結果文字
    strcpy(result, source);//複製文字
    char *former=source;                 // 尚未被取代的字串
    char *location= strstr(former, find);// 搜尋文字出現的起始位址指標
    while(location!=NULL){               // 漸進搜尋欲替換的文字
       gap+=(location - former);         // 增加定位偏移量
       result[gap]='\0';                 // 將結束符號定在搜尋到的位址上
       length+=(rep_L-find_L);           // 計算新的長度
       result = (char*)realloc(result, length * sizeof(char));// 變更記憶體空間
       strcat(result, rep);              // 替換的文字串接在結果後面
       gap+=rep_L;                       // 更新定位偏移量
       former=location+find_L;           // 更新尚未被取代的字串的位址
       strcat(result, former);           // 將尚未被取代的文字串接在結果後面
       location= strstr(former, find);   // 搜尋下次文字出現的起始位址指標
   }
   return result;
}
int main(){
    char array[9999]={'\0'};
    scanf("%[^\n]%*c",array);
    char word_dict[999][999]={'\0'};
    char *split=".";
    char *sentence=strtok(array,split);
    int cnt=0;
    while(sentence!=NULL){
        strcpy(word_dict[cnt],sentence);//儲存到字典去
        sentence=strtok(NULL,split);
        cnt+=1;
    }
    while(1){
        char active[99]={'\0'};
        scanf("%[^\n]%*c",active);
        if(active[0]=='1'){
            char pick[3][99]={'\0'};
            char *split=" ";
            char *sentence=strtok(active,split);
            int tt=0;
            while(sentence!=NULL){
                strcpy(pick[tt],sentence);//儲存到字典去
                sentence=strtok(NULL,split);
                tt+=1;
            }
            for(int x=0;x<cnt;x++){
                char* str1 =word_dict[x];
                char*save =word_dict[x];
                char* str2 = str_replace(save,pick[1],pick[2]);
                if(strcmp(str1,str2)!=0){
                    for(int x=0;x<strlen(str2);x++){
                        if(str2[x]==' ' && x==0){
                             continue;
                        }
                        else{
                            printf("%c",str2[x]);
                        }
                    }
                    printf(".\n");
                }
            }
        }
        if(active[0]=='2'){
            char pick[3][99]={'\0'};
            char *split=" ";
            char *sentence=strtok(active,split);
            int tt=0;
            while(sentence!=NULL){
                strcpy(pick[tt],sentence);//儲存到字典去
                sentence=strtok(NULL,split);
                tt+=1;
            }
            for(int x=0;x<cnt;x++){
                char line[999]={'\0'};
                char* str1 =word_dict[x];
                char*save =word_dict[x];
                char* str2 = str_replace(save,pick[1],pick[2]);
                if(strcmp(str1,str2)!=0){
                    strcat(str2,pick[2]);          //終止定義
                    char *name=str2;               //定義成指標，做尋找動作
                    char *set=pick[2];             //挑選
                    char *find=strstr(name,set);   //挑選目標
                    while(find!=NULL){
                        find[0]='\0';              //定義找到為'\0'
                        strcat(line,name);
                        if(*(find+strlen(set))!=0){
                            strcat(line,pick[2]);
                            strcat(line," ");
                            strcat(line,pick[1]);
                        }
                        name=find+strlen(set);      //下一個搜尋目標位置
                        find=strstr(name,set);
                    }
                    for(int x=0;x<strlen(line);x++){
                        if(line[x]==' ' && x==0){
                            continue;
                        }
                        else{
                            printf("%c",line[x]);
                        }
                    }
                    printf(".\n");
                }
            }
        }
        if(active[0]=='3'){
            memset(array,'\0',sizeof(char)*9999);
            scanf("%[^\n]%*c",array);
            char *take=".";
            char *list_1=strtok(array,take);
            cnt=0;
            while(list_1!=NULL){
                strcpy(word_dict[cnt],list_1);//儲存到字典去
                list_1=strtok(NULL,take);
                cnt+=1;
            }
        }
        if(active[0]=='4'){
            break;
        }
    }
    return 0;
}
