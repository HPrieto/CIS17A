/*
  Heriberto Prieto
  Assignment 10
  Chapter 14.5-8
  14.3,14.4 and 3 other problems
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
class Numbers {
private:
  string tens(int);
  int amount;
  string hundred = "hundred";
  string thousand = "thousand";
  string lessThan20[20] = { "zero",   "one",    "two",      "three",   "four",
                            "five",   "size",   "seven",    "eight",   "nine",
                            "ten",    "eleven", "twelve",   "thirteen","fourteen",
                            "fifteen","sixteen","seventeen","eighteen","nineteen" }
public:
  //Class Constructor
  Numbers(int);
  //Outputs String Representation
  void print();
};

/* Class Constructor */
Numbers::Numbers(int amount) {
  this->amount = amount;
}

/* Outputs string representation */
void Numbers::print() {
  (this->amount < 20) ? cout<<this->lessThan20[this->amount]:
  (this->amount > 19 && this->amount < 100) ? cout<<this->tens(this->amount/10%10)<<" "
                                                  <<this->lessThan20[this->amount%10]:
  (this->amount > 99 && this->amount < 1000) ? cout<<this->lessThan20[this->amount/100%10]
                                                  <<" "<<hundred<<" "<<this->tens(this->amount/10%10)<<" "
                                                  <<this->lessThan20[this->amount%10]
}

/* Returns string representation of tens place integer */
string Numbers::tens(int amount) {
  switch (amount) {
    case 2 :return "twenty"; break;
    case 3 :return "thirty"; break;
    case 4 :return "forty";  break;
    case 5 :return "fifty";  break;
    case 6 :return "sixty";  break;
    case 7 :return "seventy";break;
    case 8 :return "eighty"; break;
    default:return "ninety"; break;
  }
}
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;
}

void problem2() {
  cout<<"In problem # 2"<<endl<<endl; 
}
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