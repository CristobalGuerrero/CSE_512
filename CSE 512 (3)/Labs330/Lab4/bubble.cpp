#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void bubble_sort(vector<int> & v, int n){
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
		   if(v[j]>v[j+1])
		      swap(v[j],v[j+1]);
		}
	}

}

int main(){
	vector<int> random;
	int max_int = 1000000, usr = 0;
	
	srand(time(NULL));
	cout << "Enter a number: ";
	cin >> usr;
	
	for(int i=0; i < usr; i++){
		random.push_back(rand()%max_int);
	}
	bubble_sort(random,usr);
	for(int i=0; i < usr; i++){
		cout << random[i] << endl;
	}
return 0;
}
