cmake_minimum_required(VERSION 2.8)


include_directories(glfw/include/GLFW/)

add_subdirectory(glfw)

add_executable(CourseTask
	main.cxx)
target_link_libraries(CourseTask glfw ${GLFW_LIBRARIES})

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
	add_custom_command(OUTPUT RunTestCommand COMMAND ./CourseTask)
		add_custom_target(RunTest ALL DEPENDS RunTestCommand CourseTask)
endif()