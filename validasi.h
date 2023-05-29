
bool validName(string inputFileName){
	int i = 0;
	int j;
	
	while(inputFileName[i]!='.') i++;
	
	i++;
	char fileNameFormat[5] = {' ', ' ', ' ', ' ', ' '};
	
	for(j=0;inputFileName[i]!='\0';j++){
		fileNameFormat[j] = inputFileName[i];
		i++;
	}
	
	fileNameFormat[j] = '\0';
	
	if(strcmp(fileNameFormat, "jawa")==0){
		return true;
	}
	
	return false;
}

bool validExtension(string inputFileName){
	int i;
	
	for(i=0;inputFileName[i]!='\0';i++){
		if(inputFileName[i]=='.'){
			if(inputFileName[i+1]=='\0'){
				return false;
			}else{
				return true;
			}
		}
	}
	
	return false;
}
