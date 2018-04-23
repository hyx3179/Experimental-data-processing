#include <stdio.h>
#include <stdlib.h>

void definearray (double arr[]);

int i;
int sjsl;
int w, h;
double x[128];

void WriteBMP (char *pixels)
{
	int bmi[] = { w * h * 3 + 54, 0, 54, 40, w, h, 1 | 24 << 16, 0, 0, 0, 0, 0, 0 };
	FILE *fp = fopen ("graph.bmp", "w");
	fprintf (fp, "BM");
	fwrite (bmi, 52, 1, fp);
	fwrite (pixels, 1, w * h * 3, fp);
	fclose (fp);
}

void svbmp (double y[])
{
	w = 100 * (sjsl + 1);
	h = 1000;
	char pixels[w * h * 3];

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
	for (i = 0; i < sjsl; i++)
		x[i] = i + 1;
	do
	{
		i = getchar ();
		printf ("x默认为1-n\n");
		printf ("是否重新输入？1 是 0 否 ：");
		i = getchar ();
		if (i == '1')
			definearray (x);
	}
	while (!(i == '0' || i == '1'));
	definearray (x);
	double y0 = y[sjsl - 1] - y[0] + 2;
	int t = 0;
	for (i = 0; i < w * h * 3; i++)
	{
		if (i == (int) (y[t] * h / y0 * w * 3 + x[t] / (sjsl + 1) * w * 3))
		{
			z = i;
			pixels[z - w * 3 - 3] = 0;
			pixels[z - w * 3] = 0;
			pixels[z - w * 3 + 3] = 0;
			pixels[z - 3] = 0;
			pixels[z] = 0;
			pixels[z + 3] = 0;
			pixels[z + w * 3 - 3] = 0;
			pixels[z + w * 3] = 0;
			pixels[z + w * 3 + 3] = 0;

			pixels[z - w * 3 - 2] = 0;
			pixels[z - w * 3 + 1] = 0;
			pixels[z - w * 3 + 4] = 0;
			pixels[z - 2] = 0;
			pixels[z + 1] = 0;
			pixels[z + 4] = 0;
			pixels[z + w * 3 - 2] = 0;
			pixels[z + w * 3 + 1] = 0;
			pixels[z + w * 3 + 4] = 0;

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
	WriteBMP (pixels);
}
