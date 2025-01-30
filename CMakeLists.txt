cmake_minimum_required(VERSION 3.16)
project(BitMessenger)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Boost paths
set(BOOST_ROOT /opt/homebrew/opt/boost)
set(Boost_INCLUDE_DIR ${BOOST_ROOT}/include)
set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS system filesystem)

# Set libtorrent paths
set(LIBTORRENT_ROOT /opt/homebrew/opt/libtorrent-rasterbar)
set(LIBTORRENT_INCLUDE_DIRS ${LIBTORRENT_ROOT}/include)
set(LIBTORRENT_LIBRARIES ${LIBTORRENT_ROOT}/lib/libtorrent-rasterbar.dylib)

# Find libtorrent
include_directories(${LIBTORRENT_INCLUDE_DIRS})

# Add executable
add_executable(BitMessenger src/main.cpp)

# Link Boost and libtorrent libraries
target_link_libraries(BitMessenger PRIVATE Boost::system Boost::filesystem ${LIBTORRENT_LIBRARIES})

# Additional macOS flags (optional)
if(APPLE)
    target_link_libraries(BitMessenger PRIVATE "-framework CoreFoundation" "-framework SystemConfiguration")
endif()

