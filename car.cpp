#include "car.h"

struct CarImplementation{
  enum Type type;
  enum Color color;
  int speed;
  double fill_level;
  double acceleration_rate;
  double max_acceleration_rate;
  double min_acceleration_rate;
  bool available;
};

#define MAXCARS 6

struct CarImplementation aixam = {AIXAM, RED, 0, 16.0, 0, 1.0,-8.0, true};
struct CarImplementation multipla = {FIAT_MULTIPLA, GREEN, 0, 65.0, 0,2.26 ,-8.0, true};
struct CarImplementation multipla2 = {FIAT_MULTIPLA, BLUE, 0, 65.0, 0,2.26 ,-8.0, true};
struct CarImplementation multipla3 = {FIAT_MULTIPLA, ORANGE, 0, 65.0, 0,2.26 ,-8.0, true};
struct CarImplementation jeep = {JEEP, SILVER, 0, 80.0, 0, 3.14,-8.0, true};
struct CarImplementation jeep2 = {JEEP, BLACK, 0, 80.0, 0, 3.14,-8.0, true};

Car car_park[MAXCARS] = {&aixam, &multipla, &multipla2, &multipla3, &jeep, &jeep2 };

void init()
{
  for (int i = 0; i < MAXCARS; i++) {
    car_park[i]->available=true;
    car_park[i]->acceleration_rate=0;
  }
}

Car get_car(Type type)
{
  for (int i = 0; i < MAXCARS ; i++) {
    if (car_park[i]->type==type && car_park[i]->available==true) {
      car_park[i]->available=false;
      return car_park[i];
    }
  }
  return 0;
}
enum Type get_type(Car car)
{
  return car->type;
}
enum Color get_color(Car car)
{
  return car->color;
}
double get_fill_level(Car car)
{
  return car->fill_level;
}
double get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}
void set_acceleration_rate(Car car, double rate)
{
  if (rate <= car->max_acceleration_rate) {
    car->acceleration_rate=rate;
  }
  else{
    car->acceleration_rate=car->max_acceleration_rate;
  }
  //car->acceleration_rate=rate;
}
int get_speed(Car car)
{
  return car->speed;
}
void accelerate(Car car)
{

}
