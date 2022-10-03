#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wallet.h"

/*
 * check if the balance will go below zero
 */
static int checkBalance(WALLET *wallet, int ammount){
	int bal = wallet-> balance;	
	if(bal < ammount){
		return -1;
	}
	if(bal > ammount){
		return 0;
	}
	if(bal = ammount){
		return 1;
	}
	return 2;
}


static void writef(WALLET *wallet){
	char dir[30] = "/home/sourov/wallets/";
	char fileName[30];
	strcpy(fileName, wallet->walletName);
	strcat(dir, fileName);
	FILE *walletFile = fopen(dir, "w");
	fprintf(walletFile, "%s\t%d", wallet->walletName, wallet->balance);
	fclose(walletFile);
}

WALLET *createWallet(int balance, char *name){
	WALLET *wallet = (WALLET *) malloc(sizeof(WALLET));
	wallet->balance = balance;
	strcpy(wallet->walletName, name);
	return wallet;
}

void saveWallet(WALLET *wallet){
	FILE *walletFile = fopen("/home/sourov/walletData.txt", "w");
	fprintf(walletFile, "%s", wallet->walletName);
	fclose(walletFile);
}

void addBalance(WALLET *wallet, int amount){
	int bal = wallet->balance;
	bal = bal + amount;
	wallet->balance = bal;
	writef(wallet);
}



void deductBalance(WALLET *wallet, int ammount){
	if(checkBalance(wallet, ammount) == 0){
		int bal = wallet->balance;
		bal = bal - ammount;
		wallet->balance = bal;
	}else if(checkBalance(wallet, ammount) == -1){
		printf("Low balance");
	}
}



