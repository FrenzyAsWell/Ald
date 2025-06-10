cmake_minimum_required(VERSION 3.31.6)
project(Ald_TaskManager)

include(FetchContent)

set(MODULES_PATH "./external")
set(FRAMEWORK_NAME "FTXUI")
set(FRAMEWORK_URL "https://github.com/ArthurSonzogni/FTXUI.git")
set(FRAMEWORK_VER "6.1.9")

FetchContent_Declare(
	${FRAMEWORK_NAME}

	SOURCE_DIR "${CMAKE_SOURCE_DIR}/${VAR_MODULES}/${FRAMEWORK_NAME}"
	GIT_REPOSITORY "${FRAMEWORK_URL}"
	GIT_TAG "v${FRAMEWORK_VER}"
	
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(${FRAMEWORK_NAME})

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(
	${PROJECT_NAME}
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)
