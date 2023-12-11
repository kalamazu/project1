#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0; //�洢��λֵ
	struct ListNode* head, * cur, * next;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));     //����һ���µ�����ͷָ��
	head->next = NULL;    //��������next�ÿ�
	cur = head;     //��head����cur��curָ���head��ʼ����ƶ�
	while (l1 || l2 || carry) //����������������һ����Ϊ��ʱ���н�λʱ
	{
		next = (struct ListNode*)malloc(sizeof(struct ListNode));  // ���ٿռ�
		next->next = NULL;
		cur->next = next;    //��curָ��ָ��next
		cur = next;    //��curָ���head�ƶ���next
		l1 != NULL ? (carry += l1->val, l1 = l1->next) : (carry += 0);  // ��l1��Ϊ��ʱ��c = c + l1->val����l1Ϊ��ʱ l1 = l1->next
		l2 != NULL ? (carry += l2->val, l2 = l2->next) : (carry += 0);   // ��l2��Ϊ��ʱ��c = c + l2->val����l2Ϊ��ʱ l2 = l2->next
		cur->val = carry % 10;  // ȡ��λֵ�ĸ�λ��
		carry = carry / 10; // ȡ��λֵ��ʮλ��
	}
	return head->next;    // ֱ�ӷ���head->next
}