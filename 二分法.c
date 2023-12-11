#include<stdio.h>
int main() {//二分查找
	int key = 17;
	int a[10] = { 12,14,15,16,17,23,25,26,35,60 };
	int mid, left, right;
	while (left <= right) {//当左右不重合时
		mid = (left + right) / 2;
		if (a[mid] == key) {
			f = mid;
			break;
		}
		if (key < a[mid])right = mid - 1;
		if (key > a[mid])left = mid + 1;
	}

}
int digui(int left, int right) {//递归二分
	if (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == key)return mid;
		if (key < a[mid])return digui(left, mid - 1);
		if (key > a[mid])return digui(mid + 1, right);
	}
	else return 0;
}