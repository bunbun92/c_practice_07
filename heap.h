#include <stdlib.h>
#define MaxHeapL 260

typedef struct{
	char pool[MaxHeapL];	
} Heap;

void set_header(char* addr, char header, int sz){
	*addr = header;
	*((int*)(addr+1))= sz;
}

char* find_free(Heap* h, int sz){
	for (int i=0; i< MaxHeapL; i++){
		if (h->pool[i] == 'a')
			i += *((int*)&(h->pool[i+1])) + 5;
		if (h->pool[i] == 'f' && *((int*)(&h->pool[i+1])) >= sz + 5)
			return &(h->pool[i]);
	}
	return 0;
}

void heap_init(Heap* h){
	set_header(h->pool, 'f', MaxHeapL - 5);
}

char* heap_alloc(Heap* h, int sz){
	char* p= 0;
	if (p = find_free(h, sz)){
		set_header(p+(sz+5), 'f', *((int*)(p+1)) - (sz+5));
		set_header(p, 'a', sz);		
	}
	return p;
}

void heap_free(char* p){
	set_header(p, 'f', *((int*)(p+1)));	
}