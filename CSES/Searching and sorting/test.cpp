#include <iostream>
using namespace std;

struct person
{
    string name;
    int age;
};

int main()
{
    person a = {"Shivam", 19}, b;
    cout << "a " << a.name << " " << a.age << endl;
    cout << "b " << b.name << " " << b.age << endl;
    return 0;
}