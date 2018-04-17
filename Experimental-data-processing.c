#include <stdio.h>
#include <math.h>

double getAverage(double arr[], int sjsl, int badvalue);
double getvariance(double arr[], int sjsl, double avg, int badvalue);
double getuncertaintyA(double variance, int sjsl);
double getuncertaintyB();
double getuncertainty(double uncertaintyA, double uncertaintyB);

int main()
{
    /* 定义循环变量 */
    int i;

    /* 初始化数组 */
    /* 定义数据数量 */
    int sjsl;

    printf("数据数量\n");
    scanf("%d", &sjsl);

    /* 定义数组 data */
    double data[sjsl];

    /* 定义数组元素 */
    float element;

    printf("输入数据（用空格分隔）\n");
    for (i = 0; i < sjsl; i++)
	{
	    /* 定义第 i 个元素 */
	    scanf("%f", &element);
	    data[i] = element;
	}

    /* 数据检验 */
    /* 输出数组中每个元素的值 */
    for (i = 0; i < sjsl; i++)
	{
	    printf("data[%d] = ", ++i);
	    i--;
	    printf("%f\n", data[i]);
	}
    /* 指出错误值 */

    /* 修正错误值 */

    /* 修正零位误差 */
    int exist;
    double data0;
    do
	{
	    exist = getchar();
	    printf("是否存在零位误差？1 是 0 否\n");
	    exist = getchar();
	    if (exist == '1')
		{
		    printf("零位误差为 ");
		    scanf("%lf", &data0);
		}
	}
    while (!(exist == '0' || exist == '1'));

    /* 开始计算 */
    int badvalue = 0, nobadvalue;
    double avg0, avg, variance;

    do
	{
	    nobadvalue = 1;
	    /* 计算平均值 */
	    avg = getAverage(data, sjsl, badvalue);
	    avg0 = avg - data0;
	    printf("\navg=%f\n", avg);
	    printf("avg0=%f\n", avg0);

	    /* 计算S(x) */
	    variance = getvariance(data, sjsl, avg, badvalue);
	    printf("variance=%f\n\n", variance);

	    /* 剔除坏值 */
	    for (i = 0; i < sjsl; i++)
		{
		    if (data[i] != 0)
			{
			    if (fabs(data[i] - avg) > 3 * variance)
				{
				    printf("data[%d] = ", ++i);
				    i--;
				    printf("%f 为坏值\n", data[i]);
				    data[i] = 0;
				    badvalue++;
				    nobadvalue = 0;
				}
			}
		}
	}
    while (nobadvalue == 0);

    /* 不确定度计算 */
    double uncertaintyA, uncertaintyB, uncertainty, Ex;
    printf("不确定度计算\n");

    /* 不确定度A类分量 */
    uncertaintyA = getuncertaintyA(variance, sjsl);
    printf("\nu(A) = %f\n\n", uncertaintyA);

    /* 不确定度B类分量 */
    uncertaintyB = getuncertaintyB();
    printf("\nu(B) = %f\n", uncertaintyB);

    /* 合成不确定度 u(x) */
    uncertainty = getuncertainty(uncertaintyA, uncertaintyB);
    printf("u(x) = %f\n", uncertainty);

    /* 相对不确定度 Ex */
    Ex = uncertainty / avg0 * 100;
    printf("E(x) = %f%%\n", Ex);

    /* 直接测量结果 */

}

double getAverage(double arr[], int sjsl, int badvalue)
{
    int i;
    double sum, avg;
    for (i = 0; i < sjsl; i++)
	{
	    sum += arr[i];
	}
    avg = sum / (sjsl - badvalue);
}

double getvariance(double arr[], int sjsl, double avg, int badvalue)
{
    int i;
    double variance, sum;
    for (sum = 0, i = 0; i < sjsl; i++)
	{
	    if (arr[i] != 0)
		{
		    sum += pow((arr[i] - avg), 2);
		}
	}
    variance = sqrt(sum / (sjsl - 1 - badvalue));
}

double getuncertaintyA(double variance, int sjsl)
{
    double tp, uncertaintyA;
    printf("输入修正系数tp(ν) = ");
    scanf("%lf", &tp);
    uncertaintyA = tp * variance / sqrt(sjsl);
}

double getuncertaintyB()
{
    int form;
    double chang, uncertaintyB;
    printf("输入误差限 ∆ = ");
    scanf("%lf", &chang);
    printf("误差分布形式\n 0 均匀分布\n 1 正态分布\n");
    scanf("%d", &form);
    switch (form)
	{
	case 0:
	    uncertaintyB = chang / sqrt(3);
	    break;
	case 1:
	    uncertaintyB = chang / 3;
	    break;
	}
}

double getuncertainty(double uncertaintyA, double uncertaintyB)
{
    double uncertainty;
    uncertainty = sqrt(pow(uncertaintyA, 2) + pow(uncertaintyB, 2));
}
