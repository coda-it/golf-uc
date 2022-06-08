#ifndef H_REPOSITORY
#define H_REPOSITORY

class AbstractRepository {
public:
  virtual void get(unsigned int *points) = 0;
  virtual void set(unsigned int *points) = 0;
};

#endif /* H_REPOSITORY */