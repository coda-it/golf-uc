#ifndef H_STORE_REPOSITORY
#define H_STORE_REPOSITORY

#include "../datasources/eeprom.h"
#include "../datasources/wifi.h"
#include "./abstract.h";

class StoreRepository : public AbstractRepository {
private:
  EepromDataSource eepromDataSource;

public:
  void set(unsigned int *points) { this->eepromDataSource.set(points); }

  void get(unsigned int *points) { this->eepromDataSource.get(points); }
};

#endif /* H_STORE_REPOSITORY */