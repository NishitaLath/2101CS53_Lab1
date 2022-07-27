#include<stdio.h>
//Sorting an array using:
//1)Insertion Sort
//2)Selection Sort
//3)Bubble Sort
//4)Merge Sort
//5)Quick Sort
void insertion(int A[], int num)
{
	int i, a, j; 
	for (i = 1; i < num; i++)
	{
		a = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > a)
		{ 
			A[j + 1] = A[j]; 
			j = j - 1; 
		} 
		A[j + 1] = a; 
	}
}
int main(void)
{
	int n,sort;
	printf("Enter number of elements in array \n");
	scanf("%d",&n);
	int Arr[n];
	//Accepting elements of array
	printf("Enter %d elements\n", n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&Arr[i]);
	}
	//Choosing type of sort
	printf("Enter 1 for Insertion Sort \n");
	printf("Enter 2 for Selection Sort \n");
	printf("Enter 3 for Bubble Sort \n");
	printf("Enter 4 for Merge Sort \n");
	printf("Enter 5 for Quick Sort \n");
	scanf("%d",&sort);
	switch(sort)
	{
		case 1:
		insertion(Arr, n);
		break;
		default:
		printf("Invalid sort type\n");
		break;
	}
	//printing the array
	printf("The sorted array is:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",Arr[i]);
	}
	return 0;
}
