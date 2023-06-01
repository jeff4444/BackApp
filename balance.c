#include "main.h"
/**
 * show_balance - shows current balance
 * @myAccount: user's account
 */
void show_balance(struct Account *myAccount)
{
	printf("\nYour current account balance is $%lf\n", myAccount->balance);
}
