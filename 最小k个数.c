
//设计算法从给定的n个数中找出最小的k个数。采用递归调用实现算法。
#include<stdio.h>
//输入一个数组，数组长度为n
//将数组中的数从小到大排序(快速排序)
//从从小到大排序的数组中输出从0开始到k-1位的k个位数（即最小的k个数）


int getStandard(int array[],int low,int high){
	//基准数据 
	int key=array[low];
	while (low < high) {
		//因为默认基准是从左边开始，所以从右边开始比较 
		//当队尾的元素大于等于 基准数据 时,就一直向前挪动high指针 
		while (low < high && array[high] >= key) { 
			high--; 
		}
		//当找到比 array[low] 小的时，就把后面的值 array[high] 赋给它 
		if(low<high){
			array[low] = array[high]; 	
		}
			
		//当队首元素小于等于 基准数据 时,就一直向后挪动low指针 
		while (low < high && array[low] <= key) { 
			low++; 
		}
		//当找到比 array[high] 大的时，就把前面的值 array[low] 赋给它
		if(low<high){
			array[high] = array[low];	
		} 
	} 
	//跳出循环时low和high相等,此时的low或high就是key的正确索引位置
	//把基准数据赋给正确位置 
	array[low] = key; 	
	return low;
} 

void quickSort(int array[],int low,int high){
	//开始默认基准为	low=0
	if(low<high){
		//分段位置下标 
		int standard=getStandard(array,low,high);
		
		//递归调用排序
		//左边排序 
		quickSort(array, 0, standard - 1);
        //右边排序 
		quickSort(array, standard + 1, high);
	}
}


//main
void main()
{
	int n,i,t,arr[20],k=0;

	//输入一个数组，数组长度为n
	printf("请输入数组的长度n：");
	scanf("%d",&n);
	printf("请在数组中输入n个元素：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		arr[i]=t;
	}
	//快速排序
	quickSort(arr,0,n-1);
	
	printf("排序的数组：");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	//输出从0开始到k-1位的k个位数
	printf("请输入需要查找的最小数的个数k：");
	scanf("%d",&k);
	printf("最小的%d个数为：",k);
	for(i=0;i<k;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
