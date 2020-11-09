#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int N;

int main(int argc, char *argv[]) {

	//定义一个用来存储颜色单词的字符串 
	char* strings[1001];
	//max用来存储出现最多的那个单词出现的次数
	int max = 0;

	while (1) {
		//每次都要记得使max=0;要不然它会存储上一次的数据
		max = 0;
		scanf("%d", &N);
		if (N == 0)	break;
		for (int i = 0; i < N; i++) {
			//写成char str[15]不行，会出错。 
			char *str = (char*)malloc(sizeof(char) * 15);
			scanf("%s", str);
			strings[i] = str;
		}
		//用来暂时指向当前要比较的字符串
		char *Tstr;
		//用来存储出现次数最多的字符串的索引
		int index = -1;//或0都可
		//记录当前字符串出现的次数
		int temp = 0;
		for (int i = 0; i < N; i++) {
			Tstr = strings[i];
			for (int j = 0; j <= i; j++) {
				//这里直接判断 str == x[j] 不行，会出错。 
				if (strcmp(Tstr, strings[j]) == 0) {
					temp++;
				}
			}
			if (temp > max) {
				max = temp;
				index = i;
			}
			temp = 0;
		}
		printf("%s\n", strings[index]);
	}

	return 0;
}
