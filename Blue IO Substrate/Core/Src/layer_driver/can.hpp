/*
 * can.hpp
 *
 *  Created on: Feb 15, 2024
 *      Author: 5164580
 */

#ifndef SRC_LAYER_DRIVER_CAN_HPP_
#define SRC_LAYER_DRIVER_CAN_HPP_

#include <iostream>
#include <vector>

class CanHandler{
public:

	virtual int canRead(int id, int number, unsigned char data[8])=0;
	virtual int canID(int id){return 0;};
};

class CanSystem{
public:
	CanSystem(){}

	void addHandler(CanHandler* handler){
		handlers.push_back(handler);
	}

	void receive(int id, int number, unsigned char data[8]){
		for(auto handler: handlers){
			handler ->canRead(id, number, data);
		}
	}
private:
	std::vector<CanHandler*>handlers;
};



#endif /* INC_CAN_HPP_ */
