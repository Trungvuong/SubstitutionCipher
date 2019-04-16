/**********************************************************************
 * This program implements the substitution cipher using a command 
 * line argument style approach with file input and output.
 *
 * @author Trung-Vuong Pham
 * @version 1.0
 *********************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "functions.h"

// The main method that utilizes the header and prototype file.
int main(int argc, char* argv[]){
    char choice, ch;  // user choice of method and character for message
    FILE *fin, *fout; // File pointers				
    if (argc != 5){
	    printf ("Usage: cipher option key infile, outfile\n");
	    printf ("Choose option e for encryption and d for decryption");
	    exit(1);
    }

    choice = toupper(*argv[1]); // choice for method, e or d
    char *key = (char*)malloc(sizeof(argv[2]) + sizeof(char)); // the key of the cipher
    key = removeDuplicates(argv[2]); // remove duplicate characters from key

    char *encrypt = (char*)malloc(27 * sizeof(char));  // encrypt and decrypt arrays
    char *decrypt = (char*)malloc(27 * sizeof(char));
    initializeEncryptArray(key, encrypt);

    fin = fopen(argv[3], "r");  // reads file
    fout = fopen(argv[4], "w"); // writes file
    if(fin == NULL || fout == NULL){
	    printf("File could not be opened \n");
	    exit(1);
    }
    // To encrypt method
    if(choice  == 'E')
    	    processInput(fin, fout, encrypt);							   
    // To decrypt method
    if(choice == 'D'){
        initializeDecryptArray(encrypt, decrypt);				
	processInput(fin, fout, decrypt);							    }												   fclose(fin);
     fclose(fout);										    return 0;
}
