#include<stdio.h>
#include<stdlib.h>
#define MALLOC (struct node*)malloc(sizeof(struct node))

int main(){
	struct node
	{
		int val;
		struct node *next;
	}*new,*head,*tail,*temp,*p;

	char ch;
	int val,choice,n_nodes=0,del_choice;

	head = NULL;
	void create_list(){
		do{
			new = MALLOC;
			printf("ENTER DATA TO BE ENTERED\n");
			scanf("%d",&val);
			new->val = val;
			new->next = NULL;
			if(head == NULL){
				head = new;
				tail = new;
				n_nodes++;
				printf("\nNEW NODE ADDED\n");
			}
			else{
				tail->next = new;
				tail = new; 
				n_nodes++;
				printf("\nELEMENT ADDED IN %d NODE\n",n_nodes);
			}
			printf("\nPRESS 'Y' TO KEEP ADDING ELEMENTS\nPRESS 'N' TO ENTER MAIN MENU\n\n");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='n' || ch == 'N'){
				break;
			}
		}while(ch=='y' || ch=='Y');
	}



	void insert_atEnd(){
		temp = MALLOC;
		new = MALLOC;
		int data;
		printf("\nENTER DATA\n");
		scanf("%d",&data);
		new->val = data;
		new->next = NULL;
		if(head == NULL){
			head = new;
			tail = new;
			n_nodes++;
			printf("\nFIRST NODE ADDED!\n");
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new;
			n_nodes++;
		}
		printf("\nNEW NODE ADDED AT THE END\n",n_nodes );
	}


	void insert_atBeginning(){
		new = MALLOC;
		temp = MALLOC;
		int data;
		printf("\nENTER Data TO BE ENTERED\n");
		scanf("%d",&data);
		new->val = data;
		new->next = NULL;
		if(head == NULL){
			head = new;
			tail = new;
			n_nodes++;
			printf("\nFIRST NODE ADDED!\n");

		}
		else{
			temp = head;
			new->next = temp;
			head = new;
			n_nodes++;
			printf("\nNEW NODE ADDED IN BEGINNING\n");

		}
	}



	void insert_atK(){
		temp = MALLOC;
		new =MALLOC;
		int k,i=1,data;
		printf("\nENTER POSTION AT WHICH NODE IS TO BE ENTERED\n");
		scanf("%d",&k);
		printf("\nENTER THE DATA\n");
		scanf("%d",&data);
		new->val = data;
		new->next = NULL;
		if(head == NULL){
			head = new;
			tail = new;
			n_nodes++;
			printf("\nFIRST NODE ADDED!\n");

		}else if(k == 1){

			temp = head;
			new->next = temp;
			head = new;
			n_nodes++;
			printf("\nNEW NODE ADDED AT BEGINNING\n");

		}else{
			temp = head;
			while(i < k-1){
				temp = temp->next;
				i++;
			}
			new->next = temp->next;
			temp->next = new;
			n_nodes++;
			printf("\nNEW NODE ADDED AT POSTION %d\n",k );
		}
	}


	void delete_from_Beg(){

		temp = MALLOC;
		temp = head;
		p = MALLOC;
		p = head;
		if( temp == NULL){
			printf("\nLIST EMPTY\n");
		}
		else{
			p = temp->next;
			free(temp);
			head = p;
			printf("\nNODE DELETED\n");
			n_nodes--;
		}
	}


	void delete_from_End(){

		temp = MALLOC;
		p = MALLOC;
		temp = head;
		p = head;
		if(p == NULL){
			printf("\n LIST IS EMPTY\n");
		}
		else if(n_nodes == 1){
			free(temp);
			head = NULL;
			printf("\nFIRST NODE DELETED\n");
			n_nodes--;
		}
		else{
			while(temp->next->next != NULL){
				p = p->next;
				temp = temp->next;
			}
			printf("\nLAST NODE DELETED %d \n",temp);
			temp = temp->next;
			p->next = NULL;
			free(temp);
			n_nodes--;
		}

	}


	void delete_from_K(){
		int i=1;
		temp = MALLOC;
		p = MALLOC;
		temp = head;
		p = head;
		printf("\nENTER POSTION TO BE DELETED\n");
		scanf("%d",&val);
		if(n_nodes == 1 && val == 1){
			free(temp);
			head = NULL;
			n_nodes--;
			printf("\nFIRST NODE DELETED!\n");
		}
		else{
			while(i < val-1){
				temp = temp->next->next;
				p = p->next;
				i++;
			}
			p->next = temp->next;
			free(temp);
			n_nodes--;
			printf("\nNODE %d DELETED FROM THE LIST!\n",val );
		}	
	}

	void display_list(){
		temp = MALLOC;
		temp = head;
		printf("\n\n\n");
		while(temp!=NULL){
			printf("| %d | %d |",temp->val,temp->next);
			if(temp->next != NULL){
				printf("------->");
			}
			temp = temp->next;
		}
		printf("\nNUMBER OF NODES IN LINKED LIST ARE: %d\n",n_nodes);
	}



while(1){
	printf("\n**************************|| MAIN MENU ||********************************************\n");
	printf("\n\n1.CREATE A LINKED LIST\n2.DISPLAY THE LIST\n3.INSERT A NODE AT END\n4.INSERT A NODE IN THE BEGINNING\n5.INSERT AT GIVEN POSTION\n6.DELETE\n7.EXIT\n");
	printf("\n######################################################################################\n");
	fflush(stdin);
	scanf("%d",&choice);


	if(choice == 1){
		create_list();
	}
	else if(choice == 2){
		display_list();
	}
	else if(choice == 3){
		insert_atEnd();
	}
	else if(choice == 4){
		insert_atBeginning();
	}
	else if(choice == 5){
		insert_atK();
	}
	else if(choice == 6){
		printf("\n1.DELETE FROM START\n2.DELETE FROM END\n3.DELETE FROM K\n");
		scanf("%d",&del_choice);
		if(del_choice == 1){
				delete_from_Beg();
		}
		else if(del_choice == 2){
			delete_from_End();
		}
		else if(del_choice == 3){
			delete_from_K();
		}
		else{
			exit(0);
		}
			
		}
	else{
		exit(0);
	}
}
return 0;
}