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

    Date (int new_y, int new_m, int new_d)
    {

        if (new_m < 1 || new_m > 12) {
            throw out_of_range("Month value is invalid: " + to_string(new_m));
        } else if (new_d < 1 || new_d > 31) {
            throw out_of_range("Day value is invalid: " + to_string(new_d));
        }
        y = new_y;
        m = new_m;
        d = new_d;
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

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else {
        return lhs.GetDay() < rhs.GetDay();
    }
};

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        // событие не дублируется т. к. set хранит тоько уникальные значения
        if (!event.empty())
        {
            records[date].insert(event);
        }
    };

    bool DeleteEvent(const Date& date, const string& event){
        bool is_deleted = false;
        if (records.count(date) > 0){
            if (records[date].count(event) > 0){
                records[date].erase(event);
                is_deleted = true;
            }
        }
        return is_deleted;
    };

//    int  DeleteDate(const Date& date);

//    /* ??? */ Find(const Date& date) const; // лпределить тип данных

//    void Print() const;

private:
    map<Date, set<string>> records;
};

Date StringToDate(const string& date_string){
    istringstream date_stream(date_string);
    bool is_right_str = true;

    int year;
    date_stream >> year;
    if (date_stream.peek() != '-'){
        is_right_str = false;
    }
    date_stream.ignore(1);

    int month;
    date_stream >> month;
    if (date_stream.peek() != '-'){
        is_right_str = false;
    }
    date_stream.ignore(1);

    int day;

    date_stream >> day;
    if (not date_stream.eof()){
        is_right_str = false;
    }

    if (!is_right_str)
    {
        throw logic_error("Wrong date format: " + date_string);
    }
    return Date(year, month, day);

}

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        if(command.empty()) continue;

        stringstream input(command);
        string operation;
        input >> operation;

        if (operation == "Add"){
            string date_string, event;
            input >> date_string >> event;

            const Date date = StringToDate(date_string);

            if (!event.empty() || event != " ") {
                db.AddEvent(date, event);
            }
        } else if (operation == "Del"){
            string date_string, event;
            input >> date_string;
            if (!input.eof()) {
                input >> event;
            }
            const Date date = StringToDate(date_string);
            if (event.empty()) {
                cout << "empty";
            } else {
                if (db.DeleteEvent(date, event)) {
                    std::cout << "Deleted successfully" << std::endl;
                } else {
                    std::cout << "Event not found" << std::endl;
                }
            }
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