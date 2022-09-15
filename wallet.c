#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wallet.h"


void createWallet(WALLET *wallet, int balance, char *name){
	wallet->balance = balance;
	strcpy(wallet->walletName, name);
}

void saveWallet(WALLET *wallet){
	FILE *walletFile = fopen("/home/sourov/walletData.txt", "a");
	fprintf(wallet, "%s", wallet->walletName);
	fclose(walletFile);
}

void addBalance(WALLET *wallet, int amount){
	char dir[30] = "/home/sourov/wallets";
	char fileName[10];
	strcpy(fileName, wallet->walletName);
	strcat(dir, fileName);
	FILE *walletFile = fopen(dir, "a");
	fprintf(walletFile, "%s\t%d", wallet->walletName, wallet->balance);
	fclose(walletFile);
}
/*
static void setData(WALLET *wallet, int id, int balance, char *name){
	wallet->id = id;
	wallet->balance=balance;
	strcpy(wallet->walletName, name);
}

static char **getWalletData(){
	char **list = NULL;
	list = malloc(4*sizeof(char *));
	FILE *walletFile = fopen("/home/sourov/wallet.txt", "r");
	if(walletFile == NULL)
		return NULL;
	char buff[20];
	char **buffList = list;
	while(fscanf(walletFile, "%s\n", buff) != EOF){
		*buffList = malloc(20*sizeof(char));
		strcpy(*buffList, buff);
		buffList++;
	}
	fclose(walletFile);
	return list;
}

static int writeWalletData(WALLET *wallet){
	FILE *walletFile = fopen("/home/sourov/wallet.txt", "w");
	char id[100];
	sprintf(id, "%d", wallet->id);
	char balance[100];
	sprintf(balance, "%d", wallet->balance);
	fprintf(walletFile, "%s\n", id);
	fprintf(walletFile, "%s\n", balance);
	fprintf(walletFile, "%s\n", wallet->walletName);
	fclose(walletFile);
}


void addMoney(WALLET *wallet, int amount){
	char **dataList = getWalletData();
	int id = atoi(*(dataList));
	int bal =  atoi(*(dataList + 1));
	bal += amount;
	char name[20];
	strcpy(name, *(dataList+2));
	setData(wallet, id, bal, name);
	writeWalletData(wallet);
	freeList(dataList);
}

int deductMoney(WALLET *wallet, int amount){
	char **dataList = getWalletData();
	int id = atoi(*(dataList));
	int bal = atoi(*(dataList + 1));
	if(bal < amount)
		return 1;
	bal -= amount;
	setData(wallet, id, bal, *(dataList+2));
	writeWalletData(wallet);
	freeList(dataList);
	return 0;
}

void freeList(char **list){
	char **pList = list;
	while(*pList != NULL){
		free(*pList);
		pList++;
	}
	free(list);
}
*/
