cmake_minimum_required(VERSION 3.15)
project(ProgSythn)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O2 -fpermissive" CACHE INTERNAL "C Flags for debug" FORCE)

set(SOURCE
        src/main.cpp
#        Classifystart_test.c
#        Classifyend_test.c
#        Classifystart.c
#        Classifyend.c
#        GEClassify.h
#        GEClassify.c
#       GEListGenome.h
#        GEListGenome.cpp
        src/initfunc.cpp
	src/generate_individual.cpp
	src/evaluator.cpp
#        individual.c
#       Classify-gcc.cpp
)

#GALIB
find_path(GALIB_INCLUDE_DIR
        ga.h
        ga/ga.h
        PATHS
        /usr/include
        /usr/local/include)

find_library(GALIB_LIBRARY
        NAMES
        ga
        PATHS
        /usr/lib
        /usr/local/lib)

#GE
find_path(GELIB_INCLUDE_DIR
        ge.h
        GE/ge.h
        PATHS
        /usr/include
        /usr/local/include)

find_library(GELIB_LIBRARY
        NAMES
        GE
        PATHS
        /usr/lib
        /usr/local/lib)

include_directories(${GALIB_INCLUDE_DIR} ${GELIB_INCLUDE_DIR})
link_directories(${GALIB_LIBRARY} ${GELIB_LIBRARY})
add_executable(GEGCC ${SOURCE})
target_link_libraries(GEGCC ${GALIB_LIBRARY} ${GELIB_LIBRARY} stdc++fs)


# all these stays the same except the  files at the set source

## can you copy all you cpp and data files here
