#ifndef H_REPOSITORY
#define H_REPOSITORY

class AbstractRepository {
public:
  virtual void get() = 0;
  virtual void set() = 0;
};

#endif /* H_REPOSITORY */