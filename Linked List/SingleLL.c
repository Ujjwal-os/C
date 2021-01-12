#include<stdio.h>  
#include<stdlib.h>  

struct node{
	int data;
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

void main ()  
{  
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
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break; 
			case 9:
				exit(0); 
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}

void beginsert(){
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("overflow!!");
	}
	else{
		int item;
		printf("Enter data: ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("Node Inserted");
	}
} 

void lastinsert(){
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("overflow!!");
	}
	else{
		int item;
		printf("Enter data: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL){
			ptr->next=NULL;
			head=ptr;
			printf("Node Inserted");
		}
		else{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			printf("Node Inserted");
		}
	}
}

void randominsert(){
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("overflow!!");
	}
	else{
		int item,loc,i;
		printf("Enter data: ");
		scanf("%d",&item);
		ptr->data=item;
		printf("Enter location: ");
		scanf("%d",&loc);
		temp=head;
		for(i=1;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("Can't Insert");
				return;
			}
		}
		ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("Node inserted");
	}
}

void begin_delete(){
	struct node *ptr;
	if(head==NULL){
		printf("underflow!!");
	}
	else{
		ptr=head;
		head=head->next;
		free(ptr);
		printf("Node delete at begin");
	}
}

void last_delete(){
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
		printf("Node delete at last");
	}
}

void random_delete(){
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else{
		int loc,i;	
		printf("Enter location :");
		scanf("%d",&loc);
		ptr=head;
		for(i=1;i<loc;i++){
			ptr1=ptr;
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("Can't Delete");
				return;
			}
		}
		ptr1 ->next = ptr ->next;  
    	free(ptr);  
    	printf("\nDeleted node %d ",loc+1);  
	}
}

void search(){
	int i=0,flag,item;
	struct node *ptr;
	ptr=head;
	if(ptr==NULL){
		printf("Underflow");
	}
	else{
		printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while(ptr!=NULL){
        	if(ptr->data==item){
        		printf("Item found at location %d ",i+1);  
                flag=0; 
			}
			else{
				flag=1;	
			}
        	i++;
        	ptr=ptr->next;
		}
		if(flag==1){
			printf("Item not found\n"); 
		}
	}
}

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     
