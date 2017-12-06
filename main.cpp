#include <cstdio>
#include <rpc.h>
#include <iostream>
#include <cmath>

using namespace std;

// считывание строки
char *readLine() {
    char *str = new char[1]; // создаем строку едениченого размера

    char ch = 0;
    int i = 0;
    while ((ch = getchar()) != '\n') {            // считываем новый символ
        str[i++] = ch;                            // и добавляем его в новую
                                                  // строку, которая являеться копией
        char *copyStr = new char[i + 1];          // предедущей, но ее длинна
        strncpy(copyStr, str, i);                 // больше на 1

        delete[] str;                             // удаляем старую строку
        str = copyStr;                            // переписываем указатель
    }
    str[i] = '\0';                                      // добавление нуль символа, для корректной работы strtok

    return str;
}

void handleString(char **str) {                                 // обработка строки
    if (strlen(*str) != 0) {
        char *strBuffer = strdup(*str);                         // дублируем строку
        char *word = "", *buffer = strtok(strBuffer, " .,?!");  // и разбиваем ее на слова
        int count = 0;                                          // среди этих слов ищем
        while (buffer != nullptr) {                             // самое длинное
            if (strlen(buffer) > strlen(word)) {                // и считем сколько раз
                word = buffer;                                  // оно встретилось
                count = 1;                                      // в данно строке
            } else if (strcmp(buffer, word) == 0) count++;

            buffer = strtok(nullptr, " .,?!");              // следующая лекс.группа
        }
        free(strBuffer);                                        // освобождение памяти

        if (word != "") {                                       // вывод на экран
            printf("Самое длинное слово в строке: %s\n", word);
            printf("Оно встретилось в тексте %d раз\n", count);
        } else {
            printf("В строке нет слов\n");
        }
    } else {
        printf("Сначала создайте строку\n");
    }
}

void printString(char **str) {                      //  Вывод строки
    if (strlen(*str) != 0) {
        printf("%s\n", *str);
    } else printf("Сначала создайте строку\n");
}

bool parseInt(char *str, int *num) {                // считыване числа
    return (sscanf(str, "%d", num)) == 1;
}

int main() {
    // Для работы с русским языком
    SetConsoleCP(1251); SetConsoleOutputCP(1251);


    // Объявление переменных
    char *str = new char[1];
    int num = 0, a, b;

    while (true) {
        printf("1. Ввести строку\n2. Обработать строку\n3. Вывести строку\n4. Выход\n"); // меню

        while (!parseInt(readLine(), &num)) {
            printf("Это не число, попробуйте снова\n");
        }

        switch (num) {
            // Ввод строки
            case 1:
                printf("Введите строку:\n");
                str = readLine();
                break;

                // Обработка строки
            case 2:
                handleString(&str);
                break;

                // Вывод строки
            case 3:
                printString(&str);
                break;

                // Выход
            case 4:
                printf("Спасибо!");
                return 0;

            default:
                printf("Такого пункта меню нет!\n");
        }
    }
}
