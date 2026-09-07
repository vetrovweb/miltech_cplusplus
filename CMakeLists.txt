cmake_minimum_required(VERSION 4.2)
project(miltech_cplusplus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Створюємо окрему програму для кожного файлу
add_executable(lessons1 lessons01/lessons1.cpp)

add_executable(task1 lessons02/homework/task1.cpp)
add_executable(task2 lessons02/homework/task2.cpp)
add_executable(task3 lessons02/homework/task3.cpp)
add_executable(task4 lessons02/homework/task4.cpp)
add_executable(task5 lessons02/homework/task5.cpp)
add_executable(task6 lessons02/homework/task6.cpp)

add_executable(promocode lessons03/homework/promocode.cpp)
add_executable(converter_temp lessons03/homework/converter_temp.cpp)
add_executable(symbol lessons03/homework/symbol.cpp)
add_executable(attraction lessons03/homework/attraction.cpp)

add_executable(lessons4 lessons04/lessons4.cpp
        lessons04/homework/ternOperator.cpp
        lessons04/homework/evennumber.cpp
        lessons04/homework/banknote.cpp
        lessons04/homework/whilenew.cpp
)

add_executable(lessons5 lessons05/lessons5.cpp
        lessons05/homework/countdown.cpp
        lessons05/homework/multiplication.cpp
        lessons05/homework/sum.cpp
        lessons05/homework/unwanted.cpp
        lessons05/homework/search.cpp
        lessons05/homework/combination.cpp
)

add_executable(lessons6 lessons06/lessons6.cpp
        lessons07/homework/hello.cpp
        lessons07/homework/area.cpp
)

add_executable(maxnumber lessons07/homework/maxnumber.cpp)
add_executable(isEven lessons07/homework/isEven.cpp)

add_executable(lessons8 lessons08/lessons8.cpp)
add_executable(merging_arr lessons08/homework/merging_arr.cpp)

add_executable(lessons9 lessons09/lessons9.cpp)
add_executable(dinamic_array lessons09/homework/dinamic_array.cpp)

add_executable(lessons10 lessons10/lessons10.cpp)
add_executable(reverse lessons10/homework/reverse.cpp)
add_executable(compression lessons10/homework/compression.cpp)
add_executable(array lessons10/homework/array.cpp)

add_executable(array_standart arrays/array_standart.cpp)

add_executable(lessons11 lessons11/lessons11.cpp)
add_executable(task_manager lessons11/homework/task_manager.cpp)
#add_executable(vector lessons11/homework/vector.cpp)

add_executable(student OOP2/homework/student.cpp)
add_executable(employees OOP2/homework/employees.cpp)
