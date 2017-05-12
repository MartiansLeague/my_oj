/*

**************************************
18071 学生信息统计
**************************************
Description

输入10个学生5门课的考试成绩，分别用函数实现以下功能：

(1) 计算一个学生的平均分。

(2) 计算每门课程的平均分。

(3) 找出每门课程的最高分。

显示结果，显示两位小数。


**************************************
Input

输入10个学生5门课成绩
**************************************
Output

输出每个学生的平均分，以空格分隔

输出每门课的平均分，以空格分隔

输出每门课的最高分，以空格分隔
**************************************
Sample Input

79 61 57 70 77

67 73 83 72 70

82 59 85 84 80

80 53 67 72 79

80 59 72 92 84

88 72 79 79 80

76 99 82 73 97

67 96 81 69 63

58 80 98 93 84

66 61 64 57 64
**************************************
Sample Output

68.80 73.00 78.00 70.20 77.40 79.60 85.40 75.20 82.60 62.40 

74.30 71.30 76.80 76.10 77.80 

88.00 99.00 98.00 93.00 97.00 


**************************************
Author0*/
#include <stdio.h>

void average(double a[][5], int n)
{
    int i,j;
    double sum=0;
    for (i=0;i<10;i++){
        for(j=0;j<5;j++){
            sum+=a[i][j];
        }
        printf("%.2lf ",sum/5.0);
        sum=0;
    }
    printf("\n");
}

void average2(double a[][5], int n)
{
    int i,j;
    double sum=0;
    for (i=0;i<5;i++){
        for(j=0;j<10;j++){
            sum+=a[j][i];
        }
        printf("%.2lf ",sum/10.0);
        sum=0;
    }
    printf("\n");
}

void top(double a[][5], int n)
{   int i,j;
    double max=0;
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(a[j][i]>max)
                max=a[j][i];
        }

        printf("%.2lf ",max);
        max=0;
    }
}

int main()
{
    double a[10][5];
    int i, j;
    for(i=0; i<10; i++)
        for(j=0; j<5; j++)
            scanf("%lf", &a[i][j]);
    average(a,10);
    average2(a,10);
    top(a,10);
    return 0;
}