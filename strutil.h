#include <stdio.h>
#include <stdlib.h>


int str_length(char* str){
	int n = 0;
	for (int i= 0; *(str+i) != 0; i++)
		n++;

	return n;
}

void str_lower(char *str){
	for (; *str; str++){
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;		
	}
};

bool str_compare(char* a, char* b){
	int i= 0;
	for (; a[i]; i++){
		if (a[i] != b[i])
			return 0;
	}

	if(b[i] != 0)
		return 0;
	return 1;
};

void str_copy(char* dst, char* src){

// 	str_copy 안에 동적할당하면 왜 안되는지
// 	dst = new char[str_length(src) + 1];
	int i= 0;

	for (; src[i]; i++)
		dst[i] = src[i];

	dst[i] = 0;	
};

char* str_dup(char* str){

	char* temp= new char[str_length(str) + 1];
	str_copy(temp, str);
	
	return temp;
};

void str_append(char* str, char* str2){

	for(; *str; str++);	

	for(; *str2; str2++)
		*str++ = *str2;		

	*str = 0;
};


char* str_find(char* str, char* sub){	

	char* p = 0;
	bool check = 0;

	for(; *str, check == 0; str++){
		if(*str == *sub){
			p = str;
			check = 1;

			for (char* p2= sub; *p2; p2++){
				if(*str != *p2){
					check = 0;
					break;
				}				
				str++;
			}			
		}
	}
	return p;
};

void str_trim(char* str){	

	char* s;
	char* e;

	for(char* p= str; *p; p++){

	}

};


int str_to_int(char* str);

