#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void definearray(double arr[]);

int i;
int sjsl;
int w, h;
int x[128];

void WriteBMP(char* pixels)
{
	int bmi[] = { w * h * 3 + 54, 0, 54, 40, w, h, 1 | 24 << 16, 0, 0, 0, 0, 0, 0 };
	FILE* bmp;
	fopen_s(&bmp, "graph.bmp", "w");
	fprintf(bmp, "BM");
	fwrite(bmi, 52, 1, bmp);
	fwrite(pixels, 1, w * h * 3, bmp);
	fclose(bmp);
}

void svbmp(double y[])
{
	for (i = 0; i < sjsl; i++)
		x[i] = i + 1;

	do
	{
		i = getchar();
		printf("x默认为1-N\n");
		printf("是否重新输入? 1 是 0 否 :");
		i = getchar();
		if (i == '1')
			definearray(x);
	} while (!(i == '0' || i == '1'));

	double y0 = 0;
	int x0 = sjsl;
	for (i = 0; i < sjsl; i++)
	{
		if (y[i] > y[i + 1])
			y0 = y[i];
		else
			y0 = y[i + 1];
	}
	y0 = (int)(log10(y0) + 1);
	y0 = pow(10, y0);

	w = 100 * (sjsl + 1);
	h = 1000;
	char pixels[1 * 1 * 3];

	/* 绘制基底 */
	int z;
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 255;
		++i;
	}
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 230;
		++i;
		pixels[i] = 230;
		++i;
		pixels[i] = 230;
		i = i + 10 * 3 - 2;
	}
	for (i = 0; i < w * h * 3; i++)
	{
		if (i % (10 * w * 3) == 0)
		{
			for (z = i; z < i + w * 3;)
			{
				pixels[z] = 230;
				++z;
				pixels[z] = 230;
				++z;
				pixels[z] = 230;
				++z;
			}
		}
	}
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 100;
		++i;
		pixels[i] = 100;
		++i;
		pixels[i] = 100;
		i = i + 100 * 3 - 2;
	}
	for (i = 0; i < w * h * 3; i++)
	{
		if (i % (100 * w * 3) == 0)
		{
			for (z = i; z < i + w * 3;)
			{
				pixels[z] = 100;
				++z;
				pixels[z] = 100;
				++z;
				pixels[z] = 100;
				++z;
			}
		}
	}

	/* 绘制点 */
	/* 自定颜色 */
	int t = 0;
	for (i = 0; i < w * h * 3; i++)
	{
		if (i == (int)((int)(y[t] * h / y0) * w * 3 + x[t] * w * 3 / (x0 + 1)))
		{
			z = i;
			/* blue */
			pixels[z - w * 3 - 3] = 0;
			pixels[z - w * 3 + 0] = 0;
			pixels[z - w * 3 + 3] = 0;
			pixels[z - 3] = 0;
			pixels[z + 0] = 0;
			pixels[z + 3] = 0;
			pixels[z + w * 3 - 3] = 0;
			pixels[z + w * 3 + 0] = 0;
			pixels[z + w * 3 + 3] = 0;
			/* green */
			pixels[z - w * 3 - 2] = 0;
			pixels[z - w * 3 + 1] = 0;
			pixels[z - w * 3 + 4] = 0;
			pixels[z - 2] = 0;
			pixels[z + 1] = 0;
			pixels[z + 4] = 0;
			pixels[z + w * 3 - 2] = 0;
			pixels[z + w * 3 + 1] = 0;
			pixels[z + w * 3 + 4] = 0;
			/* red */
			pixels[z - w * 3 - 1] = 255;
			pixels[z - w * 3 + 2] = 255;
			pixels[z - w * 3 + 5] = 255;
			pixels[z - 1] = 255;
			pixels[z + 2] = 255;
			pixels[z + 5] = 255;
			pixels[z + w * 3 - 1] = 255;
			pixels[z + w * 3 + 2] = 255;
			pixels[z + w * 3 + 5] = 255;
			++t;
		}
	}
	WriteBMP(pixels);
}
