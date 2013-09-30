#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void insertion_sort(vector<int> & v, int n){
int elem;
int j;
	for(int i = 1; i < n; i++){
		for(elem=v[i], j=i-1; j>=0 and elem < v[j]; j--){
		      v[j+1]=v[j];
		}
		v[j+1]=elem;
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
	insertion_sort(random,usr);
	for(int i=0; i < usr; i++){
		cout << random[i] << endl;
	}
return 0;
}
