/*
 * Serial_Manager.cpp
 *
 *  Created on: Feb 15, 2024
 *      Author: 5164580
 */

#include "Serial_Manager.hpp"

SerialManager::SerialManager(){
	print_flag = false;
	prompt = new char[4];
}

void SerialManager::addCommandHandler(const std::string& command, std::function<void()> handler) {
	std::string modifiedCommand = "func " + command;
    commandHandlers[modifiedCommand] = handler;
}

void SerialManager::processCommand(const std::string& command){
        if (commandHandlers.find(command) != commandHandlers.end()){
            commandHandlers[command]();
        }
        else{std::cout << "\nUnknown command: " << command  << std::endl;}
    }

void SerialManager::handleSerialData(SerialManager& serialManager, char rx_data) {
    static std::string rx_buffer;
    if(rx_data == '\n' || rx_data == '\r'){
    	if(!rx_buffer.empty()){
    		serialManager.processCommand(rx_buffer);
            rx_buffer.clear();
          }
    	}else {
            rx_buffer += rx_data;
            }
        }


