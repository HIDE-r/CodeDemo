/*	
	==================================================实验五
	1.
		a.	&grid[22][56]
		b.	&grid[22][0]	grid + 22
		c.	&grid[0][0]		grid	grid[0]

	2.	
*/	
		#if 0
		#include <stdio.h>

		double differ(double * p);

		int main(void)
		{
			double fir_arr[5] = { 1,5,3,4,2 };
			double arr_diff = differ(fir_arr);
		}

		double differ(double * p)
		{
			int i,j;
			double box,diff_arr;
			for(j = 0;j < 4;j++)
			{
				for(i = 0;i < 4 - j;i++)
				{
					if(p[i]>p[i + 1])
					{
						box = p[i];
						p[i] = p[i + 1];
						p[i + 1] = box;
					}
				}
			}
			diff_arr = p[4] - p[0];

			printf("%lf\n", diff_arr);
			return 1;
		}
		#endif
/*	
	3.
		a)	int a;
		b)	int *a;
		c)	int **a;
		d)	int a[10];
		e)	int *a[10];
		f)	int (*a)[10];
		g)	int (*a)(int);
		h)	int(*a[10])(int);


	4.	i = 1,p = ref[1]的地址
		i = 2,p = ref[2]的地址
		i = 3,p = ref[3]的地址
		i = 4,p = 越界

		将打印出4,乱码
		原因是指针越界了，成为野指针

	5.	ref是 8 的地址，也是整个数组的地址
		ref + 1 是 4 的地址
		++ref指向 4 

	6.
		a)*ptr = 12		*(ptr + 2) = 16
		b)*ptr = 12		*(ptr + 2) = 14

	8.
		a)正确
		b)错误，apple是一个地址，首元素地址
		c)错误，apple是一个地址，首元素地址，不是变量
		d)正确
		e)正确
		f)正确，将apple数组的首元素地址赋值给一个变量
		g)错误，指针内容需要放地址
		h)正确

*/