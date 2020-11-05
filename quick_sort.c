#include <stdio.h>
#include <stdbool.h>

//打印
void print(int *a, int n)
{
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

//将数组中第一个 最后一个 中间一个中的中间值放到第一个
void get_mid(int *a, int n)
{
	//中间数下标
	int mid = (n-1)/2, tmp = 0;
	
	//将大的放到n-1
	if(a[mid]>a[n-1]){
		tmp = a[mid];
		a[mid] = a[n-1];
		a[n-1] = tmp;
	}
	
	//将大的放到n-1
	if(a[0]>a[n-1]){
		tmp = a[0];
		a[0] = a[n-1];
		a[n-1] = tmp;
	}
	
	//把小的放mid
	if(a[mid]>a[0]){
		tmp = a[mid];
		a[mid] = a[0];
		a[0] = tmp;
	}
}

//直接插入排序
void sort(int *a, int n)
{
	//退出条件
	if(n<2)
		return;
	
	//记录左边右边和基准
	int L = 0;
	int R = n-1;
	get_mid(a,n);//以中间值放到a[L]
	int t = a[L];//基准
	
	//以t作为基准分组
	while(L<R){
		//用R指向的元素和基准比较，大于等于基准R前移
		while(L<R&&a[R]>=t)
			R--;
		//小于基准将R指向的元素赋值给L指向的位置
		a[L] = a[R];
		//用L指向的元素和基准比较，小于等于基准L后移
		while(L<R&&a[L]<=t)
			L++;
		//大于基准将L指向的元素赋值给R指向的位置
		a[R] = a[L];
	}
	//将基准赋值回重合的位置
	a[L] = t;
	
	//递归处理前后两个分组
	sort(a,L);
	sort(a+L+1,n-L-1);
}

int main()
{
	int arr[] = {54,47,63,78,17,99,36,82,25};
	printf("排序前:");
	print(arr,9);
	
	sort(arr,9);
	
	printf("排序前:");
	print(arr,9);
	
	return 0;
}
