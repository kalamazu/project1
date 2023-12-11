#include<stdio.h>  //冒泡法，一直进行邻位互换，第一轮使得最大的一定在最大位，从而依次实现。
void sortArray(int a[], int size)
{
	int temp;//进行i轮循环
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++) //将最大值向上浮动
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

		}
	}

}


#include<stdio.h>//选择排序，一次一次找到最小的（无序队列最小的，有序队列中最大的），一个一个放在有序队列后面
void sortArray(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		int temp;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;

	}
}


#include<stdio.h>//插入排序
void sortarray(int a[], int size)
{
	int i, j, temp;//抓住有序队列后的第一个元素，插入到有序队列之中
	for (i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1])
		{
			temp = a[i];//要往后比较的数是a[i]
			for (j = i - 1; j >= 0 && a[j] > temp; j--) {//如果a[j]比a[i]大，后移留空，首先覆盖a[i]的位置，因此需要temp保存数值；
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;//放入a[i]应该在的地方；
		}
	}
}






#include<stdio.h>
void sort(int arr[], int size)//希尔排序
{
	int i, j, inc, key;
	for (inc = size / 2; inc > 0; inc /= 2)
	{
		for (i = inc; i < size; i++)
		{
			key = arr[i];
			for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
				arr[j] = arr[j - inc];
			arr[j] = key;
		}
	}
}


#include<stdio.h>//快速排序

void swap(int* a, int* b)//交换函数
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int* arr, int maxlen, int begin, int end)
{
	int i, j;
	if (begin < end) {
		i = begin + 1;//选定起始点，第一次为1；
		j = end;//选定末尾
		while (i < j)  //i，j作为”指针”，如果没有重合，则相对移动；
		{
			if (arr[i] > arr[begin])
			{
				swap(&arr[i], &arr[j]);//将a[begin]作为参考，如果大于他，就让这个值到末尾去。
				j--;//原来的j位上已有一个大于begin的值，j向前移动，提供第二个位置；
			}
			else
			{
				i++;//如果这个i值不大于begin，则恰好应该在这，i向后移动，寻找下个比较目标；
			}
		}
		if (arr[i] >= arr[begin])//现在i，j重合，如果这个位置是大于或等于begin的，i后退一位，使得i，j错开，能进行下一轮排序；
		{
			i--;
		}
		swap(&arr[begin], &arr[i]);
		QuickSort(arr, maxlen, begin, i);//递归思想，起始点和终止点重合时停止，此时排序完成
		QuickSort(arr, maxlen, j, end);
	}
}



#include <stdio.h>//堆排序
#include <stdlib.h>
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}


void max_heapify(int arr[], int start, int end) {
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子节点指标在范围内才做比较
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
			son++;
		if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
			return;
		else { //否则交换父子内容再继续子节点和孙节点比较
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}


void heap_sort(int arr[], int len) {
	int i;
	//初始化，i从最后一个父节点开始调整
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//先将第一个元素和已排好元素前一位做交换，再从新调整，直到排序完毕
	for (i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}


int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
#include<stdio.h>