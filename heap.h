#include <stdlib.h>
#include "strutil.h"


#define MaxHeapL 1000

typedef struct{
    char pool[MaxHeapL];
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

    for(int i= 5; i< MaxHeapL; i++)
        h->pool[i] = 0;
    
}

char* heap_alloc(Heap* h, int sz){

    char* address;
    
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
            str_copy(address + (sz+5), address);
            
            *address = 'a';
            heap_int_to_string(address +1, sz);
        }
    }

}