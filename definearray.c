#include <stdio.h>

int sjsl;
int i;

void definearray(double arr[])
{
	/* ��ʼ������ */
	/* ������������ */

	printf("�������� = ");
	scanf_s("%d", &sjsl);

	/* ��������Ԫ�� */

	printf("�������ݣ��ÿո�ָ���\n");
	/* ����� i ��Ԫ�� */
	for (i = 0; i < sjsl; i++)
		scanf_s("%lf", &arr[i]);

	/* ���ݼ��� */
	/* ���������ÿ��Ԫ�ص�ֵ */
	for (i = 0; i < sjsl; i++)
	{
		printf(" data[%d] = ", i + 1);
		printf("%f\n", arr[i]);
	}
}
