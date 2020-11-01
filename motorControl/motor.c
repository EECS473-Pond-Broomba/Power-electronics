#include "motor.h"

void motorInit(TIM_HandleTypeDef * htim1, TIM_HandleTypeDef * htim2,
		TIM_HandleTypeDef * htim3, TIM_HandleTypeDef * htim4){
	htiml1 = htim1;
	htiml2 = htim2;
	htimr1 = htim3;
	htimr2 = htim4;
}

void setSpeed(int pwml1, int pwml2, int pwmr1, int pwmr2){
	__HAL_TIM_SetCompare(htiml1, TIM_CHANNEL_1, pwml1);
	__HAL_TIM_SetCompare(htiml2, TIM_CHANNEL_1, pwml2);
	__HAL_TIM_SetCompare(htimr1, TIM_CHANNEL_1, pwmr1);
	__HAL_TIM_SetCompare(htimr2, TIM_CHANNEL_1, pwmr2);
	HAL_Delay(100);
}

void stopMotors(){
	__HAL_TIM_SetCompare(htiml1, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(htiml2, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(htimr1, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(htimr2, TIM_CHANNEL_1, 0);
	HAL_Delay(100);
}
