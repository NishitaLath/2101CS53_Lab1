#include<stdio.h>
//Addition, subtraction, multiplication, division
int main(void)
{
	float a, b; int op;
	printf("Enter the first number\n");
	scanf("%f",&a);
	printf("Enter the second number\n");
	scanf("%f",&b);
	//Choosing the operation to be performed
	printf("Enter 1 for addition \n");
	printf("Enter 2 for subtraction \n");
	printf("Enter 3 for multiplication \n");
	printf("Enter 4 for division \n");
	scanf("%d",&op);
	//A number can not be divided by zero
	if(op==4 && b==0)
	{
		printf("Division cannot be performed");
	}
	//Performing the operations
	else if(op==1 || op==2 || op==3 || op==4)
	{
		float res;
		switch(op)
		{
			case 1:
			res=a+b;
			break;
			case 2:
			res=a-b;
			break;
			case 3:
			res=a*b;
			break;
		}
		printf("The result is= %f \n", res);
	}
	else
	{
		printf("Invalid Operator");
	}
	return 0;
}
