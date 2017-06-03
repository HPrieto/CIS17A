/*
  Heriberto Prieto
  Assignment 6
  Chapter 13.1-9
  13.1,13.4 and 3 other problems
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
    13.1 Date
        - Design a class called Date. The class should store a date in three 
          integers: month, day, and year. There should be member functions to 
          print the date in the following forms:

          * 12/25/2014
          * December 25, 2014
          * 25 December 2014

        - Demonstrate the class by writing a complete program implementing it.
        - Input Validation: Do not accept values for the day greater than 31 or 
          less than 1. Do not accept values for the month greater than 12 or less than 1.
          cis-21,22
*/
class Date {
    private:
        int day;
        int month;
        int year;
        string getMonthName(int);
    public:
        //Class Constructor
        Date() 
          { this->day = 0; this->month = 0; this->year = 0; }

        //Set Day
        void setDay(int d) 
          { this->day = d; }

        //Set Month
        void setMonth(int m) 
          { this->month = m; }

        //Set Year
        void setYear(int y)
          { this->year = year; }

        //Prints date format: 00 / 00 / 0000
        void printDate1() 
          { cout<<this->month<<"/"<<this->day<<"/"<<this->year; }

        //Prints date format: MonthName 00, 0000
        void printDate2()
          { cout<<this->getMonthName(this->month)<<" "<<this->day<<", "<<this->year; }

        //Prints date format: 00 MonthName 0000
        void printDate3()
          { cout<<this->day<<" "<<this->getMonthName(this->month)<<" "<<this->year; }
};

string Date::getMonthName(int m) {
    switch (month) {
        case 1:
          return "January";
        break;
        case 2:
          return "February";
        break;
        case 3:
          return "March";
        break;
        case 4:
          return "April";
        break;
        case 5:
          return "May";
        break;
        case 6:
          return "June";
        break;
        case 7:
          return "July";
        break;
        case 8:
          return "August";
        break;
        case 9:
          return "September";
        break;
        case 10:
          return "October";
        break;
        case 11:
          return "November";
        break;
        case 12:
          return "December";
        break;
    }
}
int userDay();
int userMonth();
int userYear();
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;

  //Declare problem variables
  Date date;
  int format;

  //User input/output
  cout<<"Date Format Printer"<<endl;

  //Ask user to set day
  date.setDay(userDay());

  //Ask user to set month
  date.setMonth(userMonth());

  //Ask user to set Year
  date.setYear(userYear());

  //Ask user which format they'd prefer
  cout<<"Select the format:"<<endl;
  cout<<"1.) 12/25/2014  2.) December 25, 2014 3.) 25 December 2014"<<endl;
  cin>>format;
  while (format < 1 && format > 3) {
      cout<<"Invalid entry."<<endl;
      cout<<"Select the format:"<<endl;
      cout<<"1.) 12/25/2014  2.) December 25, 2014 3.) 25 December 2014"<<endl;
      cin>>format;
  }

  //Print format
  switch(format) {
      case 1:
        date.printDate1();
        break;
      case 2:
        date.printDate2();
        break;
      default:
        date.printDate3();
        break;
  }

  cout<<endl<<endl;
}

int userDay() {
    int day;
    cout<<"Begin by entering the Day:"<<endl;
    cin>>day;
    cin.clear();
    while (day < 1 && day > 31) {
        cout<<"Invalid day entry."<<endl;
        cout<<"Enter the day in proper format:"<<endl;
        cin>>day;
    }
    return day;
}

int userMonth() {
    int month;
    cout<<"Enter the Month:"<<endl;
    cin>>month;
    cin.clear();
    while (month < 1 && month > 12) {
        cout<<"Invalid month entry."<<endl;
        cout<<"Enter the month in proper format:"<<endl;
        cin>>month;
    }
    return month;
}

int userYear() {
    int year;
    cout<<"Enter the Year:"<<endl;
    cin>>year;
    cin.clear();
    while (year < 0) {
        cout<<"Invalid year entry."<<endl;
        cout<<"Enter the year in proper format:"<<endl;
        cin>>year;
    }
    return year;
}

/*
    13.2 Employee Class
      - Write a class named Employee that has the following 
        member variables:

        * name: employee name
        * idNumber: int
        * department: department name
        * position: job title string

      - Following constructors:
        - A constructor that accepts the following values as arguments 
          and assigns them to the appropriate member variables: 
          employee’s name, employee’s ID number, depart- ment, and position.
        - A constructor that accepts the following values as arguments and 
          assigns them to the appropriate member variables: employee’s name 
          and ID number. The department and position fields should be assigned 
          an empty string ("").
        - A default constructor that assigns empty strings ("") to the name, 
          department, and position member variables, and 0 to the idNumber member 
          variable.

        * Write appropriate mutator functions that store values in these member 
          variables and accessor functions that return the values in these member 
          variables. Once you have written the class, write a separate program 
          that creates three Employee objects to hold the following data.

          Name          ID Number       Department      Position
          Susan Meyers  47899           Accounting      Vice President
          Mark Jones    39119           IT              Programmer
          Joy Rogers    81774           Manufacturing   Engineer

        - The program should store this data in the three objects and then 
          display the data for each employee on the screen.
*/
class Employee {
    private:
        string name;
        string department;
        string position;
        int idNumber;
    public:
        //Empty Class Constructor
        Employee();
        //Class Constructor
        Employee(string,string,string,int);
        //Name Accessor Method
        string getName()
          { return this->name; }
        //Department Accessor Method
        string getDepartment()
          { return this->department; }
        //Position Accessor Method
        string getPosition()
          { return this->position; }
        //ID Number accessor Method
        int getID()
          { return this->idNumber; }
        //Name Mutator Method
        void setName(string name)
          { this->name = name; }
        //Department Mutator Method
        void setDepartment(string department)
          { this->department = department; }
        //Position Mutator Method
        void setPosition(string position)
          { this->position = position; }
        //ID Number Mutator Method
        void setID(int idNumber)
          { this->idNumber = idNumber; }
};

/* Empty Class Constructor */
Employee::Employee() {
    this->name = "";
    this->department = "";
    this->position = "";
    this->idNumber = 0;
}

/* Constructor that assignes data member values */
Employee::Employee(string name,string department,string position,int idNumber) {
    this->name = name;
    this->department = department;
    this->position = position;
    this->idNumber = idNumber;
}
void prntE(Employee);
void problem2() {
    cout<<"In problem # 2"<<endl<<endl;

    /*
        Name          ID Number       Department      Position
        Susan Meyers  47899           Accounting      Vice President
        Mark Jones    39119           IT              Programmer
        Joy Rogers    81774           Manufacturing   Engineer
    */

    //Declare Problem Variables
    Employee susan = Employee("Susan Meyers","Accounting","Vice President",47899);
    Employee mark  = Employee("Mark Nones","IT","Programmer",39119);
    Employee joy   = Employee("Joy Rogers","Manufacturing","Engineer",81774);

    //Output data to user
    prntE(susan);
    prntE(mark);
    prntE(joy);
}

void prntE(Employee e) {
    cout<<"Name:       "<<e.getName();
    cout<<"ID Number:  "<<e.getID();
    cout<<"Department: "<<e.getDepartment();
    cout<<"Position:   "<<e.getPosition();
    cout<<endl;
}

/*
    13.3 Car Class
    - Write a class named Car that has the following member variables:
      • yearModel. An int that holds the car’s year model.
      • make. A string that holds the make of the car.
      • speed. An int that holds the car’s current speed.
    
    - Programming Challenges 803 In addition, the class should have the 
      following constructor and other member functions.
      • Constructor. The constructor should accept the car’s year model 
        and make as argu- ments. These values should be assigned to the 
        object’s yearModel and make member variables. The constructor should 
        also assign 0 to the speed member variables.
      • Accessor. Appropriate accessor functions to get the values stored in 
        an object’s yearModel, make, and speed member variables.
      • accelerate. The accelerate function should add 5 to the speed member 
        variable each time it is called.
      • brake. The brake function should subtract 5 from the speed member 
        variable each time it is called.
    
    - Demonstrate the class in a program that creates a Car object, and then 
      calls the accelerate function five times. After each call to the accelerate 
      function, get the current speed of the car and display it. Then, call the 
      brake function five times. After each call to the brake function, get the 
      current speed of the car and display it.
*/
class Car {
private:
  int year;
  string make;
  int speed;
public:
  //Class Constructor
  Car(int,string);
  //Year accessor method
  int getYear()
    { return this->year; }
  //Make Accessor method
  string getMake()
    { return this->make; }
  //Speed Accessor Method
  int getSpeed()
    { return this->speed; }
  //Increments speed by 5
  void accelerate()
    { this->speed+=5; }
};
Car::Car(int year,string make) {
  this->year = year;
  this->make = make;
  this->speed = 0;
}
void problem3() {
  cout<<"In problem # 3"<<endl<<endl;

  //Declare problem variables
  Car shelby = Car(1997,"Shelby");

  //Begin Acceleration
  shelby.accelerate();

  //Output car speed
  cout<<"Speed After Acceleration: "<<shelby.getSpeed()<<endl;

  //Begin Acceleration
  shelby.accelerate();

  //Output car speed
  cout<<"Speed After Acceleration: "<<shelby.getSpeed()<<endl;

  //Begin Acceleration
  shelby.accelerate();

  //Output car speed
  cout<<"Speed After Acceleration: "<<shelby.getSpeed()<<endl<<endl;
}

/*
    13.4 Personal Information Class
      - Design a class that holds the following personal data: 
        name, address, age, and phone number. Write appropriate accessor 
        and mutator functions. Demonstrate the class by writing a program 
        that creates three instances of it. One instance should hold your 
        information, and the other two should hold your friends’ or family 
        members’ information.
*/
class PersonalInformation {
private:
  string name;
  string address;
  int age;
  int phone;
public:
  //Class Constructor
  PersonalInformation(string,string,int,int);
  //Name Accessor Method
  string getName()
    { return this->name; }
  //Address Accessor Method
  string getAddress()
    { return this->address; }
  //Age Accessor Method
  int getAge()
    { return this->age; }
  //Phone Number Accessor Method
  int getPhone()
    { return this->phone; }
};

PersonalInformation::PersonalInformation(string name,string address,int age,int phone) {
  this->name = name;
  this->address = address;
  this->age = age;
  this->phone = phone;
}
void prntInfo(PersonalInformation);
void problem4() {
  cout<<"In problem # 4"<<endl<<endl;

  //Declare problem variables
  PersonalInformation heri   = PersonalInformation("Heriberto","1234 Ridgeway",20,123);
  PersonalInformation nancy  = PersonalInformation("Nancy","1234 Rockway",20,123);
  PersonalInformation leonor = PersonalInformation("Leonor","1234 Hathaway",20,123);

  //print information to user
  prntInfo(heri);
  prntInfo(nancy);
  prntInfo(leonor);
}

void prntInfo(PersonalInformation p) {
  cout<<"Name:    "<<p.getName()<<endl;
  cout<<"Address: "<<p.getAddress()<<endl;
  cout<<"Age:     "<<p.getAge()<<endl;
  cout<<"Phone:   "<<p.getPhone()<<endl;
  cout<<endl;
}

/*
    13.5 RetailItem Class
      - Write a class named RetailItem that holds data about an item in a 
        retail store. The class should have the following member variables:
          • description. A string that holds a brief description of the item.
          • unitsOnHand. An int that holds the number of units currently in inventory.
          • price. A double that holds the item’s retail price.
      - Write a constructor that accepts arguments for each member variable, 
        appropriate mutator functions that store values in these member variables, 
        and accessor functions that return the values in these member variables. 
        Once you have written the class, write a separate program that creates 
        three RetailItem objects and stores the following data in them.
*/
class RetailItem {
private:
  string description;
  int units;
  float price;
public:
  //Class Constructor
  RetailItem(string,int,float);
  //Description Mutator Method
  void setDescription(string description)
    { this->description = description; }
  //Units Mutator Method
  void setUnits(int units)
    { this->units = units; }
  //Price Mutator Method
  void setPrice(int price)
    { this->price = price; }
  //Description Mutator Method
  string getDescription()
    { return this->description; }
  //Units Mutator Method
  int getUnits()
    { return this->units; }
  //Price Mutator Method
  float getPrice()
    { return this->price; }
};

RetailItem::RetailItem(string description,int units,float price) {
  this->description = description;
  this->units = units;
  this->price = price;
}
void printItem(RetailItem);
void problem5() {
  cout<<"In problem # 5"<<endl<<endl;

  //Declare problem variables
  RetailItem shoe  = RetailItem("Wearable",100,100.0f);
  RetailItem shirt = RetailItem("Wearable",150,30.0f);
  RetailItem pant  = RetailItem("Wearable",70,50.0f);

  //Output to user
  printItem(shoe);
  printItem(shirt);
  printItem(pant);
}

void printItem(RetailItem item) {
  cout<<"Description: "<<item.getDescription()<<endl;
  cout<<"Units:       "<<item.getUnits()<<endl;
  cout<<"Price:       "<<item.getPrice()<<endl;
  cout<<endl;
}
void def(int inN)
{
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}