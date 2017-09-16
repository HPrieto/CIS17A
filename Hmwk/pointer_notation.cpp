/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 13th, 2017, 2:20 PM
 * Purpose:  Database Sort
 */

//System Libraries
#include <iostream>  //Input/Output Stream Library
#include <cstdlib>   //Random number generator
#include <ctime>     //Time library for seed
using namespace std; //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
int *filArry(int);
int *filIndx(int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void markSrt(int *,int *,int);
void destroy(int *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Seed the random number function with time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize Variables
    int aSize=100;
    int perLine=10;
    int *array=filArry(aSize);
    int *index=filIndx(aSize);
   
    //Print the initialized array
    cout<<"Before sort"<<endl;
    prntAry(array,aSize,perLine);
    prntAry(index,aSize,perLine);
    
    //Sort the array
    markSrt(array,index,aSize);
    
     //Print the sorted array
    cout<<"After Sort"<<endl;
    prntAry(array,aSize,perLine);
    prntAry(index,aSize,perLine);
    prntAry(array,index,aSize,perLine);
    
    //Deallocate Memory
    destroy(array);
    destroy(index);
    
    //Exit the program
    return 0;
}

void destroy(int *a){
    delete []a;
}

void markSrt(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a +*(indx + i))>*(a + *(indx + j))){
                *(indx + i)=*(indx + i)^*(indx + j);
                *(indx + j)=*(indx + i)^*(indx + j);
                *(indx + i)=*(indx + i)^*(indx + j);
            }
        }
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[*(indx + i)]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a + i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filIndx(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        *(a + i)=i;
    }
    return a;
}

int *filArry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        *(a + i)=rand()%90+10;//[10-99]
    }
    return a;
}