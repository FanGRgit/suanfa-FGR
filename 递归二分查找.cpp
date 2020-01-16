#include <stdio.h> 
#define ARRAY_SIZE 10
#define NOT_FOUND -1
int BinarySearch(int array[], int left, int right, int NumToSearch)
{
 int mid = (left + right) / 2;
 if (left <= right)
 {
  if (NumToSearch == array[mid])
  {
   return mid;
  }
  else if (NumToSearch < array[mid])
  {
   right = mid - 1;
   return BinarySearch(array, left, right, NumToSearch);
  }
  else
  {
   left = mid + 1;
   return BinarySearch(array, left, right, NumToSearch);
  }
 }
 return NOT_FOUND;
}
int main()
{
 int a[ARRAY_SIZE] = {2, 5, 6, 7, 13, 20, 22, 27, 112, 222};//����һ����֪������������������
 int result = 0;//���ҵĽ��
 int x;//��������Ҫ���ҵ�����13
 printf("����Ҫ���ҵ���:");
 scanf("%d",&x);
 int left = 0;//���п�ʼ�±�
 int right = ARRAY_SIZE - 1;//���н�β�±�
 result = BinarySearch(a, left, right, x);
 if (result == NOT_FOUND)
 {
  printf("Not Found!\n");
 }
 else
 {
  printf("Found %d in array a, it is a[%d]\n", x, result);
 }
 return 0;
}
