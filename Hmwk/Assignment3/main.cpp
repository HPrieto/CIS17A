/*
  Heriberto Prieto
  Assignment 3
  Chapter 9 
  9.2, 9.6, 9.7 and 7 other problems
*/

#include <iostream>
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void marksort(int *,int);
void print(int *,int);
int average(int *,int);
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

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
      case 6:    problem6();break;
      case 7:    problem7();break;
      case 8:    problem8();break;
      case 9:    problem9();break;
      case 10:   problem10();break;
      default:   def(inN);}
    }while(inN<11);
    return 1;
}
void Menu()
{
       cout<<"Type 1 for problem 1"<<endl;
       cout<<"Type 2 for problem 2"<<endl;
       cout<<"Type 3 for problem 3"<<endl;
       cout<<"Type 4 for problem 4"<<endl;
       cout<<"Type 5 for problem 5"<<endl;
       cout<<"Type 6 for problem 6"<<endl;
       cout<<"Type 7 for problem 7"<<endl;
       cout<<"Type 8 for problem 8"<<endl;
       cout<<"Type 9 for problem 9"<<endl;
       cout<<"Type 10 for problem 10"<<endl;
       cout<<"Type 11 to exit \n"<<endl;
}
int getN()
{
       int inN;
       cin>>inN;
       return inN;
}

/*
  9.2 Test Scores #1
    - Write a program that dynamically allocates an array large enough to hold a 
      userdefined number of test scores. Once all the scores are entered, the array 
      should be passed to a function that sorts them in ascending order. Another function 
      should be called that calculates the average score. The program should display the 
      sorted list of scores and averages with appropriate headings. Use pointer notation 
      rather than array notation whenever possible.

      * Input Validation: Do not accept negative numbers for test scores.
*/
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;

  //Declare program variable
  int v;  //Holds test score to input to array
  int n;  //Size of test scores array
  int *s; //Test scores array

  //Output/Input to user
  cout<<"How many test scores do you need to input?"<<endl;
  cin>>n;

  //Allocate memory for array
  s = new int[n];

  //Ask user to input scores and fill array
  for (int i = 0; i < n; i++) {
    cout<<"Test score #"<<i<<endl;
    cout<<"Enter score test score: "<<endl;
    cin>>v;
    if (v < 0) {
      cout<<"Invalid entry.Input that score again."<<endl;
      i--;
    } else s[i] = v;
  }

  //Sort values in array
  marksort(s,n);

  //Print scores to user
  cout<<"Here are all of your test scores: "<<endl;
  print(s,n);

  //Get average test score
  cout<<"The average test score was: "<<average(s,n)<<endl;

  delete []s;
}

void marksort(int *a,int n) {
  for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void print(int *a,int n) {
  for (int i = 0; i < n; i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

int average(int *a,int n) {
  int v = 0;
  for (int i = 0; i < n; i++)
    v += a[i];
  return v/n;
}

/*
  9.6 Case Study Modification #1
    - Modify Program 9-19 (the United Cause case study program) so 
      it can be used with any set of donations. The program should dynamically 
      allocate the donations array and ask the user to input its values.
*/
void problem2() {
  cout<<"In problem #2"<<endl<<endl;

  //Declare problem variables
  int n;  //Number of donations chosen by user
  int *a; //Donations
  int d;  //Donation amount

  //Output to user
  cout<<"Enter the number of donations: "<<endl;
  cin>>n;

  //Allocate memory
  a = new int[n];

  //Perform loop for user input
  for (int i = 0; i < n; i++) {
    cout<<"Donation #"<<i+1<<endl;
    cout<<"Donations remaining: "<<n-i<<endl;
    cout<<"Enter donation amount:"<<endl;
    cin>>d;
    (d > 0) ? a[i] = d : i--;
  }

  //Sort donations
  marksort(a,n);

  //Print all donations to user
  for (int i = 0; i < n; i++)
    cout<<"$"<<a[i]<<" ";
  cout<<endl;

  delete []a;
}

/*
  9.7 Case Study Modification #2
    - Modify Program 9-19 (the United Cause case study program) so the 
      arrptr array is sorted in descending order instead of ascending order.
*/
//Problem 3 Function prototypes
void revsort(int *,int);
void problem3() {
  cout<<"In problem # 3"<<endl<<endl;

  //Declare problem variables
  int n;  //Number of donations chosen by user
  int *a; //Donations
  int d;  //Donation amount

  //Output to user
  cout<<"Enter the number of donations: "<<endl;
  cin>>n;

  //Allocate memory
  a = new int[n];

  //Perform loop for user input
  for (int i = 0; i < n; i++) {
    cout<<"Donation #"<<i+1<<endl;
    cout<<"Donations remaining: "<<n-i<<endl;
    cout<<"Enter donation amount:"<<endl;
    cin>>d;
    (d > 0) ? a[i] = d : i--;
  }

  //Sort donations
  revsort(a,n);
  
  //Print all donations to user
  for (int i = 0; i < n; i++)
    cout<<"$"<<a[i]<<" ";
  cout<<endl;

  delete []a;
}

/* Sorts in reverse order */
void revsort(int *a,int n) {
  for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/*
  7.3 Drop Lowest Score
    - Modify Problem 2 above so the lowest test score is dropped. This score 
      should not be included in the calculation of the average.
*/
void problem4() {
  cout<<"In problem # 4"<<endl<<endl;

  //Declare problem variables
  int n;  //Number of donations chosen by user
  int *a; //Donations
  int *v; //Donations with lowest score dropped
  int d;  //Donation amount
  int m;  //Number of 'lowest scores'

  //Output to user
  cout<<"Enter the number of donations: "<<endl;
  cin>>n;

  //Allocate memory
  a = new int[n];

  //Perform loop for user input
  for (int i = 0; i < n; i++) {
    cout<<"Donation #"<<i+1<<endl;
    cout<<"Donations remaining: "<<n-i<<endl;
    cout<<"Enter donation amount:"<<endl;
    cin>>d;
    (d > 0) ? a[i] = d : i--;
  }

  //Sort donations
  marksort(a,n);

  //Check for lowest scores
  for (int i = 0; i < n; i++)
    if (a[0] == a[i]) m++;

  //Allocate memory for new array
  v = new int[n-m];

  for (int i = m; i < n; i++) {
    v[i - m] = a[i];
  }
  
  //Print all donations to user
  for (int i = 0; i < n-m; i++)
    cout<<"$"<<v[i]<<" ";
  cout<<endl;

  delete []v;
  delete []a;
}

/*
  7.1 Array Allocator
    - Write a function that dynamically allocates an array of integers. The function 
      should accept an integer argument indicating the number of elements to allocate. 
      The function should return a pointer to the array.
*/
int *arryptr(int n) {
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    a[i] = i+1;
  return a;
}
void problem5() {
  cout<<"In problem # 5"<<endl<<endl;
  int n = 10;
  int *a = arryptr(n);
  for (int i = 0; i < n; i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

/*
  9.4 Test Scores #2
    - Modify the program of Programming Challenge 2 to allow the user to enter 
      name-score pairs. For each student taking a test, the user types the student’s 
      name followed by the student’s integer test score. Modify the sorting function 
      so it takes an array holding the student names and an array holding the student 
      test scores. When the sorted list of scores is displayed, each student’s name 
      should be displayed along with his or her score. In stepping through the arrays, 
      use pointers rather than array subscripts.
*/
#include <string>
void scoresort(int *,string *,int);
void printscores(int *,string *,int);
void problem6() {
  cout<<"In problem # 6"<<endl<<endl;

  //Declare program variable
  int n;         //Size of test scores array
  int score;     //Holds test score to input to array
  int *scores;   //Test scores array
  string name;   //Holds name input
  string *names; //Array holding every students name

  //Output/Input to user
  cout<<"How many test scores do you need to input?"<<endl;
  cin>>n;

  //Allocate memory for array
  scores = new int[n];
  names  = new string[n];

  //Ask user to input scores and fill array
  for (int i = 0; i < n; i++) {
    cout<<"Test score #"<<i<<endl;
    cout<<"Enter test score: "<<endl;
    cin>>score;
    if (score < 0) {
      cout<<"Invalid entry.Input that score again."<<endl;
      i--;
    } else {
      cout<<"Enter the student's name:"<<endl;
      cin>>name;
      names[i]  = name;
      scores[i] = score;
    }
  }

  //Sort names and scores
  scoresort(scores,names,n);

  //Print scores to user
  cout<<"Here are all of your test scores: "<<endl;
  printscores(scores,names,n);

  delete []scores;
  delete []names;
}

void scoresort(int *a,string *s,int n) {
  for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                string stemp = s[i];
                s[i] = s[j];
                s[j] = stemp;
            }
        }
    }
}

void printscores(int *scores,string *names,int n) {
  for (int i = 0; i < n; i++) {
    cout<<"Student Name: "<<names[i]<<", Student Score: "<<scores[i]<<endl;
  }
}

/*
  9.5 Pointer Rewrite
    - The following function uses reference variables as parameters. Rewrite the 
      function so it uses pointers instead of reference variables, and then demonstrate 
      the function in a complete program.

      int doSomething(int &x,int &x) {
        int temp = x;
        x = y * 10;
        y = temp * 10;
        return x + y;
      }
*/
int doSomething(int *x,int *y) {
  int temp = *x;
  *x = *y * 10;
  *y = temp * 10;
  return *x + *y;
}
void problem7() {
  cout<<"In problem # 7"<<endl<<endl;

  //Declare problem variables
  int *x;
  int *y;
  int z;

  //Set values
  x = new int(5);
  y = new int(7);

  //Output initial values to user
  cout<<"Value of x: "<<*x<<endl;
  cout<<"Value of y: "<<*y<<endl;

  //Perform problem method
  z = doSomething(x,y);

  //Output result to user
  cout<<"Value of z: "<<z<<endl;
}

/*
  9.11 Array Expander
    - Write a function that accepts an int array and the array’s size 
      as arguments. The func- tion should create a new array that is twice 
      the size of the argument array. The func- tion should copy the contents 
      of the argument array to the new array and initialize the unused elements 
      of the second array with 0. The function should return a pointer to the 
      new array.
*/
int *expander(int *,int);
void problem8() {
  cout<<"In problem # 8"<<endl<<endl;

  //Declare problem variables
  int n  = 10;
  int *a = new int[n];
  int *a2;

  //Fill array
  for (int i = 0; i < n; i++)
    a[i] = i+1;

  //Fill expanded array
  a2 = expander(a,n);

  //Print contents of expanded array
  for (int i = 0; i < n*2; i++)
    cout<<a2[i]<<" ";
  cout<<endl;

  //Deallocate memory
  delete []a;
  delete []a2;
}

/* Doubles size of any int array */
int *expander(int *a,int n) {
  int *a2 = new int[n*2];
  for (int i = 0; i < n*2; i++)
    (i < n) ? a2[i] = a[i] : a2[i] = 0;
  return a2;
}

/*
  Element shifter
    - Write a function that accepts an int array and the array’s size 
      as arguments. The function should create a new array that is one element 
      larger than the argument array. The first element of the new array 
      should be set to 0. Element 0 of the argument array should be copied 
      to element 1 of the new array, element 1 of the argument array should 
      be copied to element 2 of the new array, and so forth. The function should 
      return a pointer to the new array.
*/
int *rshift(int *,int);
void problem9() {
  cout<<"In problem # 9"<<endl<<endl;

  //Declare problem variables
  int n = 10;
  int *arr = new int[n];
  int *shifted;

  //Fill array
  for (int i = 0; i < n; i++)
    arr[i] = i + 1;

  //Copy and shift
  shifted = rshift(arr,n);

  //Print contents of arrays
  cout<<"Original array:"<<endl;
  print(arr,n);
  cout<<"Shifted array:"<<endl;
  print(shifted,n+1);

  //Free memory
  delete []arr;
  delete []shifted;
}

/* Shifts contents of array on place to the right */
int *rshift(int *a,int n) {
  int *shifted = new int[n + 1];
  for (int i = 0; i < n + 1; i++)
    (i == 0) ? shifted[i] = 0 : shifted[i] = a[i-1];
  return shifted;
}

/*
  9.10 Reverse Array
    - Write a function that accepts an int array and the array’s size as 
      arguments. The function should create a copy of the array, except that 
      the element values should be reversed in the copy. The function should 
      return a pointer to the new array. Demonstrate the function in a 
      complete program.
*/
int *reverse(int *,int);
void problem10() {
  cout<<"In problem # 10"<<endl<<endl;

  //Declare problem variables
  int n = 10;
  int *arr = new int[n];
  int *reversed;

  //Fill array
  for (int i = 0; i < n; i++)
    arr[i] = i + 1;

  //Copy and shift
  reversed = reverse(arr,n);

  //Print contents of arrays
  cout<<"Original array:"<<endl;
  print(arr,n);
  cout<<"Reversed array:"<<endl;
  print(reversed,n);

  //Free memory
  delete []arr;
  delete []reversed;
}

int *reverse(int *a,int n) {
  //Allocate memory
  int *r = new int[n];

  //Fill array
  for (int i = 0; i < n; i++)
    r[i] = a[i];

  //Reverse r array
  for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r[i] < r[j]) {
                int temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }
  return r;
}

void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}