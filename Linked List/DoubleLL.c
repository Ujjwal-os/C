#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head;

void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search(); 

void main(){
	int choice =0;  
    printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n"); 
    while(choice != 9)   
    {  
         
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randominsert();       
            break;  
//            case 4:  
//            begin_delete();       
//            break;  
//            case 5:  
//            last_delete();        
//            break;  
//            case 6:  
//            random_delete();          
//            break;  
//            case 7:  
//            search();         
//            break;  
//            case 8:  
//            display();        
//            break; 
			case 9:
				exit(0); 
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}

void beginsert(){
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("overflow!!");
	}
	else{
		printf("Enter the item: ");
		scanf("%d",&item);
		if(head==NULL){
			ptr->data=item;
			ptr->prev=NULL;			
			ptr->next=NULL;
			head=ptr;
		}
		else{
			ptr->data=item;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
	}
}

void lastinsert(){
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("Overflow!!");
	}
	else{
		printf("Enter Item: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL){
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			ptr->prev=temp;
		}
	}
}

void randominsert(){
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(struct node);
	if(ptr==NULL){
		printf("Overflow");
	}
	else{
		int item,loc,i;
		printf("Enter the item: ");
		scanf("%d",&item);
		printf("Enter the Location: ");
		scanf("%d",&loc);
		temp=head;
		for(i=1;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL){
				printf("Can't Insert");
				return;
			}
		}
		
		
	}
}
