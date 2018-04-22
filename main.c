#include <stdio.h>
#include <math.h>

void definearray ();
void uncertaintyassessment ();
void differenceaverage ();

int sjsl;
int i;
double x[128];

int main ()
{
	/* 数据输入 */
	definearray ();

	/* 功能选择 */

	printf (" 0 不确定性评估\n");
	printf (" 1 逐差法\n");
	printf (" 选择功能 ");
	scanf ("%d", &i);

	switch (i)
	{
	case 0:
		uncertaintyassessment ();
		break;
	case 1:
		differenceaverage ();
		break;
	}
}
