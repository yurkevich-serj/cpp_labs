#include <iostream>
#include <cstring>
#include <clocale>
#include <cstdio>
using namespace std;

class Book {
    char Autor[40];
    char Title[40];
    char Publish[40];
    int Year;
    int Sheet_num;
public:
    Book(const char* a, const char* b, const char* c, int i, int n) {
        strcpy_s(Autor, a);
        strcpy_s(Title, b);
        strcpy_s(Publish, c);
        Year = i;
        Sheet_num = n;
    }

    char* get_aut() { return Autor; }
    char* get_tit() { return Title; }
    char* get_pub() { return Publish; }
    int get_year() { return Year; }
    int get_num() { return Sheet_num; }

    void set_aut(char* aut) { strcpy_s(Autor, aut); }
    void set_tit(char* tit) { strcpy_s(Title, tit); }
    void set_pub(char* pub) { strcpy_s(Publish, pub); }
    void set_year(int y) { Year = y; }
    void set_num(int num) { Sheet_num = num; }

    void show() {
        cout << "Autor: " << Autor << '\t';
        cout << "Book title: " << Title << '\t';
        cout << "Publish: " << '\"' << Publish << '\"' << '\t';
        cout << "Year: " << Year << '\t';
        cout << "Title: " << Sheet_num << "\n\n";
    }

};

void SeekOnAutor(const char* str, Book* ob) {
    cout << "Author books " << str << ": " << "\n";
    for (int i = 0; i < 6; i++) {

        if (!strcmp((ob[i].get_aut()), str)) ob[i].show();
    }
    cout << '\n';
}

void SeekOnPublish(const char* str, Book* ob) {
    cout << "Publish books " << str << ": " << "\n";
    for (int i = 0; i < 6; i++) {

        if (!strcmp((ob[i].get_pub()), str)) ob[i].show();
    }
    cout << '\n';
}

void SeekOnYear(int h, Book* ob) {
    cout << "Books after " << h << ": " << "\n";
    for (int i = 0; i < 6; i++) {

        if (ob[i].get_year() >= h) ob[i].show();
    }
    cout << '\n';
}

int main()

{
    setlocale(LC_ALL, "Russian");
    Book ob[] = {
        Book("Vern","Under the water","Extremo",1995,125),
        Book("Dostoevskiy", "War", "Extremo", 2000, 350),
        Book("Dostoevskiy", "White Night", "Piter",  1998, 200),
        Book("Shekspir","Hamlet",  "Extremo", 1999, 100),
        Book("Shekspir", "King Lir", "Piter", 1996, 150),
        Book("Vern", "Around the world in 80 days","Piter", 1997, 150)
    };

    char choice, str[40];
    int h;

    for (;;) {
        do {
            cout << "Choose:\n"
                << " 1. List by author\n"
                << " 2. List by publish name\n"
                << " 3. Publish year\n"
                << "Any (q for exit): ";
            cin >> choice;
        } while (choice < '1' || choice>'3' && choice != 'q');
        if (choice == 'q') break;
        cout << "\n\n";
        switch (choice) {
        case '1':
            cout << "Enter author name: ";
            cin >> str;
            SeekOnAutor(str, ob);
            break;
        case '2':
            cout << "Enter publish name: ";
            cin >> str;
            SeekOnPublish(str, ob);

            break;
        case '3':
            cout << "Enter year: ";
            cin >> h;
            SeekOnYear(h, ob);
            break;
        }
        cout << "\n";
    }

    return 0;
}