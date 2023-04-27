#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;
char blank[6]={'_','_','_','_','_','_'};
void layout();
int check(char &, int &, char arr[][6]);
int main(){
	
	char inp;
	int catcher=1,lives=8;
	
	char words[6][6] { 
    {'b','a','t','m','a','n'},
    {'k','i','l','l','e','r'},
    {'b','e','a','u','t','y'},
    {'b','a','n','a','n','a'},
	{'t','a','x','i','l','a'},
    {'m','o','b','i','l','e'},
    };

	srand(time(0));
	int num=rand() % 6 + 1;
	
	while(blank[0]=='_' || blank[1]=='_' || blank[2]=='_' || blank[3]=='_' || blank[4]=='_' || blank[5]=='_' )
	{
	layout();
	
	cout<<"Enter a guess in Lower case, You have "<<lives<<" lives left \n"<<endl;
	cin>>inp;
	
	catcher=check(inp,num, words);
	
	if(catcher==0)
	{
    cout<<"\nWrong guess, 1 life depleted"<<endl;
    lives--;
    Sleep(1000);
   }
   if(lives==0)
   break;
   }
    
	layout();
	
	switch(lives)
	{
		case 0:
			cout<<" You ran out of lives, the correct word was ";
			for(int k=0;k<=5;k++)
			{
				cout<<words[num-1][k];
			}
			cout<<endl;
			system("pause");
			break;
			
			default:
	        cout<<" Congrats, you won!"<<endl;
	        system("pause");
	        break;
    }
}

//Checking function//

int check(char &inp, int &num, char arr[][6]){
	
	int j=0;
	
	for(int i=0;i<6;i++)
	{
		
		if(inp==arr[num-1][i])
		{
		blank[i]=arr[num-1][i];
		j=1;
	    }
		else
		{
			continue;
		}
	}
	
	return j;
}

//Layout function//

void layout()
{
	
	system("cls");
	  cout<<"\n"<<endl;
      cout<<"\n"<<endl;
      cout<<"\n"<<endl;
      cout<<"\n"<<endl;
      cout<<"          ******************************************************************************************************************************"<<endl;
	  cout<<"          *                                                 Hangman                                                                    *"<<endl;
	  cout<<"          *                                                                                                                            * "<<endl;
	  cout<<"          *               Guess the word correctly. Each wrong guess deplets one life, Guess the correct word before you die!          *"<<endl;
	  cout<<"          ******************************************************************************************************************************"<<endl;
	  cout<<"\n"<<endl;
      cout<<"\n"<<endl;
      cout<<"                                                   ";
      
	  for(int i=0;i<=5;i++)
      {
        cout<<" "<<blank[i];
	  }
	  cout<<"\n";
      cout<<"\n";
      cout<<"\n";
}
