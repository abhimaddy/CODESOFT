#include<iostream>
#include<ctime>
using namespace std;
int main(){
    cout<< "\nWelcome to NUMBER GUESSING GAME !!\n" <<endl;
    int userNumber = 0;
    srand(time(0));
    int myNumber = rand() % 101;
    cout<< "Enter your number between 0 to 100 " <<endl;
    cout<< " Enter negative number to quit\n " <<endl;
    do
    { 
         cout<< "Enter your number: ";
    cin>> userNumber ;
    if (userNumber==myNumber)
    {
        cout<< " WOOHOO!!! YOU WON  "<<endl;
        break;
    } else if (userNumber<myNumber)
    {
        cout<< "Your number is to small"<< endl;
    } else {
        cout<< "Your number is too large"<<endl;
    }
    } while (userNumber>=0);
    cout<< "My number was " << myNumber;
    return 0;
}