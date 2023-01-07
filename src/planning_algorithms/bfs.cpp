#include <iostream>
#include <queue>
#include <vector>

using matrix_2d = std::vector<std::vector <int>>;
using cell_2d = std::pair<int, int>;

void printGrid(matrix_2d& grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printQueue(std::queue<cell_2d> q)
{
    while (!q.empty())
    {   
        cell_2d cell = q.front();
        std::cout << "(" << cell.first << ", " << cell.second << ")";

        if (q.size() != 1) std::cout << " -> ";

        q.pop();
    }

    std::cout << std::endl;
}

/**
 * @brief Checks if the give point is valid. Valid means that 
 *        the point is in bounds, is not occupied, and is not visited
 * 
 * @param cell
 * @param visited
 * @param grid 
 * @return true 
 * @return false 
 */
bool isValid(cell_2d cell, matrix_2d& visited, matrix_2d& grid)
{

    int maxRow = grid.size();
    int maxCol = grid[0].size();

    // check out of bounds row
    if (cell.first >= maxRow || cell.first < 0)
        return false;

    // check out of bounds col
    if (cell.second >= maxCol || cell.second < 0)
        return false;

    // check occupancy
    if (grid[cell.first][cell.second] == 0) 
        return false;

    // check if cell has been visited
    if (visited[cell.first][cell.second] == 1)
        return false;

    return true;
}

/**
 * @brief Adds valid 4-connected neighbors of given point to unvisited queue
 * 
 */
void addNeighborsToQueue(cell_2d cell, std::queue<cell_2d>& unvisited, matrix_2d& visited, matrix_2d& grid) 
{   
    int row = cell.first;
    int col = cell.second;

    cell_2d top = {row - 1, col};
    cell_2d right = {row, col+ 1};
    cell_2d bottom = {row + 1, col};
    cell_2d left = {row, col - 1};

    if (isValid(top, visited, grid))
        unvisited.push(top);
    if (isValid(right, visited, grid))
        unvisited.push(right);
    if (isValid(bottom, visited, grid))
        unvisited.push(bottom);
    if (isValid(left, visited, grid))
        unvisited.push(left);
}

std::queue<cell_2d> BFS(cell_2d start, cell_2d goal, matrix_2d& grid)
{
    std::queue<cell_2d> unvisited; // queue to keep track of unvisited cells
    std::queue<cell_2d> path; // queue to keep track of order of traversal

    matrix_2d visited (grid.size(), std::vector <int> (grid[0].size(), 0)); // 2D vector to mark cells that were visited

    // mark start point as visited
    visited[start.first][start.second] = 1;
    addNeighborsToQueue(start, unvisited, visited, grid);
    path.push(start);

    std::cout<< "Path: ";
    printQueue(path);

    std::cout << "Unvisited: ";
    printQueue(unvisited);

    cell_2d current = start;

    // Run until there are valid unvisited nodes in the grid
    while (!unvisited.empty() && current != goal)
    {
        // update current cell with immediate unvisited neighbor
        current = unvisited.front();
        path.push(current);

        // add current cell to visited grid and remove it from unvisited queue
        visited[current.first][current.second] = 1;
        unvisited.pop(); 
        
        // add all valid unvisited neighbors of current cell to unvisited queue
        addNeighborsToQueue(current, unvisited, visited, grid);

        std::cout<< "Path: ";
        printQueue(path);

        std::cout << "Unvisited: ";
        printQueue(unvisited);

        std::cout<< "Path: ";
        printQueue(path);
    }

    if (path.front() != goal)
        std::cout << "Goal is unreachable!" << std::endl;

    return path;
}

int main()
{
    matrix_2d grid = {{1, 1, 1},
                    {1, 0, 0},
                    {1, 1, 0}};

    cell_2d start{0, 0};
    cell_2d goal{2, 2};

    printGrid(grid);

    std::queue<cell_2d> path = BFS(start, goal, grid);

    // std::cout<< "Path: ";
    // printQueue(path);

    return 0;
}