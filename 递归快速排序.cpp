#include <stdio.h>
void quickSort(int x[],int left,int right){
	int i,j,t,temp,k;
	i=left;j=right;
	t=x[i];
	if(left>=right)
		return;
	while(i<j){	
		while(x[i]<=t&&i<right){
			i++;
		}
		while(x[j]>=t&&j>left){
			j--;
		}
		if(i<j){
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
			i++;
			j--;
			for(k=left;k<=right;k++){
				printf("%d ",x[k]);
			}
			printf("\n");
		}
	}	
	x[left]=x[j];
	x[j]=t;	
	quickSort(x,left,j-1);
	quickSort(x,j+1,right);
}
int main() {
	int a[10]={14,2,3,44,5,6,7,8,9,10};
	int n=10;
	int ii,jj;
	for(ii=0;ii<n;ii++){
		printf("%d ",a[ii]);
	}
	printf("\n");
	quickSort(a,0,n-1);
	for(jj=0;jj<n;jj++){
		printf("%d ",a[jj]);
	}
	printf("\n");
	return 0;
}

