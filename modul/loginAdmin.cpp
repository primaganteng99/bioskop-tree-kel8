#include "../bioskopHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

int loginAdmin(char *username, char *password) {
	
    FILE *file = fopen("database/adminAccount.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }
    rewind(file);
    
    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];
    
    while (!feof(file)) {
        fscanf(file, "%s %s\n", storedUsername, storedPassword);
        
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            printf("==================\n");
            printf("= Login berhasil =\n");
            printf("==================\n");
            return 1; // Login berhasil
        }
    }
    
    printf("===============\n");
    printf("= Login Gagal =\n");
	printf("===============\n");
    fclose(file);
    return 0; // Login gagal
}

void registerAdmin(char *username, char *password){
	
	printf("Registrasi\n");
	printf("Username : ");
	scanf("%s\n",username);
	
	printf("Password : ");
	scanf("%s\n",password);
	
	FILE *file = fopen("database/adminAccount.txt", "r");
	if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    rewind(file);
    
    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];
	
	    while (fscanf(file, "%s %s\n", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0) {
            fclose(file);
            printf("====================\n");
    		printf("= Registrasi Gagal =\n");
    		printf("====================\n");
            printf("Username sudah digunakan.\n");

            return;
        }
	}
	fclose(file);
	
	file = fopen("database/adminAccount.txt", "a");
	if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    
    printf("=======================\n");
    printf("= Registrasi berhasil =\n");
    printf("=======================\n");
}
