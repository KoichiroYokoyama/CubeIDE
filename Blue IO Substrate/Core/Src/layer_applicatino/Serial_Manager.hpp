/*
 * Serial_Manager.hpp
 *
 *  Created on: Feb 15, 2024
 *      Author: 5164580
 */

#ifndef SRC_LAYER_APPLICATION_SERIAL_MANAGER_HPP_
#define SRC_LAYER_APPLICATION_SERIAL_MANAGER_HPP_

#include <iostream>
#include <string.h>
#include <map>
#include <functional>

class SerialManager{
public:
	SerialManager();
	void processCommand(const std::string& command);
	void addCommandHandler(const std::string& command, std::function<void()> handler);
	void handleSerialData(SerialManager& serialManager, char rx_data);
	void cycle();

private:
    std::map<std::string, std::function<void()>> commandHandlers;
    bool print_flag;
    char *prompt;
};


#endif /* INC_SERIAL_MANAGER_HPP_ */
