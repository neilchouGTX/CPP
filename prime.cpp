#include <iostream>
using namespace std;
void AllPrimeFactors(int N);
int main(){
	int i=2,number;
	cin >> number;
	AllPrimeFactors(number);
	return 0;
}
void AllPrimeFactors(int N){
	int i=2;
	while(N!=1){
		if(N%i==0){
			N/=i;
			cout << i << " ";
			i--;
		}
		i++;
	}
}