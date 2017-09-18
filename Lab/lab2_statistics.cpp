//User Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Program Functions
void destroy(int *);
void prntArr(int *,int);
void fillArr(int *,int);
int  mean(int *,int);
int  median(int *,int);
int  mode(int *,int);
void markSrt(int *,int);
int  inptLen();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    //Declare program variables
    int length = inptLen();
    int *array = new int[length];
    //Fill array with random values
    fillArr(array,length);
    //Print contents of array
    prntArr(array,length);
    //Print mean of created array
    cout<<"Mean:   "<<mean(array,length)<<endl;
    cout<<"Median: "<<median(array,length)<<endl;
    cout<<"Mode:   "<<mode(array,length)<<endl;
    //Free Memory
    destroy(array);
}

/* Calculates the mean of an array */
int mean(int *array, int length) {
    unsigned int sum = 0;
    for (int i = 0; i < length; i++)
        sum += array[i];
    return sum / length;
}

/* Calculates the median of an array */
int median(int *array, int length) {
    //Sort algorithm
    markSrt(array,length);
    return array[length/2];
}

/* Calculates the mode of an array */
int mode(int *array, int length) {
    int counter = 1;
    int max = 0;
    int mode = array[0];
    for (int i = 0; i < length - 1; i++) {
       if (array[i] == array[i+1]) {
          counter++;
          if (counter > max) {
              max = counter;
              mode = array[i];
          }
       } else
          counter = 1; // reset counter.
    }
    return mode;
}

/* Sorts an array using Dr Lehrs sorting algorithm */
void markSrt(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

/* Prompt user for decimal value and return */
int inptLen() {
    //Method variables
    int length;
    //Scan User Input
    printf("Enter the length of an array:");
    scanf("%i", &length);
    return length;
}

/* Fills an array of n length with random values [0, 100] */
void fillArr(int *array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 99 + 1;
    }
}

/* Prints array of n values in a formatted fashion */
void prntArr(int *array, int length) {
    cout<<endl;
    for(int i = 0; i < length; i++) {
        cout<<array[i]<<" ";
        if(i % 10 == (10 - 1)) cout<<endl;
    }
    cout<<endl;
}

/* Frees memory in dynamic array */
void destroy(int *array) {
    delete [] array;
}

/* Returns character representation of a 'number', including numbers > 9 */
char charRep(int value) {
  	return static_cast<char>('A' + (value - 10));
}