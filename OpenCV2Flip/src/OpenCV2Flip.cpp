// -*- C++ -*-
/*!
 * @file  OpenCV2Flip.cpp
 * @brief OpenCV2 Flip Component
 * @date $Date$
 *
 * $Id$
 */

#include "OpenCV2Flip.h"

// Module specification
// <rtc-template block="module_spec">
static const char* opencv2flip_spec[] =
  {
    "implementation_id", "OpenCV2Flip",
    "type_name",         "OpenCV2Flip",
    "description",       "OpenCV2 Flip Component",
    "version",           "1.0.0",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "TEST",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.string_encode", "off",
    "conf.default.int_encode_quality", "75",
    "conf.default.flip_mode", "0",
    // Widget
    "conf.__widget__.string_encode", "radio",
    "conf.__widget__.int_encode_quality", "spin",
    "conf.__widget__.flip_mode", "radio",
    // Constraints
    "conf.__constraints__.string_encode", "(off,jpeg,png)",
    "conf.__constraints__.int_encode_quality", "1<=x<=100",
    "conf.__constraints__.flip_mode", "(-1,0,1)",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
OpenCV2Flip::OpenCV2Flip(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
OpenCV2Flip::~OpenCV2Flip()
{
}



RTC::ReturnCode_t OpenCV2Flip::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("string_encode", m_string_encode, "off");
  bindParameter("int_encode_quality", m_int_encode_quality, "75");
  bindParameter("flip_mode", m_flip_mode, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onFinalize()
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onExecute(RTC::UniqueId ec_id)
{
	if (m_inIn.isNew())
	{
		m_inIn.read();
		cv::Mat src_img = GetCameraImage(&m_in);
		cv::Mat dist_img;
		cv::flip(src_img, dist_img, m_flip_mode);
		SetCameraImage(&m_out, &dist_img, m_string_encode, m_int_encode_quality);
		m_outOut.write();
	}
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Flip::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}



extern "C"
{
 
  void OpenCV2FlipInit(RTC::Manager* manager)
  {
    coil::Properties profile(opencv2flip_spec);
    manager->registerFactory(profile,
                             RTC::Create<OpenCV2Flip>,
                             RTC::Delete<OpenCV2Flip>);
  }
  
};


