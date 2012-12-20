#include <avr/sleep.h>
#include <avr/power.h>#include <avr/pgmspace.h>

//TypeDefs
// This will make it easier to name annoy functions, and make it really easy to call them later.
// Downside: no argument passing- all annoy functions will have to have the same API.
typedef void (*annoyFunctionPtr)(void);

// defines
#define SERIAL_DEBUG

const uint8_t sample_data[] PROGMEM = {
	255,81,61,245,210,112,94,255,157,0,165,220,90,72,212,217,27,182,255,54,82,182,158,71,22,231,187,72,216,115,190,173,28,239,113,0,228,219,83,76,235,207,0,105,176,134,114,143,178,80,173,214,15,142,243,124,111,34,170,126,7,228,178,122,160,100,241,165,60,244,155,24,115,255,165,0,152,161,32,213,236,3,33,255,255,67,129,251,130,89,171,144,118,123,134,164,6,84,231,4,
	75,255,140,31,136,255,114,0,228,114,11,221,158,52,79,217,246,6,75,163,76,195,58,57,254,94,155,216,71,136,134,129,124,96,246,147,88,255,110,157,213,92,238,127,143,186,5,195,138,9,192,161,135,79,115,185,1,140,159,0,196,239,133,35,65,204,32,115,188,0,125,254,140,68,129,159,63,181,145,0,168,255,67,54,255,151,81,255,103,1,246,212,67,112,200,155,95,205,98,36,
	247,228,92,66,177,116,1,193,117,0,229,255,32,70,250,33,88,224,0,84,236,123,86,139,112,133,216,143,51,168,255,102,0,204,225,52,228,153,12,251,214,0,59,255,116,87,232,19,39,255,146,21,193,79,44,233,41,9,255,168,48,254,131,95,255,135,51,159,182,105,164,148,74,255,175,0,201,255,119,146,62,65,228,22,27,255,116,18,248,108,59,138,119,255,97,8,164,166,67,76,
	163,45,135,187,0,112,255,101,0,166,127,111,199,37,59,198,83,133,89,40,213,32,31,255,84,7,252,196,0,0,213,191,20,210,188,79,164,143,95,135,196,121,77,127,205,110,3,132,137,148,159,73,136,178,126,100,112,255,168,0,194,210,0,111,255,101,13,98,175,208,76,193,176,82,225,192,90,120,247,166,38,108,231,109,5,141,121,204,203,61,140,170,99,146,185,80,198,225,51,143,
	184,90,134,176,82,172,249,73,91,179,92,99,182,122,81,151,175,94,81,164,150,154,111,102,255,136,3,170,223,72,110,191,25,66,199,90,101,192,81,139,255,80,157,255,55,61,255,173,49,241,176,69,167,169,84,163,229,75,197,139,44,255,98,0,255,202,4,205,147,69,255,140,59,149,152,110,147,136,94,249,210,4,73,214,146,65,177,114,4,191,74,29,255,130,144,255,31,143,246,2,
	77,201,71,144,215,65,183,255,10,32,184,110,114,175,86,160,253,92,103,195,132,65,145,180,75,114,175,107,102,155,112,115,99,172,249,17,58,234,23,0,255,177,33,245,177,0,129,255,101,119,191,116,172,117,132,210,72,195,226,27,227,201,36,255,130,27,188,84,207,186,43,255,150,59,255,129,4,215,235,39,196,254,0,57,239,78,128,144,2,151,232,48,53,214,48,91,168,0,191,255,
	0,131,255,12,24,255,100,15,255,150,0,185,248,114,110,44,158,107,98,214,33,187,191,65,253,74,52,255,39,69,237,106,119,171,107,131,157,129,95,143,168,98,155,144,90,209,123,0,150,151,66,111,177,196,52,157,255,4,36,228,69,120,104,76,243,40,118,253,32,159,235,139,75,46,255,162,0,245,151,21,137,102,207,98,87,250,68,154,250,98,64,204,248,0,58,255,60,113,255,45,
	161,231,34,202,158,112,235,99,171,194,0,129,189,0,156,211,112,107,69,252,136,44,243,63,0,250,247,9,57,255,168,0,190,164,73,159,9,166,189,27,215,78,70,241,83,78,99,214,232,0,119,255,55,179,172,79,200,73,182,147,20,241,151,10,73,229,244,0,117,230,0,157,180,53,233,86,116,209,0,179,202,0,165,249,60,177,126,152,203,17,194,123,34,214,49,151,181,0,201,119,
	106,244,48,182,176,73,225,96,143,119,102,255,47,125,239,0,65,184,156,140,73,178,155,0,131,156,151,97,107,244,49,83,255,125,57,251,134,113,123,124,240,41,129,243,62,176,101,120,189,27,184,120,85,143,91,169,121,233,145,74,215,120,160,117,149,227,117,121,71,170,103,56,255,65,87,242,58,187,166,113,243,35,142,255,47,173,217,32,142,255,135,47,216,206,84,100,241,193,0,110,
	255,34,42,255,60,82,255,87,189,184,66,253,93,97,252,28,129,255,62,0,203,235,125,119,81,184,80,0,225,123,0,166,255,35,71,243,47,125,142,104,223,41,165,199,27,244,170,77,121,49,160,77,51,154,191,95,104,214,58,181,228,4,69,255,189,0,160,255,82,43,116,244,140,17,253,126,30,255,75,99,240,41,187,152,38,254,80,80,255,28,82,255,35,57,228,17,133,181,44,236,
	112,50,255,157,0,211,208,26,224,129,87,240,33,140,167,2,230,143,9,255,184,0,182,178,16,205,109,129,202,47,216,127,63,255,128,0,168,255,79,175,173,112,130,55,214,92,70,218,110,63,60,208,90,59,232,103,151,94,116,171,10,203,161,0,211,250,10,163,180,91,136,52,218,147,0,240,214,34,241,151,70,216,144,184,64,107,226,9,147,252,15,0,188,202,27,191,225,94,51,155,
	220,3,99,228,2,80,255,120,9,150,193,181,46,130,233,25,158,255,22,111,220,56,196,114,86,169,67,216,110,92,255,78,0,255,193,27,144,116,191,115,50,247,64,122,255,6,146,213,16,218,154,89,248,67,168,191,36,241,135,0,228,255,37,96,138,119,194,47,178,160,51,246,52,43,255,41,108,255,59,169,152,54,224,55,121,255,0,126,255,39,146,175,99,255,70,107,238,35,199,165,
	27,213,96,165,204,0,185,185,15,243,121,0,215,77,52,194,73,162,106,31,254,80,28,255,64,105,229,14,145,128,89,252,35,116,255,10,157,229,0,139,167,20,166,85,172,213,3,208,183,0,208,202,7,239,173,37,195,74,177,206,1,209,137,28,255,74,55,255,53,142,191,39,243,120,56,254,36,96,255,36,138,235,52,234,157,38,247,70,90,255,26,112,250,0,136,180,6,207,110,87,
	247,23,143,233,0,180,209,0,224,181,54,250,93,126,245,33,199,201,0,230,177,0,209,130,14,217,80,132,188,0,213,207,3,239,171,18,251,120,95,251,53,178,200,25,250,152,7,255,120,7,235,73,96,213,68,225,129,43,255,90,12,255,97,53,255,78,122,209,46,227,123,5,249,86,77,255,70,161,250,0,153,167,50,239,75,80,255,30,53,236,14,125,253,36,192,186,59,255,90,14,
	255,103,116,255,64,200,222,26,225,134,63,247,46,104,255,12,97,212,0,158,162,0,216,104,42,255,50,59,255,76,171,210,30,237,144,39,255,68,34,211,15,140,211,11,199,125,8,230,55,40,255,77,118,240,16,185,217,47,236,134,119,248,14,136,255,31,145,187,7,223,167,40,252,96,84,255,66,189,214,12,223,166,61,241,64,88,255,72,181,208,0,183,171,0,170,77,32,250,87,146,
	255,0,109,255,49,191,220,49,252,146,2,224,76,79,238,25,165,215,0,159,143,39,181,24,46,255,40,77,255,55,114,229,117,200,108,86,255,101,63,207,61,170,180,44,255,168,44,238,87,132,255,25,132,230,47,220,207,28,212,155,65,209,61,93,224,29,129,179,1,184,126,0,206,66,78,254,12,99,196,56,231,132,106,255,49,116,255,28,119,180,53,249,126,0,214,77,123,244,0,128,
	190,0,207,128,0,229,93,109,245,7,144,180,25,242,111,48,254,69,157,231,0,177,172,39,253,82,27,251,53,112,224,0,148,164,37,244,76,42,239,35,136,206,0,183,171,27,235,72,51,254,43,138,208,1,211,159,33,255,80,70,253,23,126,217,0,168,170,20,218,64,55,238,17,129,213,0,172,159,1,224,94,62,228,23,156,220,0,192,162,16,237,79,50,243,30,131,213,0,181,158,
	0,238,104,35,238,32,106,230,18,192,157,4,240,97,56,253,28,102,215,0,170,170,3,226,99,55,253,37,116,238,14,189,170,2,233,108,66,255,33,101,237,10,175,181,6,238,122,31,255,66,87,239,31,187,200,0,231,143,12,230,64,88,246,10,148,207,14,227,140,19,254,89,80,255,32,117,219,14,213,179,8,221,88,77,255,43,104,226,23,208,201,0,209,122,36,255,67,87,245,15,
	159,224,39,242,153,41,255,102,99,255,42,156,239,0,154,165,0,229,131,28,255,68,65,255,57,155,227,10,217,201,0,184,107,51,255,65,34,219,15,119,221,0,173,203,16,226,135,85,255,49,126,255,7,96,165,35,248,140,0,208,72,30,210,9,107,229,0,162,195,1,223,133,10,242,72,69,218,52,214,205,0,190,148,0,196,58,44,242,25,102,190,0,190,168,0,195,74,40,217,13,
	123,207,0,170,133,19,238,59,49,225,23,150,182,0,228,157,47,255,77,114,246,19,183,204,30,235,115,77,255,55,117,246,7,165,184,10,242,129,16,240,60,84,226,10,176,191,11,213,86,52,255,34,109,230,9,182,168,0,239,138,25,246,66,91,225,3,169,187,7,215,94,60,251,27,106,201,8,195,127,4,255,98,38,241,45,128,198,1,200,126,45,234,41,129,218,0,187,144,45,248,
	52,76,255,17,119,224,10,187,135,18,239,65,79,212,17,189,164,3,232,106,91,252,11,120,224,0,179,165,15,227,79,81,242,26,158,169,32,245,84,51,220,28,161,177,0,223,131,35,234,50,118,205,1,193,135,31,206,40,142,207,0,174,115,72,247,16,75,209,9,172,142,0,220,82,68,229,26,154,161,28,239,74,42,203,34,176,160,0,223,142,80,245,26,117,244,8,178,178,16,222,
	87,89,246,24,136,151,59,255,73,48,221,35,171,188,0,214,144,19,228,54,87,225,4,162,167,28,215,60,95,228,13,168,157,55,253,55,59,228,37,167,147,0,239,117,43,232,35,129,215,10,198,130,48,230,39,135,211,11,199,122,63,253,34,98,206,0,190,155,13,242,86,72,247,31,147,177,17,233,105,61,224,32,168,186,0,218,119,71,255,36,94,207,36,214,125,31,227,65,153,186,
	};

int MIN_COUNTER_TRIGGER; 
int MAX_COUNTER_TRIGGER; 

// default values slowly get reduced in size as time goes on.
int DEFAULT_MIN_COUNTER_TRIGGER = 37; // 37 * 8 sec = 5 minutes (approximately)
int DEFAULT_MAX_COUNTER_TRIGGER = 60; // 60 * 8 sec = 8 minutes
int const DEMO_MIN_COUNTER_TRIGGER = 2;
int const DEMO_MAX_COUNTER_TRIGGER = 5;

int const DEFAULT_WATCHDOG_PARAM = 9; // 9 = 8 sec
int const DEMO_WATCHDOG_PARAM = 7; // 7 = 2 sec

long const DAY = 10800; // 10800 * 8 sec = 24 hours

long counter_trigger;
long const DEFAULT_INITIAL_COUNTER_TRIGGER = 300/8; // 5 minutes
long const DEMO_INITIAL_COUNTER_TRIGGER = 3;

long active_counter = 0; // how many watchdog timeouts we've been active for, after initial delay
boolean started = false; // don't start decreasing the default triggers until after the initial trigger

boolean demo_mode;

//int DUTY = 5; // quiet
int const SOUND_DUTY = 30;

// updated by Watchdog interrupt, hence 'volatile'
volatile long watchdog_counter = 0;

// outputs
byte const PIEZO_PIN = 9;
byte const RED_LED_PIN = 10;
byte const BLUE_LED_PIN =11;
byte const LEFT_PAGER_MOTOR_PIN = 7;
byte const RIGHT_PAGER_MOTOR_PIN = 6;

// inputs
// High = Demo, Low = hidden
byte const DEMO_CONFIG_PIN = 5;
// LOW = do stuff when dark, HIGH = do stuff when light
// NB- LDR needs to be on highside of voltage divider
byte const LIGHT_LEVEL_CONFIG_PIN = 4;
// using pin 2 as it could be used to drive interrupts
byte const LDR_PIN = 2;

// annoy functions
annoyFunctionPtr AnnoyFunctionArray[] = { &annoy0, &annoy1, &annoy2, &annoy3, &annoy4, &annoy5,  &play_pcm, &flash_eyes, &flash_body,  &pulse_eyes, &pulse_body, &spin_motors};
//annoyFunctionPtr AnnoyFunctionArray[] = {&spin_motors};

unsigned int NumberOfAnnoyFunctions = sizeof(AnnoyFunctionArray) / sizeof(annoyFunctionPtr);

void doConfig() {
  if (demo_mode) 
  {
    MIN_COUNTER_TRIGGER = DEMO_MIN_COUNTER_TRIGGER;
    MAX_COUNTER_TRIGGER = DEMO_MAX_COUNTER_TRIGGER;
    setup_watchdog(DEMO_WATCHDOG_PARAM);
  }
  else 
  {
    MIN_COUNTER_TRIGGER = DEFAULT_MIN_COUNTER_TRIGGER;
    MAX_COUNTER_TRIGGER = DEFAULT_MAX_COUNTER_TRIGGER;
    setup_watchdog(DEFAULT_WATCHDOG_PARAM);
  }
}

void newTriggerCounter() {
  counter_trigger = random(MIN_COUNTER_TRIGGER, MAX_COUNTER_TRIGGER);
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
  pinMode(DEMO_CONFIG_PIN,INPUT);
  
  randomSeed(millis());

  demo_mode = digitalRead(DEMO_CONFIG_PIN);
  doConfig();  
  
  // Set up hardware power down options  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); 

  ADCSRA &= ~(1<<ADEN); //Disable ADC
  ACSR = (1<<ACD); //Disable the analog comparator
  DIDR0 = 0x3F; //Disable digital input buffers on all ADC0-ADC5 pins

  sei();
    
  newTriggerCounter();
  
  counter_trigger += (demo_mode ? DEMO_INITIAL_COUNTER_TRIGGER : DEFAULT_INITIAL_COUNTER_TRIGGER);
  
    // flip the safety switch - sleep commands will now cause the system to powerdown
  sleep_enable();

}


void loop(){
  #ifdef SERIAL_DEBUG
  Serial.print("Sleeping...");
  Serial.flush();
  delay(20);
  
  #endif
  sleep_mode();

  #ifdef SERIAL_DEBUG
  Serial.println("awake");
  #endif

  demo_mode = digitalRead(DEMO_CONFIG_PIN);

  if (started && !demo_mode) {
    active_counter++;
  }

  // reduce default delay intervals every two days or so.
  if (active_counter >= DAY*2) {
    active_counter = 0;
    
    // halve the defaults...
    DEFAULT_MIN_COUNTER_TRIGGER = DEFAULT_MIN_COUNTER_TRIGGER / 2;
    DEFAULT_MAX_COUNTER_TRIGGER = DEFAULT_MAX_COUNTER_TRIGGER / 2;
  }

  doConfig();  // we can switch from demo to 'hidden' mode on the fly & this will update the default durations between activations
  
  if (watchdog_counter >= counter_trigger) {
    watchdog_counter = 0;
    newTriggerCounter();
    started = true;
    if (digitalRead(LIGHT_LEVEL_CONFIG_PIN) == digitalRead(LDR_PIN)) {
      Serial.println("LDR level & light config match! ")
      Serial.println("Value is:");
      Serial.println(digitalRead(LIGHT_LEVEL_CONFIG_PIN));
      
      annoy();
    } 
  }
}
  

// 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
// 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec
void setup_watchdog(int ii) {

  byte bb;
  int ww;
  if (ii > 9 ) ii=9;
  bb=ii & 7;
  if (ii > 7) bb|= (1<<5);
  bb|= (1<<WDCE);
  ww=bb;

  MCUSR &= ~(1<<WDRF);
  // start timed sequence
  WDTCR_REG |= (1<<WDCE) | (1<<WDE);
  // set new watchdog timeout value
  WDTCR_REG = bb;
  WDTCR_REG |= _BV(WDIE);
}


// executed when watchdog timer expires
ISR(WDT_vect) {
  watchdog_counter++;  // increment volatile
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

void flash_led(byte pin) {
  byte cycles = random(5, 20);
  byte incr = random(1,5);
  unsigned int del = random (50, 500 + 500 / (cycles / incr ));
  
  for(int i = 0; i < cycles; ++i) {
    for(int j = 0; j <= 255-incr; j += incr) {
      analogWrite(pin, j);
      delayMicroseconds(del);
    }
  analogWrite(pin, 0);
  }
}

void flash_eyes() {
  flash_led(RED_LED_PIN);
}

void flash_body() {
  flash_led(BLUE_LED_PIN);
}

void pulse_led(byte pin) {
  byte cycles = random(5,10);
  byte incr = random(1,10);
  unsigned int del = random(10, 125);
  byte i,j;

  for (i=0; i<cycles; ++i){
    for(j=0; j<=255-incr; j += incr) {
      analogWrite(pin, j);
      delay(del);
    }
    for(j=255; j>incr; j -= incr) {
      analogWrite(pin, j);
      delay(del);
    }
  }
  analogWrite(pin,0);
  
}

void pulse_eyes() {
  pulse_led(RED_LED_PIN);
}

void pulse_body() {
  pulse_led(BLUE_LED_PIN);
}

void spin_motors() {
  byte motors_to_use = random(1,4);
  unsigned int del = random(250, 2500);
   // ah bit masks :)
   if (motors_to_use & 1) {
     digitalWrite(LEFT_PAGER_MOTOR_PIN, HIGH);
       #ifdef SERIAL_DEBUG
       Serial.println("Left motor on");
       #endif
   }
   if (motors_to_use & 2) {
     digitalWrite(RIGHT_PAGER_MOTOR_PIN, HIGH);
       #ifdef SERIAL_DEBUG
       Serial.println("Right motor on");
       #endif

   }
   
   delay(del);
   digitalWrite(LEFT_PAGER_MOTOR_PIN, LOW);
   digitalWrite(RIGHT_PAGER_MOTOR_PIN, LOW);   
}      

void play_pcm() {
  DDRB = _BV(PB1);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = TCCR1B & 0b11111000 | 1;
  TCCR1B = _BV(WGM12) | _BV(CS10);
  OCR1A = 0;
  
  for (int i=0; i<sizeof(sample_data)/sizeof(uint8_t) ; ++i) {
    OCR1A = pgm_read_byte(&sample_data[i]);
    delayMicroseconds(250);
  }
  
  
  
  OCR1A=0;
  //analogWrite(PIEZO_PIN, 0);
}

