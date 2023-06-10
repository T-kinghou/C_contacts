#ifndef HEADERFILE_H
#define HEADERFILE_H
/*通过宏定义防止头文件被重复包含 导致重复定义变量，函数等问题*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <Windows.h>
//需要调用的C语言库 

enum Option{//枚举型存储，默认从0按顺序+1 
	Exit,//退出程序 
	Add,//增加功能 
	Del,//删除单个联系人 
	Search,//寻找文件中是否保存有该联系人 
	Modify, //修改功能 
	Show,//展示已有联系人 
	Save,//保存功能 
	Sort //排序功能 
};    /*使用枚举类型使得代码可读性更高 */

typedef struct _node{
    char name[10];//名字 
    char sex[5];  //性别
    int age;//年龄 
    long long number;//电话号码 
    char adress[10];  //住址
    struct _node* next;//用于指向下一个节点//指针域 
}Node;

 typedef struct _list{
    Node* head;//头记录指针 
    Node* tail;// 记录目前位置指针 
}List;//用来记录地址的中转指针 

/*List* plist接受维护指针List的地址，从而不需要使用二级指针就能修改和记录头指针和尾指针的作用*/
void add( List *plist, char *Name,char *Sex,int Age,long long Number,char* Adress); 
void Print(List *plist);
void search(List* plist, char *Name);
void Dellist(List* plist, char *Name);
void Add_(List *list);
//void Delall( List* plist);
void menu();  //菜单功能函数 
void SortContact(List *list);//排序功能函数 
void ModifyContact(List *list, char *name);  //修改联系人信息功能函数 
void WriteToFile(List *list, char *filename);  //写入文件功能函数 
void PrintFromFile(char *filename); //读取文件功能函数
void ReadFromFile(List *list, char *filename); 
void EasterEgg();  //彩蛋 

#endif
