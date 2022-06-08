
#ifndef H_EEPROM_REPOSITORY
#define H_EEPROM_REPOSITORY

#include "../constants.h"
#include "../virtual/repository.h"
#include <EEPROM.h>

class EepromRepository : public AbstractRepository {
private:
  unsigned int address = 0;

public:
  void set(unsigned int *points) {
    int addressIndex = 0;
    for (int i = 0; i < HOLES; i++) {
      EEPROM.write(addressIndex, points[i] >> 8);
      EEPROM.write(addressIndex + 1, points[i] & 0xFF);
      addressIndex += 2;
    }

    EEPROM.commit();
  }

  void get(unsigned int *points) {
    int addressIndex = 0;
    for (int i = 0; i < HOLES; i++) {
      points[i] =
          (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
      addressIndex += 2;
    }
  }
};

#endif /* H_EEPROM_REPOSITORY */