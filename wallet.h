#ifndef WALLET_H_
#define WALLET_H_

struct wallet{
	int balance;
	char walletName[20];
};

typedef struct wallet WALLET;

WALLET *createWallet(int,char *);
void saveWallet(WALLET *);
void addBalance(WALLET *, int);
void deductBalanace(WALLET *, int);

#endif
