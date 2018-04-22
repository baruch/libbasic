#include "basic.h"

#include <stdio.h>

struct t {
	char a[27];
	unsigned val;
};

int main(int argc, char ** UNUSED(argv))
{
	printf("STR: " STR(hello_world) "\n");

	if (likely(argc == 1)) {
		printf("One arg\n");
	} else {
		printf("multiple args\n");
	}

	char str[] = {'H', 'e' ,'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\n'};
	int i;

	for (i = 0; i < ARRAY_SIZE(str); i++) {
		putchar(str[i]);
	}

	struct t t;
	t.val = 30;

	unsigned *pval = &t.val;

	struct t* pt = container_of(pval, struct t, val);
	printf("val: %d %d\n", pt->val, *pval);

	return 0;
}
