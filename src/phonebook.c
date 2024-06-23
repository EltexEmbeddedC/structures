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

void add_abonent(abonent* abonents) {
  int index = find_free_index(abonents);
  if (index == -1) {
    printf("Справочник переполнен. Невозможно добавить нового абонента.\n");
    return;
  }

  printf("Введите имя: ");
  scanf("%9s", abonents[index].name);
  printf("Введите фамилию: ");
  scanf("%9s", abonents[index].second_name);
  printf("Введите номер телефона: ");
  scanf("%9s", abonents[index].tel);

  printf("Абонент добавлен.\n");
}

void delete_abonent(abonent* abonents) {
  char name[10];
  printf("Введите имя абонента для удаления: ");
  scanf("%9s", name);

  for (int i = 0; i < N; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
      abonents[i].name[0] = '\0';
      abonents[i].second_name[0] = '\0';
      abonents[i].tel[0] = '\0';
      printf("Абонент удален.\n");
      return;
    }
  }
  printf("Абонент с таким именем не найден.\n");
}

void find_abonent(abonent* abonents) {
  char name[10];
  printf("Введите имя для поиска: ");
  scanf("%9s", name);

  int found = 0;
  for (int i = 0; i < N; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
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
