#include <stdlib.h>
#include "strutil.h"


#define MaxHeapL 100

typedef struct{
    char pool[MaxHeapL+ 1];
} Heap;

void heap_int_to_string(char* str, int a){	
	int n = 1000;

	for(int i=0; i <4; i++){
		str[i] = (a / n) + '0';
		a %= n;
		n /= 10;
	}
}

void heap_init(Heap* h){
	
    h->pool[0] = 'f';
    heap_int_to_string((h->pool) + 1, MaxHeapL - 5);

	int i= 5;
    for(; i< MaxHeapL; i++)
        h->pool[i] = 'E';
    
	h->pool[i] = 0;
}

char* heap_alloc(Heap* h, int sz){

    char* address= 0;
    
    if(sz > MaxHeapL - 5)
        return 0;
    
    int temp = 0;

    for(int i= 0; i< MaxHeapL; i++){
        if(h->pool[i] == 'f'){
            address = &(h->pool[i]);
            temp = atoi(&(h->pool[i+1]));

            if(sz > temp - 5)
                return 0;

            heap_int_to_string(address +1, temp - (sz + 5));
            
			for(int i= 0; i< 5; i++)
				address[sz +5 +i] = address[i];
            
            *address = 'a';
            heap_int_to_string(address +1, sz);

			break;
        }
    }

	return address;
}

void heap_free(char* p){
	if(*p != 'a')
		return;

	int sz = atoi(p +1);

	int i= 0;

	for(; i< 5; i++)
		p[i] = 'E';

	for(; p[i]; i++){
		if(p[i] == 'a'){
			for(int j= 0; j< 5; j++){
				p[i - (sz+ 5) + j] = p[i + j];
				p[i + j] = 'E';
			}
			i += 4;
		}

		if(p[i] == 'f'){
			heap_int_to_string(&p[i+1], (sz+5) + atoi(&p[i+1]));
			for(int j= 0; j< 5; j++){
				p[i - (sz+ 5) +j] = p[i+j];
				p[i+ j] = 'E';
			}
			break;
		}
	}
}