#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<sys/time.h>
const int MAX = 100;
int size, top = -1;
struct timeval tv;
void fnGenerateRandomNo(int *size, int arr[MAX])
{
	srand(time(NULL));
	for(int i=0; i<*size;i++)
	{
		arr[i] = rand()%100;
	}
}
void displayRand(int arr[MAX])
{
	for(int i=0; i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void fnBubbleSort(int n, int arr[MAX])
{
	int temp;
	for(int i=0; i<n-1;i++)
	{
		for(int j =0; j< n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] =arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
//fn to check duplicate
void fnRemoveDuplicate(int arr[], int *k)
{
	*k=0;
	for(int i =0; i<size; i++)
	{
		arr[*k] = arr[i];
		if(arr[i]!=arr[i+1])
			++(*k);
	}
}
//accepting elements from the user
/*void getInfo(int *size, int set[MAX])
{
	printf("Enter the no. of elements: ");
	scanf("%d",size);
	printf("Enter the elements: ");
	for(int i =1; i< *size;i++)
		scanf("%d",&set[i]);
	//getchar();
}
*/
//pushing the element onto the stack
void push(int item, int stk[MAX])
{
	stk[++top]=item;
}

//removing the elements which fails sum>0 condition
void pop()
{
	top--;
}
//display the contents of the stack
void display(int stk[MAX])
{
	static int count=0;
	printf("Solution %d is { ",++count);
	for(int i=0; i <= top; i++)
		printf("%d, ",stk[i]);
	printf("\b\b }\n");
}

//find the subset whose sum is equal to the given sum and display all possible subset
int fnFindSubset(int pos, int sum, int stk[MAX], int set[MAX])
{
	static int foundSol = 0;
	if(sum>0)
	{
		for(int i = pos; i<= size; i++)
		{
			push(set[i], stk);
			//printf("\n%d %d %d ",i ,pos, sum);
			fnFindSubset(i+1, sum - set[i], stk, set);
			//printf("\tSubset %d %d ",i+1,sum-set[i]);
			//display(stk);
			pop();
		}
	}
	if(sum == 0)
	{
		foundSol =1;
		display(stk);
	}
	return foundSol;
}
//main fn to implement Subset sum
int main(void)
{
	int stk[MAX]; int set[MAX]; int sum;
	int k;
	printf("Enter the sum: ");
	scanf("%d",&sum);
	//getInfo(&size, set);
	printf("\nEnter the size :");
	scanf("%d",&size);
	//FILE *fp=fopen("SubsetPlot.dat","w+");
/*	for(int i =10; i<100;i++){
	top =-1;*/
	fnGenerateRandomNo(&size, set);
	printf("\nRandom Elements with duplicate items: ");
	displayRand(set);
	fnBubbleSort(size,set);
	fnRemoveDuplicate(set,&k);
	size=k;  // setting the current size;
	printf("Sorted elements with removed duplicate items: ");displayRand(set);
	//gettimeofday(&tv,NULL);
	//double dStart = tv.tv_sec + tv.tv_usec/1000000.0;
	if(fnFindSubset(0,sum,stk,set))
		printf("\nThe above mentioned are the required subset\n\n");
	else
		printf("\nThe given problem instance doesn't have any required solution\n\n");
	//gettimeofday(&tv,NULL);
	//double dEnd = tv.tv_sec + tv.tv_usec/1000000.0;
	//FILE *fp =fopen("Subset Sum","w");
	//fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);
	//}
	//fclose(fp);
	return 0;
}
