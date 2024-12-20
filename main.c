#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define LENGTH 1024

int main(int argc, char *argv[]) {
	if (argc < 4) {
		printf("Неверное количество аргументов\n");
		return 1;
	}
	const char *file = argv[1];
	const char *op = argv[2];
	FILE *input = fopen(file, "r");
	if (!input) {
		printf("Ошибка открытия основного файла txt\n");
		return 1;
	}	
	FILE *output = fopen("output.txt", "w");
	if (!output) {
		printf("Ошибка открытия выходного файла txt\n");
		fclose(input);
		return 1;
	}	
	char sentance[LENGTH];
	if (strcmp(op, "-r") == 0) {
		if (argc < 5) {
			printf("Недостаточное количество аргументов для функции -r\n");
			fclose(input);
			fclose(output);
			return 1;
		}
		const char *old_text = argv[3];
		const char *new_text = argv[4];
		while (fgets(sentance, sizeof(sentance), input)) {
			replace_text(sentance, old_text, new_text, output);
		}
	}
	else if (strcmp(op, "-d") == 0) {
		if (argc < 4) {
			printf("Недостаточное количество аргументов для функции -d\n");
			fclose(input);
			fclose(output);
			return 1;
		}
		const char *del_txt = argv[3];
		while (fgets(sentance, sizeof(sentance), input)) {
			delete_words(sentance, del_txt, output);
		}
	}
	else if (strcmp(op, "-i") == 0) {
		if (argc < 5) {
			printf("Недостаточное количество аргументов для функции -i\n");
			fclose(input);
			fclose(output);
			return 1;
		}
		const char *text = argv[4];
		if (strcmp(argv[3], "-f") == 0){
			while (fgets(sentance, sizeof(sentance), input)) {
				front_insert_text(sentance, text, output);
			}
		}
		else if (strcmp(argv[3], "-b") == 0){
			while (fgets(sentance, sizeof(sentance), input)) {
				back_insert_text(sentance, text, output);
			}
		}
		else {
			printf("Введена неизвестная операция\n");
			fclose(input);
			fclose(output);
			return 1;
		}	
	}
	fclose(input);
	fclose(output);
	return 0;
}
