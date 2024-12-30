cmake_minimum_required(VERSION 3.30)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 20)

add_executable(ComplexNumbers main.cpp
        ComplexNumber/ComplexNumber.cpp
        ComplexNumber/ComplexNumber.h
        RationalNumber/RationalNumber.cpp
        RationalNumber/RationalNumber.h
        tests/test_RationalNumber.cpp)
