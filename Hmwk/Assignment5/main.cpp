/*
  Heriberto Prieto
  Assignment 5
  Chapter 11
  11.9 and 9 other problems
*/
#include <iostream>
#include <string>
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
void problem8();

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
      case 6:    problem6();break;
      case 7:    problem7();break;
      case 8:    problem8();break;
      default:   def(inN);}
    } while (inN<9);
    return 1;
}
void Menu() {
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
int getN() {
    int inN;
    cin>>inN;
    return inN;
}

/*
  11.9 Speaker's Bureau
    - Write a program that keeps track of a speakers’ bureau. 
      The program should use a structure to store the following 
      data about a speaker:

      * Name
      * Telephone Number 
      * Speaking Topic 
      * Fee Required

    - The program should use an array of at least 10 structures. It 
      should let the user enter data into the array, change the contents 
      of any element, and display all the data stored in the array. The 
      program should have a menu-driven user interface.
      
    - Input Validation: When the data for a new speaker is entered, be 
      sure the user enters data for all the fields. No negative amounts 
      should be entered for a speaker’s fee.
*/
struct SpeakersBureau {
    string topic;
    string name;
    string phone;
    int fee;
};
void iSpkrs(SpeakersBureau *,int);
void prntBru(SpeakersBureau *,int);
void problem1() {
    cout<<"In problem # 1"<<endl<<endl;

    //Declare Method Variables
    int spkrs = 5;
    SpeakersBureau *bureau = new SpeakersBureau[spkrs];

    //Fill array of structs with user input
    iSpkrs(bureau,spkrs);

    //Print All Speakers Information
    prntBru(bureau,spkrs);

    //Free Memory
    delete [] bureau;
}

void prntBru(SpeakersBureau *b,int n) {
    cout<<"2017 Speaker Bureau"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Speaker #"<<i + 1<<endl;
        cout<<"Name:    "<<b[i].name<<endl;
        cout<<"Topic:   "<<b[i].topic<<endl;
        cout<<"Phone:   "<<b[i].phone<<endl;
        cout<<"Fee:     $"<<b[i].fee<<endl;
        cout<<endl<<endl;
    }
}

void iSpkrs(SpeakersBureau *b,int n) {
    //User input variables
    string i_topic,i_name,i_phone;
    int i_fee;

    //Output to user
    cout<<"Input the information for all Speakers:"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Speaker #"<<i + 1<<endl;
        cout<<"What is their topic of discussion?"<<endl;
        cin>>b[i].topic;
        cin.clear();
        cout<<"What was their name?"<<endl;
        cin>>b[i].name;
        cout<<"What was their phone number?"<<endl;
        cin>>i_phone;
        cin.clear();
        while (i_phone.length() < 7 && i_phone.length() > 12) {
            cout<<"Invalid Phone Number, Please Try Again:"<<endl;
            cin>>i_phone;
        }
        b[i].phone = i_phone;
        cout<<"What was their fee?"<<endl;
        cin>>i_fee;
        while (i_fee < 0) {
            cout<<"Invalid Entry, Fee must be positive."<<endl;
            cout<<"What was their fee?"<<endl;
            cin>>i_fee;
        }
        b[i].fee = i_fee;
        cout<<endl<<endl;
    }
}

/*
    11.2 Movie Data
        - Write a program that uses a structure named MovieData to store the 
            following information about a movie:
            * Title
            * Director
            * Year Released
            * Running Time (in minutes)
        - The program should create two MovieData variables, store values in their 
          members, and pass each one, in turn, to a function that displays the information 
          about the movie in a clearly formatted manner.
*/
struct MovieData {
    string title;
    string director;
    int year;
    int runTime;
};
void prntMvs(MovieData *,int);
void fillMvs(MovieData *,int);
void problem2() {
    cout<<"In problem # 2"<<endl<<endl;

    //Declare program variables
    int n = 2;
    MovieData *movies = new MovieData[n];

    //Fill Movie Data
    fillMvs(movies,n);

    //Output Movies to user
    prntMvs(movies,n);

    //Free memory
    delete [] movies;
}

/* Prints movies from Movies Data Array */
void prntMvs(MovieData *m,int n) {
    cout<<"Top Two Movies Ever:"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Movie #"<<i + 1<<endl;
        cout<<"Title:    "<<m[i].title<<endl;
        cout<<"Director: "<<m[i].director<<endl;
        cout<<"Year:     "<<m[i].year<<endl;
        cout<<"Run Time: "<<m[i].runTime<<" minutes"<<endl<<endl;
    }
  }

/* Fills MovieData from user input */
void fillMvs(MovieData *m,int n) {
    //Hard coded data input
    m[0].title    = "Tron";
    m[0].director = "Joseph Kosinski";
    m[0].year     = 1982;
    m[0].runTime  = 96;

    m[1].title    = "Toy Story";
    m[1].director = "John Lasseter";
    m[1].year     = 1995;
    m[1].runTime  = 81;
}

/*
    11.2 Movie Profit
        - Modify the Movie Data program written for Programming Challenge 1 to include 
          two additional members that hold the movie’s production costs and first-year 
          revenues. Modify the function that displays the movie data to display the title, 
          director, release year, running time, and first year’s profit or loss.
*/
struct MovieData2 {
    string title;
    string director;
    int year;
    int runTime;
    int cost;
    int revenues;
};
void prntMvs2(MovieData2 *,int);
void fillMvs2(MovieData2 *,int);
void problem3() {
    cout<<"In problem # 3"<<endl<<endl;

    //Declare program variables
    int n = 2;
    MovieData2 *movies = new MovieData2[n];

    //Fill Movie Data
    fillMvs2(movies,n);

    //Output Movies to user
    prntMvs2(movies,n);

    //Free memory
    delete [] movies;
}

/* Prints movies from Movies Data Array */
void prntMvs2(MovieData2 *m,int n) {
    cout<<"Top Two Movies Ever:"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Movie #"<<i + 1<<endl;
        cout<<"Title:     "<<m[i].title<<endl;
        cout<<"Director:  "<<m[i].director<<endl;
        cout<<"Year:      "<<m[i].year<<endl;
        cout<<"Run Time:  "<<m[i].runTime<<" minutes"<<endl;
        cout<<"Cost:     $"<<m[i].director<<endl;
        cout<<"Revenues: $"<<m[i].year<<endl<<endl;
    }
    cout<<endl;
  }

/* Fills MovieData from user input */
void fillMvs2(MovieData2 *m,int n) {
    //Hard coded data input
    m[0].title    = "Tron";
    m[0].director = "Joseph Kosinski";
    m[0].year     = 1982;
    m[0].runTime  = 96;
    m[0].cost     = 250000;
    m[0].revenues = 1200000;

    m[1].title    = "Toy Story";
    m[1].director = "John Lasseter";
    m[1].year     = 1995;
    m[1].runTime  = 91;
    m[1].cost     = 1000000;
    m[1].revenues = 3000000;
}

/*
  11.3 Corporate Sales Data
    - Write a program that uses a structure to store the 
      following data on a company division:

      Division Name (such as East, West, North, or South) First-Quarter Sales
      Second-Quarter Sales
      Third-Quarter Sales
      Fourth-Quarter Sales 
      Total Annual Sales 
      Average Quarterly Sales

    - The program should use four variables of this structure. Each variable 
      should represent one of the following corporate divisions: East, West, North, and South. 
      The user should be asked for the four quarters’ sales figures for each division. Each 
      division’s total and average sales should be calculated and stored in the appropriate 
      member of each structure variable. These figures should then be displayed on the screen.

    - Input Validation: Do not accept negative numbers for any sales figures.
*/

struct Divisions {
  string region;
  int secondQ;
  int thirdQ;
  int fourthQ;
  int total;
  int average;
};
void fillDivs(Divisions *,int);
void prntDivs(Divisions *,int);
void setQrtr(Divisions *,int,int);
void setRgn(Divisions *,int);
void setTtlS(Divisions *,int);
void setAvgS(Divisions *,int,int);
void problem4() {
  cout<<"In problem # 4"<<endl<<endl;

  //Declare problem variables
  int n = 4;
  Divisions *divisions = new Divisions[n];

  //Have user fill division info for all regions
  fillDivs(divisions,n);

  //Print region stats to user
  prntDivs(divisions,n);

  delete [] divisions;
}

/* Fills Division with region */
void fillDivs(Divisions *d,int n) {
    for (int i = 0; i < n; i++) {
        //Set Division Region
        setRgn(d,i);

        //Output to user
        cout<<d[i].region<<" Division"<<endl;

        //Set Quarter Sales
        for (int q = 1; q < n; q++)
            setQrtr(d,i,q + 1);

        //Set total sales earnings
        setTtlS(d,i);

        //Set Average Sales
        setAvgS(d,i,n);
    }
}

void setTtlS(Divisions *d,int i) {
    int total = 0;
    total += d[i].secondQ;
    total += d[i].thirdQ;
    total += d[i].fourthQ;
    d[i].total = total;
}

void setAvgS(Divisions *d,int i,int n) {
    d[i].average = d[i].total/n-1;
}

void setRgn(Divisions *d,int i) {
    //Set region
    switch (i) {
        case 0:
            d[i].region = "North";
            break;
        case 1:
            d[i].region = "South";
            break;
        case 2:
            d[i].region = "East";
            break;
        case 3:
            d[i].region = "West";
        default:
            break;
    }
}

/* Sets User inputs specified quarter earnings on user input */
void setQrtr(Divisions *d,int i,int q) {
    int sales;
    cout<<"Enter sales for quarter #"<<q<<endl;
    cin>>sales;
    while (sales < 0) {
        cout<<"Invalid sales entry."<<endl;
        cout<<"Enter sales for quarter #"<<q<<endl;
        cin>>sales;
        cin.clear();
    }
    //Set sales on specified quarter
    switch (q) {
        case 2:
            d[i].secondQ = sales;
            break;
        case 3:
            d[i].thirdQ = sales;
            break;
        case 4:
            d[i].fourthQ = sales;
            break;
    }
}

void prntDivs(Divisions *d,int n) {
    cout<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Region:                  "<<d[i].region<<endl;
        cout<<"2nd Quarter:             $"<<d[i].secondQ<<endl;
        cout<<"3rd Quarter:             $"<<d[i].thirdQ<<endl;
        cout<<"4th Quarter:             $"<<d[i].fourthQ<<endl;
        cout<<"Total Annual Sales:      $"<<d[i].total<<endl;
        cout<<"Average Quarterly Sales: $"<<d[i].average<<endl<<endl;
    }
    cout<<endl;
}

/*
  11.4 Weather Statistics
    - Write a program that uses a structure to store the following weather 
      data for a particular month:

      Total Rainfall
      High Temperature 
      Low Temperature 
      Average Temperature

    - The program should have an array of 12 structures to hold weather data for an 
      entire year. When the program runs, it should ask the user to enter data for each 
      month. (The average temperature should be calculated.) Once the data are entered 
      for all the months, the program should calculate and display the average monthly 
      rainfall, the total rainfall for the year, the highest and lowest temperatures for 
      the year (and the months they occurred in), and the average of all the monthly average 
      temperatures.

    - Input Validation: Only accept temperatures within the range between –100 and +140 
      degrees Fahrenheit.
*/
struct WeatherData {
    int rainfall;
    int highTemp;
    int lowTemp;
    int average;
};
void printW(WeatherData *,int);
void fillW(WeatherData *,int);
void setRFall(WeatherData *,int);
void setHTemp(WeatherData *,int);
void setLTemp(WeatherData *,int);
void setATemp(WeatherData *,int);
string getMonth(int);
void problem5() {
    cout<<"In problem # 5"<<endl<<endl;

    //Declare problem variables
    int months = 12;
    WeatherData *forecast = new WeatherData[months];

    //Fill weather data with user input
    fillW(forecast,months);

    //Free Memory
    delete [] forecast;
}

void fillW(WeatherData *w,int n) {
    for (int i = 0; i < n; i++) {
        //Output month to user
        cout<<"Enter the weather for the month of "<<getMonth(i)<<endl;

        //Set rainfall
        setRFall(w,i);

        //Set High Temperature
        setHTemp(w,i);

        //Set Low Temperature
        setLTemp(w,i);

        //Set Average Temperature
        setATemp(w,i);

        cout<<endl;
    }
    //Print forecast for entire year
    printW(w,n);
}

void printW(WeatherData *w,int months) {
    cout<<"Yearly Forecast"<<endl;
    for (int i = 0; i < months; i++) {
        cout<<"Weather for the month of "<<getMonth(i)<<endl;
        cout<<"Rainfall:            "<<w[i].rainfall<<" in."<<endl;
        cout<<"High Temperature:    "<<w[i].highTemp<<endl;
        cout<<"Low Temperature:     "<<w[i].lowTemp<<endl;
        cout<<"Average Temperature: "<<w[i].average<<endl<<endl;
    }
    cout<<endl;
}

void setATemp(WeatherData *w,int i) {
    int highLow = 0;
    highLow += w[i].lowTemp;
    highLow += w[i].highTemp;
    w[i].average = highLow/2;
}

void setHTemp(WeatherData *w,int i) {
    int i_high;
    cout<<"Enter the High Temperature for the month of "<<getMonth(i)<<":"<<endl;
    cin>>i_high;
    cin.clear();
    while (i_high < -100 && i_high > 140) {
        cout<<"Invalid High Temperature entry."<<endl;
        cout<<"Enter the High Temperature for the month of "<<getMonth(i)<<":"<<endl;
        cin>>i_high;
        cin.clear();
    }
    w[i].highTemp = i_high;
}

void setLTemp(WeatherData *w,int i) {
    int i_low;
    cout<<"Enter the Low Temperature for the month of "<<getMonth(i)<<":"<<endl;
    cin>>i_low;
    cin.clear();
    while (i_low < -100 && i_low > 140 && w[i].highTemp > i_low) {
        cout<<"Invalid Low Temperature entry."<<endl;
        cout<<"Enter the Low Temperature for the month of "<<getMonth(i)<<":"<<endl;
        cin>>i_low;
        cin.clear();
    }
    w[i].lowTemp = i_low;
}

void setRFall(WeatherData *w,int i) {
    int i_rainfall;
    cout<<"Enter the amount of rain fall in inches:"<<endl;
    cin>>i_rainfall;
    while (i_rainfall < 0) {
        cout<<"Invalid entry."<<endl;
        cout<<"Enter the amount of rain fall in inches:"<<endl;
        cin>>i_rainfall;
        cin.clear();
    }
    w[i].rainfall = i_rainfall;
}

string getMonth(int month) {
    switch (month) {
        case 0:
          return "January";
        break;
        case 1:
          return "February";
        break;
        case 2:
          return "March";
        break;
        case 3:
          return "April";
        break;
        case 4:
          return "May";
        break;
        case 5:
          return "June";
        break;
        case 6:
          return "July";
        break;
        case 7:
          return "August";
        break;
        case 8:
          return "September";
        break;
        case 9:
          return "October";
        break;
        case 10:
          return "November";
        break;
        case 11:
          return "December";
        break;
    }
}

/*
  11.5 Weather Statistics Modification
    - Modify the program that you wrote for Programming Challenge 4 so it defines an 
      enumerated data type with enumerators for the months (JANUARY, FEBRUARY, etc.). 
      The program should use the enumerated type to step through the elements of the array.
*/
enum Year {JAN=1,FEB=2,MAR=3,APR=4,MAY=5,JUN=6,JUL=7,AUG=8,SEP=9,OCT=10,NOV=11,DEC=12};
void problem6() {
    cout<<"In problem # 6"<<endl<<endl;

    //Declare problem variables
    int upto = DEC;
    WeatherData *forecast = new WeatherData[upto];

    //Fill weather data with user input
    fillW(forecast,upto);

    //Free Memory
    delete [] forecast;
}

/*
  11.6 Soccer Scores
    - Write a program that stores the following data about a soccer player in a structure:

      Player's Name
      Player's Number
      Points Scored by Player

    - The program should keep an array of 12 of these structures. Each element is for a 
      different player on a team. When the program runs it should ask the user to enter 
      the data for each player. It should then show a table that lists each 
      player’s number, name, and points scored. The program should also calculate and 
      display the total points earned by the team. The number and name of the player who 
      has earned the most points should also be displayed.

      Input Validation: Do not accept negative values for players’ numbers or points scored.
*/
struct SoccerPlayer {
    string name;
    int number;
    int goals;
};
void fillTeam(SoccerPlayer *,int);
void prntTeam(SoccerPlayer *,int);
void setName(SoccerPlayer *,int);
void setNumber(SoccerPlayer *,int);
void setGoals(SoccerPlayer *,int);
void problem7() {
  cout<<"In problem # 7"<<endl<<endl;

  //Declare program variables
  int team = 12;
  SoccerPlayer *players = new SoccerPlayer[team];

  //Fill entire soccer team with user input
  fillTeam(players,team);

  delete [] players;
}

/* Fills Array of SoccerPlayers with user input */
void fillTeam(SoccerPlayer *t,int n) {
    cout<<"Riverside Community College Soccer Team"<<endl;
    cout<<"Enter each soccer players information."<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Player #"<<i + 1<<endl;

        //Set player name
        setName(t,i);

        //Set Player Number
        setNumber(t,i);

        //Set Goals Scored by player
        setGoals(t,i);
    }
    //Print every soccer players info
    prntTeam(t,n);
}

/* Set player name in team/struct array */
void setName(SoccerPlayer *t,int i) {
    cout<<"What is the name of player #"<<i + 1<<"?"<<endl;
    cin>>t[i].name;
    cin.clear();
}

void setNumber(SoccerPlayer *t,int i) {
    int number;
    cout<<"Enter "<<t[i].name<<"'s player number?"<<endl;
    cin>>number;
    while (number < 0 && number > 100) {
        cout<<"Invalid player number entry."<<endl;
        cout<<"Enter "<<t[i].name<<"'s player number?"<<endl;
        cin>>number;
    }
    t[i].number = number;
}

void setGoals(SoccerPlayer *t,int i) {
    int goals;
    cout<<"Enter the amount of goals "<<t[i].name<<" scored:"<<endl;
    cin>>goals;
    while (goals < 0) {
        cout<<"Invalid entry."<<endl;
        cout<<"Enter the amount of goals "<<t[i].name<<" scored:"<<endl;
        cin>>goals;
    }
    t[i].goals = goals;
}

void prntTeam(SoccerPlayer *t,int n) {
    cout<<"Riverside Soccer Team Roster:"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Player Name:   "<<t[i].name<<endl;
        cout<<"Player Number: "<<t[i].number<<endl;
        cout<<"Goals Scored:  "<<t[i].goals<<endl<<endl;
    }
    cout<<endl;
}

/*
  11.7 Customer Accounts
    - Write a program that uses a structure to store the following data about 
      a customer account:

      Name
      Address
      City, State, and ZIP 
      Telephone Number 
      Account Balance 
      Date of Last Payment
*/
struct CustomerAccount {
    string name;
    string address;
    string city;
    string state;
    string zip;
    int balance;
    string date;
};
void problem8() {
  cout<<"In problem # 8"<<endl<<endl;

  //Declare problem variables
  CustomerAccount account;

  //User input/output
  cout<<"Enter the customer's name:"<<endl;
  cin>>account.name;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s address:"<<endl;
  cin>>account.address;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s city:"<<endl;
  cin>>account.city;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s state:"<<endl;
  cin>>account.state;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s zip:"<<endl;
  cin>>account.zip;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s balance:"<<endl;
  cin>>account.balance;
  cin.clear();

  cout<<"Enter "<<account.name<<"'s date:"<<endl;
  cin>>account.date;
  cin.clear();

  cout<<endl<<endl;
  cout<<"Name:    "<<account.name<<endl;
  cout<<"Address: "<<account.address<<endl;
  cout<<"City:    "<<account.city<<endl;
  cout<<"State:   "<<account.state<<endl;
  cout<<"Zipcode: "<<account.zip<<endl;
  cout<<"Balance: "<<account.balance<<endl;
  cout<<"Date:    "<<account.date<<endl;
}

void def(int inN) {
       cout<<"You typed "<<inN<<" to exit the program"<<endl;
}