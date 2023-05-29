#define INTEGER 5
#define PRINT 5
#define EQUALSIGN 4

string result;

char* splitTypeVariable(string input, int lengthType){
	int i = lengthType+1, j = 0;
	char buffer[50];
		
	while(input[i]!=' '){
		buffer[j] = input[i];
		i++;
		j++;
	}
	
	buffer[j] = '\0';
	
	strcpy(result, buffer);
	
	return result;
}

char* getValue(string input, int lengthType){
	int i = lengthType+1, j = 0;
	int kuwiIndex = 0;
	int countKuwi = 0;
	char buffer[50];
	char kuwi[EQUALSIGN] = {'k','u','w','i'};
	
	while(input[i]!='\0'){
		if(input[i]==kuwi[kuwiIndex]){
			countKuwi++;
			kuwiIndex++;
			if(countKuwi==EQUALSIGN){
				break;
			}
		}
		
		i++;
	}
	
	i += 2;
	
	while(input[i]!='.'){
		buffer[j] = input[i];
		i++;
		j++;
	}
	
	buffer[j] = '\0';
	
	strcpy(result, buffer);
	
	return result;
}


void parseInt(string input, string cFile){
	FILE *openFile;
	string varName;
	
	strcpy(varName, splitTypeVariable(input, INTEGER));
	
	openFile = fopen(cFile, "a");
	
	fprintf(openFile, "\n\tint %s = %s;", varName, getValue(input, INTEGER));
	
	fclose(openFile);
}

void parseChar(string input){
	
}

void parseFloat(string input){
	
}

void parseString(string input){
	
}

void parsePrint(string input, string cFile, int parseWhat, int lineParsing){
	FILE *openFile;
	string printCommand;
	string var, syntax;
	bool newLine = true;
	char noEnterFlag[7] = {'r','e','t','n','E','o','n'};
	
	int checkNewLineIndex = stringLength(input) - 1;
	int indexNoEnterFlag = 0;
	int countNewLine = 0;

	while(input[checkNewLineIndex]!='.'){
		
		if(input[checkNewLineIndex]==noEnterFlag[indexNoEnterFlag]){
			countNewLine++;
			indexNoEnterFlag++;
		}
		checkNewLineIndex--;
		
		if(input[checkNewLineIndex]!='.'){
			// warning noEnter syntax ambigu
			warningNoEnterSyntax(lineParsing);
			break;
		}
	}
	
	if(countNewLine==7){
		newLine = false;
	}
	
	strcpy(printCommand, "printf(");
	
	char buffer[50];
	char bufferVariable[50];
	
	int i, j = 0;
	
	while(printCommand[j]!='\0'){
		buffer[j] = printCommand[j];
		j++;
	}
	
	i=PRINT+1;
	i++;
	buffer[j] = '"';
	j++;
	
	while(input[i]!='"'){
		buffer[j] = input[i];
		j++;
		i++;
	}
	
	
	switch(parseWhat){
		case 1:
			// integer
			if(newLine){
				buffer[j] = '%';
				buffer[++j] = 'd';
				buffer[++j] = '\\';
				buffer[++j] = 'n';
				buffer[++j] = '"';
				buffer[++j] = ',';
				buffer[++j] = ' ';
			} else {
				buffer[j] = '%';
				buffer[++j] = 'd';
				buffer[++j] = '"';
				buffer[++j] = ',';
				buffer[++j] = ' ';
			}
		break;
		
		case 2:
			// float
		break;
		
		case 3:
			// char
		break;
		
		case 4:
			// string
		break;
		
		case -1:
			// print biasa
			if(newLine){
				buffer[j] = '\\';
				buffer[++j] = 'n';
				buffer[++j] = '"';
			} else {
				buffer[j] = '"';
			}
			
			j++;
		break;
	}
	
	
	
	i++;
	
	while(input[i]!='.'){
		buffer[j] = input[i];
		j++;
		i++;
	}
	
	buffer[j] = '\0';
	strcpy(syntax, buffer);

	openFile = fopen(cFile, "a");
	fprintf(openFile, "\n\t%s);", syntax);
	fclose(openFile);
}

int parseCheckType(char input[]){
	int i, k = 0;
	int countNomer = 0;
	int countKetok = 0;
	int countKuwi = 0;
	char nomer[INTEGER] = {'n','o','m','e','r'};
	char ketok[PRINT] = {'k','e','t','o','k'};
	
	for(i=0;input[i]!='\0';i++){
		
		if(input[i]==nomer[i]){
			countNomer++;
			if(countNomer==INTEGER){
				return 1;
			}
		}
		
		if(input[i]==ketok[k]){
			countKetok++;
			k++;
			if(countKetok==PRINT){
				return 2;
			}
		}
	}
	
	if(input[0]=='\n'){
		return 10;
	}
	
	return -1;
}

void parseFile(string fileName){
	FILE *readFile;
	FILE *createCFile;
	FILE *writeCFile;

	puts("Parsing file");
	puts(fileName);
	
	FILE *createBuildFile;
	
	char cFileName[50];
	int i;
	int lineParsing = 0;
	bool parseSuccess = true;
	
	/*
		Variabel parseWhat di gunakan untuk mengidentifikasi apakah parsing untuk print data
		apakah print data untuk menampilkan sebuah value atau tidak
		
		Contoh untuk jika perintah print data terdapat sebuah value yang akan di print = ketok "Hasil adalah = " variabel.
		
		Contoh untuk jika perintah print data bukan merupakan sebuah perintah untuk menampilkan value dari variabel = ketok "Hello world". atau bisa di sebut print data biasa
		
		Code identifikasi :
		
		print data biasa = -1
		print integer	 = 1
		print float 	 = 2
		print char		 = 3
		print string     = 4
	*/
	int parseWhat = -1;
	
	for(i=0;fileName[i]!='.';i++){
		cFileName[i] = fileName[i];
	}
	
	cFileName[i] = '.';
	cFileName[i+1] = 'c';
	cFileName[i+2] = '\0';
	
	readFile = fopen(fileName, "r");
	createCFile = fopen(cFileName, "w");
	fclose(createCFile);
	fclose(readFile);
	
	createBuildFile = fopen("build.bat", "w");
	fclose(createBuildFile);
	
	FILE *writeBuildFile;
	
	writeBuildFile = fopen("build.bat", "a");
	
	fprintf(writeBuildFile, "@echo off\n\ngcc %s -w -o jawaOutput", cFileName);
	fclose(writeBuildFile);
	
	
	writeCFile = fopen(cFileName, "a");
	
	fprintf(writeCFile, "#include <stdio.h>\n#include <stdlib.h>\n\nvoid main(){");
	fclose(writeCFile);
	
	char buffer[100];
	
	readFile = fopen(fileName, "r");
	while(fgets(buffer, 100, readFile)){
		lineParsing++;
		
		switch(parseCheckType(buffer)){
			case 1:
				// integer
				parseInt(buffer, cFileName);
				parseWhat = 1;
			break;
			
			case 2:
				// print
				parsePrint(buffer, cFileName, parseWhat, lineParsing);
				parseWhat = -1;
			break;
			
			case 10:
				// newLine
			break;
			
			case -1:
				// invalid syntax
				errorInvalidSyntax(lineParsing);
				parseSuccess = false;
			break;
		}
	}
	
	if(parseSuccess){
		writeCFile = fopen(cFileName, "a");
		fprintf(writeCFile, "\n\n\tgetch();\n\n}");
		fclose(writeCFile);
		
		system("build.bat");
		system("start jawaOutput.exe");
	}
}



