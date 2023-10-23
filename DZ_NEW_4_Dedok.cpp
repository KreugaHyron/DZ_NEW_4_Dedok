#include <iostream>
using namespace std;
//для задания 1
const int MAX_ROWS = 3; 
const int MAX_COLS = 3;
//для задания 2
const int MAX_ENTRIES = 10;
const int MAX_NAME_LENGTH = 50;
const int MAX_PHONE_LENGTH = 15;
//функция к заданию 1
void transposeMatrix(int original[MAX_ROWS][MAX_COLS], int transposed[MAX_COLS][MAX_ROWS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            transposed[j][i] = original[i][j];
        }
    }
}
//функции к заданию 2
void addEntry(char*** phonebook, int& size, char* name, char* phone) {
    if (size < MAX_ENTRIES) {
        (*phonebook)[size] = name;
        (*phonebook)[size + 1] = phone;
        size += 2;
        cout << "Запись добавлена." << "\n";
    }
    else {
        cout << "Телефонная книга полна. Невозможно добавить новую запись." << "\n";
    }
}
void findEntry(char** phonebook, int size, const char* query) {
    bool found = false;
    for (int i = 0; i < size; i += 2) {
        if (strcmp(phonebook[i], query) == 0 || strcmp(phonebook[i + 1], query) == 0) {
            cout << "Найдено: " << phonebook[i] << " - " << phonebook[i + 1] << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено." << "\n";
    }
}
void deletePhonebook(char** phonebook, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] phonebook[i];
    }
    delete[] phonebook;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    //Task_1
    int originalMatrix[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposedMatrix[MAX_COLS][MAX_ROWS];
    transposeMatrix(originalMatrix, transposedMatrix);
    for (int i = 0; i < MAX_COLS; ++i) {
        for (int j = 0; j < MAX_ROWS; ++j) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    //Task_2
    char** phonebook = new char* [MAX_ENTRIES * 2];
    int size = 0;
    addEntry(&phonebook, size, new char[MAX_NAME_LENGTH] {'A', 'l', 'i', 'c', 'e', '\0'},
    new char[MAX_PHONE_LENGTH] {'1', '2', '3', '-', '4', '5', '6', '7', '\0'});
    addEntry(&phonebook, size, new char[MAX_NAME_LENGTH] {'B', 'o', 'b', '\0'},
    new char[MAX_PHONE_LENGTH] {'8', '9', '0', '-', '1', '2', '3', '4', '\0'});
    findEntry(phonebook, size, "Alice");
    deletePhonebook(phonebook, size);
    return 0;
}

