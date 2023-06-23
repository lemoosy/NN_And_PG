#include "Mat.h"

Mat* Mat_New(int w, int h)
{
	assert((w > 0) && (h > 0));

	Mat* mat = (Mat*)calloc(1, sizeof(Mat));
	assert(mat);

	mat->w = w;
	mat->h = h;

	mat->value = (data**)calloc(h, sizeof(data*));
	assert(mat->value);

	for (int j = 0; j < h; j++)
	{
		mat->value[j] = (data*)calloc(w, sizeof(data));
		assert(mat->value[j]);
	}

	return mat;
}

Mat* Mat_Copy(Mat* m)
{
	if (!m) return NULL;

	Mat* res = Mat_New(m->w, m->h);

	int w = m->w;
	int h = m->h;
	int size = sizeof(data) * w;

	for (int j = 0; j < h; j++)
	{
		memcpy(res->value[j], m->value[j], size);
	}

	return res;
}

void Mat_Destroy(Mat* m)
{
	if (!m) return;

	int h = m->h;

	for (int j = 0; j < h; j++)
	{
		free(m->value[j]);
	}

	free(m->value);
	free(m);
}

void Mat_Print(Mat* mat)
{
	if (mat)
	{
		int w = mat->w;
		int h = mat->h;

		data* row;

		for (int j = 0; j < h; j++)
		{
			row = mat->value[j];

			for (int i = 0; i < w; i++)
			{
				printf("%.2f ", row[i]);
			}

			putchar('\n');
		}
	}
	else
	{
		printf("mat = NULL \n");
	}
}

void Mat_Add(Mat* m1, Mat* m2)
{
	int w = m1->w;
	int h = m1->h;

	assert((w == m2->w) && (h == m2->h));
	
	data* m1Row;
	data* m2Row;

	for (int j = 0; j < h; j++)
	{
		m1Row = m1->value[j];
		m2Row = m2->value[j];

		for (int i = 0; i < w; i++)
		{
			m1Row[i] += m2Row[i];
		}
	}
}

void Mat_Sub(Mat* m1, Mat* m2)
{
	int w = m1->w;
	int h = m1->h;

	assert((w == m2->w) && (h == m2->h));

	data* m1Row;
	data* m2Row;

	for (int j = 0; j < h; j++)
	{
		m1Row = m1->value[j];
		m2Row = m2->value[j];

		for (int i = 0; i < w; i++)
		{
			m1Row[i] -= m2Row[i];
		}
	}
}

Mat* Mat_Prd(Mat* m1, Mat* m2)
{
	int w = m1->w;
	int h = m2->h;
	
	assert(w == h);

	Mat* res = Mat_New(h, w);
	
	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
		{
			for (int k = 0; k < w; k++)
			{
				res->value[j][i] += m1->value[j][k] * m2->value[k][i];
			}
		}
	}

	return res;
}

void Mat_Scale(Mat* m, data s)
{
	int w = m->w;
	int h = m->h;

	data* mRow;

	for (int j = 0; j < h; j++)
	{
		mRow = m->value[j];

		for (int i = 0; i < w; i++)
		{
			mRow[i] *= s;
		}
	}
}