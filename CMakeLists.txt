cmake_minimum_required(VERSION 3.21)
project(CryptoTracker)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 6ea2dec23c3df14ac3b27b7d2d6bbff0cb7ba1b0)
FetchContent_MakeAvailable(cpr)

add_executable(CryptoTracker src/main.cpp src/price_query.cpp includes/price_query.h)
target_link_libraries(CryptoTracker PRIVATE cpr::cpr)