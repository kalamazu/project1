#include<stdio.h>  //ð�ݷ���һֱ������λ��������һ��ʹ������һ�������λ���Ӷ�����ʵ�֡�
void sortArray(int a[], int size)
{
	int temp;//����i��ѭ��
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++) //�����ֵ���ϸ���
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


#include<stdio.h>//ѡ������һ��һ���ҵ���С�ģ����������С�ģ�������������ģ���һ��һ������������к���
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


#include<stdio.h>//��������
void sortarray(int a[], int size)
{
	int i, j, temp;//ץס������к�ĵ�һ��Ԫ�أ����뵽�������֮��
	for (i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1])
		{
			temp = a[i];//Ҫ����Ƚϵ�����a[i]
			for (j = i - 1; j >= 0 && a[j] > temp; j--) {//���a[j]��a[i]�󣬺������գ����ȸ���a[i]��λ�ã������Ҫtemp������ֵ��
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;//����a[i]Ӧ���ڵĵط���
		}
	}
}






#include<stdio.h>
void sort(int arr[], int size)//ϣ������
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


#include<stdio.h>//��������

void swap(int* a, int* b)//��������
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
		i = begin + 1;//ѡ����ʼ�㣬��һ��Ϊ1��
		j = end;//ѡ��ĩβ
		while (i < j)  //i��j��Ϊ��ָ�롱�����û���غϣ�������ƶ���
		{
			if (arr[i] > arr[begin])
			{
				swap(&arr[i], &arr[j]);//��a[begin]��Ϊ�ο���������������������ֵ��ĩβȥ��
				j--;//ԭ����jλ������һ������begin��ֵ��j��ǰ�ƶ����ṩ�ڶ���λ�ã�
			}
			else
			{
				i++;//������iֵ������begin����ǡ��Ӧ�����⣬i����ƶ���Ѱ���¸��Ƚ�Ŀ�ꣻ
			}
		}
		if (arr[i] >= arr[begin])//����i��j�غϣ�������λ���Ǵ��ڻ����begin�ģ�i����һλ��ʹ��i��j�����ܽ�����һ������
		{
			i--;
		}
		swap(&arr[begin], &arr[i]);
		QuickSort(arr, maxlen, begin, i);//�ݹ�˼�룬��ʼ�����ֹ���غ�ʱֹͣ����ʱ�������
		QuickSort(arr, maxlen, j, end);
	}
}



#include <stdio.h>//������
#include <stdlib.h>
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}


void max_heapify(int arr[], int start, int end) {
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
			son++;
		if (arr[dad] > arr[son]) //������ڵ�����ӽڵ���������ϣ�ֱ����������
			return;
		else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}


void heap_sort(int arr[], int len) {
	int i;
	//��ʼ����i�����һ�����ڵ㿪ʼ����
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ���������ٴ��µ�����ֱ���������
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