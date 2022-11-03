#pragma once
#include "../map.hpp"
#include <map>
#include <vector>
#include <fstream>
#include <sys/time.h>

#define LIMITE 120000
#define TRACE_DIR	"trace/map/"
#define FT_MAP		ft::map<int,std::string >
#define STD_MAP 	std::map<int,std::string >
#define FT_ITER 	ft::map<int,std::string >::iterator
#define STD_ITER 	std::map<int,std::string >::iterator
#define FT_CITER 	ft::map<int,std::string >::const_iterator
#define STD_CITER 	std::map<int,std::string >::const_iterator

#include "utils.cpp"
#include "insert.cpp"