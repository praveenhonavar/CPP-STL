#include<iostream>
using namespace std;
class Student{
    private:
        int id;
        string name;
        int marks;

    public:
       void setStudent(int i,int m,string n){

            id= i;
            marks=m;
            name=n;
       }

};


int main(){

    pair<int,string> p1;
    pair<int,Student> p2;



    p1 = make_pair(1,"kp");

    Student s1;
    s1.setStudent(22,111,"sono");

    p2 = make_pair(2,s1);

    cout<<p2.second;


    return 0;

}


