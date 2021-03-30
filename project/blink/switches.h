#ifndef switches_included
#define switches_included

// green board switches are from P2.0-P2.3
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)       /* all the switches on the board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_down_2, switch_state_down_3, switch_state_down_4, switch_state_changed; /* effectively boolean */

#endif // included
