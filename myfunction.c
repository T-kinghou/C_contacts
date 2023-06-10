#include "headerfile.h"  //在自定义的headerfile库下运行 
//增加功能
void add( List* plist, char *Name,char* Sex,int Age,long long Number,char* Adress){
    Node* p = (Node*)malloc(sizeof(Node));//动态分配内存 
    if(p == NULL){//若无内存或分配出错 
    	printf("%s",strerror(errno));//打出错误码
		return ; 
	}
    strcpy(p->name,Name);//将Nmae复制到p->name中 
    strcpy(p->sex,Sex);//将Sex复制到p->sex中 
    p -> age = Age;//直接将年龄更改入当前节点下结构体年龄内容 
    p -> number = Number;
    strcpy(p->adress,Adress);
    p ->next = NULL;//让下一节点地址空置，防止野指针 
    if(plist->head){
        //连接链表
       plist->tail->next = p;//指向下一结点 
       plist->tail = p; 
    }else{
        plist->head = p;
        plist->tail = p;
    }
    WriteToFile(plist,"contacts.txt");
    
}

//显示所有联系人功能
/*但在后期优化中由于文件读取函数功能的实现，因此
已将此方法列为过时方法，即不再推荐使用  Out of date*/
void Print(List *plist){
	
	printf("姓名\t性别\t年龄\t 电话号码\t 住址\n");
    Node* p;
    for(p=plist->head; p; p=p->next){//若无下一节点时p为NULL条件为0自动退出 
        printf("%s\t ",p->name);
        printf("%s\t ",p->sex);
        printf("%d\t ",p->age);
        printf("%-11lld\t ",p->number);//-11为左对齐11字符，后接ll为长整型 
        printf("%s\n",p->adress);
    }
    printf("\n");
}

//查找功能
void search(List* plist, char *Name){//从该链表头指针遍历 
    Node* p;
    int ret=0;
    for( p=plist->head; p; p=p->next){
        if( !(strcmp(p->name,Name)) ){
        	system("cls");
            printf("找到了这个联系人%s\n",p->name);
            printf("他的信息为:\n");
            printf("姓名\t性别\t年龄\t电话号码\t住址\n");
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
        printf("没有找到这个联系人\n");
    }
}

//删除功能
void Dellist(List* plist, char *Name){
    
    if(plist->head == NULL){//全部为空，即链表无内容 
        printf("链表为空，删除失败\n");
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
        printf("找到该联系人，并删除成功\n");
        WriteToFile(plist,"contacts.txt");
    }else{
    	system("cls");
        printf("没有找到这个联系人，删除失败\n");
    }
}

//清空所有链表
/*void Delall( List* plist){
    Node* p,*q;
    for( p=NULL,q=plist->head; p; p=q,p=p->next){
        free(p);
    }
    printf("整个链表已经清空\n");
}   待实现功能
    作用为删除所有联系人*/  


void Add_(List *list){
    char name[10];
    char sex[5];  //性别
    int age;
    long long number;
    char adress[10];  //住址
    //List list;
//    list.head = NULL;
//    list.tail = NULL;
    printf("请依次输入该联系人的姓名，性别，年龄，电话号码，住址\n");
    scanf("%s %s%d%lld%s",&name,&sex,&age,&number,&adress);
    //add to the new date
    add( list, name,sex,age,number,adress );
        
}  

void menu(){
    printf("\t\t\t*************通讯录************\n");
    printf("\t\t\t***  1.增加         2.删除  ***\n");
    printf("\t\t\t***  3.查找         4.修改  ***\n");
    printf("\t\t\t***  5.显示         6.保存  ***\n");
    printf("\t\t\t***  7.排序         0.退出  ***\n");
    printf("\t\t\t*******************************\n");
    }
    
    /*使用冒泡排序算法进行链表排序*/ 
void SortContact(List *list){
    Node *p, *q, *tail;
    int exchange = 1;
    tail = NULL;
    while(exchange){
        exchange = 0;
        p = list->head;
        while(p->next != tail){
            q = p->next;
            if(strcmp(p->name, q->name) > 0){//根据名字字符大小依次比较进行升序排序 
                exchange = 1;
                p->next = q->next;
                q->next = p;
                if(p == list->head){
                    list->head = q;
                }
                else{
                    Node *temp = list->head; //定义中间变量用于交换 
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
    printf("排序完成\n");
	WriteToFile(list,"contacts.txt"); 
}

void ModifyContact(List *list, char *name) {
    Node *ptr = list->head;  //获得链表头的位置 
    int found = 0;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) { //查找名字是否相同 
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (found) {
        printf("请输入修改后的联系人姓名：\n");
        scanf("%s", ptr->name);
        getchar(); // 读取并丢弃输入缓冲区中的换行符
        printf("请输入修改后的联系人性别：\n");
        scanf("%s", &ptr->sex);
        //getchar(); // 读取并丢弃输入缓冲区中的换行符
        printf("请输入修改后的联系人年龄：\n");
        scanf("%d", &ptr->age);
        printf("请输入修改后的联系人电话号码：\n");
        scanf("%ld", &ptr->number);
        printf("请输入修改后的联系人住址：\n");
        scanf("%s", ptr->adress);
        printf("修改后的联系人信息如下：\n");
        printf("姓名：%s，性别：%s，年龄：%d, 电话号码：%lld, 住址：%s\n",
		ptr->name, ptr->sex, ptr->age,ptr->number,ptr->adress);
		WriteToFile(list,"contacts.txt");
		system("cls");
		printf("已经修改成功!\n");
    }
    else {
    	system("cls");
        printf("未找到指定联系人，无法修改！\n");
    }
}

//将联系人信息写入文件 
void WriteToFile(List *list, char *filename){
    FILE *fp;
    Node *p;
    fp = fopen(filename, "w");   //以写的方式打开文件 
    rewind(fp);
    if(fp == NULL){
        printf("Failed to open file %s: %s\n", filename, strerror(errno)); //如果打开失败则返回错误码 
        return;
    }
    for(p = list->head; p != NULL; p = p->next){
        fprintf(fp, "%s %s %d %11lld %s\n", p->name, p->sex, p->age, p->number, p->adress);
    }
    //rewind(fp);    //将文件指针返回首地址 
    fclose(fp);
    printf("Contacts saved to file %s successfully(文件保存成功)!\n", filename);
}

//显示文件中的联系人信息 
void PrintFromFile(char *filename){
FILE *fp;
char name[20], sex[5], adress[50];
int age;
long long number;
fp = fopen(filename, "r");
rewind(fp);
if(fp == NULL){
printf("Failed to open file %s: %s\n", filename, strerror(errno)); //如果打开失败则返回错误码
return;
}
printf("姓名\t性别\t年龄\t 电话号码\t 住址\n");
while(fscanf(fp, "%s %s %d %11lld %s", name, sex, &age, &number, adress) != EOF){
printf("%s\t ", name);
printf("%s\t ", sex);
printf("%d\t ", age);
printf("%-11lld\t ", number);//-11为左对齐11字符，后接ll为长整型
printf("%s\n", adress);
}
fclose(fp);
printf("\n");
}

//从文件中读取到链表
void ReadFromFile(List *list, char *filename){
FILE *fp;
Node *p;
char name[20], sex[5], adress[50];
int age;
long long number;
fp = fopen(filename, "r");
rewind(fp); 
if(fp == NULL){
printf("Failed to open file %s: %s\n", filename, strerror(errno)); //如果打开失败则返回错误码
return;
}
while(fscanf(fp, "%s %s %d %11lld %s", name, sex, &age, &number, adress) != EOF){
p = (Node*)malloc(sizeof(Node)); //为新节点分配内存
strcpy(p->name, name);
strcpy(p->sex, sex);
p->age = age;
p->number = number;
strcpy(p->adress, adress);
p->next = NULL;
if(list->head == NULL){ //如果链表为空，则将新节点作为头节点
list->head = p;
}
else{ //否则将新节点插入到链表末尾
Node *q = list->head;
while(q->next != NULL){
q = q->next;
}
q->next = p;
list->tail = p;
}
}
fclose(fp);
printf("Contacts loaded from file %s successfully(文件读取成功)!\n", filename);
} 

void EasterEgg(){
    float x, y, a;
    int count = 0;
    int mid_y = 75; // 爱心图像的中间位置
    int text_len = 30; // 文字的长度
    int text_start = mid_y - text_len / 2; // 文字的起始位置
    printf("  \t小组成员：侯贻达  崔涛  苟蓉  闭雅婷  胡尧\n");
    for (y = 1.5f; y > -1.5; y -= 0.1f) {/*使用两个嵌套的循环来绘制一个心形图案*/
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
        Sleep(100); //设置延时为100ms 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        /*使用Windows API函数SetConsoleTextAttribute来设置控制台输出的文本颜色。
		在这里，将红、绿、蓝三个分量都设置为1，即白色。这样做的目的是为了在输出蓝色文字后，恢复控制台输出的默认颜色，以便后续的输出不受影响。*/
        putchar('\n');
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("代码至此结束，大一生活也将结束，但我们的学习生涯还将继续，最后感谢苏老师一年的陪伴与付出！");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    putchar('\n');
    getchar();
} 

