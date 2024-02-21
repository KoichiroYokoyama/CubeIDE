/*
 * can_handler.cpp
 *
 *  Created on: Feb 17, 2024
 *      Author: 5164580
 */

#include "can_handler.hpp"

int Can::filter_number = 4;
short Can::filter0[14*4] = {};
short filter_id[4] = {};


int Can::setID(CAN_HandleTypeDef &hcan,int id){
			int row = filter_number / 4;
			filter0[filter_number] = (short)id;

			canFilter(hcan,row-1, filter0[row * 4 + 0], filter0[row * 4 + 1], filter0[row * 4 + 2], filter0[row * 4 + 3]);

			filter_number++;

			std::cout << filter_number <<  id << std::endl;
		//	std::cout << filter[4] << filter[5] << std::endl;

			return 0;
		}

int Can::canFilter(CAN_HandleTypeDef &hcan,int filter_num,short stid0,short stid1,short stid2, short stid3){



			return 0;
		}

int CanHandler::canSetId(CAN_HandleTypeDef &hcan,int id){
	return can.setID(hcan,id);
}

void CanSystem::addHandler(CanHandler* handler){
	handlers.push_back(handler);
}

//
