#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<ctime>
	
char map[50][50];
int i, j;
	using namespace std;
	
	
	void resizeConsole(int width, int height)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width, height, TRUE);
	}


	void textcolor(int x)
	{
		HANDLE mau;
		mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}


	void gotoxy(int x, int y)
	{
		HANDLE hConsoleOutput;
		COORD Cursor_an_Pos = { x - 1,y - 1 };
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
	}
	
	
	void XoaManHinh()
	{
		HANDLE hOut;
		COORD Position;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}

	void veduongdua1()

	{ 
		for (i = 0; i < 40 ; i++)
		if(i%2==0)
			{
			map[i][19]= '|';
			}
			{
				for(j = 1; j < 40 && j!=19 ; j++)
					{
						map[i][j] = ' ';
					}
			}
		}
		
	void veduongdua2()

	{ 
		for (i = 0; i < 40 ; i++)
		if(i%2!=0)
			{
			map[i][19]= '|';
			}
			{
				for(j = 1; j < 40 && j!=19 ; j++)
					{
						map[i][j] = ' ';
					}
			}
		}
	void induongdua()

		{
			for (i = 0; i < 40; i++)
			{
				cout << "\t\t\t";
				for (j = 0; j < 40; j++)
				{
					if (j == 0 || j == 39)
					{
						textcolor(191);
						cout << map[i][j];
						textcolor(7);
					}
					else if(j==19)
						{
							cout<<map[i][j];
							map[i][j]=' ';
						}
					else if(map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#')
						{
							textcolor(14);
							cout << map[i][j];
							textcolor(7);
						}
					else if(map[i][j]=='*')
						{
							//map[i][j]= ' ';
							textcolor(200);
							cout<<map[i][j];
							textcolor(7);
						}
					else {
							cout << map[i][j];
						 }
					}
				cout << endl;
			}
		}
	void vexeplayer(int x, int y)
		{
			map[x][y]='X';
			map[x][y-1]='#';
			map[x][y+1]='#';
			map[x-1][y-1]='@';
			map[x+1][y-1]='@';
			map[x-1][y+1]='@';
			map[x+1][y+1]='@';
		}
	void vexecomputer(int x, int y)
		{
			map[x][y]='*';
			map[x][y-1]='*';
			map[x][y+1]='*';
			map[x-1][y-1]='*';
			map[x+1][y-1]='*';
			map[x-1][y+1]='*';
			map[x+1][y+1]='*';
		}
		
			void xoaxecomputer(int x, int y)
	{
			map[x][y]=' ';
			map[x][y-1]=' ';
			map[x][y+1]=' ';
			map[x-1][y-1]=' ';
			map[x+1][y-1]=' ';
			map[x-1][y+1]=' ';
			map[x+1][y+1]=' ';
	}

	void dichuyenxe(int &x, int &y)
		{
			if(GetAsyncKeyState(VK_LEFT))
				{
					if(y>2)
					{
						if(map[x][y]=='*' || map[x][y-1]=='*' || map[x][y+1]=='*' || map[x-1][y-1]=='*' || map[x+1][y-1]=='*' || map[x-1][y+1]=='*' || map[x+1][y+1]=='*' )
								{
									system("pause");
								}
							map[x][y]=' ';
							
							map[x][y-1]=' ';
							map[x][y+1]=' ';
							map[x-1][y-1]=' ';
							map[x+1][y-1]=' ';
							map[x-1][y+1]=' ';
							map[x+1][y+1]=' ';
							y--;
							vexeplayer(x, y);
					}
				}
			else if(GetAsyncKeyState(VK_RIGHT))
				{
					if(y<=36)
					{
						if(map[x][y]=='*' || map[x][y-1]=='*' || map[x][y+1]=='*' || map[x-1][y-1]=='*' || map[x+1][y-1]=='*' || map[x-1][y+1]=='*' || map[x+1][y+1]=='*' )
								{
									system("pause");
								}
							map[x][y]=' ';
							map[x][y-1]=' ';
							map[x][y+1]=' ';
							map[x-1][y-1]=' ';
							map[x+1][y-1]=' ';
							map[x-1][y+1]=' ';
							map[x+1][y+1]=' ';
							y++;
							vexeplayer(x, y);
					}
				}
				
			else if(GetAsyncKeyState(VK_UP))
			{
				if(x>1)
				{
					if(map[x][y]=='*' || map[x][y-1]=='*' || map[x][y+1]=='*' || map[x-1][y-1]=='*' || map[x+1][y-1]=='*' || map[x-1][y+1]=='*' || map[x+1][y+1]=='*' )
							{
								system("pause");
							}
						map[x][y]=' ';
						map[x][y-1]=' ';
						map[x][y+1]=' ';
						map[x-1][y-1]=' ';
						map[x+1][y-1]=' ';
						map[x-1][y+1]=' ';
						map[x+1][y+1]=' ';
						x--;
						vexeplayer(x, y);
				}
			}
		
			else if(GetAsyncKeyState(VK_DOWN))
				
				{
					if(x<=37)
					{
						if(map[x][y]=='*' || map[x][y-1]=='*' || map[x][y+1]=='*' || map[x-1][y-1]=='*' || map[x+1][y-1]=='*' || map[x-1][y+1]=='*' || map[x+1][y+1]=='*' )
								{
									system("pause");
								}
							map[x][y]=' ';
							map[x][y-1]=' ';
							map[x][y+1]=' ';
							map[x-1][y-1]=' ';
							map[x+1][y-1]=' ';
							map[x-1][y+1]=' ';
							map[x+1][y+1]=' ';
							x++;
							vexeplayer(x, y);
					}
				}
		}
	
	
int main() 
	{
		resizeConsole(1000, 800);
		
		char *s= "Points: ";
		int dem=0;
		int x=38, y=21;
		int x1=2, y1=5;
		int x2=3, y2=15;
		int x3=4, y3=28;
		int x4=5, y4=34;
		int x5=6, y5=23;
		int a=0;
		
			gotoxy(80, 10);
			cout<<s;
			gotoxy(88, 10);
			cout<<dem<<endl;
			
		while(true)
			{
				a++;
				if(a%2!=0)
					{
						veduongdua1();
					}
				else 
					{
						veduongdua2();	
					}		
						
				vexeplayer(x, y);
				
				vexecomputer(x1, y1);
				
				vexecomputer(x2, y2);
				
				vexecomputer(x3, y3);
				
				vexecomputer(x4, y4);
				
				vexecomputer(x5, y5);
				
				XoaManHinh();
				
				induongdua();
				
				dichuyenxe(x, y);
				
				Sleep(0);
				
				if(a>=30)
					{
						a=0;
					}
					
			if(map[x][y]=='*' || map[x][y-1]=='*' || map[x][y+1]=='*' || map[x-1][y-1]=='*' || map[x+1][y-1]=='*' || map[x-1][y+1]=='*' || map[x+1][y+1]=='*' )
				{
					system("pause");
				}
			
			xoaxecomputer(x1, y1);
				x1++;
				if(x1==39)
					{
						x1=2;
					}
			xoaxecomputer(x2,y2);
					
				x2++;
				if(x2==39)
					{
						x2=3;
					}
			
			xoaxecomputer(x3,y3);
					
				x3++;
				if(x3==39)
					{
						x3=4;
						y3 = 2 + rand() % 36;
					}
					
			xoaxecomputer(x4, y4);
					
				x4++;
				if(x4==39)
					{
						x4=4;
						y4 = 2 + rand() % 36;
					}	
					
			xoaxecomputer(x5, y5);
					
				x5++;
				if(x5==39)
					{
						x5=6;
						y5 = 2 + rand() % 36;
					}	
		
					if(x+1==x1 || x+1==x2 || x1+1==x3 || x1+1==x4 || x1+1==x5)
						{
							XoaManHinh();
							dem+=5;
							gotoxy(88, 10);
							cout<<dem;
							Sleep(50);	
						}
			}
		
	system("pause");
	return 0;
	}
	
