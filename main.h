#ifndef BANK_H
#define BANK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct Recieved - recieve details
 * @name: Name of person recieved from
 * @amount: amount
 */
struct Recieved
{
	char *name;
	double amount;
	struct Recieved *next;
};

/**
 * struct Send - send details
 * @name: Name of person sent to
 * @amount: amount
 */
struct Send
{
	char *name;
	double amount;
	struct Send *next;
};
struct Account
{
	char *username;
	double balance;
	struct Recieved *recieve;
	struct Send *sent;
};
void recent(struct Account *myAccount);
int strip(char *str);
void show_balance(struct Account *myAccount);
int _atoi(char *s);
void send_funds(struct Account **myAccount);
void add_send(double amount, char *name, struct Send **head);
#endif
