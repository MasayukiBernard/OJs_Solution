#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Coordinate
{
public:
	int visited;
	int distance;
	Coordinate()
	{
		distance = 1000;
	}
} coord[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, -1, 0, 1};

	int x_Current = 1000, y_Current = 1000;
	int x_Target = 1000, y_Target = 1000;
	int i;
	string input;
	deque<int>X;
	deque<int>Y;
	int Quadrant;

	getline(cin, input);
	i = 0;
	int nN = count(input.begin(), input.end(), 'N'),
		nW = count(input.begin(), input.end(), 'W'),
		nE = count(input.begin(), input.end(), 'E'),
		nS = count(input.begin(), input.end(), 'S');

	x_Target = 1000 + nE - nW;
	y_Target = 1000 + nS - nN;

	if(x_Current == x_Target && y_Current == y_Target)
	{
		cout << 0;
		cin.get();
		return 0;
	}

	i = 0;
	//Initializing state of (0,0)
	coord[x_Current][y_Current].distance = 0;
	coord[x_Current][y_Current].visited = 1;
	//determining Quadrant
	if (x_Target - x_Current > 0 && y_Target - y_Current <  0)//1st
		Quadrant = 1;
	else if (x_Target - x_Current > 0 && y_Target - y_Current > 0)//2nd
		Quadrant = 2;
	else if(x_Target - x_Current < 0 && y_Target - y_Current >  0)//3rd
		Quadrant = 3;
	else if (x_Target - x_Current < 0 && y_Target - y_Current <  0)//4th
		Quadrant = 4;

	if (x_Target == 1000 && y_Target != 1000)
	{
		cout << (abs(y_Target-1000)) << endl;
		cin.get();
		return 0;
	}
	else if (y_Target == 1000 &&  x_Target != 1000)
	{
		cout << (abs(x_Target-1000)) << endl;
		cin.get();
		return 0;
	}

	while(x_Current != x_Target || y_Current != y_Target)
	{
		i = 0;
		while(i <= 3)
		{
			if(coord[x_Current + dx[i]][y_Current + dy[i]].visited == 1)
			{
				++i;
				continue;
			}
			if(Quadrant == 1)
			{
				if(x_Current + dx[i] < 1000 || y_Current + dy[i] > 1000)
				{
					++i;
					continue;
				}
			}
			else if(Quadrant == 2)
			{
				if(x_Current + dx[i] < 1000 || y_Current + dy[i] < 1000)
				{
					++i;
					continue;
				}
			}
			else if (Quadrant == 3)
			{
				if(x_Current + dx[i] > 1000 || y_Current + dy[i] < 1000)
				{
					++i;
					continue;
				}
			}
			else
			{
				if(x_Current + dx[i] > 1000 || y_Current + dy[i] > 1000)
				{
					++i;
					continue;
				}
			}
			
			X.push_back(x_Current + dx[i]);
			Y.push_back(y_Current + dy[i]);
			
			if(coord[x_Current + dx[i]][y_Current + dy[i]].distance > coord[x_Current][y_Current].distance + 1)
			{
				coord[x_Current+dx[i]][y_Current+dy[i]].distance = coord[x_Current][y_Current].distance + 1;
			}
			++i;
		}
		x_Current = X.front();
		y_Current = Y.front();
		X.pop_front();
		Y.pop_front();
	}
	cout << coord[x_Current][y_Current].distance << endl;
	cin.get();

	return 0;
}
