cmake_minimum_required(VERSION 3.10)

# Set the project name
project(WeatherApp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(WeatherApp weather_pthread.cpp)

# Find and link cpprestsdk
find_package(cpprestsdk REQUIRED)

# Find OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# Link cpprestsdk and OpenSSL to your executable
target_link_libraries(WeatherApp PRIVATE cpprestsdk::cpprest ${OPENSSL_LIBRARIES})
