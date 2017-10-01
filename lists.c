/**
    Filename:lists.c
    Author:Sushant Kumar
    Date:14-September-2017
    Aim: To study singly linked linear lists and implement various operations on it – Insert, Delete, Reverse, Order, Locate, Merge, Linked Stack, and 		Linked Queue
    Problem Statement: Create a self-referential structure, NodeLL to represent a node of a singly linked linear list. Implement the routines to (1) 	find length of the list, (2) create a list, (3) insert an element at the beginning, at the end and at a specified position in the list, (4) delete 		an element fromthe front, rear, or a specified position at the list, (5) reverse the list, (6) search the list. Create a menu-driven program to 	test these routines. Use the singly linked linear list routines to implement a linked stack and a linked queue.
*/
/* Pre-processor diectives declaration*/

/*Header file inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"


/*The main function*/
int main(){
	int mode,continueResponse,op;
	list first = NULL, neww,firstCpy = NULL;
	list queueFirst=NULL, tail =NULL;
	list stackFirst = NULL;
	int key = 0,cnt = 5,delValue,pos;
    do{
    printf("\n\t--------------------Choose an ADT--------------------");
    printf("\n\t1. General list \t2. Linked Stack \t3. Linked Queue");
    printf("\n\t-----------------------------------------------------");
    do{
    mode = get("the choice");
    }while(mode<1||mode>3);
        switch(mode){
			case 1:do{
				 		menu(mode);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>17);
				 switch(op){
					case 1: key = get("the key ");
							first = insertAtBeg(first,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:key = get("the key");
							first = insertAtEnd(first,key);break;
					case 3:	pos = get("the position");
							key = get("the key");
							first = insertAtPos(first,pos,key);break;
							
					case 4: first = createRandomLL(first,get("the length"));break;
					case 5:if(first!=NULL)
							printf("\tThe length of list is: %d",lengthLL(first));
							else
							printf("\tThe list is empty!");
							break;
							
					case 6:first = deleteAtBeg(first,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 7: first = deleteAtEnd(first,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 8: first = deleteAtPos(first,get("the position"),&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 9:if(first!=NULL){
							printf("\tList before sorting: ");
							displayLL(first);
							first = sortLL(first,1);
							printf("\n\tList after sorting: ");
							displayLL(first);}else{
								printf("\n\tThe list is empty.");
							}break;
					case 10:firstCpy = copyLL(first);
							if(firstCpy!=NULL){
							printf("\n\tThe copied linked list is\n\t");
							displayLL(firstCpy);}else{
								printf("\n\tThe list is empty!");
							}break;
					case 11:first = reverse(first);	
							if(first!=NULL){				
							printf("\tThe list after reversing is\n\t");
							displayLL(first);}else{
								printf("\n\tThe list is empty!");
							}break;
					case 12:pos = searchLL(first,get("the key to search"));
							if(pos!=STOP)
								printf("\tThe key found at %d position",pos);
							else
								printf("\tThe key not found.");break;
					case 13:if(first!=NULL) {
								printf("\tDisplaying the list\n\t");
								displayLL(first);
								}
							else
								printf("\n\tThe list is empty.");
								break;
					case 14:if(first!=NULL) {
								first = mergeLL(first);
								printf("\tDisplaying the merged list\n\t");
								displayLL(first);
								}
							else
								printf("\n\tThe list is empty.");
								break;
					case 15:if(first!=NULL) { 
							first = mergeOrdered(first);
							printf("\n\tThe merged list is\n");
							displayLL(first);}else{
								printf("\n\tThe first list is empty.");
							}
							break;
					case 16: first = createList(first);break;
					case 17: first = insertOrdered(first,get("the key"));
				 }
				  }while(op!=0);
				break;
			case 2:do{
				 		menu(mode);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>5);
				 switch(op){
					case 1: key = get("the key ");
							stackFirst = push(stackFirst,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:stackFirst = pop(stackFirst,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);
							break;
					case 3:	if(isEmpty(stackFirst))
								printf("\n\tThe queue is empty!");
							else
								printf("\n\tThe queue is not empty!");
							break;
					
					case 4: key = atTop(stackFirst);
							if(key!=STOP)
								printf("\tValue at Top is: %d",key);break;
					case 5:if(stackFirst!=NULL)
							displayStack(stackFirst);
							else
							printf("\tThe Stack is empty!");
							break;
				 }
				  }while(op!=0);
				break;
			case 3:do{
				 		menu(mode);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>6);
				 switch(op){
					case 1: key = get("the key ");
							queueFirst = insertQ(queueFirst,&tail,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:queueFirst = deleteQueue(queueFirst,&tail,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);
							break;
					case 3:	if(isEmpty(queueFirst))
								printf("\n\tThe queue is empty!");
							else
								printf("\n\tThe queue is not empty!");
							break;
					case 4:if(queueFirst!=NULL)
							displayQueue(queueFirst);
							else
							printf("\tThe queue is empty!");
							break;
					case 5: key = front(queueFirst);
							if(key!=STOP)
								printf("\tValue at front is: %d",key);break;
					case 6: key = rear(tail);
							if(key!=STOP)
								printf("\tValue at rear is: %d",key);break;
				 }
				  }while(op!=0);
				break;
                                   
        	}

    
    continueResponse = get("Press 0 to exit or any other key to continue");
    
    }while(continueResponse!=0);


	//List functions
	/*
	while(cnt!=0){
		neww  = createNode();
		first = insertAtBeg(first,key);
		cnt--;
		key+=10;
	}
	
	first = insertAtBeg(first,800);
	neww = first;
	while(neww!=NULL)
	{
		printf("%d\t",neww->data);
		neww = neww->link;
	}
	printf("\n%d",lengthLL(first));
	deleteAtEnd(first,&delValue); 
	printf("\n%d\n",delValue);
	*/
	return 0;
}
