#include <stdio.h>
#include <math.h>

void definearray(double arr[]);
void uncertaintyassessment();
void differenceaverage();
void svbmp(double y[]);

int sjsl;
int i;
double data[128];

int main()
{
	/* ����ѡ�� */
	int t;
	printf(" 0 ��ȷ��������\n");
	printf(" 1 ��\n");
	printf(" 2 ��ͼ��������y��\n");
	printf(" ѡ���� ");
	scanf_s("%d", &t);

	/* �������� */
	definearray(data);

	switch (t)
	{
	case 0:
		uncertaintyassessment();
		break;
	case 1:
		differenceaverage();
		break;
	case 2:
		svbmp(data);
		break;
	}
}
