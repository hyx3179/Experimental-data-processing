#include <stdio.h>
#include <stdlib.h>

int i;
void WriteBMP (char *pixels)
{

	int bmi[] = { w * h * 3 + 54, 0, 54, 40, w, h, 1 | 3 * 8 << 16, 0, 0, 0, 0, 0, 0 };
	FILE *fp = fopen ("graph.bmp", "w");
	fprintf (fp, "BM");
	fwrite (bmi, 52, 1, fp);
	fwrite (pixels, 1, w * h * 3, fp);
	fclose (fp);
}

void main ()
{
	int w = 1000, h = 1000;
	int z;
	char pixels[w * h * 3];

	/* 绘制基底 */
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

	/* 绘制点 */
	double x[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	double y[] = { 5.7, 9.6, 13.6, 17.8, 22.2, 26.0, 31.0, 35.8 };
	int t = 0;
	for (i = 0; i < w * h * 3; i++)
	{
		if (i == y[t] * 10 * h * 3 + x[t] * w / 10 * 3)
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
