#pragma once

// constans
// отключить счётчик энкодера [VirtEncoder, Encoder, EncButton] (экономит 4 байта оперативки)
#define EB_NO_COUNTER
// отключить буферизацию энкодера (экономит 2 байта оперативки)
#define EB_NO_BUFFER
// отключить поддержку pressFor/holdFor/stepFor и счётчик степов (экономит 2 байта оперативки)
#define EB_NO_FOR

//распиновка
#define SERVO_PIN 3         //D3
#define POTENSIOMETER_PIN 0 //A0
#define READ_LOC_PIN 10     //D10

#define GREEN_LED 5         //D7
#define YELLOW_LED 6        //D8
#define RED_LED 7           //D4

#define BUTTON_STATE_PIN 2  //D2