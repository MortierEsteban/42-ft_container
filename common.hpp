#pragma once
#include "vector/vector.hpp"
#include <vector>

#include "map/map.hpp"
#include <map>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sys/time.h>


#define LIMITE 120000
#define RAND_SEED	446
#define TRACE_DIR_VEC	"trace/vector/"
#define TRACE_DIR_MAP	"trace/map/"
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

#define	MAP_TYPE	NAMESPACE::map<KEY_TYPE,std::string >
#define	MAP_ITER	MAP_TYPE::iterator
#define	MAP_CITER	MAP_TYPE::const_iterator
#define PAIR_TYPE	NAMESPACE::pair<const KEY_TYPE, std::string >

void vector_test ();
void map_test ();
