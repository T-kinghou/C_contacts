#include "headerfile.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char name[10];//姓名长度 
	int input;//存储选择的功能代号 
	char ret;//存储输入的Yes/No简写字符 
	List list;//维护指针 ，存放目前 
    list.head = NULL;//置空头指针，防止野指针 
    list.tail = NULL;//置空尾指针 ，防止野指针 
    int Is_use = 0;
    ReadFromFile(&list,"contacts.txt");
    do{
	menu();//展示菜单 
	printf("请选择：");
	scanf("%d", &input);
	switch(input){
	//添加好友信息
	case Add:
	    out:
	   	Add_(&list);
	    printf("是否还需要继续增加联系人?  (Y/N)\n");
	    getchar(); /*清空缓冲区中的换行符*/
	    scanf("%c",&ret);
	    if(ret == 'Y') 
		goto out;
		system("cls");//清屏提高可视化 
		printf("添加成功\n"); 
		Is_use = 1;
	   break;
	   //删除好友
	   case Del:
	   printf("请输入你想要删除的联系人的姓名\n");
	   scanf("%s",&name);
	   Dellist(&list, name);
	   Is_use;
	   //printf("删除成功！\n");
	   break;
	   //查找好友信息
	   case Search:
	   	printf("请输入你想要查询的联系人的姓名\n");
	   scanf("%s",&name);
	   search(&list,name);
	   //system("cls");
	   Is_use;
	   break;
	   //修改好友信息
	   case Modify:
       printf("请输入要修改的联系人姓名：\n");
       scanf("%s", &name);
	   ModifyContact(&list, name);
	   Is_use = 1;
	   break;
	   //显示所有好友信息
	   case Show:
	   	system("cls");
	   	if(Is_use == 1){
	   printf("以下是通讯录中所有已保存的联系人信息：\n");
	   	PrintFromFile("contacts.txt");
	   }else{
	   printf("下列是所有好友的信息\n");
	   Print(&list);
	   }	
	   break;
	   //好友排序
	   case Sort:
	   SortContact(&list);
	   system("cls");
	   printf("根据姓名首字母排序成功!\n");
	   Is_use;
	   break; 
	   //通过写入Contacts.txt文档进行保存
	   case Save:
	   WriteToFile(&list, "contacts.txt"); 
	   system("cls");
	   printf("保存到本地文件成功!\n");
	   break;
	   //退出通讯录 
	   case Exit:
	   printf("您将要退出通讯录！\n");
	   printf("是否弹出彩蛋?  (Y/N)\n");
	   getchar(); /*清空缓冲区中的换行符*/
	   scanf("%c",&ret);
	   if(ret == 'Y') {
	   	system("cls");
	   	EasterEgg(); //实现彩蛋 
	   } 
	   exit(0); 
	   break;
    }
}while(1); 
   
	return 0;
}
