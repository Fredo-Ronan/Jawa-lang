
void errorNoArguments(){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 12);
	
	printf("\n==================================================================");
	printf("\n\n\tONO LUPUT : [!] RAONO JENENG FILE E [!]");
	printf("\n\n\tKudune >>>> jawa.exe <jenengFile>.jawa");
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
	
}

void errorInvalidFormat(string inputFileName){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 12);
	
	printf("\n==================================================================");
	printf("\n\n\tONO LUPUT : [!] FORMAT FILE E SALAH [!]\n");
	printf("\n\t%s", inputFileName);
	printf("\n\t");
	
	int i;
	
	for(i=0;inputFileName[i]!='.';i++){
		printf(" ");
	}
	
	printf(" ");
	printf("^");
	
	printf("\n\n\tKudune ----> <jenengFile>.jawa POKOK E .jawa format extensi file e");
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
}


void errorNoExtension(string inputFileName){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 12);
	
	printf("\n==================================================================");
	printf("\n\n\tONO LUPUT : [!] EXTENSI NE RAONO [!]\n");
	printf("\n\t%s", inputFileName);
	printf("\n\t");
	
	int i;
	
	for(i=0;inputFileName[i]!='\0';i++){
		printf(" ");
	}

	printf("^");
	
	printf("\n\n\tKudune ----> <jenengFile>.jawa POKOK E .jawa format extensi file e");
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
}

void errorNoFileExist(string inputFileName){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 12);
	
	printf("\n==================================================================");
	printf("\n\n\tONO LUPUT : [!] FILE E RAONO [!]\n");
	printf("\n\tRaiso nggolek i file seng jeneng e %s", inputFileName);
	printf("\n\n\tTulung di cek maneh nek file e ki ono tenan opo ora nggih....");
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
}

void errorInvalidSyntax(int errLine){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 12);
	
	printf("\n==================================================================");
	printf("\n\n\tONO LUPUT : [!] PENULISAN SYNTAX E SALAH [!]");
	printf("\n\n\tTulung di cek maneh menawi wonten kesalahan penulisan koyo 'nomer', 'ketok', lan sakpanunggalane...");
	printf("\n\n\tLUPUT ketemu neng baris %d", errLine);
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
}

void warningNoEnterSyntax(int warningLine){
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, 14);
	
	printf("\n==================================================================");
	printf("\n\n\tONO PERINGATAN : [!] PENULISAN SYNTAX AMBIGU [!]");
	printf("\n\n\tTulung di cek maneh menawi wonten kesalahan penulisan koyo 'nomer', 'ketok', lan sakpanunggalane...");
	printf("\n\n\tLUPUT ketemu neng baris %d", warningLine);
	printf("\n\n==================================================================");
	
	SetConsoleTextAttribute(hConsole, 7);
}
