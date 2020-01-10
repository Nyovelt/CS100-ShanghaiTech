INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/src" )

ADD_EXECUTABLE( testIO test1.cpp )
TARGET_LINK_LIBRARIES( testIO imagefiltering )

ADD_EXECUTABLE( runfilters test2.cpp )
TARGET_LINK_LIBRARIES( runfilters imagefiltering )

ADD_EXECUTABLE( runfiltersTh test3.cpp )
TARGET_LINK_LIBRARIES( runfiltersTh imagefiltering )