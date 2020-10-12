#include <iostream>
#include <math.h>
using namespace std;
void dectobin(int N, int L){
	
	for(int i=0; i<N; i++){
		int A[16]={0};
		int temp = i, loc=0;
		while(temp>0){
			if(temp == 1){
				A[loc]=1;
				break;
			}
			A[loc] = temp%2;
			temp/=2;
			loc++;
		}
		for(int j=L-1; j>=0; j--){
			cout << A[j];
		}
		cout << endl;
	}
	
};
int main(){
	int num,Long;
	while(cin >> Long){
		num = pow(2,Long);
		dectobin(num,Long);
	}
	return 0;
}