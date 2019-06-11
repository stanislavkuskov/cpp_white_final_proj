#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <exception>
// Реализуйте функции и методы классов и при необходимости добавьте свои
using namespace std;
class Date {
public:
    Date(){
        d = 0;
        m = 0;
        y = 0;
    }
    int GetYear() const{
        return y;
    };
    int GetMonth() const{
        return m;
    };
    int GetDay() const{
        return d;
    };

private:
    int d;
    int m;
    int y; // может быть отрицательным
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        // событие не дублируется т. к. set хранит тоько уникальные значения
        if (!event.empty())
        {
            records[date].insert(event);
        }
    };

    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

//    /* ??? */ Find(const Date& date) const; // лпределить тип данных

    void Print() const;

private:
    map<Date, set<string>> records;
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        if(command.empty()) continue;

        stringstream input(command);
        string operation;
        input >> operation;
        if (operation == "Add"){

            cout << "oper: " << operation;
        } else if (operation == "Del"){
            cout << "oper: " << operation;
        } else if (operation == "Find"){
            cout << "oper: " << operation;
        } else if (operation == "Print"){
            cout << "oper: " << operation;
        }

        // Считайте команды с потока ввода и обработайте каждую
    }

    return 0;
}