#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> v(30);
int counter = 1;
double temp = 0;
int thou = 1000;
for(int i=0;i<30;i++){
cout << "Enter value" << i+1;
cin >> v[i];
}
cout << "n            n^2            Exec Time (sec)     c = Time/n^2 \n" << "------------------------------------------------------------------------ \n";
for(int i=0;i<10;i++){
temp = (v[i]/((thou*thou)*(i+1)));
cout << thou*(i+1) << "           " << thou*thou*(i+1) << "            " << v[i] << "              " << temp << endl;
} 

cout << "n            n^2            Exec Time (sec)     c = Time/n^2 \n" << 
"------------------------------------------------------------------------ \n";
for(int i=0;i<10;i++){
temp = (v[i+10]/((thou*thou)*(i+1)));
cout << thou*(i+1) << "           " << thou*thou*(i+1)  << "            " << v[i+10] << "           " << temp << endl;
} 

cout << "n            n^2            Exec Time (sec)     c = Time/n^2 \n" <<    "------------------------------------------------------------------------ \n" << endl;
for(int i=0;i<10;i++){
temp = (v[i+20]/((thou*thou)*(i+1)));
cout << thou*(i+1) << "           " << thou*thou*(i+1)  << "            " << v[i+20] << "            " << temp << endl;
} 

return 0;

}

