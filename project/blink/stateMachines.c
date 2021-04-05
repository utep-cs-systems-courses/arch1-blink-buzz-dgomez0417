#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  static char state = 0;
  
  switch (state) {
    
  case 0: red_on = 0; green_on = 0; state++; break; /*turns both light off*/
  case 1: red_on = 1; green_on = 0; state++; break; /*turns the red light on*/
  case 2: red_on = 1; green_on = 0; state++; break; /*turns the red light on*/
  case 3: red_on = 0; green_on = 1; state++; break; /*turns the green light on*/
  case 4: red_on = 0; green_on = 1; state++; break; /*turns the green light on*/
  case 5: red_on = 1; green_on = 1; state = 0; break; /*turns both of the colors on*/
  default: state = 0;
  }

  led_changed = 1;
  led_update();
}

void state_advance_2()		/* alternate between toggling red & green */
{
  char changed = 0;
  static char state = 0;
  
  switch (state) {
  case 0: red_on = 1; green_on = 0; state++; break; /*turns the red light on*/
  default: state = 0;
  }

  led_changed = 1;
  led_update();
}

void state_advance_3()		/* alternate between toggling red & green */
{
  char changed = 0;
  static char state = 0;
  
  switch (state) {
  case 0: red_on = 0; green_on = 1; state++; break; /*turns the green light on*/
  default: state = 0;
  }

  led_changed = 1;
  led_update();
}

void state_advance_4()		/* alternate between toggling red & green */
{
  char changed = 0;
  static char state = 0;
  
  switch (state) {
  case 0: red_on = 0; green_on = 0; state++; break; /*turns both light off*/
  default: state = 0;
  }

  led_changed = 1;
  led_update();
}

void buzzer_state_advance(){
  if(switch_state_down){
    buzzer_state_1_advance();
    state_advance_2();
  }
  else if(switch_state_down_2){
    buzzer_state_2_advance();
    state_advance();
  }
  else if(switch_state_down_3){
    buzzer_state_3_advance();
    state_advance_3();
  }
  else if(switch_state_down_4){
    buzzer_state_4_advance();
    state_advance_4();
  }else{
    buzzer_set_period(0);
  }
}

void buzzer_state_1_advance(){
  static char buzz_state = 0;

  switch (buzz_state){
  case 0: buzzer_set_period(3092); buzz_state++; break;
  case 1: buzzer_set_period(3893); buzz_state++; break;
  case 2: buzzer_set_period(2094); buzz_state++; break;
  case 3: buzzer_set_period(5093); buzz_state++; break;
  case 4: buzzer_set_period(1843); buzz_state = 0; break;
  default: buzz_state = 0;
  }
}

void buzzer_state_2_advance(){
  static char buzz_state = 0;

  switch (buzz_state){
  case 0: buzzer_set_period(3822); buzz_state++; break;
  case 1: buzzer_set_period(3214); buzz_state++; break;
  case 2: buzzer_set_period(2551); buzz_state = 0; break;
  default: buzz_state = 0;
  }
}

void buzzer_state_3_advance(){
  static char buzz_state = 0;

  switch (buzz_state){
  case 0: buzzer_set_period(1000); buzz_state++; break;
  case 1: buzzer_set_period(2000); buzz_state++; break;
  case 2: buzzer_set_period(3000); buzz_state++; break;
  case 3: buzzer_set_period(4000); buzz_state++; break;
  case 4: buzzer_set_period(5000); buzz_state = 0; break;
  default: buzz_state = 0;
  }
}

void buzzer_state_4_advance(){
  static char buzz_state = 0;

  switch (buzz_state){
  case 0: buzzer_set_period(5084); buzz_state++; break;
  case 1: buzzer_set_period(4262); buzz_state++; break;
  case 2: buzzer_set_period(3871); buzz_state++; break;
  case 3: buzzer_set_period(1083); buzz_state++; break;
  case 4: buzzer_set_period(2954); buzz_state = 0; break;
  default: buzz_state = 0;
  }
}

