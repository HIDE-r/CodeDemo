/*	1.	struct ture
		{
			char itable;
			int num[20];
			char *togs;
		};

	2.
		struct month
		{
			char name[10];
			char mini_name[3];
			short days;
			short nums;
		};

	3.
		若是32位系统,该结构体占4+4+4= 12个字节；
		若是64位系统,该结构体占8+8+8= 24个字节；

	5.
*/
		#if 0
		#include <stdio.h>

		struct day
		{
			short year;
			short month;
			short day_num;	
		};

		int main(int argc, char const *argv[])
		{
			struct day calc_day;
			int i,sum = 0;
			int mon_num[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

			printf("please input your year:\n");
			scanf("%hd",&calc_day.year);
			printf("please input your month:\n");
			scanf("%hd",&calc_day.month);
			printf("please input your days:\n");
			scanf("%hd",&calc_day.day_num);

			//printf("%hd%hd%hd\n",calc_day.year,calc_day.month,calc_day.day_num );
			if(calc_day.year % 4 == 0)
			{
				mon_num[1] = 29;
			}else{
				mon_num[1] = 28;
			}

			for(i = 0;i < calc_day.month -1;i++)
			{
				sum += mon_num[i];
			}
			printf("this is the %hdth days in a year\n", sum + calc_day.day_num);
			return 0;
		}
		#endif

/*
	6.
		enum choices = 
		{
			no;
			yes;
			maybe;
		};

	
	7.
*/
		#if 0
		#include <stdio.h>

		double func1(double ,double );
		double func2(double ,double );
		double func3(double ,double );
		double func4(double ,double );

		int main()
		{
			double *p[4](double ,double ) = { func1,func2,func3,func4 };
		}

		double func1(double a ,double b )
		{
			;
		}
		double func2(double a ,double b )
		{
			;
		}
		double func3(double a ,double b )
		{
			;
		}
		double func4(double a ,double b )
		{
			;
		}
		#endif

/*
	8.
		若是32位系统，	
					sizeof(berry) = 20 byte;
					sizeof(struct creature) = 4 + 20 + 8 = 32 byte
					
		sizeof(struct creature) + sizeof(berry) = 52 byte

		若是64位系统，
					sizeof(berry) = 24 byte;
					sizeof(struct creature) = 8 + 24 + 8 = 40 byte

		sizeof(struct creature) + sizeof(berry) = 64 byte	

	9.
*/
		#if 0
		#include <stdio.h>

		

		#endif	