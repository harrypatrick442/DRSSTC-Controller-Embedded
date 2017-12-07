

#include <string.h>
// Minimal class to replace std::vector
template<typename Data>
class volatile_vector {
	size_t d_size; // Stores no. of actually stored objects
	size_t d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data
	public:
	bool contains(Data const &d) volatile{
 for(size_t i=0; i<d_size; i++){
	if(d==d_data[i])return true;
 }
 return false;
	}
	volatile_vector() : d_size(0), d_capacity(0), d_data(0) {

	}; // Default constructor
	volatile_vector(volatile_vector const &other) : d_size(other.d_size), d_capacity(other.d_capacity), d_data(0) { d_data = (Data *)malloc(d_capacity*sizeof(Data)); memcpy(d_data, other.d_data, d_size*sizeof(Data)); }; // Copy constuctor
	~volatile_vector() { free(d_data); }; // Destructor
	volatile_vector &operator=(volatile_vector const &other) { free(d_data); d_size = other.d_size; d_capacity = other.d_capacity; d_data = (Data *)malloc(d_capacity*sizeof(Data)); memcpy(d_data, other.d_data, d_size*sizeof(Data)); return *this; }; // Needed for memory management
	void push_back(Data const &x) volatile { if (d_capacity == d_size) resize(); d_data[d_size++] = x; }; // Adds new value. If needed, allocates more space
	size_t size() volatile const { return d_size; }; // Size getter
	Data const &operator[](size_t idx)volatile const { return d_data[idx]; }; // Const getter
	Data &operator[](size_t idx)volatile { return d_data[idx]; }; // Changeable getter
	private:
	void resize() volatile { d_capacity = d_capacity ? d_capacity*2 : 1; Data *newdata = (Data *)malloc(d_capacity*sizeof(Data)); memcpy(newdata, d_data, d_size * sizeof(Data)); free(d_data); d_data = newdata; };// Allocates double the old space
	
};