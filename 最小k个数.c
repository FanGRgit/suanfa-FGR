
//����㷨�Ӹ�����n�������ҳ���С��k���������õݹ����ʵ���㷨��
#include<stdio.h>
//����һ�����飬���鳤��Ϊn
//�������е�����С��������(��������)
//�Ӵ�С��������������������0��ʼ��k-1λ��k��λ��������С��k������


int getStandard(int array[],int low,int high){
	//��׼���� 
	int key=array[low];
	while (low < high) {
		//��ΪĬ�ϻ�׼�Ǵ���߿�ʼ�����Դ��ұ߿�ʼ�Ƚ� 
		//����β��Ԫ�ش��ڵ��� ��׼���� ʱ,��һֱ��ǰŲ��highָ�� 
		while (low < high && array[high] >= key) { 
			high--; 
		}
		//���ҵ��� array[low] С��ʱ���ͰѺ����ֵ array[high] ������ 
		if(low<high){
			array[low] = array[high]; 	
		}
			
		//������Ԫ��С�ڵ��� ��׼���� ʱ,��һֱ���Ų��lowָ�� 
		while (low < high && array[low] <= key) { 
			low++; 
		}
		//���ҵ��� array[high] ���ʱ���Ͱ�ǰ���ֵ array[low] ������
		if(low<high){
			array[high] = array[low];	
		} 
	} 
	//����ѭ��ʱlow��high���,��ʱ��low��high����key����ȷ����λ��
	//�ѻ�׼���ݸ�����ȷλ�� 
	array[low] = key; 	
	return low;
} 

void quickSort(int array[],int low,int high){
	//��ʼĬ�ϻ�׼Ϊ	low=0
	if(low<high){
		//�ֶ�λ���±� 
		int standard=getStandard(array,low,high);
		
		//�ݹ��������
		//������� 
		quickSort(array, 0, standard - 1);
        //�ұ����� 
		quickSort(array, standard + 1, high);
	}
}


//main
void main()
{
	int n,i,t,arr[20],k=0;

	//����һ�����飬���鳤��Ϊn
	printf("����������ĳ���n��");
	scanf("%d",&n);
	printf("��������������n��Ԫ�أ�");
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		arr[i]=t;
	}
	//��������
	quickSort(arr,0,n-1);
	
	printf("��������飺");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	//�����0��ʼ��k-1λ��k��λ��
	printf("��������Ҫ���ҵ���С���ĸ���k��");
	scanf("%d",&k);
	printf("��С��%d����Ϊ��",k);
	for(i=0;i<k;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
