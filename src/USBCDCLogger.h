/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2025 Sam Groveman
*
* Contributors: Sam Groveman
*/

#include <LogReceiver.h>

/// @brief Logs to the Arduino serial output
class USBCDCLogger : public LogReceiver {
	public:
		USBCDCLogger(USBCDC* USBSerial, int Baud = 115200);
		USBCDCLogger(HWCDC* USBSerial, int Baud = 115200);
		bool begin();
		bool receiveMessage(char message);
		bool receiveMessage(String message);
	protected:
		/// @brief Pointer to hardware serial to use
		USBCDC* usb_serial;

		/// @brief Pointer to hardware serial to use
		HWCDC* hw_serial;

		/// @brief Whether to use USBCDC or HWCDC
		bool use_usb = true;
		

		/// @brief The baud rate to use
		int baud;
};