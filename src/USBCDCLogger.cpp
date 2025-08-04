#include "USBCDCLogger.h"

#if CONFIG_TINYUSB_CDC_ENABLED
/// @brief Creates a new serial logger
/// @param USBSerial Pointer to a USB serial object to use
/// @param Baud The baud rate to use
USBCDCLogger::USBCDCLogger(USBCDC* USBSerial, int Baud) {
	usb_serial = USBSerial;
	baud = Baud;
}
#endif

/// @brief Creates a new serial logger
/// @param USBSerial Pointer to a USB serial object to use
/// @param Baud The baud rate to use
USBCDCLogger::USBCDCLogger(HWCDC* USBSerial, int Baud) {
	hw_serial = USBSerial;
	use_usb = false;
	baud = Baud;
}

/// @brief Starts the serial logger
/// @return True on success
bool USBCDCLogger::begin() {
	Description.name = "USB Serial Logger";
	Description.version = "0.8";
	#if CONFIG_TINYUSB_CDC_ENABLED
	if (use_usb) {
		usb_serial->begin(baud);
	} else {
		hw_serial->begin(baud);
	}
	#else
		hw_serial->begin(baud);
	#endif
	return true;
}

/// @brief Writes a char to the serial output
/// @param message The char to write
/// @return True on success
bool USBCDCLogger::receiveMessage(char message) {
	#if CONFIG_TINYUSB_CDC_ENABLED
	if (use_usb) {
		usb_serial->print(message);
	} else {
		hw_serial->print(message);
	}
	#else
	hw_serial->print(message);
	#endif
	return true;
}

/// @brief Write a string to the serial output
/// @param message The string to write
/// @return True on success
bool USBCDCLogger::receiveMessage(String message) {
	#if CONFIG_TINYUSB_CDC_ENABLED
	if (use_usb) {
		usb_serial->print(message);
	} else {
		hw_serial->print(message);
	}
	#else
	hw_serial->print(message);
	#endif
	return true;
}