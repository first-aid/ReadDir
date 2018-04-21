#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX(A,B) ((A)>(B))?(A):(B)

//获取文件内每行最大长度
int getFileLineMaxLength(FILE *fd)
{
	int ch;
	int pos=0;
	int tlen=0;
	int maxlen=0;
	
	rewind(fd);
	while( (ch=fgetc(fd)) != EOF) {
		if(ch=='\n') {
			pos=ftell(fd);
			maxlen=MAX(maxlen, pos-tlen);
			tlen=pos;
		}
	} 
	
	return maxlen;
}


int main()
{
	FILE *fd;
	int ret;

	fd=fopen("1.txt", "r");
	ret = getFileLineMaxLength(fd);
	printf("len:%d\n", ret);
	fclose(fd);
}
