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
void merge(int array[], int l, int m, int r)
{
	int i, j, t;
	int n1 = m-l+1;
	int n2 = r-m;
	int newarr[n1], newarr2[n2];
	for (i = 0; i < n1; i++)
	{
		newarr[i] = array[l+i];
	}
	for (j = 0; j < n2; j++)
	{
		newarr2[j] = array[m+1+j];
	}
	i = 0; 
	j = 0; 
	t = l;
	while (i < n1 && j < n2)
	{
		if (newarr[i] <= newarr2[j])
		{
			array[t] = newarr[i];
			i++;
		}
		else
		{
			array[t] = newarr2[j];
			j++;
		}
		t++;
	}
	while (i < n1)
	{
		array[t] = newarr[i];
		i++;
		t++;
	}
	while (j < n2)
	{
		array[t] = newarr2[j];
		j++;
		t++;
	}
}
void mergeSort(int A[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
}
void quick(int A[], int first, int last)
{
	int i, j, pt, temp;
	if(first<last)
	{
		pt = first;
		i = first;
		j = last;
		while(i<j)
		{
			while(A[i]<=A[pt]&&i<last)
			{
				i++;
			}
			while(A[j]>A[pt])
			{
				j--;
			}
			if(i<j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[pt];
		A[pt] = A[j];
		A[j] = temp;
		quick(A,first,j-1);
		quick(A,j+1,last);
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
		case 4:
		mergeSort(Arr, 0, n-1);
		break;
		case 5:
		quick(Arr, 0, n-1);
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
