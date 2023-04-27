#include<iostream>
#include<ctime>       //Roll Nos//
#include<cstdlib>     //Ashan 20-CS-80
#include<fstream>     //Wajahat Ali 20-CS-102
#include<Windows.h>   //Usama 20-CS-36
using namespace std;  //Arkam Ahmad 19-CS-35
                      
//Globals Variable//  
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
//File writer//
fstream file;
//Functions//
//Function for the board layout//
void board();
//Function for checking a win/draw scenario//
int checkwinstatus();
//Function for writing the outcome//
void writer(int &);

//Main function//
int main(){	
	
	srand(time(0));
	char mark;
	int choice,j,playernum=1,com;
	
    system("cls");
	board();
	cout<<"\n   Enter 1 if you want to play against another player or enter 0 if you want the computer to simulate player 2"<<endl;
	cin>>com;
	
	do
	{ 
		if(com==1)
		{
		system("cls");	
		board();
		playernum=((playernum%2)!=0)?1:2;
		bool okinput=false;
		
		for(int i=0;!okinput;i++)
		{
		cout<<"\n               Player "<<playernum<<", enter the number where you want to place your mark"<<endl;
		cin>>choice;
		if(choice<1 || choice>9)
		{
			system("cls");
			board();
			cout<<"            Invalid move"<<endl;
			continue;
		}else{
			okinput=true;
			break;
		}
	   }
		mark=(playernum==1)?'X':'O';
		
	    }else{
	    		
		playernum=((playernum%2)!=0)?1:2;
		
		if(playernum==1)
		{
			system("cls");
			board();
			bool okinput=false;
			for(int i=0;!okinput;i++)
			{
		cout<<"\n               Player "<<playernum<<", enter the number where you want to place your mark"<<endl;
		cin>>choice;
		if(choice<1 || choice>9)
		{
			system("cls");
			board();
			cout<<"            Invalid move"<<endl;
			continue;
		}else{
			okinput=true;
			break;
		}
	    }
	    }else{
	    	
			char numbers[9]={'1','2','3','4','5','6','7','8','9'};
	    	
	    	for(int i=0;i<9;i++)
	    	{
			choice=rand()%9;
			if(square[choice]==numbers[i])
			{
			system("cls");
			break;
		    }
			else
			continue;
		    }
		}
		
		mark=(playernum==1)?'X':'O';
		}
		
		if(choice==1 && square[1]=='1')
		{
			square[1]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==2 && square[2]=='2')
		{
			square[2]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==3 && square[3]=='3')
		{
			square[3]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==4 && square[4]=='4')
		{
			square[4]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==5 && square[5]=='5')
		{
			square[5]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==6 && square[6]=='6')
		{
			square[6]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==7 && square[7]=='7')
		{
			square[7]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==8 && square[8]=='8')
		{
			square[8]=mark;
			 j=checkwinstatus();
		  playernum++;
		}else if(choice==9 && square[9]=='9')
		{
			square[9]=mark; 
			j=checkwinstatus();
		  playernum++;
		}
		
	}while(j==1);
	
	if(j==2)
	{
		system("cls");
		board();
		cout<<"\n                Player "<<(playernum-1)<<" has won the game, Congratulations!"<<endl;
		writer(playernum);
		system("pause");
	}else if(j==0)
	{
		system("cls");
		board();
		cout<<"\n                 The game has ended in a draw"<<endl;
		writer(playernum);
		system("pause");
	}
}


//Function to check the win condition//
//'2' return value means a win scenario//
//'1' reurn value means game is going on//
//'0' return value means game has ended in a draw// 

int checkwinstatus(){
	if(square[1]==square[2] && square[2]==square[3])
	{
	return 2;
	}else if(square[3]==square[6] && square[6]==square[9])
	{
		return 2;
	}else if(square[9]==square[8] && square[8]==square[7])
	{
		return 2;
	}else if(square[7]==square[4] && square[4]==square[1]) 
	{ 
		return 2;
	}else if(square[1]==square[5] && square[5]==square[9]) //Conditions to check same mark squares of 3
	{
		return 2;
	}else if(square[3]==square[5] && square[5]==square[7])
	{
		return 2;
	}else if(square[2]==square[5] && square[5]==square[8])
	{
		return 2;
	}else if(square[4]==square[5] && square[5]==square[6])
	{
		return 2;
	}else if(square[1]!='1' && square[2]!='2' && square[3]!='3' &&  //All boxes filled/Draw scenario checker
	         square[4]!='4' && square[5]!='5' && square[6]!='6' &&
	         square[7]!='7' && square[8]!='8' && square[9]!='9')
	         {
			 return 0;
			 }
			 else{
			 	return 1;
			 }	
    cin.get();
}


//Function to show the board layout// 

void board(){
	Sleep(40);
  cout<<" \n";
  for(int i=1;i<10;i++)  //Box shape using nested loops
  {
  	cout<<" \t \t ";
	  for(int j=1;j<50;j++)
  	{
		  if(i==9 || i==1 || j==1 || j==49){
               if(i!=5 && j!=19){
  			cout<<"*";
  		}
		  }else{
		  	cout<<" ";
		  }
		  if(i==5 && j==1){
		  	cout<<"*                 TIC TAC TOE \t \t         *";	    
	}
	  }
	  cout<<endl;
  }
  cout<<"\n \t     Player 1 has the 'X' symbol and Player 2/Computer has the 'O' symbol"<<endl;
  cout<<"\n                                      |     |             "<<endl;
  cout<<"                                   "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<endl;
  cout<<"                              ________|_____|________  "<<endl;
  cout<<"                                      |     |             "<<endl;
  cout<<"                                   "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<endl;
  cout<<"                              ________|_____|________  "<<endl;
  cout<<"                                      |     |             "<<endl;
  cout<<"                                   "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<endl;
  cout<<"                                      |     | "<<endl;
}

//Function for writing the statistics//
void writer(int &playernum){
	
	int n,nu;
	playernum-=1;

    file.open("results.txt");
    
	file>>n>>nu;
	
	if(playernum==1)
	n+=1;
	else
	nu+=1;
	
	cout<<"\n           Statistics"<<endl;
	cout<<"\n    Player 1 wins: "<<n<<" | Player 2 wins: "<<nu<<"\n"<<endl;
	
	ofstream resultwriter;
	
	resultwriter.open("results.txt");
	
	resultwriter<<n<<' '<<nu<<endl;
}
