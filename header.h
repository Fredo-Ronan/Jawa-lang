#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

typedef char string[1000];

int stringLength(string input){
	int i = 0;
	
	while(input[i]!='\0'){
		i++;
//		printf("\no");
	}
	
	return i;
}

