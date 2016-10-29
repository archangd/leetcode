/**
 * Definition for singly-linked list.
 * struct struct ListNode {
 *     int val;
 *     struct struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head, *walk;
	int temp, carry = 0;

	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 0;
	head->next = NULL;
	walk = head;

	while (l1 != NULL) {
		if (l2 == NULL) {
			l2 = l1;
			break;
		}
		temp = l1->val + l2->val + carry;
		carry = temp / 10;
		walk->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		walk = walk->next;
		walk->val = temp % 10;
		walk->next = NULL;

		l1 = l1->next;
		l2 = l2->next;
	}

	while (l2 != NULL) {
		temp = l2->val + carry;
		carry = temp / 10;
		walk->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		walk = walk->next;
		walk->val = temp % 10;
		walk->next = NULL;

		l2 = l2->next;
	}

	if (carry > 0) {
		walk->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		walk = walk->next;
		walk->val = 1;
		walk->next = NULL;
	}

	walk = head->next;
	free(head);
	return walk;
}
