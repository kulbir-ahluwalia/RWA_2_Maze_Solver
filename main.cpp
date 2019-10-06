#include <iostream>
#include <fstream>
using namespace std;

char obstacle = '#';
//char path = ' ';
char maze[31][46] = {0};
char singleChar;
int start_x, start_y, goal_x, goal_y;
int count_n, count_s, count_e, count_w = 0;
int benchmark_count;

void PrintMaze();
void CheckObstacle();
bool CheckObstacle(int, int);
void TakeInput();
void CheckInput();
bool FindPath(int, int);
bool FindPathNew(int, int);


int main () {
	//Read the file contents and store in array
	ifstream inFile;
	//string line;
	inFile.open("/home/kulbir/Desktop/Robot_Programming/Assignments/maze.txt");
	for(int i = 0; i <= 31; i++)
	{
		for(int j = 0; j <= 46; j++)
		{
			inFile.get(singleChar);
			maze[i][j] = singleChar;
			//cout << singleChar;
		}
		
	}	
	
	//Take input from user the start and end positions
	TakeInput();
	
	//Check if the input co-ordinates have an obstacle on them
	CheckInput();
	
	//After confirming input and output, we assign S and G to the maze
	maze[start_x][start_y] = 'S';
	maze[goal_x][goal_y] = 'G';
	
	//Print Maze with the start and end locations
	cout << "The maze with the start and end locations is given as follows:- " << endl;
	PrintMaze();
	
	//Function for path finding
	FindPath(start_x , start_y);	
	
	maze[start_x][start_y] = 'S';	//Re-mark the start position
	PrintMaze();
  return 0;
}

void PrintMaze()
{
	for(int x = 0; x <= 31; x++)
	{
		for(int y = 0; y <= 45; y++)
		{
			cout << maze[x][y];
		}
		cout << " " << endl;
	}
}

void CheckObstacle()
{
	for(int i = 0; i <= 31; i++)
	{
		for(int j = 0; j <= 45; j++)
		{
			if(maze[i][j] == obstacle)
			{
				cout << "obstacle at: " << i << " " << j << endl;
			}
		}
	}
}

bool CheckObstacle(int x, int y)
{
	if(maze[x][y] == '#')
		return true;
}

void TakeInput()
{
	cout << "Enter the robot start positions: x,y" << endl;
	cin >> start_x >> start_y;
	
	if(start_x > 46 || start_x < 0)
	{
		cout << "The start position is out of the maze. Please re-enter the position: " << endl;
		while(start_x > 46 || start_x < 0)
		{
			cout << "Enter the x co-ordinate of robot start position: " << endl;
			cin >> start_x;
		}			
	}	
	if(start_y > 32 || start_y < 0)
	{
		cout << "The start position is out of the maze. Please re-enter the position: " << endl;
		while(start_y > 32 || start_y < 0)
		{
			cout << "Enter the y co-ordinate of robot start position: " << endl;
			cin >> start_y;
		}			
	}	
	
	cout << "Enter the desired position of the robot: x,y" << endl;
	cin >> goal_x >> goal_y;
	if(goal_x > 32 || goal_x < 0)
	{
		cout << "The desired position is out of the maze. Please re-enter the position: " << endl;
		while(goal_x > 32 || goal_x < 0)
		{
			cout << "Enter the x co-ordinate of robot desired position: " << endl;
			cin >> goal_x;
		}			
	}	
	if(goal_y > 47 || goal_y < 0)
	{
		cout << "The desired position is out of the maze. Please re-enter the position: " << endl;
		while(goal_y > 47 || goal_y < 0)
		{
			cout << "Enter the y co-ordinate of robot desired position: " << endl;
			cin >> goal_y;
		}			
	}		
	cout << "The start position is " << start_x << ", " << start_y << endl;
	cout << "The goal position is " << goal_x << ", " << goal_y << endl;
}

void CheckInput()
{
	if(maze[start_x][start_y] == obstacle )
	{
		cout << "this is an obstacle, place the start somewhere else" << endl;
		TakeInput();
	}
	if(maze[goal_x][goal_y] == obstacle)
	{
		cout << "This is an obstacle, place the goal somewhere else" << endl;
		TakeInput();
	}	
}

bool FindPath(int x, int y)
{
	if((x < 0 || x > 32) || (y < 0 || y > 47))
		return false;	
	
	if(maze[x][y] == 'G')
		return true;	
	/*if(maze[x][y] == '+')
		return false;*/
	if(maze[x][y] == '#')
		return false;		
	
	maze[x][y] = '+' ;//Marking as part of solution
	/*if((goal_y - start_y) > (goal_x - start_x))
	{
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
		maze[x][y] = ' ';
		return false;	
	}	
	else if((goal_y - start_y) < (goal_x - start_x))
	{
		if(FindPath(x+1, y))
		{
			
			return true;	
		}
		if(FindPath(x, y+1))
		{
			
			return true;	
		}
		if(FindPath(x-1, y))
		{
			
			return true;	
		}
		if(FindPath(x, y-1))
		{
			
			return true;	
		}	
		maze[x][y] = ' ';
		return false;	
	}
	else
	{
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
		maze[x][y] = ' ';
		return false;
	}*/
	
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
	maze[x][y] = ' ';
	return false;
}