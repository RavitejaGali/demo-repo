# Declare the version of the CMake API for forward-compatibility
cmake_minimum_required(VERSION 2.8.3)

# Declare the name of the CMake Project
project(pcan_topics)

# Find and get all the information about the roscpp package
find_package( catkin REQUIRED COMPONENTS roscpp libpcan)

#This function must be called before declaring any targets with add_library() or add_executable(). The function has 5 optional arguments: 
catkin_package()

# Define an execuable target called pcan_receive 
add_executable(pcan_receive src/pcan_receive_node.cpp src/pcan_receive.cpp src/common.cpp)

# Link the pcan_receive target against the libraries used by roscpp
target_link_libraries(pcan_receive   ${catkin_LIBRARIES})
#target_link_libraries(pcan_receive   ${roscpp_LIBRARIES})

# Define an execuable target called pcan_transmit
add_executable(pcan_transmit src/pcan_transmit_node.cpp src/pcan_transmit.cpp src/common.cpp)

# Link the pcan_transmit target against the libraries used by roscpp
target_link_libraries(pcan_transmit   ${catkin_LIBRARIES})
#target_link_libraries(pcan_receive   ${roscpp_LIBRARIES})

add_executable(pcan_pub src/pcan_pub.cpp)
target_link_libraries(pcan_pub ${catkin_LIBRARIES})

find_package(Qt4 COMPONENTS QtCore QtGui)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS pcan_transmitpub.h)

QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})
file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS pcan_transmitpub.cpp)
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(pcan_transmitpub src/pcan_transmitpub.cpp)
TARGET_LINK_LIBRARIES(pcan_transmitpub ${QT_LIBRARIES})

#add_executable(qnode src/qnode.hpp)
#TARGET_LINK_LIBRARIES(qnode ${QT_LIBRARIES})

#add_executable(talker src/talker.cpp)
#TARGET_LINK_LIBRARIES(talker ${QT_LIBRARIES})

#add_executable(talkerhea src/talkerhea.hpp)
#TARGET_LINK_LIBRARIES(talkerhea ${QT_LIBRARIES})
