#include "main.h"
/**
 * recent - shows recent transactions
 * @myAccount: user's account
 */
void recent(struct Account *myAccount)
{
	puts("TRANSACTIONS\n");
	puts("SENT");
	while (myAccount->sent)
	{
		printf("You sent $%lf to %s\n", myAccount->sent->amount, myAccount->sent->name);
		myAccount->sent = myAccount->sent->next;
	}
	puts("");

	puts("RECIEVED");
	while (myAccount->recieve)
	{
		printf("You recieved $%lf from %s\n", myAccount->recieve->amount, myAccount->recieve->name);
		myAccount->recieve = myAccount->recieve->next;
	}

	puts("\nEND");
}
