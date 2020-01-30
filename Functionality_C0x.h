#pragma once
#ifndef FUNCTIONALITY_C0X_H
#define FUNCTIONALITY_C0X_H

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <climits>
#include <ctime>
#include <exception>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
#include <iterator>
#include <chrono>
#include <type_traits>
#include <thread>
#include <ctime>
#include <ratio>
#include <fstream>
#include <functional>

#include <vector>
#include <memory>
#include <bitset>
#include <type_traits>
#include <numeric>



#define _STD	::std::
#define _STD_S	_STD string
#define _STD_VECTOR_INT	_STD vector<int>
#define _STD_VECTOR_DOUBLE	_STD vector<double>
#define _STD_VECTOR_MATRIX_INT	_STD vector<_STD_VECTOR_INT>
#define _STD_VECTOR_MATRIX_INT_CODE	_STD vector<_STD_VECTOR_INT>
#define _STD_VECTOR_STRING	_STD vector<_STD_S>
#define _STD_VECTOR_MATRIX_STRING	_STD vector<_STD_VECTOR_STRING>
#define _STD_VECTOR_DOUBLE	_STD vector<double>
#define _STD_VECTOR_PAIR	_STD vector<std::pair <int,_STD_S> >
#define _STD_VECTOR_T	_STD vector


template<typename T>
T variance(const std::vector<T> &vec)
{
	size_t sz = vec.size();
	if (sz == 1)
		return 0.0;

	// Calculate the mean
	T mean = std::accumulate(vec.begin(), vec.end(), 0.0) / sz;

	// Now calculate the variance
	auto variance_func = [&mean, &sz](T accumulator, const T& val)
	{
		return accumulator + ((val - mean)*(val - mean) / (sz - 1));
	};

	return std::accumulate(vec.begin(), vec.end(), 0.0, variance_func);
}

template<typename T>
T mean_t(const std::vector<T> &vec)
{
	size_t sz = vec.size();
	if (sz == 1)
		return 0.0;

	// Calculate the mean
	T mean_t = std::accumulate(vec.begin(), vec.end(), 0.0) / sz;

	return mean_t;
}

template<typename T>
T sum_t(const std::vector<T> &vec)
{
	size_t sz = vec.size();
	if (sz == 1)
		return 0.0;

	// Calculate the mean
	T sum_t = std::accumulate(vec.begin(), vec.end(), 0.0);

	return sum_t;
}

template<typename T>
T product_t(const std::vector<T> &vec_1, const std::vector<T> &vec_2)
{
	if ( vec_1.size() != vec_2.size() )
		return -1.0;

	T product_t = std::inner_product(vec_1.begin(), vec_1.end(), vec_2.begin(), 0);

	return product_t;
}

template<typename T>
_STD_VECTOR_T <T> sumbyelement_t(_STD_VECTOR_T <T> &vec_1, _STD_VECTOR_T <T> &vec_2)
{
	_STD_VECTOR_T <T> tmp;
	if (vec_1.size() != vec_2.size()){
		_STD_VECTOR_T <T> return_error;
		return return_error;
	}
	_STD transform(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.begin(), _STD plus<T>());

	return vec_1;
}

template<typename T>
_STD_VECTOR_T <T> minusbyelement_t(_STD_VECTOR_T <T> &vec_1, _STD_VECTOR_T <T> &vec_2)
{
	_STD_VECTOR_T <T> tmp;
	if (vec_1.size() != vec_2.size()) {
		_STD_VECTOR_T <T> return_error;
		return return_error;
	}
	_STD transform(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.begin(), _STD minus<T>());

	return vec_1;
}



namespace ns_Functionality
{

	class cl_Functionality
	{
	public:

		_STD_VECTOR_DOUBLE duration_slice;
		_STD_VECTOR_DOUBLE duration_parsing;
		bool b_window_ms;
		double mean;
		double variance;
		int index_tab;
		int window_ms;
		static cl_Functionality *s_instance;

		static cl_Functionality *instance()
		{
			if (!s_instance)
				s_instance = new cl_Functionality();
			return s_instance;
		}

	};

	cl_Functionality *cl_Functionality::s_instance = 0;


	inline cl_Functionality& il_SetIndexTab(const int tab) {
		ns_Functionality::cl_Functionality::instance()->index_tab = tab;
		return *ns_Functionality::cl_Functionality::instance();
	}

	inline int il_GetIndexTab() {
		return ns_Functionality::cl_Functionality::instance()->index_tab;
	}

	template<typename T>
	T  inline il_GetMean(const _STD_VECTOR_T <T> &vec) {
		return mean_t< T >(vec);
	}

	template<typename T>
	T  inline il_GetSum(const _STD_VECTOR_T <T> &vec) {
		return sum_t< T >(vec);
	}

	template<typename T>
	T  inline il_GetProduct(const _STD_VECTOR_T <T> &vec_1, const _STD_VECTOR_T <T> &vec_2) {
		return product_t< T >(vec_1, vec_2);
	}


	template<typename T>
	_STD_VECTOR_T <T> inline il_GetSumByElement(_STD_VECTOR_T <T> &vec_1, _STD_VECTOR_T <T> &vec_2) {
		return sumbyelement_t< T >(vec_1, vec_2);
	}

	template<typename T>
	_STD_VECTOR_T <T> inline il_GetMinusByElement(_STD_VECTOR_T <T> &vec_1, _STD_VECTOR_T <T> &vec_2) {
		return minusbyelement_t< T >(vec_1, vec_2);
	}
}

#endif
