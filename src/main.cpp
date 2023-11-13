#include <algorithm>
#include <cstdlib>
#include <forward_list>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <vector>
#include "../external/tree.hh/src/tree.hh"

#include <nlohmann/json.hpp>

#define SKIP_ARGV 1

struct task_t 
{
	std::string name;
	int priority;

	std::vector<task_t> sub_tasks;
} Ttask;

std::string space_subtask = "";

int InsertDataIntoTree(tree<std::string>::iterator root_node, tree<std::string> base_tree)
{
	char DoSubtaskCreation = 'N';

	int subtasks_count = 0;
	std::string subtask_name = " ";

	std::cout << "Enter count sub-tasks for " << *root_node << ": ";
	std::cin >> subtasks_count;

	for (int a = 0; a < subtasks_count; a++) 
	{
		std::cout << "Enter Sub-task name: "	;

		std::cin >> subtask_name;
		auto new_child = base_tree.append_child(root_node, subtask_name);

		std::cout << "Do you want to create sub-tasks for " << subtask_name << ": ";
		std::cin >> DoSubtaskCreation;

		if (DoSubtaskCreation != 'N') 
			InsertDataIntoTree(new_child, base_tree);
	}

	return 0;
}


void DisplayDataFromTree(tree<std::string> tree_tasks)
{
	auto locator_helper = std::find(tree_tasks.begin(), tree_tasks.end(), "root");
	if (locator_helper != tree_tasks.end())
	{
		for (tree<std::string>::iterator sibiling_root = tree_tasks.begin(locator_helper); sibiling_root != tree_tasks.end(locator_helper); ++sibiling_root) 
		{
			for (int a = 0; a < tree_tasks.depth(sibiling_root) - 1; ++a)
				std::cout << ' ';
			std::cout << *sibiling_root << '\n';
		}
	}
}

int main(int argc, char* argv[])
{
	std::string json_filename = "../resources/task.json";
	std::ofstream OutStream(json_filename);

	tree<std::string> tree_tasks = {};
	nlohmann::json json_editor = {};

	std::system("clear");

	auto tree_top = tree_tasks.begin();
	auto tree_root = tree_tasks.insert(tree_top, "root");

	if (!OutStream.is_open()) 
	{
		std::cout << "ERROR: Can't open" + json_filename << '\n';
		return 1;
	}

	if (argc <= 1) 
		InsertDataIntoTree(tree_root, tree_top);

	DisplayDataFromTree(tree_tasks);

	return 0;	
}
