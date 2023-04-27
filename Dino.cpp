#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const int width=25;
const int height=8;
int dinox,x;
char dinoy[2];
int treey,score;
bool gameover;
void setup(){
	cout<<"\n \t \t \t__________________________________________________________________"<<endl;
	cout<<" \t \t \t|\t \t \t Chrome Dino Game \t \t \t |"<<endl;
	cout<<" \t \t \t|\t \t \t Made by Wajahat Ali \t \t \t |"<<endl;
	cout<<" \t \t \t|________________________________________________________________|"<<endl;
	cout<<"\n \t \t \t \t > Press SpaceBar to jump \t \t \t \t"<<endl;
	cout<<"\t \t \t \t Press enter to start"<<endl;
	gameover=false;
	dinox=6;
	dinoy[0]=3;
	dinoy[1]=3;
	treey=25;
	x=0,score=0;
	cin.get();
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    bool showFlag=false;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void layout(){
	system("cls");
	cout<<"\n \n \n \n"<<endl;
	for(int i=0;i<height;i++)
	{ cout<<"\t \t \t \t";
		for(int j=0;j<width;j++)
		{
			if((i==6 && j==treey) || (i==5 && j==treey)){
				cout<<"$"<<" ";
			}
			else if(i==height-1)
			{
		        cout<<"-"<<"-";
			}else if(i==dinox && j==dinoy[0] || i==dinox-1 && j==dinoy[1])
			{
				cout<<"O"<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<"\n \t \t \t \t Score: "<<score<<endl;
}
void logic(){
	if(_kbhit())
	{
		if(dinox>2 && x<4)
		{
		dinox-=1;
		x++;
	    }
	}
	if(x==4){
		dinox+=1;
	    if(dinox==6)
		{
			x=0;
			while(kbhit()) getch();
		}
	}
	treey-=1.5;
	
	if((dinoy[0]==treey && (dinox==6 || dinox==5)) || (dinoy[1]==treey && (dinox==6 || dinox==5)))
	{
		layout();
		gameover=true;
	}
	if(treey<2)
	{
	treey=25;
	score+=10;
}
}
int main(){
	setup();
	while(!gameover)
	{
	layout();
	logic();
	Sleep(28);
    }
}
