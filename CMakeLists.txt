cmake_minimum_required(VERSION 3.13)
project(amath2)

set(CMAKE_CXX_STANDARD 14)

set(ELEMENTARY_SOURCES
		src/operations/elementary/addition.cpp
		src/operations/elementary/addition.h
		src/operations/elementary/subtraction.cpp
		src/operations/elementary/subtraction.h
		src/operations/elementary/multiplication.cpp
		src/operations/elementary/multiplication.h
		src/operations/elementary/division.cpp
		src/operations/elementary/division.h)

add_library(amath2_elementary STATIC ${ELEMENTARY_SOURCES})
target_link_libraries(amath2_elementary cln ginac)

set(AMATH2_SOURCES
		src/main.cpp
		src/main.h
		src/operations/operator.cpp
		src/operations/operator.h
		src/utils/number-helper.cpp
		src/utils/number-helper.h)

add_executable(amath2 ${AMATH2_SOURCES})

target_link_libraries(amath2 cln ginac amath2_elementary)
