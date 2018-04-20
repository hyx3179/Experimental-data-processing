#include <stdio.h>
#include <math.h>

double getAverage(double arr[], int total, int badvalue);
double getvariance(double arr[], int total, double avg, int badvalue);
double getuncertaintyA(int total, double variance);
double getuncertaintyB();
double getuncertainty(double uncertaintyA, double uncertaintyB);

int sjsl;
int i;
double x[128];

void uncertaintyassessment()
{
    /* 修正零位误差 */
    double x0 = 0;
    do
	{
	    i = getchar();
	    printf("是否存在零位误差？1 是 0 否\n");
	    i = getchar();
	    if (i == '1')
		{
		    printf("零位误差为 ");
		    scanf("%lf", &x0);
		}
	}
    while (!(i == '0' || i == '1'));

    /* 开始计算 */
    int badvalue = 0, nobadvalue;
    double avg0, avg, variance;

    do
	{
	    nobadvalue = 1;
	    /* 计算平均值 */
	    avg = getAverage(x, sjsl, badvalue);
	    avg0 = avg - x0;

	    /* 计算S(x) */
	    variance = getvariance(x, sjsl, avg, badvalue);

	    /* 剔除坏值 */
	    for (i = 0; i < sjsl; i++)
		{
		    if (x[i] != 0)
			{
			    if (fabs(x[i] - avg) > 3 * variance)
				{
				    printf("x[%d] = ", i + 1);
				    printf("%f 为坏值\n", x[i]);
				    x[i] = 0;
				    badvalue++;
				    nobadvalue = 0;
				}
			}
		}
	}
    while (nobadvalue == 0);

    /* 不确定度计算 */
    double uncertaintyA, uncertaintyB, uncertainty, Ex;

    /* 不确定度A类分量 */
    uncertaintyA = getuncertaintyA(sjsl, variance);

    /* 不确定度B类分量 */
    uncertaintyB = getuncertaintyB();

    /* 合成不确定度 u(x) */
    uncertainty = getuncertainty(uncertaintyA, uncertaintyB);

    /* 相对不确定度 Ex */
    Ex = uncertainty / avg0 * 100;

    /* 直接测量结果 */
    printf("平均值 x = %f\n", avg);
    printf("消除零位误差平均值 x = %f\n", avg0);
    printf("标准偏差 Sx = %f\n", variance);
    printf("u(A) = %f\n", uncertaintyA);
    printf("u(B) = %f\n", uncertaintyB);
    printf("u(x) = %f\n", uncertainty);
    printf("E(x) = %f%%\n", Ex);

}
