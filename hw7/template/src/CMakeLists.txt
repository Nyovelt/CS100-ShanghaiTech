SET( IMAGEFILTERING_SRCS image_io.cpp
                         FilteredImage.cpp
                         ThreadedFilteredImage.cpp )
ADD_LIBRARY( imagefiltering ${IMAGEFILTERING_SRCS} )