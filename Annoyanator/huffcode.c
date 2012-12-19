#include <inttypes.h>

extern uint8_t get_next_bit();

int16_t get_next_symbol() {
  if(get_next_bit() == 1) {
    if(get_next_bit() == 1) {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              return -8; // 111111
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 24; // 1111101111
                    } else {
                      return 23; // 1111101110
                    }
                  } else {
                    return -31; // 111110110
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 25; // 111110101
                  } else {
                    return -22; // 111110100
                  }
                }
              } else {
                return -14; // 1111100
              }
            }
          } else {
            if(get_next_bit() == 1) {
              return 9; // 111101
            } else {
              if(get_next_bit() == 1) {
                return 15; // 1111001
              } else {
                return 14; // 1111000
              }
            }
          }
        } else {
          return 0; // 1110
        }
      } else {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                return 13; // 1101111
              } else {
                if(get_next_bit() == 1) {
                  return -19; // 11011101
                } else {
                  if(get_next_bit() == 1) {
                    return -25; // 110111001
                  } else {
                    return 30; // 110111000
                  }
                }
              }
            } else {
              return 8; // 110110
            }
          } else {
            return 3; // 11010
          }
        } else {
          if(get_next_bit() == 1) {
            return -2; // 11001
          } else {
            if(get_next_bit() == 1) {
              return -9; // 110001
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return 31; // 11000011
                } else {
                  return 21; // 11000010
                }
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return 26; // 110000011
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return -45; // 11000001011
                      } else {
                        return -46; // 11000001010
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return -47; // 11000001001
                      } else {
                        return -50; // 11000001000
                      }
                    }
                  }
                } else {
                  return -20; // 11000000
                }
              }
            }
          }
        }
      }
    } else {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            return -5; // 10111
          } else {
            if(get_next_bit() == 1) {
              return 11; // 101101
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return -24; // 10110011
                } else {
                  return -27; // 10110010
                }
              } else {
                if(get_next_bit() == 1) {
                  return 20; // 10110001
                } else {
                  return 19; // 10110000
                }
              }
            }
          }
        } else {
          if(get_next_bit() == 1) {
            return 5; // 10101
          } else {
            return 4; // 10100
          }
        }
      } else {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            return -4; // 10011
          } else {
            return -6; // 10010
          }
        } else {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              return -12; // 100011
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return -51; // 10001011111
                      } else {
                        return -52; // 10001011110
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return -53; // 10001011101
                      } else {
                        return -57; // 10001011100
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 56; // 10001011011
                      } else {
                        return 55; // 10001011010
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return 47; // 10001011001
                      } else {
                        return 46; // 10001011000
                      }
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 44; // 10001010111
                      } else {
                        return 42; // 10001010110
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return 41; // 10001010101
                      } else {
                        return 28; // 10001010100
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return -33; // 1000101001
                    } else {
                      return -34; // 1000101000
                    }
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return -37; // 1000100111
                    } else {
                      return -38; // 1000100110
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return -39; // 1000100101
                    } else {
                      return -40; // 1000100100
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return -41; // 1000100011
                    } else {
                      return -43; // 1000100010
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return 53; // 1000100001
                    } else {
                      return 49; // 1000100000
                    }
                  }
                }
              }
            }
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 40; // 1000011111
                    } else {
                      return 39; // 1000011110
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return 38; // 1000011101
                    } else {
                      return 35; // 1000011100
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return -26; // 100001101
                  } else {
                    return -30; // 100001100
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return -42; // 100001011
                  } else {
                    return 36; // 100001010
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 34; // 100001001
                  } else {
                    return 32; // 100001000
                  }
                }
              }
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return -23; // 10000011
                } else {
                  return 22; // 10000010
                }
              } else {
                return -17; // 1000000
              }
            }
          }
        }
      }
    }
  } else {
    if(get_next_bit() == 1) {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          return 1; // 0111
        } else {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                return 16; // 0110111
              } else {
                return 18; // 0110110
              }
            } else {
              return -10; // 011010
            }
          } else {
            return 7; // 01100
          }
        }
      } else {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            return 6; // 01011
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                return 17; // 0101011
              } else {
                if(get_next_bit() == 1) {
                  return -21; // 01010101
                } else {
                  return 27; // 01010100
                }
              }
            } else {
              if(get_next_bit() == 1) {
                return -16; // 0101001
              } else {
                return -18; // 0101000
              }
            }
          }
        } else {
          return -1; // 0100
        }
      }
    } else {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              return 12; // 001111
            } else {
              return -11; // 001110
            }
          } else {
            if(get_next_bit() == 1) {
              return -15; // 001101
            } else {
              return 10; // 001100
            }
          }
        } else {
          if(get_next_bit() == 1) {
            return -7; // 00101
          } else {
            if(get_next_bit() == 1) {
              return -13; // 001001
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 33; // 0010001111
                    } else {
                      return -32; // 0010001110
                    }
                  } else {
                    return -28; // 001000110
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return -29; // 001000101
                  } else {
                    return -35; // 001000100
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return -36; // 001000011
                  } else {
                    return 45; // 001000010
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 37; // 001000001
                  } else {
                    return 29; // 001000000
                  }
                }
              }
            }
          }
        }
      } else {
        if(get_next_bit() == 1) {
          return 2; // 0001
        } else {
          return -3; // 0000
        }
      }
    }
  }
}
