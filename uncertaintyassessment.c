#include <stdio.h>
#include <math.h>

double getAverage(double arr[], int total, int badvalue);
double getvariance(double arr[], int total, double avg, int badvalue);
double getuncertaintyA(int total, double variance);
double getuncertaintyB();
double getuncertainty(double uncertaintyA, double uncertaintyB);

int sjsl;
int i;
double data[128];

void uncertaintyassessment()
{
	/* ������λ��� */
	double x0 = 0;
	do
	{
		i = getchar();
		printf("�Ƿ������λ���? 1 �� 0 �� :");
		i = getchar();
		if (i == '1')
		{
			printf("��λ���Ϊ ");
			scanf_s("%lf", &x0);
		}
	} while (!(i == '0' || i == '1'));

	/* ��ʼ���� */
	int badvalue = 0, nobadvalue;
	double avg0, avg, variance;

	do
	{
		nobadvalue = 1;
		/* ����ƽ��ֵ */
		avg = getAverage(data, sjsl, badvalue);
		avg0 = avg - x0;

		/* ����S(x) */
		variance = getvariance(data, sjsl, avg, badvalue);

		/* �޳���ֵ */
		for (i = 0; i < sjsl; i++)
		{
			if (data[i] != 0)
			{
				if (fabs(data[i] - avg) > 3 * variance)
				{
					printf("data[%d] = ", i + 1);
					printf("%f Ϊ��ֵ\n", data[i]);
					data[i] = 0;
					badvalue++;
					nobadvalue = 0;
				}
			}
		}
	} while (nobadvalue == 0);

	/* ��ȷ���ȼ��� */
	double uncertaintyA, uncertaintyB, uncertainty, Ex;

	/* ��ȷ����A����� */
	uncertaintyA = getuncertaintyA(sjsl, variance);

	/* ��ȷ����B����� */
	uncertaintyB = getuncertaintyB();

	/* �ϳɲ�ȷ���� u(x) */
	uncertainty = getuncertainty(uncertaintyA, uncertaintyB);

	/* ��Բ�ȷ���� Ex */
	Ex = uncertainty / avg0 * 100;

	/* ֱ�Ӳ������ */
	printf("ƽ��ֵ x = %f\n", avg);
	printf("������λ���ƽ��ֵ x = %f\n", avg0);
	printf("��׼ƫ�� S(x) = %f\n", variance);
	printf("u(A) = %f\n", uncertaintyA);
	printf("u(B) = %f\n", uncertaintyB);
	printf("u(x) = %f\n", uncertainty);
	printf("E(x) = %f%%\n", Ex);

}
