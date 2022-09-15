#ifndef WALLET_H_
#define WALLET_H_

struct wallet{
	int balance;
	char walletName[20];
};

typedef struct wallet WALLET;

void createWallet(WALLET *,int,char *);
void saveWallet(WALLET *);
void addBalnace(WALLET *, int);

void addMoney(WALLET *,int);
int deductMoney(WALLET *,int);
void freeList(char **);


#endif
