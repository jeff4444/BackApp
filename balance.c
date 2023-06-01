#include "main.h"
/**
 * show_balance - shows current balance
 * @myAccount: user's account
 */
void show_balance(struct Account *myAccount)
{
	printf("BALANCE\n");
	puts("------------------------------------");
	printf("USERNAME: %s\n", myAccount->username);
	printf("Your current account balance is $%.2lf\n", myAccount->balance);
}
