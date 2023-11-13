#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <variant>

#define BORDER_SIZE 1 * 2

struct cord_xy
{
	int x;
	int y;
};

int main()
{
	cord_xy start_point;
	cord_xy end_point;

	start_point.x = 0;	
	start_point.y = 0;

	end_point.x = start_point.x + 10 + BORDER_SIZE;
	end_point.y = start_point.y + 5 + BORDER_SIZE;

	std::system("clear");
	std::cout << "\033[" + std::to_string(start_point.y) + ';' + std::to_string(start_point.x) + 'H' << "┎";
	
	getchar();

	for (int a = 2; a < end_point.y - (start_point.y + BORDER_SIZE); a++) 
		std::cout << "\033[" + std::to_string(start_point.y + a) + ';' + std::to_string(start_point.x) + 'H' << "|";

	getchar();

	std::cout << "┗";
	for (int a = 0; a < end_point.x - (start_point.x + BORDER_SIZE); a++) 
		std::cout << "━";	
		
	std::cout << "\033[" + std::to_string(end_point.y) + ';' + std::to_string(end_point.x) + 'H' << "┛";
	for (int a = 0; a < end_point.y - (start_point.y + BORDER_SIZE); a++) 
		std::cout << "\033[1A" << "┃" << "\033[1D";	

	std::cout << "\033[" + std::to_string(start_point.y) + ';' + std::to_string(end_point.x) + 'H' << "┓";	
	for (int a = 0; a < end_point.x - (start_point.x + BORDER_SIZE); a++) 
		std::cout << "\033[1D" << "━" << "\033[1D";	

	return 0;
}
