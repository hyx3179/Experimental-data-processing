#include <stdio.h>
#include <math.h>

double getAverage (double arr[], int total, int badvalue);
double getvariance (double arr[], int total, double avg, int badvalue);
double getuncertaintyA (int total, double variance);
double getuncertaintyB ();
double getuncertainty (double uncertaintyA, double uncertaintyB);

int sjsl;
int i;
double data[128];
double data1[64];

void differenceaverage ()
{
	/* 检查测量质量 */
	printf ("检查测量质量\n");
	for (i = 0; i < sjsl / 2; i++)
	{
		data1[i] = fabs (data[i + 1] - data[i]);
	}
	for (i = 0; i < sjsl / 2; i++)
	{
		printf (" δ'[%d] = ", i + 1);
		printf ("%f\n", data1[i]);
	}
	do
	{
		i = getchar ();
		printf ("是否使用数据计算？1 是 0 否 ：");
		i = getchar ();
		if (i == '0')
			return;
	}
	while (!(i == '0' || i == '1'));

	/* 逐差计算 */
	printf ("逐差计算\n");
	for (i = 0; i < sjsl / 2; i++)
	{
		data1[i] = fabs (data[i + sjsl / 2] - data[i]);
	}
	for (i = 0; i < sjsl / 2; i++)
	{
		printf (" δ[%d] = ", i + 1);
		printf ("%f\n", data1[i]);
	}
	/* 开始计算 */
	double avg, avgy, variance;

	/* 计算平均值 */
	avg = getAverage (data1, sjsl / 2, 0);
	avgy = avg / sjsl * 2;

	/* 计算S(x) */
	variance = getvariance (data1, sjsl / 2, avg, 0);

	/* 不确定度计算 */
	double uncertaintyA, uncertaintyB, uncertainty, uncertaintyy, Ex;

	/* 不确定度A类分量 */
	uncertaintyA = getuncertaintyA (sjsl / 2, variance);

	/* 不确定度B类分量 */
	uncertaintyB = getuncertaintyB ();

	/* 合成不确定度 u(x) */
	uncertainty = getuncertainty (uncertaintyA, uncertaintyB);
	uncertaintyy = uncertainty / sjsl * 2;

	/* 相对不确定度 Ex */
	Ex = uncertainty / avg * 100;

	/* 直接测量结果 */
	printf ("平均值 δ = %f\n", avg);
	printf ("标准偏差 S(δ) = %f\n", variance);
	printf ("u(A) = %f\n", uncertaintyA);
	printf ("u(B) = %f\n", uncertaintyB);
	printf ("u(δ) = %f\n\n", uncertainty);

	printf ("变化量的平均值 δ(y) = %f\n", avgy);
	printf ("变化量的 u(δ) = %f\n", uncertaintyy);
	printf ("E(δ) = %f%%\n", Ex);

}
