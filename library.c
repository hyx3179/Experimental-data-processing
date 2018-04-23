#include <stdio.h>
#include <math.h>

int sjsl;
int i;
double data[128];

double getAverage (double arr[], int total, int badvalue)
{
	double sum, avg;
	for (i = 0; i < total; i++)
	{
		sum += arr[i];
	}
	avg = sum / (total - badvalue);
}

double getvariance (double arr[], int total, double avg, int badvalue)
{
	double variance, sum;
	for (sum = 0, i = 0; i < total; i++)
	{
		if (arr[i] != 0)
		{
			sum += pow ((arr[i] - avg), 2);
		}
	}
	variance = sqrt (sum / (total - 1 - badvalue));
}

double getuncertaintyA (int total, double variance)
{
	double tp, uncertaintyA;
	printf ("输入修正系数tp(ν) = ");
	scanf ("%lf", &tp);
	uncertaintyA = tp * variance / sqrt (total);
}

double getuncertaintyB ()
{
	double chang, uncertaintyB;
	printf ("输入误差限 ∆ = ");
	scanf ("%lf", &chang);
	printf ("误差分布形式\n 0 均匀分布\n 1 正态分布\n");
	scanf ("%d", &i);
	switch (i)
	{
	case 0:
		uncertaintyB = chang / sqrt (3);
		break;
	case 1:
		uncertaintyB = chang / 3;
		break;
	}
}

double getuncertainty (double uncertaintyA, double uncertaintyB)
{
	double uncertainty;
	uncertainty = sqrt (pow (uncertaintyA, 2) + pow (uncertaintyB, 2));
}
