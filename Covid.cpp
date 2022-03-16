#include <iostream>
#include <string>
using namespace std;

enum vacc_status {none, first, second, healed};

struct employees {
	string name;
	int date;
    vacc_status status = none;
    employees *pNext;
};

class List
{
    employees* Head;
public:
    List()
    {
        Head = nullptr;
    }
    ~List();
    void Add_Name(string name);
    void print_lst();
    bool add_employee(istream &in);
};

List::~List()
{
    while (Head != nullptr)
    {
        employees* temp = Head->pNext;
        delete Head;
        Head = temp;
    }
}

void List::Add_Name(string name)
{
    employees* temp = new employees;
    temp->name = name;
    temp->pNext = Head;
    Head = temp;
}

bool List::add_employee(istream& in) {
    string name;
    if (!(in >> name)) return false;
    this->Add_Name(name);
    string status;
    in >> status;
    if (status == "none") {
        Head->status = none;
    } else if (status == "first") {
        Head->status = first;
    } else if (status == "second") {
        Head->status = second;
    } else if (status == "healed") {
        Head->status = healed;
    }
    in >> Head->date;
    return true;
}

void List::print_lst()
{
    employees* temp = Head;
    while (temp != nullptr)
    {
        cout << temp->name << " ";
        cout << temp->status << " ";
        cout << temp->date << " \n";
        temp = temp->pNext;
    }
}

int main() {
    List lst;
    string name;

    while (lst.add_employee(cin));
    lst.print_lst();

}
