#include "header.h"
#include "errorHandling.h"
#include "validasi.h"
#include "parser.h"

int main(int argc, char *argv[]) {
	
	string fileName;
	FILE *openFile;
	
	if(argc < 2){
		errorNoArguments();
	} else {
		strcpy(fileName, argv[1]);
		
		if(validExtension(fileName)){
			if(validName(fileName)){
				//pass
				openFile = fopen(fileName, "r");
				
				if(openFile==NULL){
					errorNoFileExist(fileName);
					fclose(openFile);
				} else {
					// file exist and continue
					fclose(openFile);
					parseFile(fileName);
				}
			} else {
				errorInvalidFormat(fileName);
			}
		} else {
			errorNoExtension(fileName);
		}
	}
	
	return 0;
}
