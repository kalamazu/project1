#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct  student {//链表结构体
	int score;
	struct student* next;
} LinkList;//别名


LinkList* creat(int n) {//尾插法
	LinkList* head, * node, * end;//定义头节点，普通节点，尾部节点（结构体指针）；
	head = (LinkList*)malloc(sizeof(LinkList));//分配头指针地址
	end = head;         //初始化尾节点
	for (int i = 0; i < n; i++) {

		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->score);
		if (head == NULL)//若链表为空
			head = end = node;
		else
		{
			end->next = node;
			end = node;
		}
	}//链表移动，并且输入数据
	end->next = NULL;//结束创建
	return head;//返回头指针
}

LinkList* creat(int n) {//头插法
	LinkList* head=NULL, * node;
	for (int i = 0; i < n; i++)
	{
		node = (LinkList*)malloc(sizeof(LinkList));//对每个新的表元分配内存，地址
		scanf("%d", &node->score);
		node->next = head;	
		head = node;
	}return head;
}



void change(LinkList* list, int n) {
	LinkList* t = list;
	int i = 0;
	while (i < n && t != NULL)//链表的移动
	{
		t = t->next;
		i++;
	}
	if (t != NULL) {//链表的修改
		puts("输入要修改的值");
		scanf("%d", &t->score);
	}
	else {
		puts("节点不存在");
	}
}


void delet(LinkList* list, int n) {//删除指定表元
	LinkList* t = list, * in;
	int i = 0;
	while (i < n && t != NULL) {//链表的移动
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {//链表的删除
		in->next = t->next;
		free(t);
	}
	else {
		puts("节点不存在");
	}
}


void free_data(LinkList* head) {//释放所有表元
	LinkList* p = head;
	LinkList* temp;
	while (p) {
		temp = p->next;
		free(p);
		p = temp;
	}
}