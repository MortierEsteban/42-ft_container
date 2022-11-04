void	defaults( std::ofstream &out)
{
	out << "Default Constructors" << std::endl;
	MAP_TYPE t1;
	const MAP_TYPE t2;
	printSize(t1, out, 1);
	out << "Empty test : " << t1.empty() <<std::endl;
	printSize(t2, out, 1);
	out << "Empty test : " << t2.empty() <<std::endl;
}

MAP_TYPE	iterators (std::vector<int > &rands, std::ofstream &out)
{
	out << "Range Constructor" << std::endl;
	std::vector<PAIR_TYPE> tmp;
	for (std::vector<int >::iterator beg = rands.begin(); beg != rands.end(); beg++)
		tmp.push_back(PAIR_TYPE(*beg, std::string("RANGE Constructor")));
	MAP_TYPE m (tmp.begin(), tmp.end());
	printSize(m, out , 1);
	return (m);
}
void	test_constructors( std::vector<int > &rands, std::ofstream &out)
{
	defaults(out);
	out << "###############################################################################"<< std::endl;
	MAP_TYPE tmp = iterators(rands, out );
	out << "###############################################################################"<< std::endl;
	out << "Copy Constructor" << std::endl;
	MAP_TYPE cpy(tmp);
	MAP_TYPE cpy2 = tmp;
	printSize(cpy, out , 1);
	out << "Empty test : " << cpy.empty() <<std::endl;
	printSize(cpy2, out , 1);
	out << "Empty test : " << cpy2.empty() <<std::endl;
	out << "###############################################################################"<< std::endl;
}