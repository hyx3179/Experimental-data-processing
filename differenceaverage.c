#include <stdio.h>
#include <math.h>

double getAverage (double arr[], int total, int badvalue);
double getvariance (double arr[], int total, double avg, int badvalue);
double getuncertaintyA (int total, double variance);
double getuncertaintyB ();
double getuncertainty (double uncertaintyA, double uncertaintyB);

int sjsl;
int i;
double x[128];
double x1[64];

void differenceaverage ()
{
	/* 开始计算 */
	double avg, variance;

	/* 检查测量质量 */
	for (i = 0; i < sjsl / 2; i++)
	{
		x1[i] = x[i + 1] - x[i];
	}
	for (i = 0; i < sjsl / 2; i++)
	{
		printf (" x[%d] = ", i + 1);
		printf ("%f\n", x1[i]);
	}
	 /**/ for (i = 0; i < sjsl / 2; i++)
	{
		x1[i] = x[i + sjsl / 2] - x[i];
	}
	for (i = 0; i < sjsl / 2; i++)
	{
		printf (" x[%d] = ", i + 1);
		printf ("%f\n", x1[i]);
	}
	 /**/ avg = getAverage (x1, sjsl / 2, 0);

	/* 计算S(x) */
	variance = getvariance (x1, sjsl / 2, avg, 0);

	printf ("平均值 x = %f\n", avg);
	printf ("标准偏差 Sx = %f\n", variance);

}
