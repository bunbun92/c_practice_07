#include <stdio.h>
#include "strutil.h"

void main(){

	printf("%d\n", 22);

	char p1[100] = "aBcd";
	char p2[] = "aBcD";
	
	printf("%d\n", str_compare(p1, p2));	

	char* p3 = "";
	p3 = new char[str_length(p1) + 1];
	str_copy(p3, p1);

	printf("%s\n", p3);
	printf("p1= %s, p1Addr= %d // p3= %s, p3Addr= %d\n", p1, p1, p3, p3);

	char* p4 = str_dup(p3);
	printf("p4= %s, p4Addr= %d // p3= %s, p3Addr= %d\n", p4, p4, p3, p3);

	delete p3;
	delete p4;

	str_append(p1, p2);
	puts(p1);	

	printf("%s\n", str_find(p1, p2));
	printf("22\n");
}