/*
  Heriberto Prieto
  Assignment 9
  Chapter 14.1-4
  14.1,14.2 and 3 other problems
*/

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
void problem6();
void problem7();


int main(int argv,char *argc[])
{
int inN;
    do{
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
void Menu()
{
       cout<<"Type 1 for problem 1"<<endl;
       cout<<"Type 2 for problem 2"<<endl;
       cout<<"Type 3 for problem 3"<<endl;
       cout<<"Type 4 for problem 4"<<endl;
       cout<<"Type 5 for problem 5"<<endl;
       cout<<"Type 6 to exit \n"<<endl;
}
int getN()
{
       int inN;
       cin>>inN;
       return inN;
}
/*
  14.1 Numbers Class
    - Design a class Numbers that can be used to translate whole 
      dollar amounts in the range 0 through 9999 into an English 
      description of the number. For example, the number 713 would 
      be translated into the string seven hundred thirteen, and 8203 
      would be translated into eight thousand two hundred three. The 
      class should have a single integer member variable:

      int number;

    - and a static array of string objects that specify how to translate 
      key dollar amounts into the desired format. For example, you might 
      use static strings such as

      string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"}; 
      string hundred = "hundred";
      string thousand = "thousand";

    - The class should have a constructor that accepts a nonnegative 
      integer and uses it to initialize the Numbers object. It should 
      have a member function print() that prints the English description 
      of the Numbers object. Demonstrate the class by writing a main 
      program that asks the user to enter a number in the proper range 
      and then prints out its English description.
*/
class Numbers {
private:
  int number;
  string hundred  = "hundred";
  string thousand = "thousand";
  string lessThan20[20] = { "zero",    "one",       "two",      "three", 
                            "four",    "five",      "six",      "seven", 
                            "eight",   "nine",      "ten",      "eleven", 
                            "twelve",  "thirteen",  "fourteen", "fifteen", 
                            "sixteen", "seventeen", "eighteen", "nineteen" };
public:
  //Class Constructor
  Numbers(int);
  //Prints English description of number
  void print();
  //Prints Tens
  string tens(int);
};

/* Class Constructor: Sets value of number */
Numbers::Numbers(int number) {
  if (number < 0)
    this->number = -1 * number;
  else
    this->number = number;
}

/* Prints the English Description of Number */
void Numbers::print() {
  int ones,tens,hundreds,thousands;
  if (this->number < 20) cout<<lessThan20[this->number]<<endl;
  else if (this->number < 100 && this->number > 20) {
    tens = this->number / 10;
    ones = this->number % 10;
    (ones > 0) ? cout<<this->tens(tens)<<" "<<lessThan20[ones]<<endl : cout<<this->tens(tens);
  } else if (this->number > 99 && this->number < 1000) {
    hundreds  =  (this->number % 1000) / 100;
    tens      = ((this->number % 1000) % 100) / 10;
    ones      =   this->number % 10;
    (tens < 2) ?
    cout<<lessThan20[hundreds]<<" hundred "<<this->tens(tens)<<" "<<lessThan20[ones]<<endl :
    cout<<lessThan20[hundreds]<<" hundred "<<lessThan20[ones]<<endl;
  } else {
    thousands =   this->number / 1000;
    hundreds  =  (this->number % 1000) / 100;
    tens      = ((this->number % 1000) % 100) / 10;
    ones      =   this->number % 10;
    if (hundreds > 0) {
      (tens < 0) ? cout<<lessThan20[thousands]<<" thousand "<<lessThan20[hundreds]<<" hundred "
                 <<this->tens(tens)<<" "<<lessThan20[ones]<<endl:
                 cout<<lessThan20[thousands]<<lessThan20[hundreds]<<" hundred "<<lessThan20[ones]<<endl;
    } else {
      (tens < 0) ? cout<<lessThan20[thousands]<<" thousand "
                 <<this->tens(tens)<<" "<<lessThan20[ones]<<endl:
                 cout<<lessThan20[thousands]<<lessThan20[ones]<<endl;
    }
  }
}

/* Returns English Description of Tens Place */
string Numbers::tens(int tens) {
  switch (tens) {
    case 2:
      return "twenty";
      break;
    case 3:
      return "thirty";
      break;
    case 4:
      return "forty";
      break;
    case 5:
      return "fifty";
      break;
    case 6:
      return "sixty";
      break;
    case 7:
      return "seventy";
      break;
    case 8:
      return "eighty";
      break;
    case 9:
      return "ninety";
      break;
  }
}

void problem1() {
  cout<<"In problem # 1"<<endl<<endl;
  int value;
  cout<<"Enter a number and get the english description:"<<endl;
  cin>>value;
  Numbers number = Numbers(value);
  number.print();
}

/*
  14.2 Day of the Year
    - Assuming that a year has 365 days, write a class named DayOfYear that takes an 
      integer representing a day of the year and translates it to a string consisting 
      of the month followed by day of the month. For example,

      Day 2 would be January 2
      Day 32 would be February 1
      Day 365 would be December 31

    - The constructor for the class should take as parameter an integer representing 
      the day of the year, and the class should have a member function print() that prints 
      the day in the month–day format. The class should have an integer member variable to 
      represent the day and should have static member variables holding string objects that 
      can be used to assist in the translation from the integer format to the month-day format.

    - Test your class by inputting various integers representing days and printing out their 
      representation in the month–day format.
*/
void problem2() {
  cout<<"In problem # 2"<<endl<<endl; 
}

/*
  
*/
void problem3()
{
       cout<<"In problem # 3"<<endl<<endl;
}
void problem4()
{
       cout<<"In problem # 4"<<endl<<endl;
}
void problem5()
{
       cout<<"In problem # 5"<<endl<<endl;
}
void def(int inN)
{
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}