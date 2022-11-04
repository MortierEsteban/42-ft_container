#pragma once
#include "../map.hpp"
#include <map>
#include <vector>
#include <fstream>
#include <sys/time.h>


#define LIMITE 1200000
#define RAND_SEED	444
#define TRACE_DIR	"trace/map/"
#define KEY_TYPE	int
#ifndef NAMESPACE
# define NAMESPACE std
# define NAME_NS	"std" 
#endif

#ifndef NAME_NS
# define NAME_NS "ft"
#endif

#define	MAP_TYPE	NAMESPACE::map<KEY_TYPE,std::string >
#define	MAP_ITER	MAP_TYPE::iterator
#define PAIR_TYPE	NAMESPACE::pair<const KEY_TYPE, std::string >

#include "utils.cpp"
#include "insert.cpp"
#include "construct.cpp"
#include "delete.cpp"