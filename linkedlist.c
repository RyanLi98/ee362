/* This is an exercise about linked lists  
 * The functions you have to change are 
 *    + "rotate_right"
 *    + "reverse"
 *
 * rotate_right: 
 *    rotates the list to the right by one node.
 *    e.g., if the list is initially ->1 ->2 ->3 -> / 
 *    then after rotate_right, 
 *    the list becomes ->3 ->1 ->2 -> /
 *
 * reverse:
 *    reverses the list, 
 *    e.g., if the list is intially ->1 ->2 ->3 ->/ 
 *    then after reverse, 
 *    the list becomes ->3 ->2 ->1 -> /
 */

#include <stdlib.h>
#include <stdio.h>

struct Node {
	char   key;
	struct Node * next;
}; 

void display(struct Node * head);
struct Node * create_list(int num_nodes);
struct Node * delete_first(struct Node * head);
struct Node * delete_last(struct Node * head);
struct Node * rotate_right(struct Node * head);
struct Node * reverse(struct Node * head);

void main()
{
	printf("First Linked List\n");
	struct Node * head1 = create_list(10);
	printf("Initial List: \n");
	display(head1);

	head1 = delete_first(head1);
	printf("After deleting first node:\n");
	display(head1);

	head1 = rotate_right(head1);
	printf("After rotating to the right:\n");
	display(head1);

	printf("Second Linked List\n");
	struct Node * head2 = create_list(6);
	printf("Lnitial List: \n");
	display(head2);

	head2 = delete_last(head2);
	printf("After deleting last node:\n");
	display(head2);

	head2 = reverse(head2);
	printf("After reversing:\n");
	display(head2);

}

struct Node * delete_first(struct Node * head)
{
	if (head==NULL) return NULL;
	struct Node * p = head->next;
	free(head);
	return p;
}

struct Node * delete_last(struct Node * head)
{
	if (head==NULL) return NULL; /* List is empty */
	if (head->next==NULL) {  /* List has one node */
		free(head); 
		return NULL;
	}
	struct Node *p = head;
	for (; p->next->next != NULL; p=p->next);
	free(p->next);
	p->next = NULL;
	return head;
}

/* Change the next two functions so they work! */
struct Node * rotate_right(struct Node * head)
{
	return head;
}

struct Node * reverse(struct Node * head)
{
	return head;
}

/* Create a node with a key */
struct Node * create_node(char key)
{
	struct Node * p = (struct Node *) malloc(sizeof(struct Node));
	p->key = key;
	p->next = NULL;
	return p;
}

/* 
 * Create a list of num_nodes nodes:
 *   -> a -> b -> ... -> h
 */
struct Node * create_list(int num_nodes) 
{
	struct Node * head = NULL;
	struct Node * last; /* Last node in the list */
	char c = 'a';
	for (int k=0; k<num_nodes; k++, c++) {
		if (k==0) {
			head = create_node(c);
			last = head;
		}
		else {
			last->next = create_node(c);
			last = last->next;
		}
	}
	return head;
}

/* Display the list */
void display(struct Node * head)
{
	printf("List: ");
	for (struct Node * p=head; p!=NULL; p=p->next) {
		printf("-> %c ", p->key);
	}
	printf("\n");
}




