#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode {
	int data;
	struct  Listnode* link;
} ListNode;

ListNode* insert(ListNode* head, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* deletee(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	pre = removed->link;
	free(removed);
	return head;
}

int main(void) {
	ListNode* head = NULL;
	int whole, jump, i, j;
	scanf("%d %d", &whole, &jump);
	for ( i = whole; i > 0; i--){
		head = insert(head, i);
	}
	for ( i = 0; i < whole; i++){
		if (i == 0){
			printf("<");
		}
		for (j = 0; j < jump; j++) {
			do{
				head = head->link;
			} while (head->data == 0);
		}
		printf("%d", head->data);
		if (i != whole-1){
			printf(", ");
		}
		else {
			printf(">");
		}
		head->data = 0;
	}
}