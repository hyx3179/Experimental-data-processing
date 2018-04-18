#include <stdio.h>
#include <math.h>

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
