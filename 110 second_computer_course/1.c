#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char set[1001];             //��J���}�C
    char list[1001];            //�h0���}�C
    while(scanf("%s",set)!=EOF){//Ū��end of file ����
        int not_const=0;        //�����O�_��0
        int exit=0;             //�פ����@�A����0
        int count=0;
        int size=0;
        int exit1=0;            //�פ����G�A�t��
        for(int x=0;x<strlen(set);x++){
            if(set[x]=='-'){
                exit1=1;//�P�_�O�_���t��
            }
            if(set[x]=='0'){
                exit+=1;//�P�_�����O�_��0
            }
            if(set[x]!='0'){
                not_const=1;//�P�_�O�_Ū��0
            }
            if(not_const==1){   //�}�l�g�J�}�C
                size+=1;        //�P�_���ƪ���
                list[count]=set[x];
                count+=1;       //�p��
            }

        }
//================<�פ����>=========================
        if(exit1==1) break;         //�t�����}
        if(exit==strlen(set)) break;//�������O�s���}
//===================================================
        char reverse[size];//�����
        int total=0;       //�[�`
        for(int x=size-1,y=0;x>=0;x--,y++){
            total += list[x]-'0';
            reverse[y]=list[x];
        }
        int ok=0;
        for(int x=0;x<size;x++){
            if(reverse[x]!='0'){
                ok=1;//�P�_��X�Ĥ@��O�_��0
            }
            if(ok==1){
                printf("%c",reverse[x]);
            }
        }
        printf(" %d\n",total);
    }
    return 0;
}
