/**
    Filename:Arrays.c
    Author:Sushant Kumar
    Date:20-July-2017
    Aim:To study an Array ADT and to implement various operations on an array ADT.
    Problem Statement:Create and array and implement the operations - traverse(), insert_element(), delete_element(),sort(),   search(),merge(), copy(),create(),isfull(), isempty() and length(). Write a C program to demonstrate an array ADT using defined operations appropriately using a menu driven approach . Your program should be able to print the array contents appropriately at any or all instances(as required may be). You must also ensure that no input is acquired within the body of functions,nor    (preferably) display any prompts/results. 
*/

/* Header file inclusion*/
#include<stdio.h>

/* Pre-processor diectives declaration*/
#define max_size 10
#define min_value -999

/* Function prototype declaration*/
void initialize(int *);
int length(int *);
int isFull(int *);
int isEmpty(int *);
int getValue(char *);
void insertElement(int *, int, int);
void create(int arr[]);
void display(int arr[]);
void delete(int *,int);
int search(int *,int);
void sort(int *);
void copy(int *, int *);
/* The main function*/
int main(){
	int response,arr[max_size],result,cpy[max_size],mergedArray[2*max_size];
	initialize(arr);
	do{
		printf("\n\tThe list of operations you can perform on the Array ADT.\n");
		printf("\n\t1. Create\t2. Length\t3. isFull\n");
        printf("\t4. isEmpty\t5. Display\t6. Insert\n");
        printf("\t7. Delete\t8. Search\t9. Sort\n");
        printf("\t10. Copy\t11. Merge\t12. Traverse\n");
        printf("\t0. EXIT\n");
        printf("\t Enter your response? ");
        scanf("%d",&response);
        switch(response){
			case 0:printf("\tYou opted to exit!\n");break;
			case 1:create(arr);break;
        	case 2: printf("\tLength of the array is: %d\n",length(arr));break;
        	case 3:if(isFull(arr))
        			printf("\t%d the array is full.\n",isFull(arr));
        		   else
        		   	printf("\t%d the array is not full.\n",isFull(arr));
        		   break;
        	case 4:if(isEmpty(arr))
        			printf("\t%d the array is Empty.\n",isFull(arr));
        		   else
        		   	printf("\t%d the array is not Empty.\n",isFull(arr));
       		   	   break;
       		case 5:printf("\tThe elements in the array are:\n\t");
       			   display(arr);
       			   printf("\n");
       			   break;
			case 6:insertElement(arr,getValue("the index: "),getValue("the value: "));
       			   break;
       		case 7:delete(arr,getValue("the index: "));
       			   break;
       		case 8:result = search(arr,getValue("the vaule to search for: "));
       				if(result==-1)
       					printf("\tThe element does not exist in the array!");
       				else
       					printf("\tElement found at index = %d",result);
       			   break;
        	case 9:sort(arr);
       			   break;
       		case 10:copy(arr, cpy);
       			   break;
 			//case 11:merge(mergedArray, arr, cpy);
       			//   break;	   	
        }
	}while(response!=0);
}
void initialize(int arr[]){
	arr[0]=min_value;
}
int length(int arr[]){
	int i=0;
	for(i=0;i<max_size;i++){
		if(arr[i]==min_value)
		break;
	}
	return i;
}
int isFull(int arr[]){
	if(length(arr)==max_size)
		return 1;
	return 0;
}
int isEmpty(int arr[]){
	if(length(arr)==0)
		return 1;
	return 0;
}
int getValue(char *string){
	int value;
	printf("\tPlease enter %s",string);
	scanf("%d",&value);
	return value;
}
void insertElement(int arr[], int index, int value){
	arr[index] = value;
}
void create(int arr[]){
	int len,value;
	len = length(arr);
	do{
	
		
		if(len < max_size)
			{
			value = getValue("the element value(-999 to stop): ");
			insertElement(arr,len,value);
			}
		else{
			printf("\tArray Bounds Reached.\n");
			}
		len++;
	}while(value!=min_value && len<=max_size);
}
void display(int arr[]){
	int len,i;
	len = length(arr);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
		
}
void delete(int arr[],int index){
	int len = length(arr),i;
	for(i=index;i<len-1;i++)
	 arr[i] = arr[i+1];
	arr[i]=-999;
}
int search(int arr[],int value){
	int len = length(arr),i;
	for(i=0;i<len;i++)
		if(arr[i]==value)
		return i;
	return -1;
}
void sort(int arr[]){
	int i,j,t,len=length(arr);
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
			if(arr[i]>arr[j]){
				t = arr[j];
				arr[j]=arr[i];
				arr[i]=t;
			}
}
void copy(int arr[], int dest[]){
	int i,len=length(arr);
		for(i=0;i<len;i++)
			dest[i]=arr[i];
		dest[i]=-999;
}

