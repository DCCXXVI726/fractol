static int get_color(int iter, int max_iter, int color, int shift, int n)
{
	int h;
	int v1;
	int v2;
	double r;
	double g;
	double b;

	if (iter == max_iter)
		return (0);
	if (color == 0)
		iter = ((iter + shift) * n) % 255;
	h = (iter / 60) % 6;
	v1 = (iter) % 60 / 60 * 100;
	v2 = 100 - v1;
	if (color != 0)
	{
		r = color / 256 / 256 * (1 - ((double)iter / max_iter));
		g = color / 256 % 256 * (1 - ((double)iter / max_iter));
		b = color % 256 * (1 - ((double) iter / max_iter));
		return (((int)r) * 256 * 256 + ((int)g) * 256 + ((int)b));
	}
	if (h == 0)
		return (100 * 256 * 256 + v1 * 256);
	if (h == 1)
        return (v2 * 256 * 256 + 100 * 256);
	if (h == 2)
        return (100 * 256 + v1);
	if (h == 3)
        return (v2 * 256 + 100);
	if (h == 4)
        return (v1 * 256 * 256 + 100);
	if (h == 5)
        return (100 * 256 * 256 + v2);
	
}

__kernel void fractil(__global char* string, double x0, double y0, double x1, double y1, int max_iter, char type, int color, double my_re, double my_im, int shift)
{
	int i;
	int iter;
	double c_re;
	double c_im;
	double ex_re;
	double ex_im;
	double re;
	double im;
	double dx;
	double dy;
	int n;

	i = get_global_id(0);
	if (type == 'M')
	{
		c_re = x0 + ((double)(i % 1000)) / 1000 * (x1 - x0);
		c_im = y1 + ((double)(i / 1000)) / 1000 * (y0 - y1);
		iter = 0;
		re = 0;
		im = 0;
		while (iter < max_iter && (re * re + im * im) <= 4)
		{
			ex_re = re * re - im * im + c_re;
			ex_im = 2 * re * im + c_im;
			re = ex_re;
			im = ex_im;
			iter++;
		}
		n = 30;
	} else if (type == 'J')
	{
        re = x0 + ((double)(i % 1000)) / 1000 * (x1 - x0);
        im = y1 + ((double)(i / 1000)) / 1000 * (y0 - y1);
        iter = 0;
        c_re = my_im;
        c_im = my_re;
        while (iter < max_iter && (re * re + im * im) <= 4)
        {
            ex_re = re * re - im * im + c_re;
            ex_im = 2 * re * im + c_im;
            re = ex_re;
            im = ex_im;
            iter++;
        }
		n = 50;
	} else if (type == 'N')
	{
		re = x0 + ((double)(i % 1000)) / 1000 * (x1 - x0);
        im = y1 + ((double)(i / 1000)) / 1000 * (y0 - y1);
		dx = re;
		dy = im;
        iter = 0;
        while (iter < max_iter && (re * re + im * im) < 1000000 && (dx * dx + dy * dy) > 0.0000001)
        {
			c_re = re * re * re * re + 2 * re * re * im * im  + im * im * im * im;
			ex_re = re * 2 / 3 + (re * re - im * im) / 3 / c_re;
			ex_im = im * 2 / 3 * (1 - re / c_re);
			if (ex_re > re)
				dx = ex_re - re;
			else
				dx = re - ex_re;
			if (ex_im > im)
				dy = ex_im - im;
			else
				dy = im - ex_im;
            re = ex_re;
            im = ex_im;
            iter++;
        }
		n = 9;
	} else if (type == 'S')
    {
        c_re = x0 + ((double)(i % 1000)) / 1000 * (x1 - x0);
        c_im = y1 + ((double)(i / 1000)) / 1000 * (y0 - y1);
        iter = 0;
        re = c_re;
        im = c_im;
        while (iter < max_iter && (re * re + im * im) <= 16)
        {
            ex_re = re * re - im * im + c_re;
            ex_im = 2 * re * im + c_im;
			c_re = c_re / 2 + ex_re;
			c_im = c_im / 2 + ex_im;
            re = ex_re;
            im = ex_im;
            iter++;
        }
		n = 30;
    } else if (type == 'B')
    {
        c_re = x0 + ((double)(i % 1000)) / 1000 * (x1 - x0);
        c_im = y1 + ((double)(i / 1000)) / 1000 * (y0 - y1);
        iter = 0;
        re = 0;
        im = 0;
        while (iter < max_iter && (re * re + im * im) <= 4)
        {
            ex_re = re * re - im * im + c_re;
			if (re * im > 0)
            	ex_im = 2 * re * im + c_im;
			else
				ex_im = (-1) * 2 * re * im + c_im;
            re = ex_re;
            im = ex_im;
            iter++;
        }
		n = 30;
    }
	((__global unsigned int*) string)[i] = get_color(iter, max_iter, color, shift, n);
}
