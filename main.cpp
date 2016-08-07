#include <cmath>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

/*
 * Compute the intensity of a pixel by the old NTSC/PAL TV standards 
 */
uchar grayscaleIntensity(uchar blue, uchar green, uchar red)
{
	float value = .299f * red + .587f * green + .114 * blue;
	return round(value);
}

void printErrorMsg(std::string filename, std::string errorMsg)
{
	std::cerr << filename << " ERROR : " << errorMsg << "\n";
	std::cerr << "Correct command is :\n" << filename << " imageFile\n";
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printErrorMsg(argv[0], "Invalid command!");
		exit(EXIT_FAILURE);
	}

	cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

	if (!img.data) {
		printErrorMsg(argv[0], "Could not open image!");
		exit(EXIT_FAILURE);
	}

	// Create a matrix of only 1-byte elements
	cv::Mat gray(img.rows, img.cols, CV_8UC1);

	// Compute the grayscale of each individual pixel by hand (not using OpenCV functions)
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			
			cv::Vec3b pixel = img.at<cv::Vec3b>(i, j);
			uchar blue = pixel.val[0];
			uchar green = pixel.val[1];
			uchar red = pixel.val[2];

			gray.at<uchar>(i, j) = grayscaleIntensity(blue, green, red);
		}
	}

	cv::imshow("grayscaled", gray);
	cv::waitKey(0);		

	return 0;
}
