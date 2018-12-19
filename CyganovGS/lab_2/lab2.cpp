#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	const int razmer=15;
	int arr_rand[razmer], arr_ncht[razmer], p=0, i=1,len_of_arr_ncht=0, j=0;
	float sum=0;
	srand(time(0));
	for(int i1=0; i1<razmer; i1++){
		arr_rand[i1]=0;
	}
	cout<<"Array with random numbers:   ";
	for(int i2=0; i2<razmer; i2++){
		arr_rand[i2]=1+rand()%99;
		cout<<arr_rand[i2]<<"   ";
	}
	cout<<endl;
	while (i<razmer){
		j=i;
		while (arr_rand[j]<arr_rand[j-1]){
		  p=arr_rand[j];
		  arr_rand[j]=arr_rand[j-1];
		  arr_rand[j-1]=p;
		  //cout<<p<<"          "<<arr_rand[j]<<"           "<<arr_rand[j-1]<<endl;
		  j--;
		}
		i++;
	}
	cout<<"Sorted array:   ";
	for(int i3=0; i3<razmer; i3++){
		cout<<arr_rand[i3]<<"   ";
		if (arr_rand[i3]%2!=0){
			arr_ncht[len_of_arr_ncht++]=arr_rand[i3];
		}
	}
	cout<<endl;
	cout<<"Array of odd numbers:   ";
	for(int i4=0; i4<len_of_arr_ncht; i4++){
		sum+=arr_ncht[i4];
		cout<<arr_ncht[i4]<<"   ";
	}
	cout<<endl;
	cout<<"Max odd: "<<arr_ncht[len_of_arr_ncht-1]<<endl;
	cout<<"Min odd: "<<arr_ncht[0]<<endl;
	cout<<"Arithmetic average: "<<sum/len_of_arr_ncht<<endl;

	system("pause");
	return(0);
}
