#define SIZEARRAYSTRING 100
#define BUFFERSIZE 100

void initArrayString(string arr[]){
	int i;
	
	for(i=0;i<SIZEARRAYSTRING;i++){
		strcpy(arr[i], " ");
	}
}

void initArrayChar(char arr[]){
	int i;
	
	for(i=0;i<BUFFERSIZE;i++){
		arr[i] = ' ';
	}
}

bool checkNomerType(char buffer[]){
	int i, j = 0;
	
	char nomer[INTEGER] = {'n','o','m','e','r'};
	char tempNomer[INTEGER + 1];
	char tempBuffer[BUFFERSIZE];
	
	for(i=0;i<INTEGER;i++){
		tempNomer[i] = nomer[i];
	}
	
	for(i=0;i<buffer[i]!=' ';i++){
		tempBuffer[i] = buffer[i];
	}
	
	tempBuffer[i] = '\0';
	tempNomer[INTEGER] = '\0';
	
	if(strstr(tempBuffer, tempNomer) != NULL){
		return true;
	}
	
//	for(i=0;buffer[i]!=' ';i++){
//		if(buffer[i]==nomer[j]){
//			
//		}
//	}

	return false;
}

void parseSyntax(string fileName){
	FILE *openFile;
	
	string existedVariable[SIZEARRAYSTRING];
	int indexExisted = 0;
	char buffer[100];
	
	initArrayChar(buffer);
	initArrayString(existedVariable);
	
	openFile = fopen(fileName, "r");
	
	while(fgets(buffer, 100, openFile)){
		
	}
}
