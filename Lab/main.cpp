//Heriberto Prieto
//June 5th, 2017
//CIS17A Final

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();//COMPLETE
void problem2();
void problem3();
void problem4();//COMPLETE
void problem5();//COMPLETE
void problem6();//COMPLETE


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
      case 6:    problem6();break;
      default:   def(inN);break;}
    }while (inN<7);
    return 1;
}
void Menu() {
  //Set the random number seed
  srand(static_cast<unsigned int>(time(0)));
  cout<<"CIS17A Final"<<endl;
  cout<<"Type 1 for problem 1"<<endl;
  cout<<"Type 2 for problem 2"<<endl;
  cout<<"Type 3 for problem 3"<<endl;
  cout<<"Type 4 for problem 4"<<endl;
  cout<<"Type 5 for problem 5"<<endl;
  cout<<"Type 6 for problem 6"<<endl;
  cout<<"Type 8 to exit \n"<<endl;
}
int getN() {
       int inN;
       cin>>inN;
       return inN;
}

/*
Problem #1  (Random Sequence)
  Create a class that
returns a random number from the following set,
{16,33,56,78,126}.  Loop 100,000 times with this 
procedure and print the frequency of each of the 
5 numbers obtained.  The following is the 
specification for the class.

Specification

class Prob1Random
{
  private:
    char *set;      //The set of numbers to draw random numbers from
    char  nset;     //The number of variables in the sequence
    int  *freq;     //Frequency of all the random numbers returned
    int   numRand;  //The total number of times the random number function is called
  public:
    Prob1Random(const char,const char *);     //Constructor
    ~Prob1Random(void);                       //Destructor
    char randFromSet(void);                   //Returns a random number from the set
    int *getFreq(void) const;                 //Returns the frequency histogram
    char *getSet(void) const;                 //Returns the set used
    int getNumRand(void) const;               //Gets the number of times randFromSet has
                                              //been called
};

Driver program to return a random sequence
  char n=5;
  char rndseq[]={17,33,56,79,126};
  int ntimes=100000;
  Prob1Random a(n,rndseq);
  for(int i=1;i<=ntimes;i++)
  {
    a.randFromSet();
  }
  int *x=a.getFreq();
  char *y=a.getSet();
  for(int i=0;i<n;i++)
  {
    cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
  }
  cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

Sample Output

17 occured 20045 times
33 occured 19952 times
56 occured 20035 times
79 occured 20039 times
126 occured 19929 times
The total number of random numbers is 100000

Note:  Your results are not expected to be exactly the
same!  After all these are pseudo-random number sequences
with different seeds.
*/
class Prob1Random {
  private:
    char *set;      //The set of numbers to draw random numbers from
    char  nset;     //The number of variables in the sequence
    int  *freq;     //Frequency of all the random numbers returned
    int   numRand;  //The total number of times the random number function is called
  public:
    //Constructor
    Prob1Random(const char,const char *);
    //Destructor
    ~Prob1Random(void);
    //Returns a random number from the set
    char randFromSet(void);
    //Returns the frequency histogram
    int *getFreq(void) const;
    //Returns the set used
    char *getSet(void) const;
    //Gets the number of times randFromSet has been called
    int getNumRand(void) const;
};
/* Prob1Random Class Constructor */
Prob1Random::Prob1Random(const char nset,const char *set) {
  this->numRand = 0;
  this->nset = nset;
  this->set  = new char[nset];
  this->freq = new int[nset];
  for (int i = 0; i < nset; i++)
    this->set[i] = set[i];
}

/* Prob1Random Class Destructor */
Prob1Random::~Prob1Random() {
  delete [] set;
  delete [] freq;
}

/* Returns a random number from the set */
char Prob1Random::randFromSet() {
  //Random generated index value within set bounds
  int index = (rand() % this->nset);
  //Increment number of times numRand is called
  this->numRand++;
  //Increment frequency at reflected index
  this->freq[index]++;
  //Return setValue with random generated index
  return set[index];
}

/* Returns the frequeny histogram */
int* Prob1Random::getFreq() const {
  return this->freq;
}

/* Returns set array */
char* Prob1Random::getSet() const {
  return this->set;
}

/* Returns the number of time randFromSet has been called */
int Prob1Random::getNumRand() const {
  return this->numRand;
}

void problem1() {
  cout<<"In problem # 1"<<endl<<endl;
  //Declare problem variables
  char n = 5;
  char rndseq[] = {17,33,56,79,126};
  int  ntimes   = 100000;
  Prob1Random a(n,rndseq);
  for (int i = 1; i <= ntimes; i++)
    a.randFromSet();
  int *x  = a.getFreq();
  char *y = a.getSet();
  for (int i = 0; i < n; i++)
    cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
  cout<<"The total number of random numbers is "<<a.getNumRand()<<endl<<endl;
}

/*
Problem #2  (All Kinds of Sorting)
Sort a single column array and/or sort a 2 dimensional array 
of characters given any column.  Here is what I used as my
template specification.

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
  private:
    int *index;                                 //Index that is utilized in the sort
  public:
    Prob2Sort(){index=NULL;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

Driver program for the above class.  Create your own file to read.

  cout<<"The start of Problem 2, the sorting problem"<<endl;
  Prob2Sort<char> rc;
  bool ascending=true;
  ifstream infile;
  infile.open("Problem2.txt",ios::in);
  char *ch2=new char[10*16];
  char *ch2p=ch2;
  while(infile.get(*ch2)){cout<<*ch2;ch2++;}
  infile.close();
  cout<<endl;
  cout<<"Sorting on which column"<<endl;
  int column;
  cin>>column;
  char *zc=rc.sortArray(ch2p,10,16,column,ascending);
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<16;j++)
    {
      cout<<zc[i*16+j];
    }
  }
  delete []zc;
  cout<<endl;

The output from this problem.

The start of Problem 2, the sorting problem
Lbekoeddhoffbmg
Lkcmggjcdhhglif
Cgldjhcekjigcdd
Cgldjhcekjigcdm
Bffmdbkcenlafjk
Fggdijijegfblln
Jjlncnimjldfedj
Amliglfohajcdmn
Balgfcaelhfkgeb
Kmlhmhcddfoeilc

Sorting on column 15
Cgldjhcekjigcdm
Fggdijijegfblln
Amliglfohajcdmn
Bffmdbkcenlafjk
Jjlncnimjldfedj
Lbekoeddhoffbmg
Lkcmggjcdhhglif
Cgldjhcekjigcdd
Kmlhmhcddfoeilc
Balgfcaelhfkgeb

*/
template <class T>
class Prob2Sort
{
  private:
    int *index;                                 //Index that is utilized in the sort
  public:
    //Class Constructor
    Prob2Sort(){index=NULL;};
    //Class Deconstructor
    ~Prob2Sort(){delete []index;};
    //Sorts a single column array
    T * sortArray(const T*,int,bool);
    //Sorts a 2 dimensional array represented as a 1 dim array
    T * sortArray(const T*,int,int,int,bool);
};

/* Sorts single column array */
template <class T>
T* Prob2Sort<T>::sortArray(const T *values,int size,bool ascending) {
  T *array = new T[size];
  for (int i = 0; i < size; i++)
    array[i] = values[i];
  for (int i = 0;i < size-1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (ascending == true) {
        if (array[i] > array[j]) {
          char temp = array[i];
          array[i]  = array[j];
          array[j]  = temp;
        }
      } else {
        if (array[i] < array[j]) {
          char temp = array[i];
          array[i]  = array[j];
          array[j]  = temp;
        }
      }
    }
  }
  return array;
}

/* Sorts a 2 Dimensional array represented as a 1 dim array */
template <class T>
T* Prob2Sort<T>::sortArray(const T *values,int rows,int columns,int column,bool ascending) {
  int size  = (rows * (columns)) + 8;
  int index = 0;
  T *temp = new T[size];
  for (int i = 0; i < size; i++)
    temp[i] = 0;
  cout<<"output values"<<endl;
  cout<<values<<endl;
  cout<<"End of values"<<endl;
  return temp;
}
void newFile();
void problem2() {
  cout<<"In problem # 2"<<endl<<endl;
  cout<<"The start of Problem 2, the sorting problem"<<endl;
  Prob2Sort<char> rc;
  bool ascending=true;
  ifstream infile;
  infile.open("Problem2.txt",ios::in);
  char *ch2=new char[10*16];
  char *ch2p=ch2;
  while(infile.get(*ch2)){cout<<*ch2;ch2++;}
  infile.close();
  cout<<endl;
  cout<<"Sorting on which column"<<endl;
  int column;
  cin>>column;
  char *zc=rc.sortArray(ch2p,10,16,column,ascending);
  cout<<"Final Print"<<endl;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<16;j++)
    {
      cout<<zc[i*16+j];
    }
  }
  cout<<"End of final print"<<endl;
  delete []zc;
  cout<<endl;
}

void newFile() {
  fstream file;
    file.open ("Problem2.txt",ios::out);
    file<<"Lbekoeddhoffbmg"<<endl;
    file<<"Lkcmggjcdhhglif"<<endl;
    file<<"Cgldjhcekjigcdd"<<endl;
    file<<"Cgldjhcekjigcdm"<<endl;
    file<<"Bffmdbkcenlafjk"<<endl;
    file<<"Fggdijijegfblln"<<endl;
    file<<"Jjlncnimjldfedj"<<endl;
    file<<"Amliglfohajcdmn"<<endl;
    file<<"Balgfcaelhfkgeb"<<endl;
    file<<"Kmlhmhcddfoeilc"<<endl;
    file.close();
}

/*
Problem #3  (Spreadsheet Stuff)
Class Specifications

template<class T>
class Prob3Table
{
  protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
  public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
  protected:
    T *augTable;                                  //Augmented Table with sums
  public:
    Prob3TableInherited(char *,int,int);          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;}; 
};

Driver code
  cout<<"Entering problem number 3"<<endl;
  int rows=5;
  int cols=6;
  Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
  const int *naugT=tab.getTable();
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<<naugT[i*cols+j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  const int *augT=tab.getAugTable();
  for(int i=0;i<=rows;i++)
  {
    for(int j=0;j<=cols;j++)
    {
      cout<<augT[i*(cols+1)+j]<<" ";
    }
    cout<<endl;
  }


Example Input Table
   100   101   102   103   104   105
   106   107   108   109   110   111
   112   113   114   115   116   117
   118   119   120   121   122   123
   124   125   126   127   128   128
Example Output Table with rows summed,
columns summed and the grand total printed.
   100   101   102   103   104   105   615
   106   107   108   109   110   111   651
   112   113   114   115   116   117   687
   118   119   120   121   122   123   723
   124   125   126   127   128   128   758
   560   565   570   575   580   584  3434
*/
template<class T>
class Prob3Table {
  private:
  protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
  public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template <class T>
void Prob3Table<T>::calcTable() {
  int index = 0;
  this->rowSum  = new T[this->rows];
  this->colSum  = new T[this->cols];
  //Prepare rowSum and colSum for calculation
  for (int c = 0; c < this->cols; c++)
    this->colSum[c] = 0;
  for (int r = 0; r < this->rows; r++)
    this->rowSum[r] = 0;
  //Calculate Column Sum
  for (int r = 0; r < this->rows; r++) {
    for (int c = 0; c < this->cols; c++) {
      this->colSum[c] += this->table[(this->cols*r)+c];
    }
  }
  //Calculate RowSum
  for (int i = 0; i < (this->rows * this->cols)+1; i++) {
    if (i != 0 && (i % 6) == 0)
      index++;
    this->rowSum[index] += this->table[i];
  }
  //Calculate Grand Total
  this->grandTotal = 0;
  for (int c = 0; c < this->cols; c++)
    this->grandTotal += this->colSum[c];
}

/* Prob3Table Constructor */
template <class T>
Prob3Table<T>::Prob3Table(char *file,int rows,int columns) {
  int index = 0;
  ifstream infile;
  infile.open(file,ios::in);
  this->rows  = rows;
  this->cols  = columns;
  this->table = new T[this->rows * this->cols];
  T **temp    = new T*[this->rows];
  //Allocate memory for 2DArray
  for (int r = 0; r < this->rows; r++)
    for (int c = 0; c < this->cols; c++)
      temp[r] = new T[this->cols];
  //Read Table from File
  for (int r = 0; r < this->rows; r++)
    for (int c = 0; c < this->cols; c++)
      infile>>temp[r][c];
  //Copy Contents from 2DArray to 1DArray
  for (int r = 0; r < this->rows; r++)
    for (int c = 0; c < this->cols; c++) {
      table[index] = temp[r][c];
      index++;
    }
  //Free Memory
  for (int i = 0; i < this->rows; i++)
    delete [] temp[i];
  delete [] temp;
  calcTable();
  //Close file
  infile.close();
}

template<class T>
class Prob3TableInherited:public Prob3Table<T> {
  protected:
    T *augTable;
  public:
    Prob3TableInherited(char *,int,int);
    ~Prob3TableInherited(){delete [] augTable;};
    const T *getAugTable(void){return augTable;}; 
};

/* Class Constructor */
template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file,int rows,int columns):
                        Prob3Table<T>(file,rows,columns) {
  int index = 0;
  this->augTable = new T[(rows+1)*(columns+1)];
  //Input row values and row Sums
  for(int r = 0; r <= rows; r++) {
    for(int c = 0; c < columns; c++) {
      if (r * columns + c == ((columns * ((r-1) + 1)) + (r-1)))
        this->augTable[r*columns+c] = this->rowSum[r - 1];
      else {
        this->augTable[r*columns+c] = this->table[index];
        index++;
      }
    }
  }
  //Input column sums
  for (int c = 0; c < columns; c++)
    this->augTable[((rows*(columns+1))+c)] = this->colSum[c];
  //Bottom RightMost Value
  this->augTable[(((rows+1)*(columns+1))-1)] = this->grandTotal;
}

void problem3() {
  cout<<"In problem #3"<<endl<<endl;
  cout<<"Entering problem number 3"<<endl;
  int rows=5;
  int cols=6;
  Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
  const int *naugT=tab.getTable();
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<<naugT[i*cols+j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  const int *augT=tab.getAugTable();
  for(int i=0;i<=rows;i++)
  {
    for(int j=0;j<=cols;j++)
    {
      cout<<augT[i*(cols+1)+j]<<" ";
    }
    cout<<endl;
  }
}

/*
Problem #4  (Savings Account Class)
  Create a SavingsAccount class with the following
specification
  public:
    SavingsAccount(float);               //Constructor
    void  Transaction(float);            //Procedure
    float Total(float=0,int=0);          //Savings Procedure
    float TotalRecursive(float=0,int=0);
    void  toString();                    //Output Properties
  private:
    float Withdraw(float);               //Utility Procedure
    float Deposit(float);                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property

1)  The constructor initilizes the balance if greater than
0 and sets the other properties to 0.
2)  If the transaction is greater than 0 then a Deposit is
made else a Withdraw is made.
3)  The balance is increased with a deposit but decreased
if a Withdrawal.  This assumes the Withdrawal is less than
the balance.  Can't have a negative balance.  Tell the user
that he is trying to make a withdrawal that exceeds his
balance.
4)  When a WithDrawal is made increment FreqWithDraw else
if a Deposit is made increment FreqDeposit.
5)  The toString procedure outputs all properties.
6)  The total procedure tells you how much you will have in
savings given the interest rate and the amount of time.
Total(float savint,int time)  returns Balance*(1+savint)^time.
Utilize a for loop for this calculation.
7)  See if you can write a recursive procedure that does
the same thing as 6).  Call it TotalRecursive.
8)  Think of what follows as pseudocode.  The random number
generator below produces a number between 0 and 32,767.  If
you fashion a random number that will do the same then you
will get positive and negative transactions (-500,500).  
The output simply calculates the current balance with a 10 
percent interest rate and 7 years worth of compounding.  
Also, you tried to start out with a negative balance which 
should have been initialized to 0.

  SavingsAccount mine(-300);

  for(int i=1;i<=10;i++)
  {
    mine.Transaction((float)(rand()%500)*(rand()%3-1));
  }
  mine.toString();
  cout<<"Balance after 7 years given 10% interest = "
    <<mine.Total((float)(0.10),7)<<endl;
  cout<<"Balance after 7 years given 10% interest = "
    <<mine.TotalRecursive((float)(0.10),7)
    <<" Recursive Calculation "<<endl;

Example Output:
  WithDraw not Allowed
  WithDraw not Allowed
  Balance=1056
  WithDraws=4
  Deposit=5
  Balance after 7 years given 10% interest = 2057.85
  Balance after 7 years given 10% interest = 2057.85 Recursive Calculation
*/
class SavingsAccount {
  private:
    //Utility Procedure
    float Withdraw(float);
    //Utility Procedure
    float Deposit(float);
    //Property
    float Balance;
    //Property
    int FreqWithDraw;
    //Property
    int FreqDeposit;
  public:
    //Constructor
    SavingsAccount(float);
    //Procedure
    void Transaction(float);
    //Savings Procedure
    float Total(float=0,int=0);
    //Savings Procedure using recursion
    float TotalRecursive(float=0,int=0);
    //Output Properties
    void toString();
};

/* Savings Account Constructor */
SavingsAccount::SavingsAccount(float amount) {
  (amount > 0) ? this->Balance = amount:
                 this->Balance = 0;
  this->FreqWithDraw = 0;
  this->FreqDeposit  = 0;
}

/* Procedure */
void SavingsAccount::Transaction(float amount) {
  (amount > 0) ? Deposit(amount) : Withdraw(amount);
}

/* Savings Procedure: Balance*(1+savint) */
float SavingsAccount::Total(float interest,int time) {
  float savings = this->Balance;
  for (int i = 0; i < time; i++)
    savings *= (1 + interest);
  return savings;
}

/* Savings Procedure using recursion */
float SavingsAccount::TotalRecursive(float interest,int time) {
  if (time == 0) return this->Balance;
  return (interest + 1) * TotalRecursive(interest,time - 1);
}

/* Returns properties in a string representation */
void SavingsAccount::toString() {
  cout<<"Balance:            "<<this->Balance<<endl;
  cout<<"WithDraw Frequency: "<<this->FreqWithDraw<<endl;
  cout<<"Deposit Frequency:  "<<this->FreqDeposit<<endl<<endl;
}

/* Reduces the $$$ amount from balance */
float SavingsAccount::Withdraw(float amount) {
  if (Balance < 0)
    cout<<"You do not have the funds to make this transaction."<<endl;
  else if (Balance < (amount * -1))
    cout<<"You are trying to make a withdrawal that exceeds his balance."<<endl;
  else {
    this->Balance += amount;
    this->FreqWithDraw++;
  }
  return this->Balance;
}

/* Increases the $$ amount from balance */
float SavingsAccount::Deposit(float amount) {
  this->Balance += amount;
  this->FreqDeposit++;
  return this->Balance;
}

void problem4() {
  cout<<"In problem # 4"<<endl<<endl;
  SavingsAccount mine(-300);

  for(int i=1;i<=10;i++)
    mine.Transaction((float)(rand()%500)*(rand()%3-1));
  mine.toString();
  cout<<"Balance after 7 years given 10% interest = "
    <<mine.Total((float)(0.10),7)<<endl;
  cout<<"Balance after 7 years given 10% interest = "
    <<mine.TotalRecursive((float)(0.10),7)
    <<" Recursive Calculation "<<endl;
}

/*
Problem #5  (Employee Class)
  Create an Employee class with the following
specification
  public:
    Employee(char[],char[],float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure
  private:
    double Tax(float);      //Utility Procedure
    char   MyName[20];      //Property
    char   JobTitle[20];    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property

1)  The constructor inputs the Name, Job Title and Hourly rate of
the employee.
2)  All other properties are initialized to zero in the constructor.
3)  The Tax utility routine calculates the tax based on 
.1 for GrossPay < 500,
.2 for GrossPay<1000 but greater than 500, and 
.3 for anything above 1000.
4)  The Set procedures simply write and return the obvious
properties.
5)  The toString procedure prints all the properties.
6)  The getGrossPay procedure calculates straight time for hours
worked < 40, time and 1/2 for hours worked < 50 but greater than
40, double time for all hours above 50.  The inputs to this
routine are the hourly rate and the hours worked.
7)  The net pay routine returns the gross pay subtracting
off any taxes.  Realize that the Tax procedure is utilized
but these taxes are progressive rates for income above the
cutoff limit as described in 3).  Taxes are calculated for
10% below 500, 20% for amounts between 500 and 1000 and
finally anything above 1000 is calculated at the 30% rate.
8)  The Hoursworked must be > 0 and < 84
9)  The Hourlyrate must be > 0 and < 200
10) The calculate pay routine returns the net pay.
  return getNetPay(getGrossPay(setHourlyRate(x)
    ,setHoursWorked(y)));

Example Input
  Employee Mark("Mark","Boss",215.50);
  Mark.setHoursWorked(-3);
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(20.0),
    Mark.setHoursWorked(25));
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(40.0),
    Mark.setHoursWorked(25));
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(60.0),
    Mark.setHoursWorked(25));
  Mark.toString();

  Employee Mary("Mary","VP",50.0);
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(40));
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(50));
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(60));
  Mary.toString();

Example Output
Unacceptable Hourly Rate
Unacceptable Hours Worked
Name = Mark Job Title = Boss
 Hourly Rate = 0 Hours Worked = 0 Gross Pay = 0 Net Pay = 0
Name = Mark Job Title = Boss
 Hourly Rate = 20 Hours Worked = 25 Gross Pay = 500 Net Pay = 450
Name = Mark Job Title = Boss
 Hourly Rate = 40 Hours Worked = 25 Gross Pay = 1000 Net Pay = 850
Name = Mark Job Title = Boss
 Hourly Rate = 60 Hours Worked = 25 Gross Pay = 1500 Net Pay = 1200
Name = Mary Job Title = VP
 Hourly Rate = 50 Hours Worked = 0 Gross Pay = 0 Net Pay = 0
Name = Mary Job Title = VP
 Hourly Rate = 50 Hours Worked = 40 Gross Pay = 2000 Net Pay = 1550
Name = Mary Job Title = VP
 Hourly Rate = 50 Hours Worked = 50 Gross Pay = 2750 Net Pay = 2075
Name = Mary Job Title = VP
 Hourly Rate = 50 Hours Worked = 60 Gross Pay = 3750 Net Pay = 2775
*/
class Tax {
private:
public:
};

class Employee {
  public:
    //Constructor
    Employee(char[],char[],float);
    //Procedure
    float  CalculatePay(float,int);
    //Procedure
    float  getGrossPay(float,int);
    //Procedure
    float  getNetPay(float);
    //Procedure
    void   toString();
    //Procedure
    int    setHoursWorked(int);
    //Procedure
    float  setHourlyRate(float);
  private:
    //Calculate Tax based on Gross Pay
    double Tax(float);
    char   MyName[20];
    char   JobTitle[20];
    float  HourlyRate;
    int    HoursWorked;
    float  GrossPay;
    float  NetPay;
};

/* Class Constructor */
Employee::Employee(char *name,char *title,float rate) {
  for (int i = 0; i < 20; i++) {
    this->MyName[i] = name[i];
    this->JobTitle[i] = title[i];
  }
  this->HourlyRate = rate;
  this->HoursWorked = 0;
  this->GrossPay = 0;
  this->NetPay = 0;
}

/* Calculate Tax based on Gross Pay */
double Employee::Tax(float gross) {
  if (gross < 500) 
    return gross * .1;
  else if (gross > 500 && gross < 1000)
    return gross * .2;
  else
    return gross * .3;
}
/*
The calculate pay routine returns the net pay.
return getNetPay(getGrossPay(setHourlyRate(x)
,setHoursWorked(y)));
*/
float Employee::CalculatePay(float x,int y) {
  return getNetPay(getGrossPay(setHourlyRate(x)
    ,setHoursWorked(y)));
}

/*
The net pay routine returns the gross pay subtracting
off any taxes.  Realize that the Tax procedure is utilized
but these taxes are progressive rates for income above the
cutoff limit as described in 3).  Taxes are calculated for
10% below 500, 20% for amounts between 500 and 1000 and
finally anything above 1000 is calculated at the 30% rate.
*/
float Employee::getNetPay(float rate) {
  this->NetPay = this->getGrossPay(rate,this->HoursWorked) - this->Tax(this->GrossPay);
  return this->NetPay;
}

/*
The getGrossPay procedure calculates straight time for hours
worked < 40, time and 1/2 for hours worked < 50 but greater than
40, double time for all hours above 50.  The inputs to this
routine are the hourly rate and the hours worked.
*/
float Employee::getGrossPay(float rate,int hours) {
  if (hours < 40) 
    this->GrossPay =  rate * hours;
  else if (hours  >= 40 && hours < 50) 
    this->GrossPay = (rate * 40) + ((rate * 1.5) * (hours - 40));
  else this->GrossPay = (rate * 40) + ((rate * 1.5) * 10) + ((rate * 2) + (hours - 50));
  return this->GrossPay;
}

/*
The toString procedure prints all the properties.
*/
void Employee::toString() {
  cout<<"Name:         "<<this->MyName<<endl;
  cout<<"Job Title:    "<<this->JobTitle<<endl;
  cout<<"Hourly Rate:  "<<this->HourlyRate<<endl;
  cout<<"Hours Worked: "<<this->HoursWorked<<endl;
  cout<<"GrossPay:     "<<this->GrossPay<<endl;
  cout<<"NetPay:       "<<this->NetPay<<endl;
}

/*
The Set procedures simply write and return the obvious
properties.
The Hoursworked must be > 0 and < 84
*/
int Employee::setHoursWorked(int hours) {
  if (hours > 0 && hours < 84) this->HoursWorked = hours;
  return this->HoursWorked;
}
/*
The Set procedures simply write and return the obvious
properties.
The Hourlyrate must be > 0 and < 200
*/
float Employee::setHourlyRate(float rate) {
  if (rate > 0 && rate < 200) this->HourlyRate = rate;
  return this->HourlyRate;
}

void problem5() {
  cout<<"In problem # 5"<<endl<<endl;
  Employee Mark("Mark","Boss",215.50);
  Mark.setHoursWorked(-3);
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(20.0),
    Mark.setHoursWorked(25));
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(40.0),
    Mark.setHoursWorked(25));
  Mark.toString();
  Mark.CalculatePay(Mark.setHourlyRate(60.0),
    Mark.setHoursWorked(25));
  Mark.toString();

  Employee Mary("Mary","VP",50.0);
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(40));
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(50));
  Mary.toString();
  Mary.CalculatePay(Mary.setHourlyRate(50.0),
    Mary.setHoursWorked(60));
  Mary.toString();
}
/*
Problem #6  (Conversions)

Given the following base 10 decimals
  a)3.75
  b)0.7
  c)89.9

  1) Convert to binary, octal and hex, then 
  2) Convert to Hex float with first 24 bits representing the
     signed fraction and the last 8 bits representing the
     signed exponent. Scaled as 0.FRACTION x 2^E
   convert b) to integer binary 2 byte,
   convert c) to integer binary 3 byte.
  4) multiply 3) by 7 then shift back to integer and output the result
  5) Then convert using IEEE 754 format
*/
void convert(char *,int,int,int);
void prntRep(char *,int);
void blnkRep(char *,int);
void destroy(char *);
char charRep(int);
void problem6() {
  cout<<"In problem #6"<<endl<<endl;
  //Declare variables
  int  bits    = 16, decimal;
  char *binary = new char[bits];
  char *octal  = new char[bits/2];
  char *hexdec = new char[bits/4];
  //Set binary/octal/hex string representation to 0's
  blnkRep(binary,bits);
  blnkRep(octal, bits/2);
  blnkRep(hexdec,bits/4);
  //Set Binary/Octal/Hex string representations
  cout<<"Enter a number:"<<endl;
  cin>>decimal;
  convert(binary,bits,  decimal, 2);
  convert(octal, bits/2,decimal, 8);
  convert(hexdec,bits/4,decimal,16);
  //Output representations to user
  cout<<"Binary Representation:"<<endl;
  prntRep(binary,bits);
  cout<<"Octal Representation:"<<endl;
  prntRep(octal, bits/2);
  cout<<"Hexadecimal Representation:"<<endl;
  prntRep(hexdec,bits/4);
  //Free Memory
  destroy(binary);
  destroy(octal);
  destroy(hexdec);
}
/* Converts int decimal value to specified base representation */
void convert(char *rep,int size,int dec,int base) {
  int index = 1,remainder;
  while (dec != 0) {
    remainder = dec % base;
    dec /= base;
    (remainder < 10) ? rep[size - index] = '0' + remainder:
                       rep[size - index] = charRep(remainder);
    index++;
  }
}

/* Creates blank representation of char array with all 0's */
void blnkRep(char *rep,int size) {
  for (int i = 0; i < size; i++)
    rep[i] = '0';
  rep[size] = '\0';
}

/* Outputs specified string representations to user */
void prntRep(char *rep,int size) {
  //Output formatted representation
  for (int i = 0; i < size; i++)
    ((i + 1) % 8 == 0) ? cout<<rep[i]<<endl:
    ((i + 1) % 4 == 0) ? cout<<rep[i]<<"  ":
                         cout<<rep[i]<<" ";
  cout<<endl;
}

/* Frees memory in dynamic array */
void destroy(char *array) {
  delete [] array;
}

/* Returns character representation of hexidecimal int greater than 9 */
char charRep(int number) {
  return static_cast<char>('A' + (number - 10));
}

void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
























