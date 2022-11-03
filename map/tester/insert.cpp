template<class MAP, class PAIR_TYPE>
void	test_insert(MAP& _m, std::vector< int > rands, std::string outpt)
{
	std::vector<PAIR_TYPE> tmp;
	for (int i = 0; i < 5 ;i++)
		tmp.push_back(PAIR_TYPE(i, std::string("RANGE INSERT")));
	std::vector<int>::iterator beg = rands.begin();
	while (beg != rands.end())
	{
		if (*beg % 3 )
			_m[*beg] = "Bracket insert";
		else
			_m.insert(PAIR_TYPE(*beg, "PAIR INSERT"));
		beg++;
	}
	_m.insert(tmp.begin(),tmp.end());
	typename MAP::iterator hint(_m.begin());
	hint = _m.begin();
	for( int i = 0; i < LIMITE / 4 && hint != _m.end(); i++)
		hint++;
	_m.insert(hint, PAIR_TYPE((hint->first ) + LIMITE/4, "HINT INSERT"));
	printSize( _m, outpt, 1);
}