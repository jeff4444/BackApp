#include "main.h"
/**
 * send_funds - sends funds to another user
 * @myAccount: user's account
 */
void send_funds(struct Account **myAccount)
{
	char *amt = NULL, *name = NULL;
	size_t n_chars, n = 0;
	double money;

	printf("Enter amount\n$ ");
	n_chars = getline(&amt, &n, stdin);
	if (n_chars == -1)
	{
		puts("Wrong input");
		return;
	}
	money = _atoi(amt);
	if (money ==-1)
	{
		puts("You entered a not allowed character");
		return;
	}
	if (!money)
	{
		puts("You can not send $0");
		return;
	}
	printf("Send $%.2lf to: ", money);
	n = 0;
	n_chars = getline(&name, &n, stdin);
	name[n_chars - 1] = '\0';
	if (n_chars == -1)
	{
		puts("Incorrect input");
		return;
	}
	if ((*myAccount)->balance < money)
	{
		puts("Not enough account balance to proceed with this transaction");
		return;
	}
	(*myAccount)->balance -= money;
	add_send(money, name, &((*myAccount)->sent));
	printf("Successfully sent $%.2lf to %s\n", money, name);
	puts("RECIEPT");
	puts("--------------------------------------------------");
	printf("Amount Sent: $%.2lf\n", money);
	printf("Sent to: %s\n", name);
	show_balance(*myAccount);
}

/**
 * _atoi - converts a string to an int
 * @s: string
 * Return: amount or -1 if fails
 */
int _atoi(char *s)
{
	int i = 0, res = 0;

	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res);
}

/**
 * add_send - adds a recieve node to the fron of my recieve linked list
 * @amount: amount
 * @name: name of recipient
 * @head: head of node
 */
void add_send(double amount, char *name, struct Send **head)
{
	struct Send *newNode;

	newNode = malloc(sizeof(struct Send));
	newNode->amount = amount;
	newNode->name = name;
	time(&(newNode->t));
	newNode->next = *head;
	*head = newNode;
}
