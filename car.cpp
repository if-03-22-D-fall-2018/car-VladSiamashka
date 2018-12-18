#include "car.h"

struct CarImplementation{
  enum Type type;
  enum Color color;
  double speed;
  double fill_level;
  double acceleration_rate;
  double max_acceleration_rate;
  double min_acceleration_rate;
  bool available;
  int max_speed;
};

#define MAXCARS 6

struct CarImplementation aixam = {AIXAM, RED, 0.0, 16.0, 0.0, 1.0,-8.0, true, 45};
struct CarImplementation multipla = {FIAT_MULTIPLA, GREEN, 0.0, 65.0, 0.0,2.26 ,-8.0, true, 170};
struct CarImplementation multipla2 = {FIAT_MULTIPLA, BLUE, 0.0, 65.0, 0.0,2.26 ,-8.0, true, 170};
struct CarImplementation multipla3 = {FIAT_MULTIPLA, ORANGE, 0.0, 65.0, 0.0,2.26 ,-8.0, true, 170};
struct CarImplementation jeep = {JEEP, SILVER, 0.0, 80.0, 0.0, 3.14,-8.0, true, 196};
struct CarImplementation jeep2 = {JEEP, BLACK, 0.0, 80.0, 0.0, 3.14,-8.0, true, 196};

Car car_park[MAXCARS] = {&aixam, &multipla, &multipla2, &multipla3, &jeep, &jeep2 };

void init()
{
  for (int i = 0; i < MAXCARS; i++) {
    car_park[i]->available=true;
    car_park[i]->acceleration_rate=0;
    car_park[i]->speed=0;
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
  if (rate <= car->max_acceleration_rate&&rate>=car->min_acceleration_rate) {
    car->acceleration_rate=rate;
  }
  else if(rate<0){
    car->acceleration_rate=car->min_acceleration_rate;
  }
  else{
    car->acceleration_rate=car->max_acceleration_rate;
  }
}
int get_speed(Car car)
{
  if (car->speed - (int)car->speed>=0.5) {
    return (int)car->speed+1;
  }
  return (int)car->speed;
}
void accelerate(Car car)
{
  double speed=car->acceleration_rate*3.6;
  if (car->speed+speed < car->max_speed) {
    car->speed+=speed;
  }
  else if (car->speed < car->max_speed){
    speed=car->max_speed-car->speed;
    car->speed+=speed;
  }
}
