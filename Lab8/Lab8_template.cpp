#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#define INFINITY 10000
using namespace std;

vector<vector<char>> GetMazeInfo(fstream& file, pair<int, int>& StartPos, pair<int, int>& EndPos) {
	// Create a 2D vector to store the maze information.
	vector<vector<char>> Maze;
	int mazeRowSize, mazeColSize;
	file >> mazeRowSize >> mazeColSize;

	for (int i = 0; i < mazeRowSize; i++) {
		vector<char> row;
		for (int j = 0; j < mazeColSize; j++) {
			char temp;
			file >> temp;

			row.push_back(temp);
			if (temp == 'S') {
				StartPos.first = i;
				StartPos.second = j;
			}
			if (temp == 'E') {
				EndPos.first = i;
				EndPos.second = j;
			}
		}
		Maze.push_back(row);
	}
	return Maze;
}

vector<vector<int>> DistanceInfo(const vector<vector<char>>& Maze) {
	// Create a 2D vector to store the distance between each cell and the starting point.
	// If the cell is empty, initialize the distance to INFINITY, otherwise set the distance to -1.
	vector<int> row(Maze[0].size(), 0);
	vector<vector<int>> res(Maze.size(), row);

	for (int i = 0; i < Maze.size(); i++) {
		for (int j = 0; j < Maze[0].size(); j++) {
			if (Maze[i][j] == '#')
				res[i][j] = -1;
			else
				res[i][j] = INFINITY;
		}
	}
	return res;
}

void PrintResult(vector<vector<int>>& m, vector<vector<char>>& Maze, pair<int, int> EndPos) {

	int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int distance = m[EndPos.first][EndPos.second];
	vector<pair<int, int>> path;

    //////////////////////////////////////
	// TODO: 
	// Find the path from end position to start position, and store it in "vector<pair<int, int>> path".
	path.push_back(EndPos);
	pair<int, int> temp;
	queue<pair<int, int>> Q;
	Q.push(EndPos);
	for(int j=0;j<m[EndPos.first][EndPos.second];j++){
		for(int i=0;i<4;i++){
			temp.first=Q.front().first+move[i][0];
			temp.second=Q.front().second+move[i][1];
			if(temp.first>=0&&temp.first<m.size()&&temp.second>=0&&temp.second<m[0].size()){
				if(m[temp.first][temp.second]==m[Q.front().first][Q.front().second]-1){
					path.push_back(temp);
					Q.pop();
					Q.push(temp);	
				}
			}
		}
	}
	
	//////////////////////////////////////

	for (int i = 0; i < path.size(); i++) {
		Maze[path[i].first][path[i].second] = 'o';
	}
	
	for (int i = 0; i < Maze.size(); i++) {
		for (int j = 0; j < Maze[0].size(); j++) {
			cout << Maze[i][j];
		}
		cout << endl;
	}

}

void BFS(vector<vector<int >>& m, const pair<int, int>& StartPos) {

	int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	queue<pair<int, int>> Q;
	pair<int, int> begin(StartPos.first, StartPos.second);
	m[StartPos.first][StartPos.second] = 0;
	Q.push(begin);

	//////////////////////////////////////
    // TODO:
	// Update the distances in "vector<vector<int >>& m" by BFS.
	// Hint: If the distance is INFINITY, it means that the cell has not been visited.
	while(!Q.empty()){
		pair<int, int> temp;
		for(int i=0;i<4;i++){
			temp.first=Q.front().first+move[i][0];
			temp.second=Q.front().second+move[i][1];
			if(temp.first>=0&&temp.first<m.size()&&temp.second>=0&&temp.second<m[0].size()){
				if(m[temp.first][temp.second]==INFINITY){
					m[temp.first][temp.second]=m[Q.front().first][Q.front().second]+1;
					Q.push(temp);
				}
			}
		}
		Q.pop();
	}
	

	//////////////////////////////////////
}

int main() {

	fstream  file;

	file.open("input.txt");
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;

	while (TestCase) {
		pair<int, int> StartPos, EndPos;
		vector<vector<char>> Maze = GetMazeInfo(file, StartPos, EndPos);
		vector<vector<int >> m = DistanceInfo(Maze);

		BFS(m, StartPos);

		//Print result
		if (m[EndPos.first][EndPos.second] == INFINITY) {
			cout << "No solution!" << endl;
		}
		else {
			PrintResult(m,Maze,EndPos);
			// cout << m[EndPos.first][EndPos.second] << endl;
		}

		cout << endl;
		TestCase--;
	}

	return 0;

}
