//Mark E. Lehr
//August 28, 2017
//Menu to be used for the midterm
//homework and midterm, etc....

#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
bool isLeapYear(int);
void daysInMonth(int,int);


int main(int argv,char *argc[]) {
int inN;
    do {
     Menu();
     inN=getN();
     switch(inN){
      case 1:    problem1();break;
      case 2:    problem2();break;
      case 3:    problem3();break;
      case 4:    problem4();break;
      case 5:    problem5();break;
      default:   def(inN);}
    }while(inN<6);
    return 1;
}
void Menu() {
   cout<<"Type 1 for problem 1"<<endl;
   cout<<"Type 2 for problem 2"<<endl;
   cout<<"Type 3 for problem 3"<<endl;
   cout<<"Type 4 for problem 4"<<endl;
   cout<<"Type 5 for problem 5"<<endl;
   cout<<"Type 6 to exit \n"<<endl;
}
int getN() {
       int inN;
       cin>>inN;
       return inN;
}
void problem1() {
  cout<<"In problem: 3.12"<<endl<<endl;

  //Declare problem variables
  int divSales = rand()%900+100;
  int whole    = divSales/100;
  int decimal  = divSales%100;

  //Output result to user
  cout<<setw(8)<<whole<<"."<<decimal<<endl;
}

/* Chapter 3.13
 * Write a cout statement so the variable totalAge is displayed in a field of 12 spaces,
 * in fixed point notation, with a precision of 4 decimal places. */
void problem2() {
  cout<<"In problem: 3.13"<<endl<<endl;

  //Declare problem variables
  int totalAge = rand()%9000+1000;
  int whole    = totalAge/10000;
  int decimal  = totalAge%10000;

  //Output result to user
  cout<<setw(12)<<whole<<"."<<decimal<<endl;  
}

/* Chapter 4.10
 * Days in a Month
 * Write a program that asks the user to enter the month (letting the user enter an
 * integer in the range of 1 through 12) and the year. The program should then display the
 * number of days in that month. Use the following criteria to identify leap years:
 * 
 * 1.) Determine whether the year is divisble by 100. If it is, then it is a leap year if
 *     and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
 * 2.) If the year is not divisble by 100, then it is a leap year if and only if it is divisble by
 *     4. For example, 2008 is a leap year but 2009 is not.
 *  */
void problem3() {
  cout<<"In problem 4.10"<<endl<<endl;
  //Declare problem variables
  int month;
  int year;

  //User output/input
  cout<<"Enter any month:"<<endl;
  cin>>month;
  cout<<"Enter any year:"<<endl;
  cin>>year;
  daysInMonth(month,year);
}

bool isLeapYear(int year) {
    if(year%100==0)
        if(year%400==0) return true;
        else return false;
    else if(year%4==0) return true;
    return false;
}

void daysInMonth(int month,int year) {
  switch(month) {
    case 1:
        cout<<"January has 31 Days!"<<endl;
        break;
    case 2:
        if(isLeapYear(year))
            cout<<year<<" is a leap year! On this year February has 29 days!"<<endl;
        else
            cout<<year<<" is not a leap year! On this year February has 28 days!"<<endl;
        break;
    case 3:
        cout<<"March has 31 days!"<<endl;
        break;
    case 4:
        cout<<"April has 30 days!"<<endl;
        break;
    case 5:
        cout<<"May has 31 days!"<<endl;
        break;
    case 6:
        cout<<"June has 30 days!"<<endl;
        break;
    case 7:
        cout<<"July has 31 days!"<<endl;
        break;
    case 8:
        cout<<"August has 31 days!"<<endl;
        break;
    case 9:
        cout<<"September has 30 days!"<<endl;
        break;
    case 10:
        cout<<"October has 31 days!"<<endl;
        break;
    case 11:
        cout<<"November has 30 days!"<<endl;
        break;
    case 12:
        cout<<"December has 31 days!"<<endl;
        break;
    default:
        cout<<"Invalid Entry."<<endl<<endl;
        break; 
  }
  cout<<endl;
}

/*
  4.12 Assignment
  A software company sells a package that retails for $99.
  Quantity discounts are given according to the following table.

  Quantity        Discount
  10-19           20%
  20-49           30%
  50-99           40%
  100 or more     50%
  
  Write a program that asks for the number of units sold and computes
  the total cost of the purchase.

  Input validation: Make sure the number of units is greater than 0.
*/
void problem4() {
  cout<<"In problem: 4.12"<<endl<<endl;

  //Declare method variables
  int cost = 99;
  int units;
  float total;

  //User output/input
  cout<<"Assignment 4.12"<<endl;
  cout<<"Input the number of units you wish to purchase:"<<endl;
  cin>>units;

  //Perform problem logic
  (units <= 0) ? total = 0 : total = units * cost; 
  (units >= 10 && units < 19)  ? total *= .8 :
  (units >= 20 && units < 50)  ? total *= .7 :
  (units >= 50 && units < 100) ? total *= .6 :
  units *= .5;

  //Output result to user
  cout<<"Your total cost is: $"<<total<<endl;
}

/*
  4.13 Book Club Points
  - Serendipity Booksellers has a book club that awards points to its customers
    based on the number of books purchased each month. The points are awarded
    as follows:
    * If a customer purchases 0 books, he or she earns 0 points.
    * If a customer purchases 1 book, he or she earns 5 points.
    * If a customer purchases 2 books, he or she earns 15 points.
    * If a customer purchases 3 books, he or she earns 30 points.
    * If a customer purchases 4 or more books, he or she earns 60 points.
  - Write a program that asks the user to enter the number of books that he or she
    has purchased this month and then displays the number of points awarded.
*/
void problem5() {
  cout<<"In problem # 5"<<endl<<endl;

  //Declare method variables
  int units;
  int points;

  //User output/input
  cout<<"In problem # 5"<<endl<<endl;
  cout<<"Assignment 4.13"<<endl;
  cout<<"Input the number of books you've purchased this month "<<endl;
  cout<<"and find out the number of points earned:"<<endl;
  cin>>units;

  //Perform problem logic
  (units <= 0) ? points = 0 : points = units;
  (units >= 1 && units < 2) ? points *= 5 :
  (units >= 2 && units < 3) ? points *= 15 :
  (units >= 3 && units < 4) ? points *= 30 :
  points *= 60;

  //Output result to user
  cout<<"The number of points you've earned this month: "<<points<<endl;
}

void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}