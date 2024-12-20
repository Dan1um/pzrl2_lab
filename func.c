#include <stdio.h>
#include <string.h>
#include "func.h"

void replace_text(const char *line, const char *old_text, const char *new_text, FILE *output) {
	const char *pos = line;
	while ((pos = strstr(pos, old_text)) != NULL) {
		fwrite(line, 1, pos - line, output);
		fprintf(output, "%s", new_text);
		pos += strlen(old_text);
		line = pos;
	}
	fprintf(output, "%s", line);
}

void delete_words(const char *line, const char *text_to_delete, FILE *output) {
	if (strstr(line, text_to_delete) == NULL) {
		fprintf(output, "%s", line);
	}
}

void front_insert_text(const char *line, const char *insert_text, FILE *output) {
	fprintf(output, "%s %s", insert_text, line);
}
void back_insert_text(const char *line, const char *insert_text, FILE *output) {
	 size_t len = strlen(line);
	 fprintf(output, "%.*s %s\n", (int)(len - 2), line, insert_text);
}
