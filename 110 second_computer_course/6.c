#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include <ctype.h>
char *str_replace (char *source, char *find,  char *rep){
    int find_L=strlen(find);    // �j�M��r������
    int rep_L=strlen(rep);      // ������r������
    int length=strlen(source)+1;// ���G��r������
    int gap=0;                  // �̲ת��w�찾���q
    char *result = (char *)malloc(sizeof(char) * length);// �إߵ��G��r
    strcpy(result, source);//�ƻs��r
    char *former=source;                 // �|���Q���N���r��
    char *location= strstr(former, find);// �j�M��r�X�{���_�l��}����
    while(location!=NULL){               // ���i�j�M����������r
       gap+=(location - former);         // �W�[�w�찾���q
       result[gap]='\0';                 // �N�����Ÿ��w�b�j�M�쪺��}�W
       length+=(rep_L-find_L);           // �p��s������
       result = (char*)realloc(result, length * sizeof(char));// �ܧ�O����Ŷ�
       strcat(result, rep);              // ��������r�걵�b���G�᭱
       gap+=rep_L;                       // ��s�w�찾���q
       former=location+find_L;           // ��s�|���Q���N���r�ꪺ��}
       strcat(result, former);           // �N�|���Q���N����r�걵�b���G�᭱
       location= strstr(former, find);   // �j�M�U����r�X�{���_�l��}����
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
        strcpy(word_dict[cnt],sentence);//�x�s��r��h
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
                strcpy(pick[tt],sentence);//�x�s��r��h
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
                strcpy(pick[tt],sentence);//�x�s��r��h
                sentence=strtok(NULL,split);
                tt+=1;
            }
            for(int x=0;x<cnt;x++){
                char line[999]={'\0'};
                char* str1 =word_dict[x];
                char*save =word_dict[x];
                char* str2 = str_replace(save,pick[1],pick[2]);
                if(strcmp(str1,str2)!=0){
                    strcat(str2,pick[2]);          //�פ�w�q
                    char *name=str2;               //�w�q�����СA���M��ʧ@
                    char *set=pick[2];             //�D��
                    char *find=strstr(name,set);   //�D��ؼ�
                    while(find!=NULL){
                        find[0]='\0';              //�w�q��쬰'\0'
                        strcat(line,name);
                        if(*(find+strlen(set))!=0){
                            strcat(line,pick[2]);
                            strcat(line," ");
                            strcat(line,pick[1]);
                        }
                        name=find+strlen(set);      //�U�@�ӷj�M�ؼЦ�m
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
                strcpy(word_dict[cnt],list_1);//�x�s��r��h
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
