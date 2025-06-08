cmake_minimum_required(VERSION 3.31.6)
project(Ald_TaskManager)

include(FetchContent)

set(VAR_FRAMEWORK "FTXUI")
set(VAR_MODULES "./external")

FetchContent_Declare(
	${VAR_FRAMEWORK}
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/${VAR_MODULES}/${VAR_FRAMEWORK}
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
	GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(${VAR_FRAMEWORK})

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_directories(
	${PROJECT_NAME}
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)
