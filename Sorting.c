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
void selection(int A[], int num)
{
	int i,j,pos,new;
	for(i = 0; i < num - 1; i++)
	{
		pos=i;
		for(j = i + 1; j < num; j++)
		{
			if(A[pos] > A[j])
			{
				pos=j;
			}
		}
		if(pos != i)
		{
			new = A[i];
			A[i] = A[pos];
			A[pos] = new;
		}
	}
}
void bubble(int A[], int num)
{
	int i, j;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1]= temp;
			}
		}
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
		case 2:
		selection(Arr, n);
		break;
		case 3:
		bubble(Arr, n);
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
