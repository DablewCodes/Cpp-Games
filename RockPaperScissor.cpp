#include<iostream>
#include<ctime>
#include<cstdlib>
int check(int &, int &);
int input(int &);
void layout();
using namespace std;
int main(){

	layout();
	
	int userchoice,com,catcher=2;
	
	string arr[3]={"Rock","Paper","Scissor"};

	srand(time(0));
	com=rand() % 3;
		
		input(userchoice);
		
		cout<<"\n You chose "<<arr[userchoice-1]<<" & the computer chose "<<arr[com-1]<<endl;
	    
		catcher=check(userchoice, com);
    
    switch(catcher){
    	
    	case 1:
    		cout<<"\n Congratulations, you won \n";
    		system("pause");
    	    break;
    	    
    	    case 0:
    	    	cout<<"\n The computer won \n";
    	    	system("pause");
    	    	break;
    	    	
    	    	case 2:
    	    		cout<<"\n Its a draw \n";
    	    		system("pause");
    	    		break;
	}
}

void layout(){
	cout<<"                  **************************************************************"<<endl;
	cout<<"                  *                       Rock, Paper, Scissor                 *"<<endl;
	cout<<"                  **************************************************************"<<endl;
	cout<<"\n         You are playing against computer, 1 is for Rock, 2 is for Paper & 3 is for Scissor"<<endl;
}

int input(int &userchoice){
		
	cout<<"\n                  What do you choose!"<<endl;
	cin>>userchoice;
	
}

int check(int &userchoice, int &com){
	
	if(userchoice==1 && com==3)
	return 1;
	
	else if(userchoice==2 && com==1)
	return 1;
	
	else if(userchoice==3 && com==2)
	return 1;
	
	if(userchoice==3 && com==1)
	return 0;
	
	else if(userchoice==1 && com==2)
	return 0;
	
	else if(userchoice==2 && com==3)
	return 0;
	
	else return 2;
}
