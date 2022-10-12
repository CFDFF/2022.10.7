#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


void explicitly_method()
{

	//已知的量，den k c L dx dt TL TR
	double  s, den, k, c;
	double dx, dt;
	double TL, TR;
	double length;
	int n;

	int F;    //F为时间步，dt为时间步长

	printf("The number of time step:");
	scanf("%d", &F);


	length = 3;
	TL = 3;
	TR = 5;
	den = 100;
	c = 1000;
	k = 10;
	s = 10;
	dt = 100;
	n = 3;
	dx = length / n;

	//赋值
	//scanf("密度：%f", &den);
	//scanf("s：%f", &s);
	//scanf("k：%f", &k);
	//scanf("c：%f", &c);
	//scanf("length：%f", &length);
	//系数ap0 ae0 aw0 ap1  ap1=ap0 +ae0 +aw0 +ap1

	double ap0[10] = { 0 }, ae0[10] = { 0 }, aw0[10] = { 0 }, ap1[10] = { 0 }, b[10] = { 0 };


	for (int i = 1; i <= n; i++)
	{
		//左边界第一个内节点的系数
		if (i == 1)
		{
			ae0[i] = k / dx;
			aw0[i] = k / (dx / 2);
			ap1[i] = den * c * dx / dt;
			ap0[i] = ap1[i] - aw0[i] - ae0[i];
			b[i] = s * dx;


		}
		//右边界第一个内节点的系数
		else if (i == n)
		{
			ae0[i] = k / (dx / 2);
			aw0[i] = k / dx;
			ap1[i] = den * c * dx / dt;
			ap0[i] = ap1[i] - aw0[i] - ae0[i];
			b[i] = s * dx;


		}
		//中间节点的系数
		else
		{
			ae0[i] = k / dx;
			aw0[i] = k / dx;
			ap1[i] = den * c * dx / dt;
			ap0[i] = ap1[i] - aw0[i] - ae0[i];
			b[i] = s * dx;

		}

	}

	//for (int i = 1; i <= n; i++)
	//{

	//	printf("ae0[%d]=%f   ", i, ae0[i]);
	//	printf("ap0[%d]=%f   ", i, ap0[i]);
	//	printf("aw0[%d]=%f   ", i, aw0[i]);
	//	printf("ap1[%d]=%f   ", i, ap1[i]);
	//	printf("\n");
	//}

	double T1[10] = { 0 }, T0[10] = { 0 };
	//for (int i = 1; i <= n; i++)
	//{
	//	T0[i] = 3;
	//}
	T0[0] = TL;
	T0[n + 1] = TR;

	for (int k = 0; k < F; k++)
	{
		for (int i = 1; i <= n; i++)
		{

			T1[i] = (ap0[i] * T0[i] + aw0[i] * T0[i - 1] + ae0[i] * T0[i + 1] + s * dx) / ap1[i];

		}
		for (int j = 1; j <= n; j++)
		{
			T0[j] = T1[j];
		}
		printf("第%d步 ", k);
		for (int j = 1; j <= n; j++)
		{
			printf("T[%d]=%f   ", j, T1[j]);
		}
		printf("\n");
	}










	return;
}