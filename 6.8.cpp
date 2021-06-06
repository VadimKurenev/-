#include <iostream>
#include <string>
using namespace std;
struct type_1;
struct type_2;
struct type_1 {
    type_2* leftHead;
    type_2* rightHead;
    string text;
};
struct type_2 {
    type_2* ptrNext;
    type_1* ptrNextNode;
    string text;
};
struct nodes {
    type_1* head;
    type_1* obj;
    int count = 0;
    void  addFoo();
    void  printFoo();
    nodes() : head(nullptr), obj(nullptr) {}
};

int amount();

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите количество ячеек(в одной ячейке - 5 ступеней): ";
    int numOfSteps = amount();

    nodes* catalog = new nodes();

    for (int i = 0; i < numOfSteps; i++) {
        cout << "\nВведите первые пять ступеней в " << i + 1 << " ячейке: " << endl;
        catalog->addFoo();
    }

    catalog->printFoo();
}
void nodes::addFoo() {
    if (head == nullptr) {
        head = new type_1();
        cin >> head->text;
        head->leftHead = new type_2;
        cin >> head->leftHead->text;
        head->rightHead = new type_2;
        cin >> head->rightHead->text;
        head->leftHead->ptrNext = new type_2;
        cin >> head->leftHead->ptrNext->text;
        head->rightHead->ptrNext = new type_2;
        cin >> head->rightHead->ptrNext->text;
        head->leftHead->ptrNext->ptrNextNode = new type_1;
        head->rightHead->ptrNext->ptrNextNode = head->leftHead->ptrNext->ptrNextNode = nullptr;
        count++;

    }
    else {
        if (count == 1) {
            obj = head;
        }

        if (obj->leftHead->ptrNext->ptrNextNode == nullptr) {
            obj->leftHead->ptrNext->ptrNextNode = new type_1();
        }

        obj = obj->leftHead->ptrNext->ptrNextNode;
        cin >> obj->text;
        obj->leftHead = new type_2;
        cin >> obj->leftHead->text;
        obj->rightHead = new type_2;
        cin >> obj->rightHead->text;
        obj->leftHead->ptrNext = new type_2;
        cin >> obj->leftHead->ptrNext->text;
        obj->rightHead->ptrNext = new type_2;
        cin >> obj->rightHead->ptrNext->text;
        obj->leftHead->ptrNext->ptrNextNode = new type_1;
        obj->rightHead->ptrNext->ptrNextNode = obj->leftHead->ptrNext->ptrNextNode = nullptr;
        count++;
    }
}

void nodes::printFoo() {
    type_1* current = head;
    while (current != nullptr) {
        cout << current->text << endl;
        cout << current->leftHead->text << endl;
        cout << current->rightHead->text << endl;
        cout << current->leftHead->ptrNext->text << endl;
        cout << current->rightHead->ptrNext->text << endl;
        cout << endl;
        current = current->leftHead->ptrNext->ptrNextNode;
    }
}
int amount() {
    while (true) {
        int num;
        cin >> num;

        if (cin.fail() || num <= 0) {
            cout << "Ошибка: введено недопустимое значение.\nПовторите ввод: ";
            cin.clear();
            cin.ignore(3333, '\n');
        }
        else {
            cin.ignore(3333, '\n');
            return num;
        }
    }
}