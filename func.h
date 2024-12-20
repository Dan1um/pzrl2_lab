#include <stdio.h>

void replace_text(const char *line, const char *old_text, const char *new_text, FILE *output);
void delete_words(const char *line, const char *text_to_delete, FILE *output);
void front_insert_text(const char *line, const char *insert_text, FILE *output);
void back_insert_text(const char *line, const char *insert_text, FILE *output);
