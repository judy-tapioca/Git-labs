#include "barrel.hpp"

Barrel::Barrel(double capacity, double initial_alcohol_volume)
    : capacity(capacity), alcohol_volume(initial_alcohol_volume),
      liquid_volume(capacity) {}

double Barrel::get_alcohol_concentration() const {
  // Guard clause for division by zero.
  if (liquid_volume == 0)
    return 0;
  // Concentration is a percentage of alcohol in the total liquid.
  return (alcohol_volume / liquid_volume) * 100.0;
}


void Barrel::transfer_from(Barrel &other, double volume) {
  if (volume > other.liquid_volume)
    volume = other.liquid_volume;
  
  // TODO: add checks that assure that capacity is not overflown
  //Check that capacity is not overflown
    double available_space = capacity - liquid_volume;
    if (volume > available_space)
        volume = available_space;

  double alcohol_transferred =
      (other.alcohol_volume / other.liquid_volume) * volume;

  other.alcohol_volume -= alcohol_transferred;
  other.liquid_volume -= volume;

  this->alcohol_volume += alcohol_transferred; // this barrel gains the alcohol that left other
  this->liquid_volume += volume;// this barrel gains the total liquid
}
