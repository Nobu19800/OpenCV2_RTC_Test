// -*- C++ -*-
/*!
 * @file  ImageDataConv.cpp
 * @brief RTC::CameraImage‚Æcv::Mat‚Ì‘ŠŒÝ•ÏŠ·
 * @date $Date$
 *
 * $Id$
 */

#include "ImageDataConv.h"

cv::Mat GetCameraImage(RTC::CameraImage *ci)
{
	std::string format = (const char*)ci->format;
	if(format == "jpeg" || format == "png")
	{
		std::vector<uchar> buff;
		int len = ci->pixels.length();
		buff.resize(len);
		memcpy(&buff[0], &ci->pixels[0], sizeof(unsigned char)*len);
		cv::Mat jpegimage = cv::imdecode(cv::Mat(buff),CV_LOAD_IMAGE_COLOR);

		return jpegimage;

	}
	else
	{
		if(ci->pixels.length() == ci->width * ci->height * 3)
		{
			cv::Mat dist_img(cv::Size(ci->width, ci->height), CV_8UC3);
			memcpy(&dist_img.data[0],&ci->pixels[0],ci->pixels.length());
			return dist_img;
		}
		else if(ci->pixels.length() == ci->width * ci->height)
		{
			cv::Mat dist_img(cv::Size(ci->width, ci->height), CV_8UC1);
			memcpy(&dist_img.data[0],&ci->pixels[0],ci->pixels.length());
			return dist_img;
		}
	}
	return cv::Mat();

	
}

void SetCameraImage(RTC::CameraImage *ci, cv::Mat *im, std::string string_encode, int int_encode_quality)
{
  ci->width = im->cols;
  ci->height = im->rows;

  ci->format = string_encode.c_str();

  if(string_encode == "off")
  {
	  int len = im->channels() * im->cols * im->rows;
	  ci->pixels.length(len);

	  memcpy(&ci->pixels[0],im->data,len);
  }
  else if(string_encode == "jpeg")
  {
	  std::vector<int> param = std::vector<int>(2);
	  std::vector<uchar> buff;
	  param[0] = CV_IMWRITE_JPEG_QUALITY;
	  if(0 <= int_encode_quality && int_encode_quality <= 100){
		param[1] = int_encode_quality;
	  }
	  else{
		param[1] = 75;
		
	  }
	  
	 

	  cv::imencode(".jpg", *im ,buff, param);

	  int len = buff.size();
	  ci->pixels.length(len);
	  memcpy(&ci->pixels[0],&buff[0], sizeof(unsigned char)*len);
  }
  else if(string_encode == "png")
  {
	  std::vector<int> param = std::vector<int>(2);
	  std::vector<uchar> buff;
	  param[0] = CV_IMWRITE_PNG_COMPRESSION;

	  if(0 <= int_encode_quality && int_encode_quality <= 9){
		param[1] = int_encode_quality;
	  }
	  else{
		param[1] = 3;
		
	  }


	  cv::imencode(".png", *im ,buff, param);

	  int len = buff.size();
	  ci->pixels.length(len);
	  memcpy(&ci->pixels[0],&buff[0], sizeof(unsigned char)*len);
  }
}


