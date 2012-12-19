#include <avr/pgmspace.h>
#include "huffcode.h"
#include "huffcode.c"
#include "sound_struct.h"
#include "Wilhelm-4k.h"

//TypeDefs
// This will make it easier to name annoy functions, and make it really easy to call them later.
// Downside: no argument passing- all annoy functions will have to have the same API.
typedef void (*annoyFunctionPtr)(void);

// defines
#define SERIAL_DEBUG



int const SOUND_DUTY = 30;

// outputs
unsigned int const PIEZO_PIN = 9;
unsigned int const RED_LED_PIN = 10;
unsigned int const BLUE_LED_PIN =11;
unsigned int const LEFT_PAGER_MOTOR_PIN = 7;
unsigned int const RIGHT_PAGER_MOTOR_PIN = 6;

// inputs
// using pin 2 as it could be used to drive interrupts
unsigned int const TIMER_CONFIG_PIN = 5;
unsigned int const LIGHT_LEVEL_CONFIG_PIN = 4;
unsigned int const LDR_PIN = 2;

// annoy functions
//annoyFunctionPtr AnnoyFunctionArray[] = { &annoy0, &annoy1, &annoy2, &annoy3, &annoy4, &annoy5,  &play_pcm, &blink_eyes};
annoyFunctionPtr AnnoyFunctionArray[] = { &play_pcm};

unsigned int NumberOfAnnoyFunctions = sizeof(AnnoyFunctionArray) / sizeof(annoyFunctionPtr);

PGM_P cur_byte_ptr;
register uint8_t cur_byte asm("r2");
register uint8_t cur_bit_idx asm("r3");
//uint8_t cur_byte;
//uint8_t cur_bit_idx;

uint8_t get_next_bit() {
  uint8_t rv = 0;
  if((cur_byte & (1<<cur_bit_idx)) != 0) {
    rv = 1;
  }
  cur_bit_idx++;
  if(cur_bit_idx == 8) {
    cur_byte_ptr++;
    cur_byte = pgm_read_byte(cur_byte_ptr);
    cur_bit_idx = 0;
  }  
  return rv;
}

void setup(){
  #ifdef SERIAL_DEBUG
  Serial.begin(9600);
  Serial.println("-> Setup");
  #endif
  
  // hardware configuration
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RIGHT_PAGER_MOTOR_PIN, OUTPUT);
  pinMode(LEFT_PAGER_MOTOR_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(LDR_PIN,INPUT);
  pinMode(LIGHT_LEVEL_CONFIG_PIN,INPUT);
  pinMode(TIMER_CONFIG_PIN,INPUT);
  
  // other setup
  randomSeed(millis());
  
}


void loop(){
  #ifdef SERIAL_DEBUG
  Serial.println("-> Loop");
  #endif

  annoy();
  
  delay(500);  
}

// Play sounnd- shamelessly copied from https://github.com/lewisd32/AnnoyATtiny85/blob/master/AnnoyATTiny85.ino
void play(long period, long durationMillis) {
  play(period, durationMillis, 0, SOUND_DUTY);
}

// Play sounnd- shamelessly copied from https://github.com/lewisd32/AnnoyATtiny85/blob/master/AnnoyATTiny85.ino
void play(long period, long durationMillis, long pauseMillis) {
  play(period, durationMillis, pauseMillis, SOUND_DUTY);
}

// Play sounnd- shamelessly copied from https://github.com/lewisd32/AnnoyATtiny85/blob/master/AnnoyATTiny85.ino
void play(long period, long durationMillis, long pauseMillis, int duty) {
  period = period;
  durationMillis = durationMillis;
  pauseMillis = pauseMillis;
  unsigned long const end = millis() + durationMillis;
  unsigned long pa = period * (long)(duty) / (long)100;
  if (pa > 150) {
    pa = 150;
  }
  unsigned long const pb = period - pa;
  while (end > millis()) {
    digitalWrite(PIEZO_PIN, HIGH);
    delayMicroseconds(pa);
    digitalWrite(PIEZO_PIN, LOW);
    delayMicroseconds(pb);
  }
  delay(pauseMillis);
}


// Play sounnd- shamelessly copied from https://github.com/lewisd32/AnnoyATtiny85/blob/master/AnnoyATTiny85.ino
void annoy() {
  int const annoyance = random(0, NumberOfAnnoyFunctions);
  (*AnnoyFunctionArray[annoyance])();
  
}

void annoy0() {
  play(400, 50);
  play(390, 50);
  play(380, 50);
  play(370, 50);
  play(360, 50);
  play(350, 500);
}

void annoy1() {
  play(300, 50);
  play(290, 50);
  play(280, 50);
  play(270, 50);
  play(260, 50);
  play(250, 50);
  play(240, 50);
  play(230, 50);
  play(220, 50);
  play(210, 500);
}

void annoy2() {
  play(350, 500);
}

void annoy3() {
  annoy3_basis(400,500);
}

void annoy4() {
  annoy3_basis(300,400);
}

void annoy5() {
  annoy3_basis(200,300);
}

void annoy3_basis(int min, int max) {
  int periods[100];
  for (int x = 0; x < 100; ++x) {
    periods[x] = random(min, max);
  }
  
  for (int x = 0; x < 100; ++x) {
    play(periods[x], 1);
  }
  for (int x = 100; x >= 0; --x) {
    play(periods[x], 1);
  }
}

void blink_eyes() {
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j <= 255; ++j) {
      analogWrite(RED_LED_PIN, j);
      delayMicroseconds(250);
    }
  analogWrite(RED_LED_PIN, 0);
  delay(25);
  }
}

void play_pcm() {
  DDRB = _BV(PB1);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = TCCR1B & 0b11111000 | 1;
  TCCR1B = _BV(WGM12) | _BV(CS10);
  OCR1A = 0;
  
  uint16_t total_samples = 0;
  uint16_t samples_read = 0;

  // keep track of sample count
  total_samples = sound_Wilhelm_4k.samples;

  // cue beginning
  cur_byte_ptr = sound_Wilhelm_4k.data;
  cur_byte = pgm_read_byte(cur_byte_ptr);
  cur_bit_idx = 0;

  int16_t next_sym;
  int16_t y=0, y_1=0, y_2=0;
  int16_t y_out;
  uint8_t y_out_real;
  
  while(samples_read < total_samples) {
    next_sym = get_next_symbol();
    //printf_P(PSTR("%d\r\n"), next_sym);
    samples_read++;
    
    // compute it
    //y = (next_sym) + (2*y_1) + (-y_2);
    y = (next_sym) + (y_1);
    
    // clip output
    y_out = y + 128;
    if(y_out < 0) {
      y_out_real = 0;
    } else if(y_out > 255) {
      y_out_real = 255;
    } else {
      y_out_real = y_out;
    }
    
    OCR1A = y_out_real;
    
    // shift
    y_2 = y_1;
    y_1 = y;
    
    delayMicroseconds(500);
  }

  
  
  
  OCR1A=0;
  //analogWrite(PIEZO_PIN, 0);
}

