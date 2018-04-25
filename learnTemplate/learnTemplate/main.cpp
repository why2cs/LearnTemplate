#include <vector>
#include <memory>
#include <string>
#include <utility>
#include <stdexcept>

template<typename T>class Blob {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T> il);

	size_type size() const;
	bool empty() const;
	
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back(); 

	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};


//template <typename T>
//inline int compare(const T &v1, const T &v2) {
//	if (v1 < v2) return -1;
//	if (v2 < v1) return 1;
//	return 0;
//}
//
//
//template <unsigned N,unsigned M>
//int compare(const char(&v1)[N], const char(&v2)[M]) {
//	return strcmp(v1, v2);
//}
//
//#include <functional>
//
//template <typename T>
//int compare(const T &v1, const T &v2) {
//	if (std::less<T>()(v1, v2)) return -1;
//	if (std::less<T>()(v2, v1)) return 1;
//	return 0;
//}
//
//
//#include <iostream>
//
//int main()
//{
//	int i = 6, j = 16;
//	int *ip = &i, *jp = &j;
//	auto result = compare(ip, jp);
//	auto result2 = compare("hi", "hello");
//	return 0;
//}

template<typename T>
Blob<T>::Blob()
{
	data = std::make_shared<std::vector<T>>();
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
{
	data = std::make_shared<std::vector<T>>(il);
}

template<typename T>
Blob<T>::size_type Blob<T>::size() const
{
	return data->size();
}

template<typename T>
bool Blob<T>::empty() const
{
	return data->empty();
}

template<typename T>
void Blob<T>::pop_back()
{
	if (!empty()) 
		data->pop_back();
}

template<typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T & Blob<T>::operator[](size_type i)
{
	check(i, "out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}


int main()
{
	return 0;
}