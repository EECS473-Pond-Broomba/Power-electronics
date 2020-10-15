class motors{
	
	TIM_HandleTypeDef * htim;
	uint32_t Channel;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	GPIO_PinState PinState;
	bool right; //Informs us on if we're working with the righ or left motor

	
	/*
	* Initialize the motor to start running and slowing increase speed to a steady pace. 
	*/
	void motor_init();
	
	/*
	* Set the motor to a new speed
		TIM_	CHANNEL_4: TIM Channel 4 selected
	*	pwm: 	specifies the Capture Compare register new value which generates a new duty cycle of the motor
	*	delay: Amount of time in miliseconds before moving on to the next line
	*/
	void changeSpeed(int pwm, int delay);
	
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
	void changeDirection(int direction, int degreeTurn);
	
	/*
	* Causes the motors to move forward or backward based on current GPIO Pin State
	*	
	*/
	void oppositeDirection();
	
	
	/*
	* Turns motors off by setting the pwm equal to 0
	*/
	void stopMotor();
	
	
	
}