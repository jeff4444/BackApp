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
		printf("You sent $%lf to %s\n", sent->amount, sent->name);
		sent = sent->next;
	}
	puts("");

	puts("RECIEVED");
	while (recieve)
	{
		printf("You recieved $%lf from %s\n", recieve->amount, recieve->name);
		recieve = recieve->next;
	}

	puts("\nEND");
}
