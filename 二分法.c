#include<stdio.h>
int main() {//���ֲ���
	int key = 17;
	int a[10] = { 12,14,15,16,17,23,25,26,35,60 };
	int mid, left, right;
	while (left <= right) {//�����Ҳ��غ�ʱ
		mid = (left + right) / 2;
		if (a[mid] == key) {
			f = mid;
			break;
		}
		if (key < a[mid])right = mid - 1;
		if (key > a[mid])left = mid + 1;
	}

}
int digui(int left, int right) {//�ݹ����
	if (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == key)return mid;
		if (key < a[mid])return digui(left, mid - 1);
		if (key > a[mid])return digui(mid + 1, right);
	}
	else return 0;
}