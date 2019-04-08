#include <stdio.h>
#include <string.h>

//两个无序的数组，找出第三的数并排序。
//先将两数组有序，再将两数组前两个数归并，找出第三大的数。

void pop(int *array, int length, int *addr)
{
	int i,j;
	int temp;

	for(i=length-1; i>length-3; i--){
		for(j=length-1; j>=length-(i+1); j--){
			if(array[j]<array[j-1]){
					if(i == length-1){
						addr[0] = j;
					}else if(i == length-2){
						addr[1] = j;
					}

					temp = array[j];
					array[j] = array[j-1];
					array[j-1] = temp;
			}
			if(i == length-1){
				addr[0] = j-1;
			}else if(i == length-2){
				addr[1] = j-1;
			}
		}
		
	}
	
	return ;
}


void 3_largest(int *array00, int *array01, int length00, int length01, int *addr)
{
	pop(array00, length00, addr);
	pop(array01, length01, &addr[2]);

	return ;
}

void main ()
{
	int i=0,j=0,k=0;
	int array00[] = {1,4,2,7,3,6,9};
	int array00[] = {3,6,9,2,4,1,3};
	int length00 = sizeof(array00);
	int length01 = sizeof(array01);
	int addr[4];
	int temp[4]; 

	3_largest(array00, array01, length00, length01, addr);

	while(i!=2 || j!=2){
		if(array00[i]<=array01[j]){
			temp[k++] = array00[i++];
		}else{
			temp[k++] = array01[j++];
		}
	}
	if(i == 2){
		memcpy(&temp[2], &array01[j]);
	}else {
		memcpy(&temp[2], &array00[i]);
	}

	printf("The third largest is %d\n", temp[2]);

	return ;
}
