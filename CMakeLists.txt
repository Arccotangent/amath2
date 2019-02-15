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
		src/operations/elementary/division.h
		src/operations/elementary/modulus.cpp
		src/operations/elementary/modulus.h
		src/operations/elementary/exponentiation.cpp
		src/operations/elementary/exponentiation.h
		src/operations/elementary/square-root.cpp
		src/operations/elementary/square-root.h
		src/operations/elementary/factorial.cpp
		src/operations/elementary/factorial.h
		src/operations/elementary/factor.cpp
		src/operations/elementary/factor.h
		src/operations/elementary/number-factor.cpp
		src/operations/elementary/number-factor.h
		src/operations/elementary/gcd.cpp
		src/operations/elementary/gcd.h
		src/operations/elementary/lcm.cpp
		src/operations/elementary/lcm.h)

set(ALGEBRA_SOURCES
		src/operations/algebra/quadratic.cpp
		src/operations/algebra/quadratic.h
		src/operations/algebra/cubic.cpp
		src/operations/algebra/cubic.h
		src/operations/algebra/logarithm.cpp
		src/operations/algebra/logarithm.h
		src/operations/algebra/base-10-logarithm.cpp
		src/operations/algebra/base-10-logarithm.h
		src/operations/algebra/binary-logarithm.cpp
		src/operations/algebra/binary-logarithm.h
		src/operations/algebra/custom-base-logarithm.cpp
		src/operations/algebra/custom-base-logarithm.h
		src/operations/algebra/compound-interest.cpp
		src/operations/algebra/compound-interest.h
		src/operations/algebra/continuous-compound-interest.cpp
		src/operations/algebra/continuous-compound-interest.h
		src/operations/algebra/arithmetic-sequence-term-n.cpp
		src/operations/algebra/arithmetic-sequence-term-n.h
		src/operations/algebra/arithmetic-sequence-sum.cpp
		src/operations/algebra/arithmetic-sequence-sum.h
		src/operations/algebra/combination.cpp
		src/operations/algebra/combination.h
		src/operations/algebra/permutation.cpp
		src/operations/algebra/permutation.h)

set(UTILS_SOURCES
		src/utils/number-helper.cpp
		src/utils/number-helper.h)

set(OPERATIONS_SOURCES
		src/operations/operator.cpp
		src/operations/operator.h)

find_package(Boost 1.60.0 REQUIRED COMPONENTS program_options system)

add_library(amath2_elementary STATIC ${ELEMENTARY_SOURCES})
target_link_libraries(amath2_elementary cln ginac)

add_library(amath2_algebra STATIC ${ALGEBRA_SOURCES})
target_link_libraries(amath2_algebra cln ginac)

add_library(amath2_operations STATIC ${OPERATIONS_SOURCES})
target_link_libraries(amath2_operations amath2_elementary amath2_algebra cln ginac)

add_library(amath2_utils STATIC ${UTILS_SOURCES})
target_link_libraries(amath2_utils cln ginac)

set(AMATH2_SOURCES
		src/main.cpp
		src/main.h
		src/configuration.cpp
		src/configuration.h)

add_executable(amath2 ${AMATH2_SOURCES})

target_link_libraries(amath2 cln ginac jsoncpp boost_program_options boost_system amath2_elementary amath2_algebra amath2_operations amath2_utils)
