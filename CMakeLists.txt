cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fopenmp" )
SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fopenmp" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fopenmp" )
SET( LINKER_FLAGS  "${LINKER_FLAGS} -fopenmp" )


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")

project (artificialIntelligenceBenchmark)

file(GLOB_RECURSE all_SRC "source/*.cpp" "source/*.h")

add_executable(artificialIntelligenceBenchmark ${all_SRC})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

TARGET_LINK_LIBRARIES(artificialIntelligenceBenchmark png16)

add_custom_command(TARGET artificialIntelligenceBenchmark PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/AnalysisImages $<TARGET_FILE_DIR:artificialIntelligenceBenchmark>)