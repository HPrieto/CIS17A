/*
  Heriberto Prieto
  Assignment 8
  Chapter 12
  12.7,12.8, 12.11 and 2 other problems
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
  12.7 Sentence Filter
    - Write a program that asks the user for two file names. 
      The first file will be opened for input and the second file 
      will be opened for output. (It will be assumed that the first 
      file contains sentences that end with a period.) The program will 
      read the contents of the first file and change all the letters to 
      lowercase except the first letter of each sentence, which should 
      be made uppercase. The revised contents should be stored in the 
      second file.
*/
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;
}

/*
  12.8 Array/File Functions
    - Write a function named arrayToFile. The function should accept three 
      arguments: the name of a file, a pointer to an int array, and the size 
      of the array. The function should open the specified file in binary mode, 
      write the contents of the array to the file, and then close the file.

    - Write another function named fileToArray. This function should accept three 
      arguments: the name of a file, a pointer to an int array, and the size of 
      the array. The function should open the specified file in binary mode, read 
      its contents into the array, and then close the file.

    - Write a complete program that demonstrates these functions by using the 
      arrayToFile function to write an array to a file, and then using the fileToArray 
      function to read the data from the same file. After the data are read from the 
      file into the array, display the array’s contents on the screen.
*/
void problem2() {
  cout<<"In problem # 2"<<endl<<endl; 
}

/*
  12.11 Coporate Sales Data Output
    - Write a program that uses a structure to store the following data
      on a company division:
        - Division Name(East, West, North , South)
        - Quarter ( 1,2,3, or 4)
        - Quarterly Sales
    - The user should be asked for the four quarters’ sales figures for the 
      East, West, North, and South divisions. The data for each quarter for 
      each division should be written to a file.

      Input Validation: Do not accept negative numbers for any sales figures
*/
void problem3() {
       cout<<"In problem # 3"<<endl<<endl;
}

/*
  12.1 File Head Program
    - Write a program that asks the user for the name of a file. The program 
      should display the first 10 lines of the file on the screen (the “head” 
      of the file). If the file has fewer than 10 lines, the entire file should 
      be displayed, with a message indicating the entire file has been displayed.
*/
void problem4() {
       cout<<"In problem # 4"<<endl<<endl;
}

/*
  11.2 File Display Program
    - Write a program that asks the user for the name of a file. The program 
      should display the contents of the file on the screen. If the file’s contents 
      won’t fit on a single screen, the pro- gram should display 24 lines of output 
      at a time, and then pause. Each time the program pauses, it should wait for 
      the user to strike a key before the next 24 lines are displayed.
*/
void problem5() {
       cout<<"In problem # 5"<<endl<<endl;
}
void def(int inN)
{
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}