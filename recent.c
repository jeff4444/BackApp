#include "main.h"
/**
 * recent - shows recent transactions
 * @myAccount: user's account
 */
void recent(struct Account *myAccount)
{
	struct Send *sent = myAccount->sent;
	struct Recieved *recieve = myAccount->recieve;

	puts("TRANSACTIONS\n");
	puts("SENT");
	while (sent)
	{
		printf("You sent $%lf to %s, on %s\n", sent->amount, sent->name, ctime(&(sent->t)));
		sent = sent->next;
	}
	puts("");

	puts("RECIEVED");
	while (recieve)
	{
		printf("You recieved $%lf from %s, on %s\n", recieve->amount, recieve->name, ctime(&(recieve->t)));
		recieve = recieve->next;
	}

	puts("\nEND");
}
