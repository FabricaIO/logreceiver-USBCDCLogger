#include "USBCDCLogger.h"

/// @brief Creates a new serial logger
/// @param USBSerial Pointer to a USB serial object to use
/// @param Baud The baud rate to use
USBCDCLogger::USBCDCLogger(USBCDC* USBSerial, int Baud) {
	usb_serial = USBSerial;
	baud = Baud;
}

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
	if (use_usb) {
		usb_serial->begin(baud);
	} else {
		hw_serial->begin(baud);
	}
	return true;
}

/// @brief Writes a char to the serial output
/// @param message The char to write
/// @return True on success
bool USBCDCLogger::receiveMessage(char message) {
	if (use_usb) {
		usb_serial->print(baud);
	} else {
		hw_serial->print(baud);
	}
	return true;
}

/// @brief Write a string to the serial output
/// @param message The string to write
/// @return True on success
bool USBCDCLogger::receiveMessage(String message) {
	if (use_usb) {
		usb_serial->print(baud);
	} else {
		hw_serial->print(baud);
	}
	return true;
}