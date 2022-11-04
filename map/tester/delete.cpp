
void erases(std::vector<int> rands, std::ofstream &out)
{
	MAP_TYPE m;
	out << "Range Constructor" << std::endl;
	std::vector<PAIR_TYPE> tmp;
	for (std::vector<int >::iterator beg = rands.begin(); beg != rands.end(); beg++)
		tmp.push_back(PAIR_TYPE(*beg, std::string("RANGE Constructor")));
	m.insert(tmp.begin(), tmp.end());
	out << "BEFORE DELETION" << std::endl;
	printSize(m, out, 1);
	// m.erase(++m.begin());
	// m.erase(rands[LIMITE / 2]);
	for (int i = LIMITE / 4 ; i< LIMITE / 2 ; i++)
	{
		// if (i % 3)
			out << "Erasing[" << rands[i] << "] = " << m.erase(rands[i])<< std::endl;
	}
		m.at(682927509);//ce ptr disparait, prev perdu?
	// MAP_ITER beg = m.begin();
	// for(int i = 0; i < LIMITE / 6;i++ )
	// 	beg++;
	// m.erase(m.begin(), beg);
	// out << "After every deletion" << std::endl;
	printSize(m, out, 1);

}