#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
//Global variables
char map[11][11]={{'#','#','#','#','#','#','#','#','#','#','#'},
                  {'#','@','.','.','.','#','.','.','.','.','#'},
                  {'#','.','#','#','.','#','.','#','#','.','#'},
                  {'#','.','#','.','.','.','.','.','#','.','#'},
                  {'#','.','#','.','#','#','#','.','#','.','#'},
                  {'#','.','.','.','.',' ','.','.','.','.','#'},
                  {'#','.','#','.','#','#','#','.','#','.','#'},
                  {'#','.','#','.','.','.','.','.','#','.','#'},
                  {'#','.','#','#','.','#','.','#','#','.','#'},
                  {'#','.','.','.','.','#','.','.','.','@','#'},
                  {'#','#','#','#','#','#','#','#','#','#','#'}};
char pacman='C';
int pacmanx=6,pacmany=6,score=0;
bool gameover=false;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void layout(){
	
	system("cls");
	cout<<"\n \n \n \n"<<endl;
	for(int i=0;i<11;i++)
	{
		cout<<"\t \t \t \t";
		for(int j=0;j<11;j++)
		{
			if(i==pacmanx-1 && j==pacmany-1)
			cout<<pacman<<"    ";
			else
			cout<<map[i][j]<<"    ";	
        }
        cout<<"\n"<<endl;
	}
	cout<<"\n \t \t \t \t Score: "<<score<<" ";
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = UP;
            break;
        case 'd':
            dir = DOWN;
            break;
        case 'w':
            dir = LEFT;
            break;
        case 's':
            dir = RIGHT;
            break;
        }
    }
}

void banner(){
	cout<<"\n \t \t \t__________________________________________________________________"<<endl;
	cout<<" \t \t \t|\t \t \t PACMAN \t \t \t \t |"<<endl;
	cout<<" \t \t \t|\t \t \t Made by Wajahat Ali \t \t \t |"<<endl;
	cout<<" \t \t \t|________________________________________________________________|"<<endl;
	cout<<"\n \t \t \t \t > Win by either eating all coins from the map \t \t \t \t"<<endl;
	cout<<"\n \t \t \t \t \t \t   OR \t \t \t \t "<<endl;
	cout<<"\n \t \t \t \t         Gettin a score of 550 "<<endl;
	cout<<"\n     > Don't touch the monsters '@' or the walls '#', The monsters move randomly and lay coins so try to keep up ;)"<<endl;
	cout<<"\n \t \t \t \t \t Press Enter to start \t"<<endl;
}

void logic(){
	
	switch (dir)
    {
    case LEFT:
        pacmanx--;
        break;
    case RIGHT:
        pacmanx++;
        break;
    case UP:
        pacmany--;
        break;
    case DOWN:
        pacmany++;
        break;
    default:
        break;
    }
    
    if(score==550)
    {
    gameover=true; 
    }
    
    int oldarraypos[1][2];
    
    srand(time(NULL));
    int movement=rand()%4;
    
    switch (movement)
    {
    	case 1:
    		for(int i=0;i<11;i++)
    		{
    			for(int j=0;j<11;j++)
    			{
    				if(map[i][j]=='@')
    				{
    					oldarraypos[1][0]=i;
    					oldarraypos[1][1]=j;
    					if(map[i+1][j]!='#')
    					{
    						map[i+1][j]='@';
    						map[i][j]='.';
    						break;
						}
					}
				}
			}
    		break;
    		
    		case 2:
    			for(int i=0;i<11;i++)
    		{
    			for(int j=0;j<11;j++)
    			{
    				if(map[i][j]=='@')
    				{
    					oldarraypos[1][0]=i;
    					oldarraypos[1][1]=j;
    					if(map[i-1][j]!='#')
    					{
    						map[i-1][j]='@';
    						map[i][j]='.';
    						break;
						}
					}
				}
			}
    			break;
    			
    			case 3:
    				for(int i=0;i<11;i++)
    		{
    			for(int j=0;j<11;j++)
    			{
    				if(map[i][j]=='@')
    				{
    					oldarraypos[1][0]=i;
    					oldarraypos[1][1]=j;
    					if(map[i+1][j]!='#')
    					{
    						map[i+1][j]='@';
    						map[i][j]='.';
    						break;
						}
					}
				}
			}
    				break;
    				
    				case 4:
    					for(int i=0;i<11;i++)
    		{
    			for(int j=0;j<11;j++)
    			{
    				if(map[i][j]=='@')
    				{
    					oldarraypos[1][0]=i;
    					oldarraypos[1][1]=j;
    					if(map[i+1][j+1]!='#')
    					{
    						map[i-1][j]='@';
    						map[i][j]='.';
    						break;
						}
					}
				}
			}
    					break;
	}    

    for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			if(pacmanx-1==i && pacmany-1==j && map[i][j]=='@')
			{
			gameover=true;
			layout();
			break;
		    }
			
			else if(pacmanx-1==i && pacmany-1==j && map[i][j]=='.')
			{
				map[i][j]=' ';
				score+=10;
			}
			else if(pacmanx-1==i && pacmany-1==j && map[i][j]==' ')
			{
				continue;
			}
			else if(pacmanx-1==i && pacmany-1==j && map[i][j]=='#')
			{
				gameover=true;
				layout();
				break;
			}
        }
}
    
}
int main(){
	
	banner();
	cin.get();
	
	while(!gameover)
	{
	layout();
	Input();
	logic();
	Sleep(150);
    }
	
}
