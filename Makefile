CXX=g++
SRC=*.cpp
LD_OPENCV_FLAGS=-lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
#LD_OPENCV_FLAGS_LITE=-lopencv_core -lopencv_highgui
DEBUG_FLAGS=-g -pg

all:
	$(CXX) $(SRC) $(LD_OPENCV_FLAGS) -o grayscale
