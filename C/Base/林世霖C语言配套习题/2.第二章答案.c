=================================================第二章
	1.
*/	

		#if 0
		#include <stdio.h>

		int main(int argc, char const *argv[])
		{
			int num,i;
			printf("please input a number:");
			scanf("%d",&num);
			for(i = 0;i <= 10;i++)
			{	
				printf("num = %d\n",num );
				num += 1;
			}
			return 0;
		}
		#endif
/*
	2.
		(1)a = 24;
		(2)a = 10;
		(3)a = 60;
		(4)a = 0;
		(5)a = 0;
		(6)a = 0;

	3.
*/		
		#if 0

		#include <stdio.h>
		
		double cube(double num);

		int main(void)
		{
			double num;
			printf("please input a num:");
			scanf("%lf",&num);
			cube(num);

		}

		double cube(double num)
		{
			double result;
			result = num * num * num;
			printf("%lf\n",result);
		}

		#endif
	
//	4.
		#if 0
		#include <stdio.h>
		
		#define UINT unsigned int

		int main(int argc, char const *argv[])
		{
			UINT day_num,week,days;
			printf("please input a day:");
			while(1)
			{
				scanf("%d",&day_num);
				if(day_num < 0)
				{
					printf("Going wrong!!!please input your days again!!\n");
					continue;
				}
				week = day_num / 7;
				days = day_num % 7;
				printf("%d days are %d weeks,%d days\n",day_num,week,days);
				printf("please input the next day to calc:\n");
			}
			return 0;
		}
		#endif


/*	5. a = 13 ; b = 10 ;c = 12;d = 120 

	printf("b,c,d: %d, %d, %d", b, c, d);

结果打印：	b,c,d: 10, 12,120

*/



