// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//#include <fiostream.h>  
#include<string> 

using namespace std;

typedef int int32_t;

struct binHeader {
	int32_t rows;
	int32_t cols;
	int32_t step;
	int32_t dtype;
};

int main()
{
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	int features[128];
	printf("随即初始化数组的128个数(范围是0~100).\n");
	for (int i = 0; i<100; i++) {
		features[i] = rand() % 101;    //用rand函数生成0-100的随机数，并赋值给数组a[i]
		printf("%4d", features[i]);
		if (i % 10 == 0 && i != 0)
			printf("\n");
	}

//	getchar();
	string PATH = "C:\\Users\\zykjguoc\\Desktop\\testpic.bin";
	FILE *fp=NULL;
	errno_t err = 0;
	binHeader bin_header;
	bin_header.rows = 128;
	bin_header.cols = 1;
	bin_header.step = 4;
	bin_header.dtype = 5;


	fp = fopen("PATH", "wb");
	fwrite(&bin_header, 4, 4, fp);
	fwrite(&features[0], 4, 128, fp);
	fclose(fp);
	
    return 0;
}

