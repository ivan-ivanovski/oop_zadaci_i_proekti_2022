// program Plata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


class Employee {
private:
    int age, yearsofservice, salary;
public:
    Employee(int age = 0, int yearsofservice = 0, int salary = 0) {
        this->age = age;
        this->yearsofservice = yearsofservice;
        this->salary = salary;
    }

    void set_age(int Age){
        age = Age;
    }
    int get_age() {
        return age;
    }

    void set_years(int years) {
        yearsofservice = years;
    }

    int get_years() {
        return yearsofservice;
    }

    void set_salary(int salaryindolars){
        salary = salaryindolars;
    }

    int get_salary() {
        return salary;
    }

    void get_Denars() {
        int den;
        den = salary * 56;
        cout << "Plata vo denari: "<<setprecision(1000)<<den<< " denari" << endl;
    }

    void Pecati() {
        cout << "Vozrast na rabotnikot: " << age << endl;
        cout << "Godini na sluzba: " << yearsofservice << " god. \n";
        cout << "Plata vo dolari: $" << salary << endl;
        get_Denars();
    }

};



int main()
{
    Employee E1;
    int age, yearsOfService, salary;
    cout << "We need a informations about two employers" << endl;
    cout << "E1->Age: " << endl;
    cin >> age; E1.set_age(age);
    cout << "E1->Years of service: " << endl;
    cin >> yearsOfService;
    E1.set_years(yearsOfService);
    cout << "E1->Salary: " << endl;
    cin >> salary;
    E1.set_salary(salary);

    E1.Pecati();

}











// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
