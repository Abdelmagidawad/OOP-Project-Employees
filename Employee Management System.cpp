#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

/////////Employee Management System
/////// implementation OOP(concepts) in C++

class Employee
{
protected: 
    string name; 
    int em_id;  
    float salary;

public:
    Employee():name("Unknown"),em_id(0),salary(0)
    {
        cout << "Welcome to the company" << endl;
    }
    Employee(string name,int em_id,float salary )
    {  
        this->name = name; 
        this->em_id = em_id; 
        this->salary = salary;
    }

    void display(){
        cout << " Name= " << name <<endl<< " Emp_id= " << em_id <<endl<< " Salary= " << salary << endl;
    }

    //pur virtual function(abustruct)
   virtual float get_totalsalary() = 0;

   //virtual function(polymorphism)
    virtual void time_start() {
        cout << " The time of depart employee start " << endl;
    }
    //constant function
    void Admin() const {
        cout << name << " Admin in this system " << endl;
    }
  
    friend class sales;
    
};


class sales :public Employee
{

protected:
    float gross_sales;
    float commission_rate;

public:
    
    sales(string n, int id, float s, float g, float cr) :Employee(n, id, s)
    {
        gross_sales = g;
        commission_rate = cr;
    }

    void set_gross_sales(float g) {
        gross_sales = g;
    }
    void set_commission_rate(float cr) {
        commission_rate = cr;
    }

    //pur virtual function
    float get_totalsalary() {

        return salary + (gross_sales * commission_rate);
    }

    //virtual function
    void time_start() {
        cout << " time this department(Sales) belong to Employee "<<name<<" start\" 9:00 PM\" " << endl;
    }

    void display(){
        Employee::display();
        cout << " Gross Sales= " << gross_sales <<endl<< " Commition Rate= " << commission_rate << endl;
    }

    // friend function
    friend void emp_attn(sales e);

};


void emp_attn(sales e) {
    cout << "               Hello" << endl<<endl;
    cout << "Employee Sales Name " << e.name << endl;
    cout << "   The Informtion Employee Name= " << e.name << " and ID= " << e.em_id << endl;
}


class engineer :public Employee
{

    string speciality;
    int experience;
    int overtime_hs;  //over time hours
    int overtime_h_r;  //over time hours rate

public:
    engineer(string name, int em_id, float salary, string speciality, int experience, int overtime_hs, int overtime_h_r) :
        Employee(name, em_id, salary) {

        this->speciality = speciality;
        this->experience = experience;
        this->overtime_hs = overtime_hs;
        this->overtime_h_r = overtime_h_r;
    }

    void set_experience(int ex) {
        experience = ex;
    }
    int get_experience() {
        return experience;
    }

    //pur virtual function
    float get_totalsalary() {

        return salary + (overtime_hs * overtime_h_r);
    }

    //virtual function
    void time_start() {
        cout << " Time this depart(Engineer) belong to Employee "<<name<<" start \" 10:30 AM\"" << endl;
    }

    void display() {
        Employee::display();
        cout<<" Speciality= "<< speciality <<endl<<" Experince= "<< experience <<endl<<" Over Time hours= "<< overtime_hs<<
            endl<<" Over Time hour Rate= "<<overtime_h_r<<endl;

    }

    //friend function
    friend void emp_attn(engineer e);
};

void emp_attn(engineer e) {
    cout << "           Hello " << endl;
    cout << " Employee Engineer Name= " << e.name << endl;
    cout << "   The Informtion Employee Name= " << e.name << " and ID= " << e.em_id << endl;
}

int main()
{
    Employee* emp_ptr;

    sales emp1("Migo", 120, 5000, 1500, 80);
    emp_attn(emp1);
    emp1.display();
    cout << " Totale Salary= "<<emp1.get_totalsalary()<< endl;

    emp_ptr = &emp1;
    emp_ptr->time_start();
    // constant object
     const sales emp("Mr Abdelmagid",1,8000,0,0);
     emp.Admin();


    cout << endl << "     ********************" << endl;
    
    engineer eng1("Ahmed", 250, 8000, "Software enginering", 23, 2, 8);
    emp_attn(eng1);
    eng1.display();
    cout << " Totale slary= " << eng1.get_totalsalary() << endl;

    emp_ptr = &eng1;
    emp_ptr->time_start();
    //constsnt object
    const engineer eng("Mr Mohamed ", 1, 9000, "Admin", 25, 0, 0);
    eng.Admin();


    return 0;
}
