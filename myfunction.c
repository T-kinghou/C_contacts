#include "headerfile.h"  //���Զ����headerfile�������� 
//���ӹ���
void add( List* plist, char *Name,char* Sex,int Age,long long Number,char* Adress){
    Node* p = (Node*)malloc(sizeof(Node));//��̬�����ڴ� 
    if(p == NULL){//�����ڴ�������� 
    	printf("%s",strerror(errno));//���������
		return ; 
	}
    strcpy(p->name,Name);//��Nmae���Ƶ�p->name�� 
    strcpy(p->sex,Sex);//��Sex���Ƶ�p->sex�� 
    p -> age = Age;//ֱ�ӽ���������뵱ǰ�ڵ��½ṹ���������� 
    p -> number = Number;
    strcpy(p->adress,Adress);
    p ->next = NULL;//����һ�ڵ��ַ���ã���ֹҰָ�� 
    if(plist->head){
        //��������
       plist->tail->next = p;//ָ����һ��� 
       plist->tail = p; 
    }else{
        plist->head = p;
        plist->tail = p;
    }
    WriteToFile(plist,"contacts.txt");
    
}

//��ʾ������ϵ�˹���
/*���ں����Ż��������ļ���ȡ�������ܵ�ʵ�֣����
�ѽ��˷�����Ϊ��ʱ�������������Ƽ�ʹ��  Out of date*/
void Print(List *plist){
	
	printf("����\t�Ա�\t����\t �绰����\t סַ\n");
    Node* p;
    for(p=plist->head; p; p=p->next){//������һ�ڵ�ʱpΪNULL����Ϊ0�Զ��˳� 
        printf("%s\t ",p->name);
        printf("%s\t ",p->sex);
        printf("%d\t ",p->age);
        printf("%-11lld\t ",p->number);//-11Ϊ�����11�ַ������llΪ������ 
        printf("%s\n",p->adress);
    }
    printf("\n");
}

//���ҹ���
void search(List* plist, char *Name){//�Ӹ�����ͷָ����� 
    Node* p;
    int ret=0;
    for( p=plist->head; p; p=p->next){
        if( !(strcmp(p->name,Name)) ){
        	system("cls");
            printf("�ҵ��������ϵ��%s\n",p->name);
            printf("������ϢΪ:\n");
            printf("����\t�Ա�\t����\t�绰����\tסַ\n");
            printf("%s\t ",p->name);
        	printf("%s\t ",p->sex);
        	printf("%d\t ",p->age);
        	printf("%lld\t ",p->number);
        	printf("%s\n ",p->adress);
            ret = 1;
            break;
        }
    }
    if( !ret ){
        printf("û���ҵ������ϵ��\n");
    }
}

//ɾ������
void Dellist(List* plist, char *Name){
    
    if(plist->head == NULL){//ȫ��Ϊ�գ������������� 
        printf("����Ϊ�գ�ɾ��ʧ��\n");
        return;
    }
    Node* p = plist->head;
    Node* q = plist->head->next;
    int ret = 0;
    if(!strcmp(p->name, Name)){
        plist->head = q;
        free(p);
        ret = 1;
    }else{
        while(q){
            if(!strcmp(q->name, Name)){
                p->next = q->next;
                free(q);
                ret = 1;
                break;
            }
            p = q;
            q = q->next;
        }
    }
    if(ret){
    	system("cls");
        printf("�ҵ�����ϵ�ˣ���ɾ���ɹ�\n");
        WriteToFile(plist,"contacts.txt");
    }else{
    	system("cls");
        printf("û���ҵ������ϵ�ˣ�ɾ��ʧ��\n");
    }
}

//�����������
/*void Delall( List* plist){
    Node* p,*q;
    for( p=NULL,q=plist->head; p; p=q,p=p->next){
        free(p);
    }
    printf("���������Ѿ����\n");
}   ��ʵ�ֹ���
    ����Ϊɾ��������ϵ��*/  


void Add_(List *list){
    char name[10];
    char sex[5];  //�Ա�
    int age;
    long long number;
    char adress[10];  //סַ
    //List list;
//    list.head = NULL;
//    list.tail = NULL;
    printf("�������������ϵ�˵��������Ա����䣬�绰���룬סַ\n");
    scanf("%s %s%d%lld%s",&name,&sex,&age,&number,&adress);
    //add to the new date
    add( list, name,sex,age,number,adress );
        
}  

void menu(){
    printf("\t\t\t*************ͨѶ¼************\n");
    printf("\t\t\t***  1.����         2.ɾ��  ***\n");
    printf("\t\t\t***  3.����         4.�޸�  ***\n");
    printf("\t\t\t***  5.��ʾ         6.����  ***\n");
    printf("\t\t\t***  7.����         0.�˳�  ***\n");
    printf("\t\t\t*******************************\n");
    }
    
    /*ʹ��ð�������㷨������������*/ 
void SortContact(List *list){
    Node *p, *q, *tail;
    int exchange = 1;
    tail = NULL;
    while(exchange){
        exchange = 0;
        p = list->head;
        while(p->next != tail){
            q = p->next;
            if(strcmp(p->name, q->name) > 0){//���������ַ���С���αȽϽ����������� 
                exchange = 1;
                p->next = q->next;
                q->next = p;
                if(p == list->head){
                    list->head = q;
                }
                else{
                    Node *temp = list->head; //�����м�������ڽ��� 
                    while(temp->next != p){
                        temp = temp->next;
                    }
                    temp->next = q;
                }
                p = q;
            }
            p = p->next;
        }
        tail = p;
    }
    printf("�������\n");
	WriteToFile(list,"contacts.txt"); 
}

void ModifyContact(List *list, char *name) {
    Node *ptr = list->head;  //�������ͷ��λ�� 
    int found = 0;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) { //���������Ƿ���ͬ 
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (found) {
        printf("�������޸ĺ����ϵ��������\n");
        scanf("%s", ptr->name);
        getchar(); // ��ȡ���������뻺�����еĻ��з�
        printf("�������޸ĺ����ϵ���Ա�\n");
        scanf("%s", &ptr->sex);
        //getchar(); // ��ȡ���������뻺�����еĻ��з�
        printf("�������޸ĺ����ϵ�����䣺\n");
        scanf("%d", &ptr->age);
        printf("�������޸ĺ����ϵ�˵绰���룺\n");
        scanf("%ld", &ptr->number);
        printf("�������޸ĺ����ϵ��סַ��\n");
        scanf("%s", ptr->adress);
        printf("�޸ĺ����ϵ����Ϣ���£�\n");
        printf("������%s���Ա�%s�����䣺%d, �绰���룺%lld, סַ��%s\n",
		ptr->name, ptr->sex, ptr->age,ptr->number,ptr->adress);
		WriteToFile(list,"contacts.txt");
		system("cls");
		printf("�Ѿ��޸ĳɹ�!\n");
    }
    else {
    	system("cls");
        printf("δ�ҵ�ָ����ϵ�ˣ��޷��޸ģ�\n");
    }
}

//����ϵ����Ϣд���ļ� 
void WriteToFile(List *list, char *filename){
    FILE *fp;
    Node *p;
    fp = fopen(filename, "w");   //��д�ķ�ʽ���ļ� 
    rewind(fp);
    if(fp == NULL){
        printf("Failed to open file %s: %s\n", filename, strerror(errno)); //�����ʧ���򷵻ش����� 
        return;
    }
    for(p = list->head; p != NULL; p = p->next){
        fprintf(fp, "%s %s %d %11lld %s\n", p->name, p->sex, p->age, p->number, p->adress);
    }
    //rewind(fp);    //���ļ�ָ�뷵���׵�ַ 
    fclose(fp);
    printf("Contacts saved to file %s successfully(�ļ�����ɹ�)!\n", filename);
}

//��ʾ�ļ��е���ϵ����Ϣ 
void PrintFromFile(char *filename){
FILE *fp;
char name[20], sex[5], adress[50];
int age;
long long number;
fp = fopen(filename, "r");
rewind(fp);
if(fp == NULL){
printf("Failed to open file %s: %s\n", filename, strerror(errno)); //�����ʧ���򷵻ش�����
return;
}
printf("����\t�Ա�\t����\t �绰����\t סַ\n");
while(fscanf(fp, "%s %s %d %11lld %s", name, sex, &age, &number, adress) != EOF){
printf("%s\t ", name);
printf("%s\t ", sex);
printf("%d\t ", age);
printf("%-11lld\t ", number);//-11Ϊ�����11�ַ������llΪ������
printf("%s\n", adress);
}
fclose(fp);
printf("\n");
}

//���ļ��ж�ȡ������
void ReadFromFile(List *list, char *filename){
FILE *fp;
Node *p;
char name[20], sex[5], adress[50];
int age;
long long number;
fp = fopen(filename, "r");
rewind(fp); 
if(fp == NULL){
printf("Failed to open file %s: %s\n", filename, strerror(errno)); //�����ʧ���򷵻ش�����
return;
}
while(fscanf(fp, "%s %s %d %11lld %s", name, sex, &age, &number, adress) != EOF){
p = (Node*)malloc(sizeof(Node)); //Ϊ�½ڵ�����ڴ�
strcpy(p->name, name);
strcpy(p->sex, sex);
p->age = age;
p->number = number;
strcpy(p->adress, adress);
p->next = NULL;
if(list->head == NULL){ //�������Ϊ�գ����½ڵ���Ϊͷ�ڵ�
list->head = p;
}
else{ //�����½ڵ���뵽����ĩβ
Node *q = list->head;
while(q->next != NULL){
q = q->next;
}
q->next = p;
list->tail = p;
}
}
fclose(fp);
printf("Contacts loaded from file %s successfully(�ļ���ȡ�ɹ�)!\n", filename);
} 

void EasterEgg(){
    float x, y, a;
    int count = 0;
    int mid_y = 75; // ����ͼ����м�λ��
    int text_len = 30; // ���ֵĳ���
    int text_start = mid_y - text_len / 2; // ���ֵ���ʼλ��
    printf("  \tС���Ա�����ݴ�  ����  ����  ������  ��Ң\n");
    for (y = 1.5f; y > -1.5; y -= 0.1f) {/*ʹ������Ƕ�׵�ѭ��������һ������ͼ��*/
        for (x = -1.5; x < 1.5f; x += 0.05f) {
            a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y < 0.0f) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                if (count >= mid_y && count <= mid_y + text_len && y >= -0.5f && y <= 0.5f) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                    putchar(' ');
                } else {
                    putchar('x');
                }
                count++;
            } else {
                putchar(' ');
            }
        }
        Sleep(100); //������ʱΪ100ms 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        /*ʹ��Windows API����SetConsoleTextAttribute�����ÿ���̨������ı���ɫ��
		��������졢�̡�����������������Ϊ1������ɫ����������Ŀ����Ϊ���������ɫ���ֺ󣬻ָ�����̨�����Ĭ����ɫ���Ա�������������Ӱ�졣*/
        putchar('\n');
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("�������˽�������һ����Ҳ�������������ǵ�ѧϰ���Ļ�������������л����ʦһ�������븶����");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    putchar('\n');
    getchar();
} 

