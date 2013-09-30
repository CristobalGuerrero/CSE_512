//Cristobal Guerrero
//Class: CSE330
//Meeting: Monday, Wednesday
//Summary: This program simulates a coin sliding game that has logic
//due to game rule. I made the game a bit more challenging because if 
//the user is to make an invalid move their turn is skipped which is
//how I thought they should be penalized. Though not included in the
//instructions it was my decision to do so.
#include <iostream>
#include <vector>

using namespace std;
//This prints the vector
void print(vector<int> board, int size){
	cout<< endl;	
	for(int i=1; i<=size; i++){
	if(i<10){cout << "  " << i << " ";}
	else{cout << " " << i << " ";}
	}
	cout << endl;
	for(int i=0; i<size; i++){
	if(board[i]==1){cout << " [@]";}
	else{cout << " [ ]";}
	}
	cout << endl;
}

//make a function that goes through the vector 
//to see if the move is a valid one
bool isgranted(vector<int> & board, int choice, int moveto){
   int count=0;
   if(choice<moveto){
     for(choice; choice <= moveto-1; choice++){
	if(board[choice]==1){count++;}
     }
   }
   else{
       for(choice; choice-1 >= moveto; choice--){
	   if(board[choice]==1){count++;}
       }
   }
  if(count>0){return false;}
  else{return true;}
}

//checks to see if the move was valid
bool valid(vector<int> & board, int choice, int moveto){
    if(choice != moveto and board[choice-1]==1 and choice > 0 and choice < 16){
	if(isgranted(board, choice, moveto)){
		return true;
        }
        else { return false; }
    }
    else{ return false; }
}

//checks to see if the player is the winner
bool win(vector<int> & board){
	return (board[14]==1 and board[13]==1 and board[12]==1 and board[11]==1 and board[10]==1);
}

int main(){
int size=15,count=0, turn=1, choice=0, moveto=0;
vector<int> board(size);
//sets up the board to be completely zero instead of a null character or a random value
for(int i=0; i<size; i++){
	board[i]=0;
}

//Gets players input for the coin positions
while(count<5){
cout<< "Place coin " << count+1 << " where?: ";
cin >> choice;
//checks to see if a coin is currently there already
if(board[choice-1]!=1 and choice>0 and choice<16){
	board[choice-1]=1;
	count++;
}
else{ cout << "That is an invalid coin placement!\n";}
}
count=0;
//Prints the board with the current coins in place
print(board, size);
//checks to see if there is a winner each run through
//This point of the game of taking turns could have been done with another
//function that is set for each player and passes in the players number
while(!win(board)){
	//player ones turn
	if(turn=1){
	  cout << "Player A turn \nWhich position would you like to move: ";
	  cin >> choice;
	  cout << "Now which position do you want to move to: ";
	  cin >> moveto;
	  turn++;
	//checks to see if the move is valid
	if(valid(board,choice,moveto)){
	board[choice-1]=0;
	board[moveto-1]=1;
	}
	//spits out an invalid move error
	else { cout << "!!!!!!!!!!!!!!!!!::::::::Invalid move::::::::::!!!!!!!!!!!!!!!\n"; }
	//prints the board with or without change
	print(board, size);
	if(win(board)){cout << "Player A wins!!!!!!!!!!"; turn=1;}
	}
	//player twos turn
	if(turn=2){
	  cout << "Player B turn \nWhich position would you like to move: ";
	  cin >> choice;
	  cout << "Now which position do you want to move to: ";
	  cin >> moveto;
	  turn--;
	//checks to see if the move is valid
	if(valid(board,choice,moveto)){
	board[choice-1]=0;
	board[moveto-1]=1;
	}
	//spits out an invalid move error
	else { cout << "!!!!!!!!!!!!!!!!!::::::::Invalid move::::::::::!!!!!!!!!!!!!!!\n"; }
	//prints the board with or without change
	print(board, size);
	if(win(board)){cout << "Player B wins!!!!!!!!!!";}
	}
}
cout << endl << endl;
return 0;
}
