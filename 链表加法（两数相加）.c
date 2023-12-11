#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0; //存储进位值
	struct ListNode* head, * cur, * next;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));     //创建一个新的链表头指针
	head->next = NULL;    //并将它的next置空
	cur = head;     //将head赋给cur，cur指针从head开始向后移动
	while (l1 || l2 || carry) //当两个链表其中有一个不为空时或有进位时
	{
		next = (struct ListNode*)malloc(sizeof(struct ListNode));  // 开辟空间
		next->next = NULL;
		cur->next = next;    //将cur指针指向next
		cur = next;    //将cur指针从head移动到next
		l1 != NULL ? (carry += l1->val, l1 = l1->next) : (carry += 0);  // 当l1不为空时，c = c + l1->val，当l1为空时 l1 = l1->next
		l2 != NULL ? (carry += l2->val, l2 = l2->next) : (carry += 0);   // 当l2不为空时，c = c + l2->val，当l2为空时 l2 = l2->next
		cur->val = carry % 10;  // 取进位值的个位数
		carry = carry / 10; // 取进位值的十位数
	}
	return head->next;    // 直接返回head->next
}