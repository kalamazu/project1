#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct  student {//����ṹ��
	int score;
	struct student* next;
} LinkList;//����


LinkList* creat(int n) {//β�巨
	LinkList* head, * node, * end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣨�ṹ��ָ�룩��
	head = (LinkList*)malloc(sizeof(LinkList));//����ͷָ���ַ
	end = head;         //��ʼ��β�ڵ�
	for (int i = 0; i < n; i++) {

		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->score);
		if (head == NULL)//������Ϊ��
			head = end = node;
		else
		{
			end->next = node;
			end = node;
		}
	}//�����ƶ���������������
	end->next = NULL;//��������
	return head;//����ͷָ��
}

LinkList* creat(int n) {//ͷ�巨
	LinkList* head=NULL, * node;
	for (int i = 0; i < n; i++)
	{
		node = (LinkList*)malloc(sizeof(LinkList));//��ÿ���µı�Ԫ�����ڴ棬��ַ
		scanf("%d", &node->score);
		node->next = head;	
		head = node;
	}return head;
}



void change(LinkList* list, int n) {
	LinkList* t = list;
	int i = 0;
	while (i < n && t != NULL)//������ƶ�
	{
		t = t->next;
		i++;
	}
	if (t != NULL) {//������޸�
		puts("����Ҫ�޸ĵ�ֵ");
		scanf("%d", &t->score);
	}
	else {
		puts("�ڵ㲻����");
	}
}


void delet(LinkList* list, int n) {//ɾ��ָ����Ԫ
	LinkList* t = list, * in;
	int i = 0;
	while (i < n && t != NULL) {//������ƶ�
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {//�����ɾ��
		in->next = t->next;
		free(t);
	}
	else {
		puts("�ڵ㲻����");
	}
}


void free_data(LinkList* head) {//�ͷ����б�Ԫ
	LinkList* p = head;
	LinkList* temp;
	while (p) {
		temp = p->next;
		free(p);
		p = temp;
	}
}