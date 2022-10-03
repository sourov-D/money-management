#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wallet.h"

int main(int argc, char **argv){
	WALLET *p = createWallet(300, "Market");
	addBalance(p, 500);
	printf("%d\n", p->balance);
	free(p);
	return 0;
}
