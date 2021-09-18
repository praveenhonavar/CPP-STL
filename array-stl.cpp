#include<iostream>
#include<array>

using namespace std;

int main(){

    array<int,5> myArray = {10,20,30,40};

    cout<<myArray.at(3);
    cout<<endl;
    cout<<myArray.front();
    cout<<endl;
    cout<<myArray.back();
    cout<<endl;
    cout<<myArray.size();
    cout<<endl;
    for(int i=0;i<myArray.size();i++){

        cout<<myArray[i]<<endl;

    }

    return 0;



}
