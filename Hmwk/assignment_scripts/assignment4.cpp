/*
  Heriberto Prieto
  Assignment 4
  Chapter 10
  10.4, 10.6 and 3 other problems
*/

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();


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
    } while (inN<6);
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

/*
  10.3 Word Counter
    - Write a function that accepts a pointer to a C-string as an 
      argument and returns the number of words contained in the string. 
      For instance, if the string argument is “Four score and seven 
      years ago” the function should return the number 6. Demonstrate 
      the function in a program that asks the user to input a string and 
      then passes it to the func- tion. The number of words in the string 
      should be displayed on the screen. Optional Exercise: Write an 
      overloaded version of this function that accepts a string class 
      object as its argument.

  10.4 Average Number of Letters
    - Modify the program you wrote for Problem 3 (Word Counter), 
      so it also displays the average number of letters in each word.
*/
int nwords(char *,int);
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;
}

int nwords(char *c,int n) {
  int w = 1;
  for (int i = 0; i < n; i++)
    if (c[i] == ' ' && c[i + 1] != ' ') w++;
  return w;
}

/*
  10.6 Vowels and Consonants
    - Write a function that accepts a pointer to a C-string as its 
      argument. The function should count the number of vowels appearing 
      in the string and return that number.

    - Write another function that accepts a pointer to a C-string as its 
      argument. This func- tion should count the number of consonants 
      appearing in the string and return that number.

    - Demonstrate these two functions in a program that performs the following steps:
        * The user is asked to enter a string
        * The program displays the following menu:
            a.) Count the number of vowels in the string
            b.) Count the number of consonants in the string
            c.) Count both the vowels and consonants in the string
            d.) Enter another string
            e.) Exit the program

    - The program performs the operation selected by the user and 
      repeats until the user selects E to exit the program.
*/

string createS();
short nVowels(string);
short nCnsnts(string);
bool isVowel(char);
bool isCnsnt(char);

void problem2() {
  cout<<"In problem # 2"<<endl<<endl;

  //Declare problem variables
  string s = createS();
  short  v = nVowels(s);
  short  c = nCnsnts(s);

  // Output to user
  cout<<"Sentence:   "<<s<<endl;
  cout<<"Vowels:     "<<v<<endl;
  cout<<"Consonants: "<<c<<endl;
}

/* Reads in and returns line entered by user */
string createS() {
  string s;
  cout<<"Enter a sentence to find the number of vowels and consonants:"<<endl;
  cin.ignore();
  getline(cin, s);
  return s;
}

/* Returns number of vowels in string */
short nVowels(string s) {
  short vowels = 0;
  for (int i = 0; i < s.size(); i++)
    if (isVowel(s.at(i)) == true)
      vowels++;
  return vowels;
}

/* Returns number of consonants in string */
short nCnsnts(string s) {
  short cnsnts = 0;
  for (int i = 0; i < s.size(); i++)
    if (isCnsnt(s.at(i)) == true)
      cnsnts++;
  return cnsnts;
}

/* Returns True if character is a vowel */
bool isVowel(char c) {
  char vowels[] = "aeiou";
  for (int i = 0; i < sizeof(vowels); i++)
    if (vowels[i] == tolower(c))
      return true;
  return false;
}

/* Returns True if character is a consonant */
bool isCnsnt(char c) {
  char cnsnts[] = "bcdfghjklmnpqrstvwxyz";
  for (int i = 0; i < sizeof(cnsnts); i++)
    if (cnsnts[i] == tolower(c))
      return true;
  return false;
}

/*
  10.7 Name Arranger
    - Write a program that asks for the user’s first, middle, and 
      last names. The names should be stored in three different 
      character arrays. The program should then store, in a fourth 
      array, the name arranged in the following manner: the last name 
      followed by a comma and a space, followed by the first name and 
      a space, followed by the middle name. For example, if the user 
      entered “Carol Lynn Smith”, it should store “Smith, Carol Lynn” 
      in the fourth array. Display the contents of the fourth array on 
      the screen.
*/

char getFirst();
string getMiddle();
string getLast();

void problem3() {
    cout<<"In problem # 3"<<endl<<endl;

    // Declare variables
    char *firstN = getFirst();

    //Output to user
    cout<<"First Name: "<<firstN<<endl;
}

char getFirst() {
  string s;
  cin.ignore();
  getline(cin, s);
  return static_cast<char>(s);
}

/*
  10.8 Sum of Digits in a String
    - Write a program that asks the user to enter a series of single 
      digit numbers with nothing separating them. Read the input as a 
      C-string or a string object. The program should display the sum of 
      all the single-digit numbers in the string. For example, if the 
      user enters 2514, the program should display 12, which is the sum 
      of 2, 5, 1, and 4. The program should also display the highest and 
      lowest digits in the string.
*/
void problem4() {
       cout<<"In problem # 4"<<endl<<endl;
}

/*
  10.9 The Most Frequent Character
    - Write a function that accepts either a pointer to a C-string, 
      or a string object, as its argument. The function should return 
      the character that appears most frequently in the string. Demonstrate 
      the function in a complete program.
*/
void problem5() {
       cout<<"In problem # 5"<<endl<<endl;
}
void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}