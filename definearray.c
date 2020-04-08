#include <stdio.h>

int sjsl;
int i;

void definearray(double arr[])
{
	/* 初始化数组 */
	/* 定义数据数量 */

	printf("数据数量 = ");
	scanf_s("%d", &sjsl);

	/* 定义数组元素 */

	printf("输入数据（用空格分隔）\n");
	/* 定义第 i 个元素 */
	for (i = 0; i < sjsl; i++)
		scanf_s("%lf", &arr[i]);

	/* 数据检验 */
	/* 输出数组中每个元素的值 */
	for (i = 0; i < sjsl; i++)
	{
		printf(" data[%d] = ", i + 1);
		printf("%f\n", arr[i]);
	}
}
