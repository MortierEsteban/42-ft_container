#pragma once
#include "../map.hpp"
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>


#define LIMITE 120000
#define RAND_SEED	446
#define TRACE_DIR	"../trace/map/"
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
#define	MAP_CITER	MAP_TYPE::const_iterator
#define PAIR_TYPE	NAMESPACE::pair<const KEY_TYPE, std::string >