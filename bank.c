#include "main.h"
/**
 * main - bank system
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	struct Account *myAccount = malloc(sizeof(struct Account));
	char *reply = NULL;
	size_t n_chars, n = 0;
	int response;

	myAccount->balance = 100;
	myAccount->recieve = NULL;
	myAccount->sent = NULL;
	printf("Enter your name: ");
	n_chars = getline(&(myAccount->username), &n, stdin);
	(myAccount->username)[n_chars - 1] = '\0';
	n = 0;

	while (1)
	{
		printf("\nSelect Option, %s: \n[1] Recieve\n[2] Send\n[3] Show Balance \n[4] Show my recent transactions\n[5] Log out\n", myAccount->username);
		n_chars = getline(&reply, &n, stdin);
		if (n_chars == -1)
			break;
		response = strip(reply);
		switch (response)
		{
			case 1:
				recieve_funds(&myAccount);
				break;
			case 2:
				send_funds(&myAccount);
				break;
			case 3:
				show_balance(myAccount);
				break;
			case 4:
				recent(myAccount);
				break;
			case 5:
				exit(1);
			default:
				printf("Input either 1, 2, 3 or 4\n");
				break;
		}
	}
	return (0);
}

/**
 * strip - strips  string to get response
 * @str: string
 * Return: choice
 */
int strip(char *str)
{
	int choice;
	char *token;

	token = strtok(str, " ");
	choice = _atoi(token);
	return (choice);
}
