

#ifndef __SIMPLEVECTOR_H__
#define __SIMPLEVECTOR_H__
#include <string.h>
#include <stdlib.h>
// Minimal class to replace std::vector
template<typename Data>
class    simple_vector {
	size_t d_size; // Stores no. of actually stored objects
	size_t d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data
	public:
	bool contains(Data const &d) {
		for(size_t i=0; i<d_size; i++){
			if(d==d_data[i])return true;
		}
		return false;
	}
	simple_vector() : d_size(0), d_capacity(0), d_data(0) {

	}; // Default constructor
	simple_vector(   simple_vector const &other) : d_size(other.d_size), d_capacity(other.d_capacity), d_data(0)
	{
		d_data = (Data *)malloc (d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~simple_vector() {
		free(d_data);
	}; // Destructor

	simple_vector &operator=(   simple_vector const &other) {
		free(d_data); d_size = other.d_size; d_capacity = other.d_capacity; d_data = (Data *)malloc(d_capacity*sizeof(Data)); memcpy(d_data, other.d_data, d_size*sizeof(Data)); return *this;
	}; // Needed for memory management

	void push_back(Data const &x)  {
		if (d_capacity == d_size) resize(); d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space
	void erase(size_t idx){
		d_size--;
		size_t from=(idx+1)* sizeof(Data);
		size_t ncpy=(d_size * sizeof(Data)) - from;
		memcpy(d_data, d_data[from],ncpy);
	}
	size_t index_of(Data const & x)
	{
		for(size_t i=0; i<d_size; i++){
			if(d_data[i]==x)
			return i;
		}
		return -1;
	}
	void erase(Data const & x){
		size_t idx=index_of(x);
		if(idx>=0)
		erase(idx);
	}
	size_t size()  const {
		return d_size;
	}; // Size getter

	Data const &operator[](size_t idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](size_t idx) {
		return d_data[idx];
	}; // Changeable getter

	private:
	void resize()  {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data); d_data = newdata;
	};// Allocates double the old space
	
};
#endif