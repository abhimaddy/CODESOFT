#include<iostream>
#include<cctype>
using namespace std;
int main(){
    //Variable declaration
int var1, var2, result;
char choice;

cout<<"\n--------!! CALCULATOR !!--------\n"<<endl;
    //Take input from user
cout<< "Enter your first number: "<<endl;
cin>>var1;
cout<< "Enter your second number: "<<endl;
cin>>var2;
    //Show options for operations
cout<< "\nHere are some Arithmetic Operations.\n"<< endl;
cout<<"A for  =>  addition"<<endl;
cout<<"S for  =>  subtraction"<<endl;
cout<<"M for  =>  multiplication"<<endl;
cout<<"D for  =>  division"<<endl;
//Take choice from user
cout<< "\nChoose your operation...."<<endl;
cin>>choice;
choice = toupper(choice);
//operations
switch (choice)
{   
case 'A':
   result = var1 + var2;
   cout<< "Addition of "<< var1 << " and "<< var2 << " is: "<< result<<endl;
    break;  

case 'S':
   result = var1 - var2;
   cout<< "Subtraction of "<< var1 << " and "<< var2 << " is: "<< result<<endl;
    break;
    
case 'M':
   result = var1 * var2;
   cout<< "Multiplication of "<< var1 << " and "<< var2 << " is: "<< result<<endl;
    break;
    
case 'D':
if (var2 == 0){
    cout<< "Error!. Division by zero is not allowed. Please enter a valid number"<<endl;
}else{
   result = var1 / var2;
   cout<< "Division of "<< var1 << " by "<< var2 << " is: "<< result<<endl;
}
    break;

default:
cout<< "Invalid choice. Please enter A, S, M, or D";
    break;
}

    return 0;
}