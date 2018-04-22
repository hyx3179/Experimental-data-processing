#include <stdio.h>

int sjsl;
int i;
double x[128];

void definearray ()
{
	/* 初始化数组 */
	/* 定义数据数量 */

	printf ("数据数量 = ");
	scanf ("%d", &sjsl);

	/* 定义数组元素 */

	printf ("输入数据（用空格分隔）\n");
	for (i = 0; i < sjsl; i++)
	{
		/* 定义第 i 个元素 */
		scanf ("%lf", &x[i]);
	}

	/* 数据检验 */
	/* 输出数组中每个元素的值 */
	for (i = 0; i < sjsl; i++)
	{
		printf (" x[%d] = ", i + 1);
		printf ("%f\n", x[i]);
	}
}
