#pragma once

#include <iostream>
#include "car.hpp"

enum Type {
	Petrol,
	Diesel
};

class FuelCar : public Car {
private:
	Type type;
	u_int fuelTankCapacity;
	u_int horsePower;

	void copyFrom(const FuelCar& other) {
		this->type = other.type;
		this->fuelTankCapacity = other.fuelTankCapacity;
		this->horsePower = other.horsePower;
	}

public:
	FuelCar(
		const char* model = "",
		u_int height = 0,
		u_int weight = 0,
		u_int length = 0,
		u_int width = 0,
		Type type = Petrol,
		u_int fuelTankCapacity = 0,
		u_int horsePower = 0
	) : Car(model, height, weight, length, width)
	{
		setType(type);
		setFuelTankCapacity(fuelTankCapacity);
		setHorsePower(horsePower);
	}

	Type getType() const {
		return type;
	}

	u_int getFuelTankCapacity() cosnt {
		return fuelTankCapacity;
	}

	u_int getHorsePower() const {
		return horsePower;
	}

	void setType(Type type) {
		this->type = type;
	}

	void setFuelTankCapacity(u_int fuelTankCapacity) {
		this->fuelTankCapacity = fuelTankCapacity;
	}

	void setHorsePower(u_int horsePower) {
		this->horsePower = horsePower;
	}

	void print() const {
		Car::print();
		std::cout << "Type: " << type << std::endl;
		std::cout << "Fuel tank capacity: " << fuelTankCapacity << std::endl;
		std::cout << "Horsepower: " << horsePower << std::endl;
	}
};