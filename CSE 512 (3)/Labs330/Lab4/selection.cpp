#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void selection_sort(vector<int> & v, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
		   if(v[i]>v[j])
		      swap(v[i],v[j]);
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
	selection_sort(random,usr);
	for(int i=0; i < usr; i++){
		cout << random[i] << endl;
	}
return 0;
}
