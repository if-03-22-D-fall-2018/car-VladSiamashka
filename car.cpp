#include "car.h"

struct CarImplementation{
  enum Type type;
  enum Color color;
  int speed;
  double fill_level;
  double acceleration_rate;
  bool available;
};

#define MAXCARS 3

struct CarImplementation aixam = {AIXAM, RED, 0, 16.0, 0, true};
struct CarImplementation multipla = {FIAT_MULTIPLA, GREEN, 0, 65.0, 0, true};
struct CarImplementation jeep = {JEEP, RED, 0, 80.0, 0, true};

Car car_park[MAXCARS] = {&aixam, &multipla, &jeep };

void init()
{

}

Car get_car(Type type)
{
  for (int i = 0; i < MAXCARS ; i++) {
    if (car_park[i]->type==type && car_park[i]->available==true) {
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
  return 0.0;
}
void set_acceleration_rate(Car, double rate)
{

}
int get_speed(Car car)
{
  return 0;
}
void accelerate(Car car)
{

}
