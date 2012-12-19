#ifndef __SOUND_STRUCT_H
#define __SOUND_STRUCT_H

#include <avr/pgmspace.h>

typedef struct {
  uint16_t samples;	// size of huffman-encoded output
  uint16_t size;	// size of huffman-encoded thing in bytes
  PGM_P data;
} sound_t;

#endif
