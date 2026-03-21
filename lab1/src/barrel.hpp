#ifndef BARREL_HPP
#define BARREL_HPP

class Barrel {
public:
  // Constructor: Initializes the barrel's state.
  Barrel(double capacity, double initial_alcohol_volume);

  // Getter: Provides a calculated view of the internal state.
  double get_alcohol_concentration() const;

  void transfer_from(Barrel &other, double volume);

private:
  
  double capacity;
  double alcohol_volume;
  double liquid_volume;
};

#endif 
