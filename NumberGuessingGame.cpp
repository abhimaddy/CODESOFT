#include<iostream>
#include<ctime>
using namespace std;
int main(){
    cout<< "Welcome to !! NUMBER GUESSING GAME !!" <<endl;
    int userNumber = 0;
    srand(time(0));
    int myNumber = rand() % 101;
    do
    { 
         cout<< "Enter your number (1 to 100) "<<endl;
    cin>> userNumber ;
    if (userNumber==myNumber)
    {
        cout<< " WOOHOO!!! YOU WON  "<<endl;
        break;
    } else if (userNumber<myNumber)
    {
        cout<< "Your number is to small"<< endl;
    } else {
        cout<< " Your number is too large"<<endl;
    }
    } while (userNumber>=0);
    cout<< "My number was " << myNumber;
    return 0;
}