// -*- C++ -*-
/*!
 * @file  ImageDataConv.h
 * @brief RTC::CameraImage��cv::Mat�̑��ݕϊ�
 * @date $Date$
 *
 * $Id$
 */
#ifndef IMAGEDATACONV_H
#define IMAGEDATACONV_H


#include <string>
#include <rtm/idl/InterfaceDataTypesSkel.h>
#include "InterfaceDataTypesStub.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>


/**
*@brief CameraImage�^����cv::Mat�̉摜�f�[�^���擾
* @param ci CameraImage�^�̉摜�f�[�^
* @return cv::Mat�̉摜�f�[�^
*/
cv::Mat GetCameraImage(RTC::CameraImage *ci);

/**
*@brief cv::Mat�̉摜�f�[�^��CameraImage�^�̃f�[�^�ɐݒ�
* @param ci CameraImage�^�̃f�[�^
* @param im cv::Mat�̉摜�f�[�^
* @param string_encode ���k�̌`��(off�͈��k�Ȃ��Apng�Ajpeg��I���\)
* @param int_encode_quality ���k��(png��0�`10�Ajpeg��0�`100)
*/
void SetCameraImage(RTC::CameraImage *ci, cv::Mat *im, std::string string_encode, int int_encode_quality);




#endif