#include <iostream>
using namespace std;

	char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char turn = 'X';
	int row,col;
	bool draw = false;

		//commit

void printBoard(){
	
	// clear the board to stay protected from repetition 
	system("cls");
	
	// Game starts from here
	cout<<"\t\t T I C  T A C  T O E\n\n";
	cout<<"\tPlayer1 [X]\n\tPlayer2 [O]\n\n";
	
	// Board
	cout<<"\t\t     0     1     2  \n\n";
	cout<<"\t\t        :     :     \n";
	cout<<"\t\t0    "<<board[0][0]<<"  :  "<<board[0][1]<<"  :  "<<board[0][2]<<"  \n";
	cout<<"\t\t   _____:_____:_____\n";
	cout<<"\t\t        :     :     \n";
	cout<<"\t\t1    "<<board[1][0]<<"  :  "<<board[1][1]<<"  :  "<<board[1][2]<<"  \n";
	cout<<"\t\t   _____:_____:_____\n";
	cout<<"\t\t        :     :     \n";
	cout<<"\t\t2    "<<board[2][0]<<"  :  "<<board[2][1]<<"  :  "<<board[2][2]<<"  \n";
	cout<<"\t\t        :     :     \n";
	
	
}

void makeMove(){
	
	int choice;
	
	// making choice
	if (turn == 'X'){
		cout<<"\n\nPlayer1 [X] turn ";	
	} 
	if (turn == 'O') {
		cout<<"\n\nPlayer2 [O] turn ";
	} 
	
	cin>>choice;
	
	// checking if choice is valid i.e between 1 and 9
	while(choice < 1 || choice > 9){
		cout<<"Number must be between 1 and 9!\nEnter valid choice:  ";
		if (turn == 'X'){
			cout<<"\n\nPlayer1 [X] turn ";	
		} 
		if (turn == 'O') {
			cout<<"\n\nPlayer2 [O] turn ";
		}
		cin>>choice;
	}
	
	// saving the choice for making move
	switch(choice){
		
		case 1: 
			row = 0; col = 0; break;
		case 2: 
			row = 0; col = 1; break;
		case 3: 
			row = 0; col = 2; break;
		case 4: 
			row = 1; col = 0; break;
		case 5: 
			row = 1; col = 1; break;
		case 6: 
			row = 1; col = 2; break;
		case 7: 
			row = 2; col = 0; break;
		case 8: 
			row = 2; col = 1; break;
		case 9: 
			row = 2; col = 2; break;
				
		default:
			cout<<"Invalid Choice"<<endl;
			break;
	}
	
	// Making move for 'X' on the board
	if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
		board[row][col] = 'X';
		turn = 'O';	
	} 
	// Making move for 'O' on the board
	else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O') {
		board[row][col] = 'O';
		turn = 'X';
	} 
	// Box is already filled 
	else {
		cout<<"BOX already filed!\nPlease try again:  ";
		makeMove();
	}
	
	printBoard();
	
}

bool gameStatus(){
	
	// checking for game wins by row and by column
	for (int i = 0; i < 3; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] ||
			board[0][i] == board[1][i]  && board[1][i] == board[2][i])
		return false;
	}
	
	// checking for game wins diagonally
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
			board[0][2] == board[1][1]  && board[1][1] == board[2][0]){
		return false;
	}
	//checking for empty boxes for if game ends or not 
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] != 'X' && board[i][j] != 'O'){
				return true;
			}
		}
	}
	
	// when all the above conditions are false we just draws the game
	draw = true;
	return false;
	
}


int main(){
	
	// Game starts 
	while (gameStatus()){
		printBoard();
		makeMove();	
	}
	
	// checking if 'O' wins 
	if (turn == 'X' && draw == false){
		cout<<"\nPlayer2 [O] Wins!! Congratulation \n";
	} 
	// checking if 'X' wins
	else if (turn == 'O' && draw == false){
		cout<<"\nPlayer1 [X] Wins!! Congratulation \n";
	} 
	// Game Draw
	else {
		cout<<"\nGAME DRAW!! Try again. \n";
	}
	
	return 0;
}
