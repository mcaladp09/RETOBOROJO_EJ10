#include <Arduino.h>
#include "task1.h"


void task4(){
    enum class Task1States{
        INIT,
        WAIT_TO_TOGGLE_LED
    };
    static Task1States task1State = Task1States::INIT;
    static uint32_t lasTime;
    static constexpr uint32_t INTERVAL = 250;
    static constexpr uint8_t ledYellow = 27;
    static bool ledStatus = false;

    switch(task1State){
        case Task1States::INIT:{
            pinMode(ledYellow,OUTPUT);
            lasTime = millis();
            task1State = Task1States::WAIT_TO_TOGGLE_LED;
            break;
        }

        case Task1States::WAIT_TO_TOGGLE_LED:{
            // evento 1:
            uint32_t currentTime = millis();
            if( (currentTime - lasTime) >= INTERVAL ){
                lasTime = currentTime;
                digitalWrite(ledYellow,ledStatus);
                ledStatus = !ledStatus;
            }
            break;
        }

        default:{
            break;
        }
    }

}