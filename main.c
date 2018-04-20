#include <stdio.h>
#include <math.h>

void definearray();
void uncertaintyassessment();
void differenceaverage();

int sjsl;
int i;
double x[128];

int main()
{
    /* 数据输入 */
    definearray();

    /* 功能选择 */

    printf("数据数量\n");
    scanf("%d", &i);

    switch (i)
	{
	case 0:
	    uncertaintyassessment();
	    break;
	case 1:
	    differenceaverage();
	    break;
	}
}
