//==============================第一章
/*	1.
		a)'\b'			转义字符，退格
		b）1066			整型
		c）99.44			双精度浮点型
		d）0XAA			十六进制数字，十进制为170
		e）2.0e30		双精度浮点型，小数点右移30位
		

	2.                                                   
 */
		#if 0

		#include <stdio.h>

		int main()
		{
			int ASCII;
			printf("please input a ASCII number:");
			scanf("%d",&ASCII);
			printf("the symbol of the number is: %c\n",ASCII );
		}
		#endif

/*	3.	错误1：#include <stdio.h>
			   int main()
			   {
					float g;
					float tax,rate;
					g = 1e21;
					tax = rate * g;
					printf("%lf\n",tax);
			   }

	4.
*/
		#if 0
		#include <stdio.h>

		int main()
		{
			int num;
			double m = 3.0*10 - 23,sum;
			printf("please input the KT number of water:");
			scanf("%d",&num);
			sum = (num * 950)/m;
			printf("the number of the water is :%lf\n",sum);
		}
		#endif
/*
	5.         char c = '\r';    //转义字符
			   char c = 13;		 //ASCII码(十进制)
			   char c = 1101; //二进制
			   char c = 15;//八进制
			   char c = 0xD;//十六进制


	6.'A'是一个字符，大小为1字节
	  "A"是一个字符串，大小为2字节，后面还有'\0'作为结束符

	7.使用uint32_t的原因是在不同平台下变量的存储大小可能不一样，
		当该平台的程序移植到其他系统要使用该变量,方便移植
	  使用unsigned int类型变量的原因是在实际开发中，部分问题可能不需要负数整数，用该变量可以更精确定义变量，
	  不必产生过多的内存浪费


