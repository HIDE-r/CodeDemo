/*
=================================================实验六

	1.	有问题，str是首元素的地址,当sizeof(str)时，测的是地址的大小，
		并不是题目需要的数组的大小

	2.	4，2000000

	3.	
*/
		#if 0
		#include <stdio.h>

		int main(int argc, char const *argv[])
		{
			int arr[2][3] = { {1,2,3},{4,5,6} };
			int *p2arr[2] = { arr[0],arr[1] };

			int sum;
			sum = *p2arr[0] + *(p2arr[0] + 1) + *(p2arr[0] + 2) + \
					*p2arr[1] + *(p2arr[1] + 1) + *(p2arr[1] + 2);
			printf("%d\n",sum );
		}
		#endif

//	5.
		#if 0
		#include <stdio.h>


		int main(int argc, char const *argv[])
		{
			int arr_length,i,j,box;
			printf("请输入数组的长度:");
			scanf("%d",&arr_length);
			int num_arr[arr_length];
		    
		    for(i = 0;i < arr_length;i++)
		    {
		        printf("请输入数字:");
		        scanf("%d",&num_arr[i]);   
		    }
		   
		   	printf("******************************************\n");
		    printf("输入的数组为:");//打印
		    for(i = 0;i < arr_length;i++)
		    {
		    	printf("%d ",num_arr[i]);
		    }
		    printf("\n");


		    int sum = 0;												//子数组数量
		    for(i = 1;i <= arr_length;i++ )								//计算子数组的数量
		    {
		    	sum = sum + i;
		    }
		    printf("子数组的数量为： %d\n",sum );
		    int text[sum],arr_sum = 0,calc_num = 0;						//text数组存放各个子组合之和
		    for(j = 0;j < arr_length;j++)
		    {
		    	for(i = j;i < arr_length;i++)
			    {
			    	arr_sum = arr_sum + num_arr[i];
			    	text[calc_num] = arr_sum;
			    	calc_num++;
			    }
			    arr_sum = 0;
		    }
		    
		    printf("由子数组之和组成的text数组为：");						//打印
		    for(i = 0;i < sum;i++)
		    {
		    	printf("%d ",text[i]);
		    }
		    printf("\n");

		    for(j = 0;j < sum-1;j++)									//冒泡排序法，选出最大值
		    {
		    	for(i = 0;i < sum-1-j ;i++)
			    {
			    	if( text[i] > text[i + 1] )
			    	{
			    		box = text[i];
			    		text[i] = text[i + 1];
			    		text[i + 1] = box;
			    	}
			    }
		    }
		    
		    printf("排序后的text数组为 :");								//打印
		    for(i = 0;i < sum;i++)
		    {
		    	printf("%d ",text[i]);
		    }
		    printf("\n");
		    
		    printf("子数组之和的最大值为：%d\n",text[sum-1] );


		}
		#endif

//	6.
		#if 0
		#include <stdio.h>

		#define LENGTH 3
		#define	WIDTH  5

		void copy_arr( int m,int n,double arr1[m][n],double arr2[m][n] );//数组的复制
		void show_arr(int m,int n,double arr[m][n]);//数组的显示

		int main(void)
		{
			double array[LENGTH][WIDTH];
			double text[LENGTH][WIDTH];
			int i,j;
			printf("以下将为一个3×5的array数组赋值！！\n");
			printf("array数组元素：\n");
			for(i = 0;i < LENGTH;i++)
			{
				for(j = 0;j < WIDTH;j++)
				{
					printf("请输入arra的第%d行的第%d个元素:",i+1,j+1 );
					scanf("%lf",&array[i][j]);
				}
			}

			printf("array数组：\n");
			show_arr(LENGTH,WIDTH,array);
			printf("原来的text数组：\n");
			show_arr(LENGTH,WIDTH,text);
			copy_arr(LENGTH,WIDTH,array,text);
			printf("复制后的text数组：\n");
			show_arr(LENGTH,WIDTH,text);

		}

		/*
		 功  能：实现数组的复制
		 参  数：m，n,arr1[m][n]（被复制的数组）,arr2[m][n]（目标数组）
		 返回值：无
		*/
		void copy_arr( int m,int n,double arr1[m][n],double arr2[m][n] )
		{
			int i,j;
			for(i = 0;i < m;i++)
			{
				for(j = 0;j < n;j++)
				{
					arr2[i][j] = arr1[i][j];
				}
			}
		}

		/*
		 功  能：实现数组的显示
		 参  数：m，n,arr[m][n]（需要显示的数组）
		 返回值：无
		*/
		void show_arr(int m,int n,double arr[m][n])
		{
			int i,j;
			for(i = 0;i < m;i++)
			{
				for(j = 0;j < n;j++)
				{
					printf("%.2lf ",arr[i][j]);
				}
				printf("\n");
			}
		}


		#endif

//	7.
		#if 0
		#include <stdio.h>
		#include <stdlib.h>
		#include<string.h>

		int main(int argc, char const *argv[])
		{
			char str[50];
			int i,j,k,same_num = 0;
			printf("\nplease input a string:");
			scanf("%s",str);
			short length = strlen(str);
			
			printf("the length of the string is:%d\n",length );
			printf("*********************************\n");

			for(i = 0;i < length;i++)
			{
				for( j = i + 1 ; j < length ;j++ )
				{
					if( str[i] == str[j] )						//对比两个字符
					{
						for(k = j ;k < j + length - j - 1;k++)//将后面的字母推前
						{
							str[k] = str[k + 1];
						}

						str[length - 1] = '\0';					//将最后一个字符变成结束符'\0'
						length = strlen(str);					//重新测字符串长度
						//printf("the length of the string is:%d ",length );//观察长度变化！
						same_num++;
						if( str[i] == str[j] )					//排除一些小bug，当输入aaabc时，
						{										//将会出现aabc，下次循环时将从b开始,
							j--;								//会发现有一个a被忽略了
						}
					}
				}
			}
			//printf("\n********************************\n");
			printf("the end of the string:%s\n",str );
			printf("the number of same letter is:%d\n\n",same_num );

		}

	#endif