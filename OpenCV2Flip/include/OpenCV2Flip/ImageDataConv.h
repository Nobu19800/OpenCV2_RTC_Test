// -*- C++ -*-
/*!
 * @file  ImageDataConv.h
 * @brief RTC::CameraImageとcv::Matの相互変換
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
*@brief CameraImage型からcv::Matの画像データを取得
* @param ci CameraImage型の画像データ
* @return cv::Matの画像データ
*/
cv::Mat GetCameraImage(RTC::CameraImage *ci);

/**
*@brief cv::Matの画像データをCameraImage型のデータに設定
* @param ci CameraImage型のデータ
* @param im cv::Matの画像データ
* @param string_encode 圧縮の形式(offは圧縮なし、png、jpegを選択可能)
* @param int_encode_quality 圧縮率(pngは0～10、jpegは0～100)
*/
void SetCameraImage(RTC::CameraImage *ci, cv::Mat *im, std::string string_encode, int int_encode_quality);




#endif