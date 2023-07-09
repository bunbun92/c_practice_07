#include <stdio.h>
#include "strutil.h"
#include "arr.h"

int main(){

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

	char p5[] = "  ai jf  ";

	printf("trim:%s:\n", p5);
	str_trim(p5);
	printf("trim:%s:\n", p5);


	Arr p6;
	Arr* p7= &p6;
	

	arr_alloc(p7, 5);

	arr_push_back(p7, 'a');

	printf("p7: %s\n", p7->A);

	arr_push_back(p7, 'g');

	printf("p7: %s, N: %d\n", p7->A, p7->N);

	arr_push_at(p7, 'D', 4);

	printf("p7: %s, N: %d\n", p7->A, p7->N);

	char* p8= "3425";

	printf("%d\n", str_to_int(p8));

	Arr p9;
	Arr* p10= &p9;

	arr_alloc(p10, 5);
	arr_push_back(p10, '3');
	arr_push_back(p10, '4');
	arr_push_back(p10, 'g');
	arr_push_back(p10, '4');
	printf("%s, %d\n", p10->A, p10->A);
	printf("%d\n", arr_min(p10));
	printf("%s, %d\n", p10->A, p10->A);

	printf("%.2lf\n", arr_avg(p10));
	printf("%s, %d\n", p10->A, p10->A);
	return 0;
}