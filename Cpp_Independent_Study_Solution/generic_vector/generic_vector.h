#pragma once
#include <initializer_list>

template<typename gVector>
class gVectorReverseIterator {
public:
	using valueType = typename gVector::valueType;
	using pointerType = valueType*;
	using referenceType = valueType&;

public:
	// why is it possible to pass this as const? And why not as a reference too?
	gVectorReverseIterator(const pointerType ptr) : m_ptr(ptr) {}

	bool operator!=(const gVectorReverseIterator& other) const noexcept {
		return m_ptr != other.m_ptr;
	}

	referenceType operator*() {
		return *m_ptr;
	}

	gVectorReverseIterator& operator++() {
		m_ptr--;
		return *this;
	}

	gVectorReverseIterator operator++(int) {
		gVectorReverseIterator temp = *this;
		//++(*this);
		m_ptr--;
		return temp;
	}

	gVectorReverseIterator& operator--() {
		m_ptr++;
		return *this;
	}
	
	gVectorReverseIterator operator--(int) {
		gVectorReverseIterator temp = *this;
		m_ptr++;
		return temp;
	}

private:
	pointerType m_ptr;
};

template<typename gVector>
class gVectorIterator {
public:
	using valueType = typename gVector::valueType;
	using pointerType = valueType*;
	using referenceType = valueType&;

public:
	gVectorIterator(const pointerType ptr) : m_ptr(ptr) {}

	bool operator!=(const gVectorIterator& other) const noexcept {
		return m_ptr != other.m_ptr;
	}

	referenceType operator*() {
		return *m_ptr;
	}

	pointerType& operator->() {
		return m_ptr;
	}

	// prefix
	gVectorIterator& operator++() {
		++m_ptr;
		return *this;
	}

	// postfix
	gVectorIterator operator++(int) {
		gVectorIterator temp = *this;
		//++(*this);
		++m_ptr;
		return temp;
	}

private:
	pointerType m_ptr;
};

template<typename T>
class gVector {
public:
	using valueType = T;
	using Iterator = gVectorIterator<gVector<T>>;
	using ReverseIterator = gVectorReverseIterator<gVector<T>>;

public:
	ReverseIterator rbegin() {
		return ReverseIterator(m_data + m_current_size - 1);
	}

	ReverseIterator rend() {
		// must end one byte before the first element
		return ReverseIterator(m_data - 1);
	}

	Iterator begin() {
		return Iterator(m_data);
	}

	Iterator end() {
		// the iterator must end when it reaches an unitialized block of memory or when it overflows its memory
		return Iterator(m_data + m_current_size);
	}

	T pop_back() {
#ifdef _DEBUG
		if (m_current_size < 1) throw "Can't pop more than this";
#endif
		T temp = m_data[--m_current_size];
		m_data[m_current_size].~T();
		return temp;
	}

	template<typename ...Args>
	void emplace_back(Args&&... args) {
		if (m_current_size == m_total_size) {
			this->reserve(1 + m_total_size / 2);
		}
		new (&m_data[m_current_size++]) T(std::forward<Args>(args)...);
	}

	void push_back(T&& t) {
		if (m_current_size == m_total_size) {
			this->reserve(1 + m_total_size / 2);
		}
		// constroi o objeto no local de memoria designado
		new (&m_data[m_current_size++]) T(std::move(t));
	}

	size_t size() { return m_current_size; }

	T& at(const size_t& index) {
		return operator[](index);
	}

	void reserve(const size_t& r_size) {
		printf("reserved %zu\n", r_size);
		const size_t temp_size = r_size + m_total_size;
		T* temp_data = (T*) ::operator new(temp_size * sizeof(T));

		_move_construct(temp_data, m_data, m_current_size);

		// chama os destrutores ateh m_current_size (objetos além de m_current_size já foram destruídos / não foram construídos, então não é preciso chamar seus destrutores)
		_clear(m_data, m_current_size);
		// desaloca toda a memoria
		::operator delete(m_data, m_total_size * sizeof(T));

		m_data = temp_data;
		m_total_size = temp_size;
	}

	gVector() : 
		m_total_size(0), 
		m_current_size(0) {
		reserve(2);
	}

	gVector(const std::initializer_list<T>& list)
	{
		const size_t size = list.size();
		m_total_size = 0;
		reserve(size + size / 2);
		m_current_size = size;

		auto it = list.begin();
		for (size_t i = 0; i < size; ++i) 
			new (&m_data[i]) T(*(it + i));
	}

	gVector(const size_t& size) :
		m_total_size(size), 
		m_current_size(0) 
	{
		reserve(size);
		printf("Constructed\n");
	}

	// copy
	gVector(const gVector<T>& other) {
		printf("Constructed\n");
		m_current_size = other.m_current_size;
		m_total_size = other.m_total_size;

		m_data = (T*) ::operator new(m_total_size * sizeof(T));
		_copy_construct(m_data, other.m_data, m_current_size);
	}

	// move
	gVector(gVector<T>&& other) noexcept {
		printf("Move Constructed\n");
		m_current_size = other.m_current_size;
		m_total_size = other.m_total_size;
		m_data = other.m_data;

		other.m_current_size = 0;
		other.m_total_size = 0;
		other.m_data = nullptr;
	}

	~gVector() {
		printf("Destructed\n");
		// chama os destrutores ateh m_current_size (objetos além de m_current_size já foram destruídos / não foram construídos, então não é preciso chamar seus destrutores)
		_clear(m_data, m_current_size);
		// desaloca toda a memoria
		::operator delete(m_data, m_total_size * sizeof(T));
	}

	// assignment
	gVector<T>& operator=(const gVector<T>& other)
		= delete;
	/*{
		// its more than it looks, if the vectors are of distinct sizes, a new block needs to be allocated
		printf("Copied\n");
		if (this != &other) {
			m_current_size = other.m_current_size;
			m_total_size = other.m_total_size;
			_copyData(m_data, other.m_data, m_current_size);
		}
		return *this;
	}*/

	// move assignment
	gVector<T>& operator=(gVector<T>&& other) noexcept {
		printf("Moved\n");
		if (this != &other) {
			// chama os destrutores ateh m_current_size
			_clear(m_data, m_current_size);
			// desaloca toda a memoria
			::operator delete(m_data, m_total_size * sizeof(T));

			m_current_size = other.m_current_size;
			m_total_size = other.m_total_size;
			m_data = other.m_data;

			other.m_current_size = 0;
			other.m_total_size = 0;
			other.m_data = nullptr;
		}
		return *this;
	}

	T& operator[](const size_t& index) {
#ifdef _DEBUG
		if (m_current_size == 0 || index > m_current_size - 1)
			throw "No you don't";
#endif
		return m_data[index];
	}

private:
	void _clear(T* const& target, const size_t& size) {
		for (size_t i = 0; i < size; ++i)
			target[i].~T();
	}

	void _move_construct(T* const& dst_data, T* const& src_data, const size_t& size) noexcept {
		for (size_t i = 0; i < size; ++i)
			// placement new
			new (&dst_data[i]) T(std::move(src_data[i]));
	}

	void _copy_construct(T* const& dst_data, const T* const& src_data, const size_t& size) {
		for (size_t i = 0; i < size; ++i)
			new (&dst_data[i]) T(src_data[i]);
	}

private:
	size_t m_total_size;
	size_t m_current_size;
	T* m_data;
};