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
void random_delete_by_loc();
void random_delete_by_val();  
void display();  
void search(); 

void main(){
	int choice =0;  
    printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Delete node by value\n8.Search for an element\n9.Show\n10.Exit\n"); 
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
            random_delete_by_loc();          
            break;  
            case 7:  
            random_delete_by_val();      
            break;  
            case 8:  
            search();       
            break; 
			case 9:
			display();
			break;
			case 10:
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
	ptr=(struct node*)malloc(sizeof(struct node));
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
		ptr->data=item;
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next=ptr;
		temp->next->prev=ptr;
		printf("Node Inserted");
	}
}

void begin_delete(){
	struct node *ptr;
	if(head==NULL)
	{
		printf("\n UNDERFLOW");  
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
		printf("Node Deleted");
	}
	else{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
		printf("Node Deleted");
	}
}

void last_delete(){
	struct node *ptr;
	if(head==NULL){
		printf("Underflow");
	}
	else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nNode Deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nNode Deleted\n");  
    }  
}

void random_delete_by_loc(){
	struct node *ptr,*temp;
	int loc,i;
	if(head==NULL){
		printf("Overflow");
	}
	else{
		temp=head;
		printf("Enter the position : ");
		scanf("%d",&loc);
		for(i=1;i<loc;i++){
			temp=temp->next;
			if(ptr==NULL){
				printf("Can't Delete");
				return;
			}
		}
		ptr=temp->next;
		temp->next=ptr->next;
		temp->next->prev=temp;
		free(ptr);
		printf("Node Deleted");
	}
}

void random_delete_by_val(){
	struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}

void display()  
{  
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}  

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}   
