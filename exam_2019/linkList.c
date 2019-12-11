#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linkNode {
	int data;
	struct linkNode *next;
}linkNode, *linkList;

/****************** (START) code code (START) ***********************/
void insert(linkList head, int val) {
	linkNode *pre, *p, *newNode;
	newNode = malloc(sizeof(linkNode));
	newNode->data = val;

	pre = head;
	p = head->next;

	while (p != NULL && p->data <= val) {
		pre = pre->next;
		p = p->next;
	}
	
	newNode->next = pre->next;
	pre->next = newNode;
}
/****************** (END) code code (END) ***********************/

void printLinkList(linkList head) {
	head = head->next;
	while (head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}
	putchar('\n');
}

int main() {
	// create an empty linkList
	linkList head = malloc(sizeof(linkNode));
	head->next = NULL;

	int val;
	while (true) {
		printf("Enter a number to insert into the linkList(Exit with 0): ");
		scanf("%d", &val);
		if (val == 0)
			break;
		insert(head, val);
		printLinkList(head);
	}

	return 0;
}
