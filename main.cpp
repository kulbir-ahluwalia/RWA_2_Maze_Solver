#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <bits/stdc++.h>
//using namespace std;

char obstacle = '#';
char maze[31][47] = {0};
char singleChar;
int start_x, start_y, goal_x, goal_y = 0 ;
std::string str_start_x {}, str_start_y {}, str_goal_x {}, str_goal_y {};
int goal_flag = 0;

bool IntegerInput(std::string s);
void PrintMaze();
void TakeInput();
void CheckInput(int, int, int, int);
bool FindPath(int, int);
void ClearMarker();

int main () {
	std::ifstream MazeFile;
	MazeFile.open("/home/shubham/Desktop/A2/Assignment/maze.txt");
	for(int i = 0; i <= 31; i++)
	{
		for(int j = 0; j <= 46; j++)
		{
			MazeFile.get(singleChar);
			maze[i][j] = singleChar;
		}		
	}
	MazeFile.close();	
	TakeInput();	
	CheckInput(start_x, start_y, goal_x, goal_y);
	maze[start_x][start_y] = 'S';
	maze[goal_x][goal_y] = 'G';	
	std::cout << "The maze with the start and end locations is given as follows:- " << std::endl;
	PrintMaze();
	FindPath(start_x , start_y);
	ClearMarker();
	bool result = FindPath(start_x , start_y);
	if(result == false && goal_flag != 1)
	{
		std::cout << "Partial path found" << std::endl;
	}
	maze[start_x][start_y] = 'S';	
	PrintMaze();
	return 0;	
}

bool IntegerInput(std::string s)
{
	const int length = s.size();
	for(int z = 0; z < length; ++z)
	{
		if(!isdigit(s[z]))
			return false;
	}
	return true;
}

void PrintMaze()
{
	for(int x = 0; x <= 31; x++)
	{
		for(int y = 0; y <= 45; y++)
		{
			std::cout << maze[x][y];
		}
		std::cout << " " << std::endl;
	}
}

void TakeInput()
{
	std::cout << "Enter the robot start positions: x (0-45) and press Enter " << std::endl;
	std::cin >> str_start_x;
	if(IntegerInput(str_start_x) == false)
	{
		while(IntegerInput(str_start_x) == false)
		{
			std::cout << "Invalid Input " << std::endl;
			std::cin >> str_start_x;
		}
	}
	start_x = stoi(str_start_x);
	std::cout << "Enter the robot start positions: y (0-30) and press Enter " << std::endl;
	std::cin >> str_start_y;
	if(IntegerInput(str_start_y) == false)
	{
		while(IntegerInput(str_start_y) == false)
		{
			std::cout << "Invalid Input " << std::endl;
			std::cin >> str_start_y;
		}
	}
	start_y = stoi(str_start_y);
	
	if(start_x >= 46 || start_x < 0)
	{
		std::cout << "The x co-ordinate of the start position is out of the maze. Please re-enter the position: " << std::endl;
		while(start_x >= 46 || start_x < 0)
		{
			std::cout << "Enter the x co-ordinate of robot start position: " << std::endl;
			std::cin >> start_x;
		}			
	}	
	if(start_y >= 31 || start_y < 0)
	{
		std::cout << "The y co-ordinate of the start position is out of the maze. Please re-enter the position: " << std::endl;
		while(start_y >= 31 || start_y < 0)
		{
			std::cout << "Enter the y co-ordinate of robot start position: " << std::endl;
			std::cin >> start_y;
		}			
	}	
	
	std::cout << "Enter the goal position of the robot: x(0-45) and press Enter" << std::endl;
	std::cin >> str_goal_x;
	if(IntegerInput(str_goal_x) == false)
	{
		while(IntegerInput(str_goal_x) == false)
		{
			std::cout << "Invalid Input " << std::endl;
			std::cin >> str_goal_x;
		}
	}
	goal_x = stoi(str_goal_x);
	std::cout << "Enter the robot goal positions: y (0-30) and press Enter " << std::endl;
	std::cin >> str_goal_y;
	if(IntegerInput(str_goal_y) == false)
	{
		while(IntegerInput(str_goal_y) == false)
		{
			std::cout << "Invalid Input " << std::endl;
			std::cin >> str_goal_y;
		}
	}
	goal_y = stoi(str_goal_y);
	
	if(goal_x >= 46 || goal_x < 0)
	{
		std::cout << "The x co-ordinate of the desired position is out of the maze. Please re-enter the position: " << std::endl;
		while(goal_x >= 46 || goal_x < 0)
		{
			std::cout << "Enter the x co-ordinate of robot desired position: " << std::endl;
			std::cin >> goal_x;
		}			
	}	
	if(goal_y >= 31 || goal_y < 0)
	{
		std::cout << "The y co-ordinate of the desired position is out of the maze. Please re-enter the position: " << std::endl;
		while(goal_y >= 31 || goal_y < 0)
		{
			std::cout << "Enter the y co-ordinate of robot desired position: " << std::endl;
			std::cin >> goal_y;
		}			
	}	
	std::cout << "The start position is " << start_x << ", " << start_y << std::endl;
	std::cout << "The goal position is " << goal_x << ", " << goal_y << std::endl;
	int t1 = start_y;
	int t2 = goal_y;
	goal_y = goal_x;
	start_y = start_x;
	start_x = 30 - t1;
	goal_x = 30 - t2;
}

void CheckInput(int x, int y, int x1, int y1)
{
	if(maze[x][y] == '#' )
	{		
		while(maze[x][y] == '#')
		{
			std::cout << "This is an obstacle, place the start somewhere else" << std::endl;
			TakeInput();
		}		
	}
	if(maze[x1][y1] == obstacle)
	{
		
		while(maze[x1][y1] == obstacle)
		{
			std::cout << "This is an obstacle, place the goal somewhere else" << std::endl;
			TakeInput();
		}
	}
	if(x == x1 && y == y1)
	{
		while(x == x1 && y == y1)
		{
			std::cout << "The start and goal positions entered are the same" << std::endl;
			TakeInput();
		}
	}
}

bool FindPath(int x, int y)
{
	if((x < 0 || x > 30) || (y < 0 || y > 45))
		return false;	
	if(maze[x][y] == 'G')
	{
		goal_flag = 1;
		std::cout << "Complete Path Found " << std::endl;
		return true;
	}			
	if(maze[x][y] == '+')
		return false;
	if(maze[x][y] == '#')
		return false;
	if(maze[x][y] == 'x')
		return false;

	maze[x][y] = '+' ;
	if(FindPath(x-1, y))	
	{
		return true;	
	}
	if(FindPath(x, y+1))
	{
		return true;	
	}
	if(FindPath(x+1, y))
	{
		return true;	
	}
	if(FindPath(x, y-1))
	{
		return true;	
	}	
	maze[x][y] = 'x';
	return false;
}

void ClearMarker()
{
	for(int i = 0; i <= 31; i++)
	{
		for(int j = 0; j < 45; j++)
		{
			if(maze[i][j] == 'x')
				maze[i][j] = ' ';
		}
	}
}