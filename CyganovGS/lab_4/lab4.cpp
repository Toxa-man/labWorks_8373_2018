#include<iostream>

using namespace std;

double step(int ch, int pok){
	if (pok>=0) {
		double x=1;
		for(int h=0; h<pok; h++){
			x*=ch;
		}
		return(x);
	} else{
		double x=1;
		for(int h=0; h>pok; h--){
			x=x/ch;
		}
		return(x);
	}
}

int fackt(int arg){
	int otv=0;
	if (arg>=0){
		otv=1;
		for(int f=2; f<=arg; f++){
			otv*=f;
		}
	}
	return otv;
}

double kvadr_kor(double arg){
	const double EPS=1E-15;
	double x;
	if(arg==0){
		return 0;
	} else{
		x=1;
		for(;;){
			double xp=(x+arg/x)/2;
			if (x-xp>=0){
		 		if(x-xp<EPS){
					break;
				}
			}
			if (x-xp<0){
				if(x-xp>-EPS){
					break;
				}
			}
			x=xp;
		}
	return x;
	}
}

bool my_prime(int arg){
	for(int i=2; i<arg; i++){
		if(arg%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int ch, pok, facktor, pri;
	double kor;
	cout<<"First we calculate the power of number. Enter a number: ";
	cin>>ch;
	cout<<"Enter the power of number: ";
	cin>>pok;
	cout<<"Here is the result: "<<step(ch, pok)<<endl;
	cout<<endl;
	cout<<"Calculate a facktorial. Print your number: ";
	cin>>facktor;
	cout<<facktor<<"! = "<<fackt(facktor)<<endl;
	cout<<endl;
	cout<<"From your next number my program will calculate the square root: ";
	cin>>kor;
	cout<<"The square root of "<<kor<<" is "<<kvadr_kor(kor)<<endl;
	cout<<endl;
	cout<<"Now let's check is your number prime or not? Print your number here: ";
	cin>>pri;
	if(my_prime(pri)){
		cout<<"Your number is prime."<<endl;
	}else{
		cout<<"Your number is not prime."<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}
