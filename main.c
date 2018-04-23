#include <stdio.h>
#include <math.h>

void definearray (double arr[]);
void uncertaintyassessment ();
void differenceaverage ();
void svbmp (double y[]);

int sjsl;
int i;
double data[128];

int main ()
{
	/* 功能选择 */
	int t;
	printf (" 0 不确定性评估\n");
	printf (" 1 逐差法\n");
	printf (" 2 画图（先输入y）\n");
	printf (" 选择功能 ");
	scanf ("%d", &t);

	/* 数据输入 */
	definearray (data);

	switch (t)
	{
	case 0:
		uncertaintyassessment ();
		break;
	case 1:
		differenceaverage ();
		break;
	case 2:
		svbmp (data);
		break;
	}
}
