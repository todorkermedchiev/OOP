#pragma once
#include <cstring>
#include <iostream>

typedef unsigned int u_int;

class Car {
private:
	char* model;
	u_int height;
	u_int weight;
	u_int length;
	u_int width;

	void copyFrom(const Car& other) {
		this->model = new char[strlen(other.model) + 1];
		strcpy(this->model, other.model);
		this->height = other.height;
		this->weight = other.weight;
		this->length = other.length;
		this->width = other.width;
	}

	void free() {
		delete[] model;
	}

public:
	Car(const char *model = "", u_int height = 0, u_int weight = 0, u_int length = 0, u_int width = 0) {
		model = nullptr;
		setModel(model);
		setHeight(height);
		setWeight(weight);
		setLength(length);
		setWidth(width);
	}

	Car(const Car& other) {
		copyFrom(other);
	}

	const Car& operator=(const Car& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	~Car() {
		free();
	}

	const char* getModel() const {
		return model;
	}

	u_int getHeight() const {
		return height;
	}

	u_int getWeight() const {
		return weight;
	}

	u_int getLength() const {
		return length;
	}

	u_int getWidth() const {
		return width;
	}

	void setModel(const char* model) {
		free();
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}

	void setHeight(u_int height) {
		this->height = height;
	}

	void setWeight(u_int weight) {
		this->weight = weight;
	}

	void setLength(u_int length) {
		this->length = length;
	}

	void setWidth(u_int width) {
		this->width = width;
	}

	void print() const {
		std::cout << "Model: " << model << std::endl;
		std::cout << "Height: " << height << std::endl;
		std::cout << "Weight: " << weight << std::endl;
		std::cout << "Length: " << length << std::endl;
		std::cout << "Width: " << width << std::endl;
	}
};