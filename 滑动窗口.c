#include<stdio.h>
#include<string.h>
int lengthoflongetsSubstring(char* s)//���ظ��ַ�����ִ������Ӵ�˵����������һ���ַ�������˿�ʹ�û������ڣ�
{
	int result = 0;
	int hush[256] = { 0 };
	int left = 0;
	int right = -1;
	int len = strlen(s);
	while (left < len) {

		if (hush[s[right + 1]] == 0 && right < len - 1) 
		{
			hush[s[++right]]++;
		}
		else
		{
			hush[s[left++]]--;
		}
		if (right - left + 1 > result) 
		{
			result = right - left + 1;
		}
	}   return result;

}
int main() {
	char str[7] = { "qwdadae" };
	int result = lengthoflongetsSubstring(str);
	printf("%d", result);
}