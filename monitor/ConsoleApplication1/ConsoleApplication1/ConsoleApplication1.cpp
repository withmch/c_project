// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������
	int features[128];
	printf("�漴��ʼ�������128����(��Χ��0~100).\n");
	for (int i = 0; i<100; i++) {
		features[i] = rand() % 101;    //��rand��������0-100�������������ֵ������a[i]
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

