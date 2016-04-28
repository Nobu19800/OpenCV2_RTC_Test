// -*- C++ -*-
/*!
 * @file  OpenCV2Test.cpp
 * @brief OpenCV2 Test
 * @date $Date$
 *
 * $Id$
 */

#include "OpenCV2Test.h"

// Module specification
// <rtc-template block="module_spec">
static const char* opencv2test_spec[] =
  {
    "implementation_id", "OpenCV2Test",
    "type_name",         "OpenCV2Test",
    "description",       "OpenCV2 Test",
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
    // Widget
    "conf.__widget__.string_encode", "radio",
    "conf.__widget__.int_encode_quality", "spin",
    // Constraints
    "conf.__constraints__.string_encode", "(off,jpeg,png)",
    "conf.__constraints__.int_encode_quality", "1<=x<=100",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
OpenCV2Test::OpenCV2Test(RTC::Manager* manager)
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
OpenCV2Test::~OpenCV2Test()
{
}



RTC::ReturnCode_t OpenCV2Test::onInitialize()
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
  // </rtc-template>
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onFinalize()
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onExecute(RTC::UniqueId ec_id)
{
	if (m_inIn.isNew())
	{
		m_inIn.read();
		cv::Mat src_img = GetCameraImage(&m_in);

		SetCameraImage(&m_out, &src_img, m_string_encode, m_int_encode_quality);
		m_outOut.write();
		src_img.release();
	}
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t OpenCV2Test::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}



extern "C"
{
 
  void OpenCV2TestInit(RTC::Manager* manager)
  {
    coil::Properties profile(opencv2test_spec);
    manager->registerFactory(profile,
                             RTC::Create<OpenCV2Test>,
                             RTC::Delete<OpenCV2Test>);
  }
  
};


