#include<stdio.h>
#include<string.h>
int lengthoflongetsSubstring(char* s)//无重复字符的最长字串（是子串说明是连续的一段字符串，因此可使用滑动窗口）
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