#include "headerfile.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char name[10];//�������� 
	int input;//�洢ѡ��Ĺ��ܴ��� 
	char ret;//�洢�����Yes/No��д�ַ� 
	List list;//ά��ָ�� �����Ŀǰ 
    list.head = NULL;//�ÿ�ͷָ�룬��ֹҰָ�� 
    list.tail = NULL;//�ÿ�βָ�� ����ֹҰָ�� 
    int Is_use = 0;
    ReadFromFile(&list,"contacts.txt");
    do{
	menu();//չʾ�˵� 
	printf("��ѡ��");
	scanf("%d", &input);
	switch(input){
	//��Ӻ�����Ϣ
	case Add:
	    out:
	   	Add_(&list);
	    printf("�Ƿ���Ҫ����������ϵ��?  (Y/N)\n");
	    getchar(); /*��ջ������еĻ��з�*/
	    scanf("%c",&ret);
	    if(ret == 'Y') 
		goto out;
		system("cls");//������߿��ӻ� 
		printf("��ӳɹ�\n"); 
		Is_use = 1;
	   break;
	   //ɾ������
	   case Del:
	   printf("����������Ҫɾ������ϵ�˵�����\n");
	   scanf("%s",&name);
	   Dellist(&list, name);
	   Is_use;
	   //printf("ɾ���ɹ���\n");
	   break;
	   //���Һ�����Ϣ
	   case Search:
	   	printf("����������Ҫ��ѯ����ϵ�˵�����\n");
	   scanf("%s",&name);
	   search(&list,name);
	   //system("cls");
	   Is_use;
	   break;
	   //�޸ĺ�����Ϣ
	   case Modify:
       printf("������Ҫ�޸ĵ���ϵ��������\n");
       scanf("%s", &name);
	   ModifyContact(&list, name);
	   Is_use = 1;
	   break;
	   //��ʾ���к�����Ϣ
	   case Show:
	   	system("cls");
	   	if(Is_use == 1){
	   printf("������ͨѶ¼�������ѱ������ϵ����Ϣ��\n");
	   	PrintFromFile("contacts.txt");
	   }else{
	   printf("���������к��ѵ���Ϣ\n");
	   Print(&list);
	   }	
	   break;
	   //��������
	   case Sort:
	   SortContact(&list);
	   system("cls");
	   printf("������������ĸ����ɹ�!\n");
	   Is_use;
	   break; 
	   //ͨ��д��Contacts.txt�ĵ����б���
	   case Save:
	   WriteToFile(&list, "contacts.txt"); 
	   system("cls");
	   printf("���浽�����ļ��ɹ�!\n");
	   break;
	   //�˳�ͨѶ¼ 
	   case Exit:
	   printf("����Ҫ�˳�ͨѶ¼��\n");
	   printf("�Ƿ񵯳��ʵ�?  (Y/N)\n");
	   getchar(); /*��ջ������еĻ��з�*/
	   scanf("%c",&ret);
	   if(ret == 'Y') {
	   	system("cls");
	   	EasterEgg(); //ʵ�ֲʵ� 
	   } 
	   exit(0); 
	   break;
    }
}while(1); 
   
	return 0;
}
