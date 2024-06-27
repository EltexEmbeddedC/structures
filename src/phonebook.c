#include "../include/phonebook.h"

void print_menu() {
  printf(
      "1) Добавить абонента\n"
      "2) Удалить абонента\n"
      "3) Поиск абонентов по имени\n"
      "4) Вывод всех записей\n"
      "5) Выход\n");
}

void run() {
  abonent abonents[N];
  int choice;

  init_abonents(abonents);
  do {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_abonent(abonents);
        break;
      case 2:
        delete_abonent(abonents);
        break;
      case 3:
        find_abonent(abonents);
        break;
      case 4:
        print_abonents(abonents);
        break;
      case 5:
        printf("Выходим...\n");
        break;

      default:
        printf("Ошибка! Неверное значение пункта меню.\n");
        break;
    }
  } while (choice != 5);
}

void init_abonents(abonent* abonents) {
  for (int i = 0; i < N; i++) {
    abonents[i].name[0] = '\0';
    abonents[i].second_name[0] = '\0';
    abonents[i].tel[0] = '\0';
  }
}

int find_free_index(abonent* abonents) {
  for (int i = 0; i < N; i++) {
    if (abonents[i].name[0] == '\0') {
      return i;
    }
  }
  return -1;
}

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void safe_input(char* input, size_t size, const char* prompt) {
  while (1) {
    printf("%s", prompt);
    if (scanf("%9s", input) == 1) {
      if (strlen(input) == size - 1) {
        int c = getchar();
        if (c != '\n' && c != EOF) {
          clear_input_buffer();
          printf("Введено слишком много символов. Попробуйте снова.\n");
          continue;
        }
      }
      break;
    } else {
      printf("Ошибка ввода. Попробуйте снова.\n");
      clear_input_buffer();
    }
  }
}

void add_abonent(abonent* abonents) {
  int index = find_free_index(abonents);
  if (index == -1) {
    printf("Справочник переполнен. Невозможно добавить нового абонента.\n");
    return;
  }

  safe_input(abonents[index].name, 10, "Введите имя: ");
  safe_input(abonents[index].second_name, 10, "Введите фамилию: ");
  safe_input(abonents[index].tel, 10, "Введите номер телефона: ");

  printf("Абонент добавлен.\n");
}

void delete_abonent(abonent* abonents) {
  char name[10], second_name[10];
  safe_input(name, 10, "Введите имя: ");
  safe_input(second_name, 10, "Введите фамилию: ");

  int found = 0;
  for (int i = 0; i < N; i++) {
    if (strcmp(abonents[i].name, name) == 0 &&
        strcmp(abonents[i].second_name, second_name) == 0) {
      abonents[i].name[0] = '\0';
      abonents[i].second_name[0] = '\0';
      abonents[i].tel[0] = '\0';
      printf("Абонент удален.\n");
      found = 1;
    }
  }
  if (!found) {
    printf("Абоненты с таким именем не найдены.\n");
  }
}

void find_abonent(abonent* abonents) {
  char name[10], second_name[10];
  safe_input(name, 10, "Введите имя: ");
  safe_input(second_name, 10, "Введите фамилию: ");

  int found = 0;
  for (int i = 0; i < N; i++) {
    if (strcmp(abonents[i].name, name) == 0 &&
        strcmp(abonents[i].second_name, second_name) == 0) {
      printf("Имя: %s, Фамилия: %s, Телефон: %s\n", abonents[i].name,
             abonents[i].second_name, abonents[i].tel);
      found = 1;
    }
  }
  if (!found) {
    printf("Абоненты с таким именем не найдены.\n");
  }
}

void print_abonents(abonent* abonents) {
  for (int i = 0; i < N; i++) {
    if (abonents[i].name[0] != '\0') {
      printf("Имя: %s, Фамилия: %s, Телефон: %s\n", abonents[i].name,
             abonents[i].second_name, abonents[i].tel);
    }
  }
}
