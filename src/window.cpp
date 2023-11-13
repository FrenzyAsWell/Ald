#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <string>
#include <vector>

#define BORDER_SIZE 1 * 2

struct cord_xy
{
	int x;
	int y;
};
/*
class CBox_Drawer
{
	private:
		cord_xy start_point;
		cord_xy end_point;
	public:
		void DrawBox(cord_xy current_cursor_pos, std::vector<std::string> data_space)
		{
			start_point.x = current_cursor_pos.x;
			start_point.y = current_cursor_pos.y;
			
			end_point.y = start_point.y + data_space.size();

			for (int count_rows = 0; count_rows < start_point.y + 2; count_rows++)
			{
				for (int count_columns = 0; count_columns < start_point.x + 2; count_columns++)
				{
					if (count_columns <= 0 || count_columns >= start_point.x - 1)
						std::cout << "┃";
					else if (count_rows > 0 && count_rows < start_point.y - 1)
						std::cout << ' ';
					else
						std::cout << "━";
				}
				std::cout << '\n';

			}

			DrawBorders();
		}
		void DrawBorders()
		{	
			std::cout << "\033[" + std::to_string(start_point.x) + ';' + std::to_string(start_point.y) + 'H' << "┎";
			std::cout << "\033[" + std::to_string(end_point.x) + ';' + std::to_string(start_point.y) + 'H' << "┗";
			std::cout << "\033[" + std::to_string(start_point.x) + ';' + std::to_string(end_point.y) + 'H' << "┓";	
			std::cout << "\033[" + std::to_string(end_point.x) + ';' + std::to_string(end_point.y) + 'H' << "┛";

			std::cout << "\033[" + std::to_string(start_point.x + 2) + ';' + std::to_string(start_point.y + 2) + 'H';
		}

		std::vector<std::string> SetDataInside(int argc, char* argv[])	
		{
			std::vector<std::string> data_container;
			std::string temp_string;


			for (int a = 1; a < 5; a++) 
			{	
				std::cin >> temp_string;
				data_container.push_back(temp_string);

				if (start_point.x < temp_string.size())
					start_point.x = temp_string.size();

				std::cout << temp_string.size();
				getchar();
			}

			return data_container;
		}

		cord_xy Getter_cords()
		{
			return end_point;
		}
};
*/

class CBox_table {
public:

	void DrawObject(cord_xy cursor_current_pos)
	{
		start_point.x = cursor_current_pos.x;
		start_point.y = cursor_current_pos.y;

		end_point.x = start_point.x + 10 + BORDER_SIZE;
		end_point.y = start_point.y + data_container.size() + BORDER_SIZE;

		std::cout << "\033[" + std::to_string(start_point.y) + ';' + std::to_string(start_point.x) + 'H' << "┎";

		std::cout << "\033[1B";
		for (int a = 0; a < end_point.y - (start_point.y + BORDER_SIZE); a++) 
			std::cout << "\033[1D" << "┃" << "\033[1B";	

		std::cout << "┗";
		for (int a = 0; a < end_point.x - (start_point.x + BORDER_SIZE); a++) 
			std::cout << "━";	
		
		std::cout << "\033[" + std::to_string(end_point.y) + ';' + std::to_string(end_point.x) + 'H' << "┛";
		for (int a = 0; a < end_point.y - (start_point.y + BORDER_SIZE); a++) 
			std::cout << "\033[1A" << "┃" << "\033[1D";	

		std::cout << "\033[" + std::to_string(start_point.y) + ';' + std::to_string(end_point.x) + 'H' << "┓";	
		for (int a = 0; a < end_point.x - (start_point.x + BORDER_SIZE); a++) 
			std::cout << "\033[1D" << "━" << "\033[1D";	

		getchar();
	}

	void GetDataInSide()
	{
		std::string line_string;
		for (int a = 0; a < 5; a++) 
		{
			std::getline(std::cin, line_string);
			data_container.push_back(line_string);
		}

		std::system("clear");
	}
private:
	cord_xy start_point;
	cord_xy end_point;

	std::vector<std::string> data_container;
};

int main(int argc, char* argv[])
{	
	setlocale(LC_ALL, "en_US.UTF-16");

	CBox_table object_drawer;
	
	cord_xy cursor_pos;
	
	cursor_pos.x = 0;
	cursor_pos.y = 0;

	object_drawer.GetDataInSide();
	object_drawer.DrawObject(cursor_pos);
	
//	std::vector<std::string> task_storage = object_drawer.SetDataInside(argc, argv);

//	std::system("clear");
//	object_drawer.DrawBox(cursor_pos, task_storage);	

//	for (int a = 0; a < task_storage.size(); a++)
//	{
//		std::cout << task_storage[a] << "\033[1B";
//		std::cout << "\033[" + std::to_string(task_storage[a].size()) + "D"; 
//	}
	
//	cord_xy cords = object_drawer.Getter_cords();
//	std::cout << cords.x << " | " << cords.y << '\n';

	getchar();

	return 0;
}
