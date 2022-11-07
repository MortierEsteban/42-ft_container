#pragma once
#include "../vector.hpp"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sys/time.h>


#define LIMITE 12000
#define RAND_SEED	446
#define TRACE_DIR	"../trace/vector/"
#define KEY_TYPE	int
#ifndef NAMESPACE
# define NAMESPACE std
# define NAME_NS	"std" 
#endif

#ifndef NAME_NS
# define NAME_NS "ft"
#endif

#define KEY_TYPE int
#define VECTOR_TYPE NAMESPACE::vector<KEY_TYPE>
#define VECTOR_ITER VECTOR_TYPE::iterator
#define VECTOR_CITER VECTOR_TYPE::const_iterator

