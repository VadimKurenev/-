#include <iostream>
#include <string>

using namespace std;
string addition(string text);

int main()
{
    setlocale(LC_ALL, "Ru");
    cout << "Введите английское предложение, которое будет раскодированно по принципу 'дополнения' " << endl;
    string word;
    getline(cin, word);
    word = addition(word);
    cout << " Программа раскодировала ваше предложение: " << word << endl;
}
string addition(string say)
{
    char character;
    for (int i = 0, size = say.length(); size > i; ++i)
    {
        character = say[i];
        if (character >= 'A' && character <= 'Z')
            say[i] = 'Z' - (say[i] - 'A');
        else if (character >= 'a' && character <= 'z')
            say[i] = 'z' - (say[i] - 'a');
        else continue;
        // (character >= 'A' && character <= 'Z') ? (say[i] = 'Z' - (say[i] - 'A')) : ((character >= 'a' && character <= 'z') ? (say[i] = 'z' - (say[i] - 'a')) : continue);
    }
    return say;
}