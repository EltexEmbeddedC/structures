#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdio.h>
#include <string.h>

#define N 100

typedef struct {
  char name[10];
  char second_name[10];
  char tel[10];
} abonent;

void run();
void print_menu();

void init_abonents(abonent* abonents);
int find_free_index(abonent* abonents);

void clear_input_buffer();
void safe_input(char* input, size_t size, const char* prompt);

void add_abonent(abonent* abonents);
void delete_abonent(abonent* abonents);
void find_abonent(abonent* abonents);
void print_abonents(abonent* abonents);

#endif  // PHONEBOOK_H
