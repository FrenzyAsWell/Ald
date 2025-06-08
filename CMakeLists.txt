cmake_minimum_required(VERSION 3.31.6)
project(Ald_TaskManager)

set(VAR_FRAMEWORK "FTXUI")
set(VAR_MODULES "./external")

add_subdirectory(${CMAKE_SOURCE_DIR}/${VAR_MODULES}/${VAR_FRAMEWORK})

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_directories(
	${PROJECT_NAME}
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)
