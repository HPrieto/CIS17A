#include <iostream>
using namespace std;

int main(int argc,char **argv) {
	unsigned short scale=0x5B33;  //16w12s  5.7base10
	unsigned short x=372;		  //16w 0s
	unsigned int   answer=x*scale;//32w12s

	cout<<"Scaled 5.7 x 372 = "<<answer<<endl;

	answer>>=12;

	cout<<"Scaled 5.7 x 372 = "<<answer<<"/4"<<endl;

	return 0;
}