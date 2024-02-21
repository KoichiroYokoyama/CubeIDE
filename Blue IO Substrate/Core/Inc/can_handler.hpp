/*
 * can_handler.hpp
 *
 *  Created on: Feb 17, 2024
 *      Author: 5164580
 */

#ifndef INC_CAN_HANDLER_HPP_
#define INC_CAN_HANDLER_HPP_

#include <iostream>
#include <vector>
#include "stm32f4xx_hal.h"
#include "can.h"

using namespace std;

class Can{
private:
	static int filter_number;
	static short filter0[14*4];
	int count = 0;


public:
	int setID(CAN_HandleTypeDef &hcan, int id);
	int canFilter(CAN_HandleTypeDef &hcan,int filter_num,short stid0,short stid1,short stid2,short stid3);
};

class CanHandler{
public:
	virtual int canRead(CAN_HandleTypeDef *hcan, int id, int number, unsigned char data[8])=0;
	int canSetId(CAN_HandleTypeDef &hcan,int id);

private:
	Can can;
};

class CanSystem{
public:
	CanSystem(){}
	 void addHandler(CanHandler* handler);
	    void receive(int id, int number, unsigned char data[8]);

	private:
	    std::vector<CanHandler*> handlers;

};


#endif /* INC_CAN_HANDLER_HPP_ */
