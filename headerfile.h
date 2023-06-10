#ifndef HEADERFILE_H
#define HEADERFILE_H
/*ͨ���궨���ֹͷ�ļ����ظ����� �����ظ��������������������*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <Windows.h>
//��Ҫ���õ�C���Կ� 

enum Option{//ö���ʹ洢��Ĭ�ϴ�0��˳��+1 
	Exit,//�˳����� 
	Add,//���ӹ��� 
	Del,//ɾ��������ϵ�� 
	Search,//Ѱ���ļ����Ƿ񱣴��и���ϵ�� 
	Modify, //�޸Ĺ��� 
	Show,//չʾ������ϵ�� 
	Save,//���湦�� 
	Sort //������ 
};    /*ʹ��ö������ʹ�ô���ɶ��Ը��� */

typedef struct _node{
    char name[10];//���� 
    char sex[5];  //�Ա�
    int age;//���� 
    long long number;//�绰���� 
    char adress[10];  //סַ
    struct _node* next;//����ָ����һ���ڵ�//ָ���� 
}Node;

 typedef struct _list{
    Node* head;//ͷ��¼ָ�� 
    Node* tail;// ��¼Ŀǰλ��ָ�� 
}List;//������¼��ַ����תָ�� 

/*List* plist����ά��ָ��List�ĵ�ַ���Ӷ�����Ҫʹ�ö���ָ������޸ĺͼ�¼ͷָ���βָ�������*/
void add( List *plist, char *Name,char *Sex,int Age,long long Number,char* Adress); 
void Print(List *plist);
void search(List* plist, char *Name);
void Dellist(List* plist, char *Name);
void Add_(List *list);
//void Delall( List* plist);
void menu();  //�˵����ܺ��� 
void SortContact(List *list);//�����ܺ��� 
void ModifyContact(List *list, char *name);  //�޸���ϵ����Ϣ���ܺ��� 
void WriteToFile(List *list, char *filename);  //д���ļ����ܺ��� 
void PrintFromFile(char *filename); //��ȡ�ļ����ܺ���
void ReadFromFile(List *list, char *filename); 
void EasterEgg();  //�ʵ� 

#endif
