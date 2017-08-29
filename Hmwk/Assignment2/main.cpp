/*
  Heriberto Prieto
  August 28th, 2017
  Assignment 2
  Chapters 4-8
  5.11, 6.7, 7.6, 8.7 and 1 other problem
*/

#include <iomanip>
#include <iostream>
using namespace std;

void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
float celsius(int);
void problem3();
void fill(int *,int);
void prntGrt(int *,int,int);
void problem4();
void accounts(int *,int);
bool linSrch(int *,int,int);
void problem5();
void winners(int *,int);
bool jackpot(int *,int,int);

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
       cout<<"Type 6 to exit."<<endl;
}
int getN() {
  int inN;
  cin>>inN;
  return inN;
}

/*
  5.11 Population:
    - Write a program that will predict the size of a population of organisms. 
      The program should ask the user for the starting number of organisms, their average 
      daily population increase (as a percentage), and the number of days they will multiply. 
      A loop should display the size of the population for each day.

    - Input Validation: Do not accept a number less than 2 for the starting size of the population. 
      Do not accept a negative number for average daily population increase. Do not accept a number 
      less than 1 for the number of days they will multiply.
*/
void problem1() {
  //Declare problem variables
  int nOrgnsm;//Starting number of organims >= 2
  int pInc;   //Average daily population increase(percentage) > 0
  int nDays;  //Number of days they will multiply > 0
  int total;  //Total population increase
  float dInc; //Percent increase as a decimal

  //User output/input
  cout<<"In problem #1: 5.11"<<endl<<endl;
  cout<<"Get a prediction on the size of a population ";
  cout<<"of organisms!"<<endl;
  cout<<"Begin by inputing the starting number of organisms:"<<endl;
  cin>>nOrgnsm;
  cout<<"Now input the average daily population increase as a percent:"<<endl;
  cin>>pInc;
  cout<<"Finally, enter the number of days they will multiply:"<<endl;
  cin>>nDays;

  //Begin calculation
  if (nOrgnsm > 1 && pInc >= 0 && nDays > 1) {
    total = nOrgnsm; dInc  = (pInc * 0.01) + 1;
    for (int i = 0; i < nDays; i++) {
      total *= dInc;
      cout<<"Day "<<i+1<<" population size: "<<total<<endl;
    }
    cout<<"Final Cycle Population Size: "<<total<<endl;
  } else cout<<"Invalid Entry."<<endl;
}

/*
  6.7 Celsius Temperature Table:
    - The formula for converting a temperature from Fahrenheit to Celsius is:

      C = (5/9) (F - 32)

    - where F is the Fahrenheit temperature and C is the Celsius temperature. 
      Write a function named celsius that accepts a Fahrenheit temperature as 
      an argument. The function should return the temperature, converted to Celsius. 
      Demonstrate the function by calling it in a loop that displays a table of the 
      Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
*/
void problem2() {
  cout<<"In problem #2: 6.7"<<endl<<endl;
  cout<<"Ceslius Temperature Converter!"<<endl;
  cout<<"Fahrenheit | Celsius"<<endl;
  for (int f = 1; f <= 20; f++)
    (f < 10) ? cout<<setw(4)<<f<<setw(8)<<"|"<<setw(6)<<celsius(f)<<setw(5)<<" "<<endl:
               cout<<setw(5)<<f<<setw(7)<<"|"<<setw(6)<<celsius(f)<<setw(5)<<" "<<endl;
  cout<<endl;
}

float celsius(int f) {
  return (5.0f/9.0f) * (f*1.0f - 32.0f);
}

/*
  7.6 Larger Than N
    - In a program, write a function that accepts three arguments: an array, 
      the size of the array, and a number n. Assume that the array contains integers. 
      The function should display all of the numbers in the array that are greater than 
      the number n.
*/
void problem3() {
  cout<<"In problem #3: 7.6"<<endl<<endl;

  //Declare problem variables
  srand(static_cast<unsigned int>(time(0)));
  int n  = 20;
  int *a = new int[n];
  int v;

  //User output/input
  cout<<"Select a number 0 - 100 and see what numbers were greater:"<<endl;
  cin>>v;

  //Fill Array with random values
  fill(a,n);

  //Print values greater than v
  prntGrt(a,n,v);
}

void prntGrt(int *a,int n,int v) {
  for (int i = 0; i < n; i++)
    if (a[i] > v)
      cout<<a[i]<<" ";
    cout<<endl;
}

void fill(int *a,int n) {
  for (int i = 0; i < n; i++)
    a[i] = rand()%90+10;
}

/*
  8.1 Charge Account Validation
    - Write a program that lets the user enter a charge account number. 
      The program should determine if the number is valid by checking for 
      it in the following list:

      5658845 4520125 7895122 8777541 8451277 1302850 8080152 4562555 5552012 
      5050552 7825877 1250255 1005231 6545231 3852085 7576651 7881200 4581002

    - The list of numbers above should be initialized in a single-dimensional 
      array. A simple linear search should be used to locate the number entered 
      by the user. If the user enters a number that is in the array, the program 
      should display a message saying that the number is valid. If the user enters 
      a number that is not in the array, the program should display a message 
      indicating that the number is invalid.
*/
void problem4() {
  cout<<"In problem #4: 8.1"<<endl<<endl;

  //Declare problem variables
  int n  = 18;
  int *a = new int[n];
  int acc;

  //Fill array with account numbers
  accounts(a,n);

  //Output/Input to user
  cout<<"Valid charge account numbers:"<<endl;
  cout<<"5658845 4520125 7895122 8777541 8451277 1302850 8080152 4562555 5552012"<<endl; 
  cout<<"5050552 7825877 1250255 1005231 6545231 3852085 7576651 7881200 4581002\n"<<endl;
  cout<<"Enter a valid charge account number: "<<endl;
  cin>>acc;
  if (linSrch(a,n,acc))
    cout<<"This account number is valid!"<<endl;
  else
    cout<<"This account number is invalid!"<<endl;

}

/* Performs linear search */
bool linSrch(int *a,int n,int acc) {
  for (int i = 0; i < n; i++)
    if (a[i] == acc) return true;
  return false;
}

/* Fills array with customer account numbers */
void accounts(int *a,int n) {
  //Fill array with values
  a[0]  = 5658845;a[1]  = 4520125;a[2]  = 7895122;
  a[3]  = 8777541;a[4]  = 8451277;a[5]  = 1302850;
  a[6]  = 8080152;a[7]  = 4562555;a[8]  = 5552012;
  a[9]  = 5050552;a[10] = 7825877;a[11] = 1250255;
  a[12] = 1005231;a[13] = 6545231;a[14] = 3852085;
  a[15] = 7576651;a[16] = 7881200;a[17] = 4581002;
}

/*
  8.2 Lottery Winner
    - A lottery ticket buyer purchases 10 tickets a week, always playing the same 
      10 5-digit “lucky” combinations. Write a program that initializes an array 
      or a vector with these numbers and then lets the player enter this week’s 
      winning 5-digit number. The program should perform a linear search through 
      the list of the player’s numbers and report whether or not one of the tickets 
      is a winner this week. Here are the numbers:

      13579 26791 26792 33445 55555 
      62483 77777 79422 85647 93121
*/
void problem5() {
  cout<<"In problem #5: Any Other (8.2)"<<endl<<endl;

  //Declare problem variables
  int c;
  int n = 10;
  int *a = new int[n];

  //Fill array with winning numbers
  winners(a,n);

  //Output/Input to user
  cout<<"Enter your lottery ticket combination(5-digit combination):"<<endl;
  cin>>c;

  //Check for winning number
  if (jackpot(a,n,c))
    cout<<"You won the lottery!"<<endl;
  else
    cout<<"You did not win the lottery!"<<endl;

  // Free Memory
  delete [] a;
}

/* Fills array with winning numbers */
void winners(int *a,int n) {
  a[0] = 13579;a[1] = 26791;a[2] = 26792;a[3] = 33445;a[4] = 55555;
  a[5] = 62483;a[6] = 77777;a[7] = 79422;a[8] = 85647;a[9] = 93121;
}

/* Performs linear search for winning numbers */
bool jackpot(int *a,int n,int c) {
  for (int i = 0; i < n; i++)
    if (a[i] == c) return true;
  return false;
}

void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}