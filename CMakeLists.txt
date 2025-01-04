cmake_minimum_required(VERSION 3.5)
project(HelloWorld)

# Set paths for Protobuf, gRPC, and Abseil
set(GRPC_DIR /usr/local/lib/cmake/grpc)
set(Protobuf_DIR /usr/local/lib/cmake/protobuf)
set(ABSEIL_DIR /usr/local)  # Set to directory where Abseil is installed

# Add the directory containing the Abseil CMake configuration file
set(CMAKE_PREFIX_PATH "${ABSEIL_DIR}/lib/cmake:${CMAKE_PREFIX_PATH}")

# Find the required packages
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Include directories for protobuf, gRPC, and Abseil
include_directories(${PROTOBUF_INCLUDE_DIRS} ${GRPC_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR} ${ABSEIL_DIR}/include)

# Add source files with proper paths
set(SOURCES
    ${CMAKE_SOURCE_DIR}/serverProject/server.cpp
    ${CMAKE_SOURCE_DIR}/helloworld.pb.cc
    ${CMAKE_SOURCE_DIR}/helloworld.grpc.pb.cc
)

# Add executable
add_executable(server ${SOURCES})

# Link the gRPC, protobuf, and Abseil libraries manually
target_link_libraries(server
    ${PROTOBUF_LIBRARIES}
    ${gRPC_LIBRARIES}
    ${ABSEIL_DIR}/lib/libabsl_base.a
    ${ABSEIL_DIR}/lib/libabsl_flags.a
    ${ABSEIL_DIR}/lib/libabsl_time.a
    ${ABSEIL_DIR}/lib/libabsl_status.a
)

# Specify where to find gRPC, protobuf, and Abseil
link_directories(/usr/local/lib)

# Optionally, if needed for gRPC runtime support
add_definitions(-DGPR_MAX_STACK_SIZE=1024)
