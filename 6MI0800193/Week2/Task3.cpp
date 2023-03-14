#include <iostream>
#include <fstream>
using namespace std;

struct Pair
{
	int x;
	int y;
};

Pair create_pair(int x, int y)
{
	return {x,y};
}

void init_pair(Pair& to_init, int x, int y)
{
	to_init.x = x;
	to_init.y = y;
}

Pair read_pair_from_file(ifstream& file)
{
	int x, y;
	file >> x >> y;

	return {x, y};
}

void write_pair_to_file(ofstream& file, const Pair& pair)
{
	file << pair.x << " " << pair.y << endl;
}

//-----------------------------------------------------------------

struct Relation
{
	Pair pairs[25];
	size_t pairs_count=0;
};

bool add_pair(Relation& rel, const Pair& pair)
{
	if (rel.pairs_count >= 25)
		return false;

	rel.pairs[rel.pairs_count] = pair;
	rel.pairs_count++;
	return true;
}

bool write_relation(const Relation& rel, const char* file_path)
{
	ofstream output(file_path);

	for (size_t i = 0; i < rel.pairs_count; i++)
	{
		output << rel.pairs[i].x << " " << rel.pairs[i].y << endl;
	}

	output.close();

	return true;
}

bool read_relation(Relation& rel, const char* file_path)
{
	ifstream input(file_path);

	while (!input.eof())
	{
		int x, y;
		input >> x >> y;

		if (input.eof())
			break;

		rel.pairs[rel.pairs_count].x = x;
		rel.pairs[rel.pairs_count].y = y;
		rel.pairs_count++;

		if (rel.pairs_count == 25)
			break;
	}


	input.close();

	return true;
}



int main()
{
	Pair a = { 2,6 };
	Pair b = { 3,7 };
	Pair c = { 7,8 };

	Relation rel, read_rel;
	add_pair(rel, a);
	add_pair(rel, b);
	add_pair(rel, c);

	write_relation(rel, "output_rel.txt");
	read_relation(read_rel, "output_rel.txt");

	for (size_t i = 0; i < read_rel.pairs_count; i++)
	{
		cout << read_rel.pairs[i].x << " " << read_rel.pairs[i].y << endl;
	}

}
