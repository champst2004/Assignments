//struct node* mergeLists(struct node* list1, struct node* list2) not used

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int prn;
	char name[30];
	struct node* next;	
};

struct node* head = NULL;

struct node* create(int prn, char name[]){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prn = prn;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

void addPresident(int prn, char name[]){
	struct node* newPresident = create(prn, name);
	newPresident->next = head;
	head = newPresident;
}

void addSecretary(int prn, char name[]){
	struct node* newSecretary = create(prn, name);
	struct node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newSecretary;
}

void addMember(int prn, char name[]){
	struct node* newMember = create(prn, name);
	struct node* temp = head;
	while(temp->next !=NULL && temp->next->next !=NULL){
		temp = temp->next;
	}
	newMember->next = temp->next;
	temp->next = newMember;
}

void count(){
	struct node* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	printf("There are %d members in the club\n", count);
}

void display(){
	struct node* temp = head;
	while(temp != NULL){
		printf("PRN: %d, Name: %s\n",temp->prn, temp->name);
		temp = temp->next; 
	}
}

void deleteMember(int prn){
    struct node* temp = head;
    struct node* prev = NULL;
    while(temp != NULL && temp->prn != prn){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Member not found\n");
    }
    else if(prev == NULL){
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
    printf("Member deleted\n");
}

void deletePresident(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    printf("President deleted\n");
}

void deleteSecretary(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    }
    free(temp);
    printf("Secretary deleted\n");
}

void swap(struct node* a, struct node* b){
    int tempPrn = a->prn;
    char tempName[50];
    strcpy(tempName, a->name);
 
    a->prn = b->prn;
    strcpy(a->name, b->name);
 
    b->prn = tempPrn;
    strcpy(b->name, tempName);
}

void sortList(struct node** head){
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;
 
    if(*head == NULL)
        return;
 
    do{
        swapped = 0;
        ptr1 = *head;
 
        while (ptr1->next != lptr){
            if (ptr1->prn > ptr1->next->prn){
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

struct node* mergeLists(struct node* list1, struct node* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
 
    if (list1->prn < list2->prn){
        list1->next = mergeLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
}

void reverseList(){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main(){

    printf("Pinnacle Club\n");
    addPresident(515, "Shivank");
    addMember(646, "Ajay");
    addMember(254, "Nikhil");
    addMember(666, "Aradhya");
    addMember(123, "Soham");
    addMember(354, "Tanishka");
    addSecretary(765, "Faiza");
    count();
    display();

    printf("\nAfter Sorting\n");
    sortList(&head);
    display();

    printf("\nAfter reversing\n");
    reverseList();
    display();

    printf("\nAfter deletion\n");
    deletePresident();
    deleteSecretary();
    deleteMember(354);
    display();
}
