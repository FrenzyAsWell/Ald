#include <cstdio>
#include <iostream>
#include <algorithm>

#include <string>
#include <vector>

struct cord_xy
{
	int x;
	int y;
};

class CBox_Drawer
{
	private:
		cord_xy start_point;
		cord_xy end_point;
	public:
		void DrawBox(cord_xy current_cursor_pos, int size_h, int size_l)
		{
			start_point.y = current_cursor_pos.y;
			start_point.x = current_cursor_pos.x;

			end_point.x = current_cursor_pos.x + size_h;
			end_point.y = current_cursor_pos.y + size_l;

			for (int count_rows = 0; count_rows < size_h; count_rows++)
			{
				for (int count_columns = 0; count_columns < size_l; count_columns++)
				{
					if (count_columns <= 0 || count_columns >= size_l - 1)
						std::cout << "┃";
					else if (count_rows > 0 && count_rows < size_h - 1)
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
};

int main()
{	
	setlocale(LC_ALL, "en_US.UTF-16");

	CBox_Drawer object_drawer;

	std::vector<std::string> task_storage; 
	std::string temp_task = " ";
	
	cord_xy cursor_pos;
	cursor_pos.x = 0;
	cursor_pos.y = 0;

	int size_height = 0; 
	
	for (int a = 0; a < 5; a++) 
	{	
		std::cout << (a + 1) << ". Enter your task: "; 
		std::getline(std::cin, temp_task);

		task_storage.push_back(temp_task);
		if (size_height < temp_task.size())
			size_height = temp_task.size();
	}

	std::system("clear");
	object_drawer.DrawBox(cursor_pos, task_storage.size() + 2, size_height + 2);	

	for (int a = 0; a < task_storage.size(); a++)
	{
		std::cout << task_storage[a] << "\033[1B";
		std::cout << "\033[" + std::to_string(task_storage[a].size()) + "D"; 
	}

	
	getchar();

	return 0;
}
