#define _CRT_SECURE_NO_DEPRECATE


#include<stdio.h>   //带参宏
#define y(a,b,c) c=a;a=b;b=c
int main() {
	int a = 1;
	int b = 2;
	int c;
	y(a, b, c);
	printf("%d %d", a, b);
}

#include<stdio.h>
#define y(a,b) a%b;
int main() {
	int a;
	int b;
	scanf("%d %d", &a, &b);
	int c = y(a, b);
	printf("%d", c);
}

#include<stdio.h>//三角形面积
#define area(a,b,c) (a+b+c)/2 
#include<math.h>
int main() {
	float duanbian;
	float duanbian1;
	float changbian;
	scanf_s("%f %f %f", &duanbian, &duanbian1, &changbian);

	float c = area(duanbian, duanbian1, changbian);
	float mianji = sqrt(c * (c - duanbian) * (c - duanbian1) * (c - changbian));
	printf("%.3f", mianji);


}

#include<stdio.h>//闰年
#define LEAP_YEAR(a) (a%400==0)||(a%4==0&&a%100!=0)?'L':'N'
int main() {
	int a;
	scanf_s("%d", &a);
	char ch = LEAP_YEAR(a);
	printf("%c", ch);
}

