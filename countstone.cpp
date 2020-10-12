#include <iostream>
using namespace std;
int main(){
	int A[1000]={0};
	int temp;
	cin >> temp;
	while(temp != 0){
		A[temp]++;
		cin >> temp;
	}
	for(int i=0; i<1000; i++){
		if(A[i]==2){
			cout << i << endl;
		}
	}
	return 0;
}