template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}




template <unsigned N,unsigned M>
int compare(const char(&v1)[N], const char(&v2)[M]) {
	return strcmp(v1, v2);
}


#include <iostream>

int main()
{
	auto result = compare(13, 5);
	auto result2 = compare("hi", "hello");
	return 0;
}