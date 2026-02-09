#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person {
    public:
        string name;
        int age;
        
        virtual void getdata(){
            cin >> name >> age;
        }
        virtual void putdata(){
            cout << name << age << endl;
        }
};

class Professor:public Person {
    string publications;
    static int next_id;
    const int id;
    public:
        void getdata() override {
            cin >> name >> age >> publications;
        }
        void putdata() override {
            cout << name << " " << age << " " << publications << " " << id << endl;
        }
        
        //constructor
        Professor(): id(next_id++){}

};

class Student:public Person {
    vector<int> marks;
    static int next_id;
    const int id;
    public:
        void getdata() override {
            string mark="";
            cin >> name >> age;
            for (int i=0;i<6;i++) {
                cin >> mark;
                marks.push_back(stoi(mark));
            }
        }
        void putdata() override {
            int sum = 0;
            for (auto i: marks){
                sum += i;
            }
            cout << name << " " << age << " " << sum << " " << id << endl;;
        }
        //constructor
        Student(): id(next_id++){}
};

int Professor::next_id=1;
int Student::next_id=1;

int main(){
