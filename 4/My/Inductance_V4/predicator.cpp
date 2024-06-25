//predicator.cpp
//
// Created by Anatejl on 01.06.2024.
//

#include "predicator.h"

bool pred_R1(void *object){
    Application &app = *((Application*)object);
    if(app.isFirst){
        return true;
    }
    return false;
}

bool pred_R2(void *object){
    Application &app = *((Application*)object);
    if(app.current_element.second <= app.last_element){
        return true;
    }
    return false;
}

bool pred_R3(void *object){
    Application &app = *((Application*)object);
    if(app.tempCS > app.finalCS) {
        return true;
    }
    return false;
}

bool pred_R4(void *object){
    Application &app = *((Application*)object);
    if(app.delta_v < app.const_D){
        return true;
    }
    return false;
}

bool pred_R5(void *object){
    Application &app = *((Application*)object);
    if(app.delta_v > app.const_D){

        return true;
    }
    return false;
}
