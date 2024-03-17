#pragma once

template<typename T>
class GenericArray {
private:
	std::string m_name;
	T* m_data;
	uint32_t m_size;

public:
	// common constructor
	GenericArray(const std::string& name, const uint16_t& m_size);
	// copy constructor
	GenericArray(const GenericArray<T>& other);
	// move constructor
	GenericArray(GenericArray<T>&& other) noexcept;
	// destructor
	~GenericArray();
	// assignment operator
	GenericArray<T>& operator=(const GenericArray<T>& other);
	// move assignment operator
	GenericArray<T>& operator=(GenericArray<T>&& other) noexcept;
};

//----------------------------------------------------------------------------

template<typename T>
GenericArray<T>::GenericArray(const std::string& name, const uint16_t& m_size) :
	m_name(name), m_data(new T[m_size]), m_size(m_size) {
	std::cout << m_name << ": Inside Constructor\n";
}

template<typename T>
GenericArray<T>::GenericArray(const GenericArray<T>& other) {
	m_name = "(copy)" + other.m_name;
	m_data = new T[other.m_size];
	m_size = other.m_size;
	memcpy(m_data, other.m_data, sizeof(T) * other.m_size);
	std::cout << m_name << ": Inside Copy Constructor\n";
}

template<typename T>
GenericArray<T>::GenericArray(GenericArray<T>&& other) noexcept {
	m_name = std::move(other.m_name);
	m_data = other.m_data;
	m_size = other.m_size;
	other.m_name = "MOVED";
	other.m_data = nullptr;
	other.m_size = 0;
	std::cout << m_name << ": Inside Move Constructor\n";
}

template<typename T>
GenericArray<T>::~GenericArray() {
	std::cout << m_name << ": Inside Destructor\n";
	delete[] m_data;
}

template<typename T>
GenericArray<T>& GenericArray<T>::operator=(const GenericArray<T>& other) {
	if (this != &other) {
		delete[] m_data;
		m_name = "(copy)" + other.m_name;
		m_data = new T[other.m_size];
		m_size = other.m_size;
		memcpy(m_data, other.m_data, sizeof(T) * other.m_size);
		std::cout << m_name << ": Inside Assignment Operator\n";
	}
	return *this;
}

template<typename T>
GenericArray<T>& GenericArray<T>::operator=(GenericArray<T>&& other) noexcept {
	if (this != &other) {
		delete[] m_data;
		m_name = std::move(other.m_name);
		m_data = other.m_data;
		m_size = other.m_size;
		other.m_name = "MOVED";
		other.m_data = nullptr;
		other.m_size = 0;
		std::cout << m_name << ": Inside Move Assignment Operator\n";
	}
	return *this;
}