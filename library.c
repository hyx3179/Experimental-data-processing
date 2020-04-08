#include <stdio.h>
#include <math.h>

int sjsl;
int i;
double data[128];

double getAverage(double arr[], int total, int badvalue)
{
	double sum = 0, avg;
	for (i = 0; i < total; i++)
		sum += arr[i];
	return avg = sum / ((__int64)total - badvalue);
}

double getvariance(double arr[], int total, double avg, int badvalue)
{
	double variance, sum;
	for (sum = 0, i = 0; i < total; i++)
	{
		if (arr[i] != 0)
		{
			sum += pow((arr[i] - avg), 2);
		}
	}
	return variance = sqrt(sum / ((__int64)total - 1 - badvalue));
}

double getuncertaintyA(int total, double variance)
{
	double tp, uncertaintyA;
	printf("输入修正系数tp(ν) = ");
	scanf_s("%lf", &tp);
	return uncertaintyA = tp * variance / sqrt(total);
}

double getuncertaintyB()
{
	double chang, uncertaintyB = 0;
	printf("输入误差限 = ");
	scanf_s("%lf", &chang);
	printf("误差分布形式\n 0 均匀分布\n 1 正态分布\n");
	scanf_s("%d", &i);
	switch (i)
	{
	case 0:
		uncertaintyB = chang / sqrt(3);
		break;
	case 1:
		uncertaintyB = chang / 3;
		break;
	}
	return uncertaintyB;
}

double getuncertainty(double uncertaintyA, double uncertaintyB)
{
	double uncertainty;
	return uncertainty = sqrt(pow(uncertaintyA, 2) + pow(uncertaintyB, 2));
}
