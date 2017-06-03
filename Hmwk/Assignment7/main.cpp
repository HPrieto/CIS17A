/*
  Heriberto Prieto
  Assignment 7
  Chapter 13.10-18
  13.5,13.6 and 3 other problems
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


int main(int argv,char *argc[]) {
  int inN;
  do {
   Menu();
   inN=getN();
   switch(inN) {
    case 1:    problem1();break;
    case 2:    problem2();break;
    case 3:    problem3();break;
    case 4:    problem4();break;
    case 5:    problem5();break;
    default:   def(inN);}
  } while(inN < 6);
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
void problem1() {
  cout<<"In problem # 1"<<endl<<endl;

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

/*
  13.6 Inventory Class
    - Design an Inventory class that can hold information and 
      calculate data for items in a retail store’s inventory. 
      The class should have the following private member variables:

      * int : itemNumber
      * int : quantity
      * float : cost
      * float : totalCost

    - Public Member Functions
      1.) Default Constructor
      2.) Constructor 2: args -> itemNumber,cost,quantity
          * Call set total cost function
      3.) setItemNumber
      4.) setQuantity
      5.) setCost
      6.) setTotalCost: Quantity * Cost
      7.) getItemNumber
      8.) getCost
      9.) getTotalCost
*/
class Inventory {
private:
  int itemNumber;
  int quantity;
  float cost;
  float totalCost;
public:
  //Default Constructor
  Inventory();
  //Constructor #2: Sets itemNumber,cost,quantity
  Inventory(int,int,float);
  //ItemNumber Mutator Method
  void setItemNumber(int);
  //Quantity Mutator Method
  void setQuantity(int);
  //Cost Mutator Method
  void setCost(float);
  //TotalCost Mutator Method
  void setTotalCost();
  //ItemNumber Accessor Method
  int getItemNumber()
    { return this->itemNumber; }
  //Cost Accessor Method
  float getCost()
    { return this->cost; }
  //TotalCost Accessor Method
  float getTotalCost()
    { return this->totalCost; }
};

/* Default Class Constructor */
Inventory::Inventory() {
  this->itemNumber = 0;
  this->quantity   = 0;
  this->cost       = 0;
  this->totalCost  = 0;
}

/* Constructor #2: Sets itemNumber,cost,quantity */
Inventory::Inventory(int itemNumber,int quantity,float cost) {
  this->itemNumber = itemNumber;
  this->quantity   = quantity;
  this->cost       = cost;
  this->setTotalCost();
}

/* ItemNumber Mutator Method */
void Inventory::setItemNumber(int itemNumber) {
  this->itemNumber = itemNumber;
}

/* Quantity Mutator Method, updates total inventory cost */
void Inventory::setQuantity(int quantity) {
  this->quantity = quantity;
  this->setTotalCost();
}

/* Cost mutatory method, updates total cost */
void Inventory::setCost(float cost) {
  this->cost = cost;
  this->setTotalCost();
}

/* TotalCost Mutator Method */
void Inventory::setTotalCost() {
  this->totalCost = this->quantity * this->cost;
}

void prntInv(Inventory);
void problem2() {
  cout<<"In problem # 2"<<endl<<endl; 
  //Declare problem variables
  Inventory comps = Inventory(1000,200,1500.0f);
  //Print Inventory
  prntInv(comps);
}

void prntInv(Inventory inv) {
  cout<<"ItemNumber: "<<inv.getItemNumber()<<endl;
  cout<<"Cost:       "<<inv.getCost()<<endl;
  cout<<"Total Cost: "<<inv.getTotalCost()<<endl<<endl;
}

/*
  13.7 TestScores Class
    - Design a TestScores class that has member variables to hold 
      three test scores. The class should have a constructor, accessor, 
      and mutator functions for the test score fields and a member 
      function that returns the average of the test scores. Demonstrate the
      class by writing a separate program that creates an instance of the 
      class. The program should ask the user to enter three test scores, 
      which are stored in the TestScores object. Then the program should 
      display the average of the scores, as reported by the TestScores object.
*/
class TestScores {
private:
  int nScores;
  int *scores;
public:
  //Class Constructor
  TestScores();
  //Sets test score at given index
  void setTestScore(int,int);
  //Gets test score at given index
  int getTestScore(int);
  //Returns the average of all three scores
  int getAverage();
};

/* Class Constructor: Allocates memory */
TestScores::TestScores() {
  nScores = 3;
  scores = new int[nScores];
  //Set scores to 0
  for (int i = 0; i < nScores; i++)
    scores[i] = 0;
}

/* Sets the Test Score at given index */
void TestScores::setTestScore(int value,int index) {
  scores[index] = value;
}

/* Returns the test score at given index */
int TestScores::getTestScore(int index) {
  return scores[index];
}

/* Returns the average of all three test scores */
int TestScores::getAverage() {
  int total = 0;
  for (int i = 0; i < nScores; i++)
    total += scores[i];
  return total / nScores;
}

void printTestScores(TestScores *,int);
void problem3() {
  cout<<"In problem # 3"<<endl<<endl;
  //Declare problem variables
  int value;
  int nScores = 3;
  TestScores *scores;
  //Output/Input to user
  for (int i = 0; i < nScores; i++) {
    cout<<"Enter your the "<<i + 1<<" of 3 testscores:"<<endl;
    cin>>value;
    while (value < 0) {
      cout<<"Invalid entry."<<endl;
      cout<<"Enter your the "<<i<<" of 3 testscores:"<<endl;
      cin>>value;
    }
    scores->setTestScore(value,i);
  }
  printTestScores(scores,nScores);
}

/* Prints contents of test scores */
void printTestScores(TestScores *scores,int nScores) {
  for (int i = 0; i < nScores; i++)
    cout<<"Test Score #"<<i+1<<": "<<scores->getTestScore(i)<<endl;
  cout<<"Test Score Average: "<<scores->getAverage()<<endl;
}

/*
  13.8 Circle Class
    - Member Variables
      * float: radius
      * float: 3.14159
    - Member Functions
      * Default Constructor
      * Constructor(radius of circle)
      * setRadius
      * getRadius
      * getArea: pi * radius * radius
      * getDiameter: radius * 2
      * getCircumference: 2 * pi * radius
*/
class Circle {
private:
  float radius;
  float pi;
public:
  //Class Constructor
  Circle()
    { this->radius = 0; this->pi = 3.14159f; }
  //Class Constructor #2
  Circle(float);
  //Radius Mutator
  void setRadius(float);
  //Radius Accessor
  float getRadius()
    { return this->radius; }
  //Area Accessor
  float getArea()
    { return this->pi * this->radius * this->radius; }
  //Diameter Accessor
  float getDiameter()
    { return this->radius * 2.0f; }
  //Circumference Accessor
  float getCircumference()
    { return 2.0f * this->pi * this->radius; }
};

/* Class Constructor: Sets Radius */
Circle::Circle(float radius) {
  this->radius = radius;
  this->pi = 3.14519f;
}

/* Radius Mutator */
void Circle::setRadius(float radius) {
  this->radius = radius;
}

void problem4() {
  cout<<"In problem # 4"<<endl<<endl;
  //Declare program variables
  float radius;
  Circle *circle;
  //Output/Input to user
  cout<<"Enter you desired radius: "<<endl;
  cin>>radius;
  while (radius < 0) {
    cout<<"Invalid entry."<<endl;
    cout<<"Enter your desired radius:"<<endl;
    cin>>radius;
  }
  circle->setRadius(radius);
  //Output to user
  cout<<"Circle Radius:        "<<circle->getRadius()<<endl;
  cout<<"Circle Area:          "<<circle->getArea()<<endl;
  cout<<"Circle Diameter:      "<<circle->getDiameter()<<endl;
  cout<<"Circle Circumference: "<<circle->getCircumference()<<endl<<endl;
}

/*
  13.9 Population
    - Birth Rate: Number of Births / Population
    - Death Reat: Number of Deaths / Population

    Stores:
      * population
      * nBirths
      * nDeaths

    Member Functions:
      * return BirthRate
      * return DeathRate
*/
class Population {
private:
  int population;
  int nBirths;
  int nDeaths;
public:
  //Class Constructor
  Population(int,int,int);
  //BirthRate Accessor
  float getBirthRate();
  //DeathRate Accessor
  float getDeathRate();
};

/* Class Constructor: Sets Data Members from Params */
Population::Population(int population,int nBirths,int nDeaths) {
  this->population = population;
  this->nBirths = nBirths;
  this->nDeaths = nDeaths;
}

/* Calculates and returns Birth Rate: nBirths / Population */
float Population::getBirthRate() {
  return static_cast<float>((this->nBirths * 1.0f) / (this->population * 1.0f));
}

/* Calculates and returns Death Rate: nDeaths / Population */
float Population::getDeathRate() {
  return static_cast<float>((this->nDeaths * 1.0f) / (this->population * 1.0f));
}

void problem5() {
  cout<<"In problem # 5"<<endl<<endl;
  //Declare Problem Variables
  int population = 350000000;
  int nBirths    = 4000000;
  int nDeaths    = 2600000;
  Population pop = Population(population,nBirths,nDeaths);
  cout<<"US Population Stats:"<<endl;
  cout<<"Population:         "<<population<<endl;
  cout<<"Number of Births:   "<<nBirths<<endl;
  cout<<"Number of Deaths:   "<<nDeaths<<endl;
  cout<<"Birth Rate:         "<<pop.getBirthRate()<<endl;
  cout<<"Death Rate:         "<<pop.getDeathRate()<<endl<<endl;
}
void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}