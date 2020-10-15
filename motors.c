#include "motors.h"



void motors::motor_init() {
	
	HAL_TIM_PWM_Start(&htim, Channel);
	HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, PinState);
	HAL_Delay(100);
	int pwm = 50
	while(pwm < 350) {
	__HAL_TIM_SetCompare(&htim, Channel, pwm);
	HAL_Delay(100);
	pwm += 50;
	} // We can change the pwm and increments, will need to test out different speeds for this
}
	

	void changeSpeed(int pwm, int delay) { 
		__HAL_TIM_SetCompare(&htim, Channel, pwm);
		HAL_Delay(delay);
	} //We can change pwm to an exact speed we want and calculate the pwm in the function if it makes this easier to use
	
	/*
	* 
	*/
	
	/* Return the speed the motor is driving at
	* 
	*/
	//float readSpeed();
	
	/*
	* Changes the direction the motors are driving in
	*	direction: A value that distinguishes which exact direction the motors should go in: left forward(0), left back(1),
				   right forward(4), right back (5), forward(2), backwards(3)
	* 	degreeTurn: The amount of degrees ro turn the robot

	*/
	void changeDirection(int direction, int degreeTurn) {
		int delayTurn = 0;
		if(degreeTurn == 45) {
			delay = 450;
		}
		else if(degreeTurn = 90) {
			delay = 700;
		}
		else {} //Want to add more angle cases but need to mess around with motor
		
			switch(direction) {
				case 0: //Left Forward
					if(right) {
						__HAL_TIM_SetCompare(&htim, Channel, 300);
					}
					else {
						__HAL_TIM_SetCompare(&htim, Channel, 0);
					}
					
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_SET);
						HAL_Delay(delay);
						
				case 1: //Left Back
					if(right) {
						__HAL_TIM_SetCompare(&htim, Channel, 0);
					}
					else{
						__HAL_TIM_SetCompare(&htim, Channel, 300);
					}
					
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_RESET);
					HAL_Delay(delay);
					
				case 2: //Forward
					__HAL_TIM_SetCompare(&htim, Channel, 200);
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_SET);
					HAL_Delay(delay);
					
				case 3: //Backward
					__HAL_TIM_SetCompare(&htim, Channel, 200);
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_RESET);
					HAL_Delay(delay);
					
				case 4: //Right Forward
					if(right){
						__HAL_TIM_SetCompare(&htim, Channel, 0);
					}
					else {
						__HAL_TIM_SetCompare(&htim, Channel, 300);
					}
					
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_SET);
					HAL_Delay(delay);
					
				case 5: //Right Backward
					if(right) {
					__HAL_TIM_SetCompare(&htim, Channel, 300);
					}
					else {
						__HAL_TIM_SetCompare(&htim, Channel, 0);
					}
					HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, GPIO_PIN_RESET);
					HAL_Delay(delay);
				
			}
}

			
	
	/*
	* Causes the motors to move forward or backward based on current GPIO Pin State
	*	
	*/
	void oppositeDirection() {
		HAL_GPIO_WritePin(&GPIOx, GPIO_PIN, ~PinState);
	}
	
	
	/*
	* Turns motors off by setting the pwm equal to 0
	*/
	void stopMotor() {
		__HAL_TIM_SetCompare(&htim, Channel, 0);
	}