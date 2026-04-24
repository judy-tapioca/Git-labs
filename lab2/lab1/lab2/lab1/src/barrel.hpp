#ifndef BARREL_HPP
#define BARREL_HPP

class Barrel {
public:
  
  Barrel(double capacity, double initial_alcohol_volume);

  double get_alcohol_concentration() const;

  void transfer_from(Barrel &other, double volume);

private:
  
  double capacity;
  double alcohol_volume;
  double liquid_volume;
};

#endif 
