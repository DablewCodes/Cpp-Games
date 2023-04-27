#include <iostream>
#include <cstring>
using namespace std;
bool gameover;
char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
int points[] = {2,4,3,5,7,1,5,3,6,7,3,2,1,9,4};
string wordentered;
int score=0;
string validwords[] = {"bach","beach","ache","face","chef","cafe","each","bead","deaf","fade","head","cab","bad","bed","fed","bae"};
void setup(){
	gameover = false;
}
void layout(){
	system("cls");
	cout<<"\n    Welcome to the Word Game, Make a word out of the following letters, each letter has specific points assigned to it"<<endl;
	cout<<"\n \t \t \t";
	for(int i = 0 ; i < 15 ; i++)
	{
		cout<<letters[i]<<"   ";
	}
	cout<<endl;
}
void input(){
	cout<<"\n \t \t \t Enter the word you formed"<<endl;
	while(1)
	{
	cin>>wordentered;
	int length = wordentered.length();
	if(length < 3 || length > 15)
	{
		cout<<"\n \t \t The entered word should must have 3 to 15 letters"<<endl;
		continue;
	}else{
		break;
	}
}
}
void logic(){

	
	int lengthe = wordentered.length(); //making char array of entered string
	char wordenteredarray[lengthe+1];
	strcpy(wordenteredarray, wordentered.c_str());
	
		
	for(int i = 0 ; i < lengthe ; i++) //Checking if it contains numbers
	{
		if(wordenteredarray[i] >= 'a' && wordenteredarray[i] <= 'z')
		{
			continue;
		}else{
			cout<<"\t \n \n The entered word has a number, game over! your score is 0"<<endl;
			gameover = true;
			return;
		}
	}
	
	for(int i = 0 ; i < lengthe ; i++)  //Checking if letters exist in original array
	{
		bool found = false;
		for(int j = 0 ; j < 15 ; j++)
		{
			if(wordenteredarray[i] == letters[j])
			{
				found = true;
				score += points[j];
			}
		}
		if(found)
		{
		continue;
	}
		else
		{
			cout<<"\n \t \t Then entered word contains letter which is not present in the assigned letters, game over! your score is 0"<<endl;
			gameover = true;
			return;
	}
	}
	
	for(int i = 0 ; i < 16 ; i ++ )
	{
		if(validwords[i] == wordentered)
		{
			cout<<"\n \t \t You made a correct word! Your score is "<<score+50<<endl;
			return;
		}
	}
	
	cout<<"\n \t \t The word you entered is not a proper word, game over! You score is 0"<<endl;
	
}
int main(){
	setup();
	char choice;
	do
	{
	layout();
	input();
	logic();
	cout<<"\n \t \t \t Do you want to play again? Enter 'y' for yes and 'n' for no"<<endl;	
	cin>>choice;
	if(choice == 'y' || choice =='Y')
	{
		gameover = false;
	continue;
    }
	else
	break;
	}while(!gameover);
}
