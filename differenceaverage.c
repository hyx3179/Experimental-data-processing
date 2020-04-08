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
double data1[64];

void differenceaverage()
{
	/* ���������� */
	printf("����������\n");
	for (i = 0; i < sjsl / 2; i++)
		data1[i] = fabs(data[i + 1] - data[i]);

	for (i = 0; i < sjsl / 2; i++)
	{
		printf(" ��'[%d] = ", i + 1);
		printf("%f\n", data1[i]);
	}

	do
	{
		i = getchar();
		printf("�Ƿ�ʹ�����ݼ���? 1 �� 0 ��:");
		i = getchar();
		if (i == '0')
			return;
	} while (!(i == '0' || i == '1'));

	/* ������ */
	printf("������\n");
	for (i = 0; i < sjsl / 2; i++)
		data1[i] = fabs(data[i + sjsl / 2] - data[i]);

	for (i = 0; i < sjsl / 2; i++)
	{
		printf(" ��[%d] = ", i + 1);
		printf("%f\n", data1[i]);
	}

	/* ��ʼ���� */
	double avg, avgy, variance;

	/* ����ƽ��ֵ */
	avg = getAverage(data1, sjsl / 2, 0);
	avgy = avg / sjsl * 2;

	/* ����S(x) */
	variance = getvariance(data1, sjsl / 2, avg, 0);

	/* ��ȷ���ȼ��� */
	double uncertaintyA, uncertaintyB, uncertainty, uncertaintyy, Ex;

	/* ��ȷ����A����� */
	uncertaintyA = getuncertaintyA(sjsl / 2, variance);

	/* ��ȷ����B����� */
	uncertaintyB = getuncertaintyB();

	/* �ϳɲ�ȷ���� u(x) */
	uncertainty = getuncertainty(uncertaintyA, uncertaintyB);
	uncertaintyy = uncertainty / sjsl * 2;

	/* ��Բ�ȷ���� Ex */
	Ex = uncertainty / avg * 100;

	/* ֱ�Ӳ������ */
	printf("ƽ��ֵ �� = %f\n", avg);
	printf("��׼ƫ�� S(��) = %f\n", variance);
	printf("u(A) = %f\n", uncertaintyA);
	printf("u(B) = %f\n", uncertaintyB);
	printf("u(��) = %f\n\n", uncertainty);

	printf("�仯����ƽ��ֵ ��(y) = %f\n", avgy);
	printf("�仯���� u(��) = %f\n", uncertaintyy);
	printf("E(��) = %f%%\n", Ex);

}
