/* *********************************************************************************

	EXAMPLE main() for smbPitchShift using MiniAiff to handle sound file i/o
	(c) 2003-2009 S. M. Bernsee, http://www.dspdimension.com
	
	IMPORTANT: requires miniAIFF to be included in the project

********************************************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MiniAiff.h"
#define N 10


void smbPitchShift(float pitchShift, long numSampsToProcess, long fftFrameSize, long osamp, float sampleRate, float *indata, float *outdata);
void pingfang( int *indata, int *outdata);

int main()
{

 
    int i,j;
	float a[N],b[N];

    FILE * fp1 = fopen("mytestmusic1to5.txt", "r");//�������ļ�
   FILE * fp2 = fopen("output.txt", "w");//������ļ�
   
    if (fp1==NULL || fp2==NULL) {//�����ļ�ʧ�����˳�
        puts("���ܴ��ļ���");
        return 0;
    }
	
	/*  if (fp1==NULL) {//�����ļ�ʧ�����˳�
        puts("���ܴ��ļ���");
        return 0;
    }*/
    for(i=0;fscanf(fp1,"%f",a+i)!=EOF;i++);//�������ļ�������ȡ����������a
    for(;i--;)
		fscanf(fp2,"%f",b[i]);//������a����д�뵽����ļ�����
   
	for(j=0;j<N;j++)
	printf("a[j]=%f\n",a[j]);

  smbPitchShift(1.5, 4096, 1024, 4, 24000, &a[0], &b[0]);
   // pingfang(a,b);
   	printf("\n");

	for(j=0;j<N;j++)
	printf("b[j]=%f\n",b[j]);


    fclose(fp1);//�ر������ļ�
    fclose(fp2);//�ر�����ļ����൱�ڱ���
    return 0;


}

void pingfang( int *indata, int *outdata)
{
	int k;
	for(k=0;k<N;k++)
     outdata[k]=indata[k]*indata[k];
}