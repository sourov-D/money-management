#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wallet.h"

int main(int argc, char **argv){

	if(!(strcmp("-cw", *(argv+1)))){
		WALLET wallet;
		WALLET *walletp = &wallet;
		int bal = atoi(*(argv + 3));
		createWallet(walletp, bal, *(argv + 2));
	}else if(!(strcmp("-ab", *(argv+1)))){
		WALLET wallet;
		WALLET *walletp = &wallet;
		walletp->balance = atoi(*(argv + 3));
		strcpy(walletp->walletName, *(argv + 2));
		addBalance(wallet, amount)
	}

	return 0;
}
