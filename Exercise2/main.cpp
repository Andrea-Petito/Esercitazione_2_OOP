#include <iostream>
#include <fstream>
#include <iomanip>

double map(double x)
{
	return ((x - 1) / 4) * 3 - 1;
}

double mean_function(double sum, int i)
{
	return sum / i;
}

int main()
{
	std::ifstream i_file("data.txt");
	std::ofstream o_file("result.txt");
	
	if (i_file.fail())
	{
		std::cerr << "Non è stato possibile aprire il file di input" << std::endl;
		return 1;
	}
	
	double value;
	double sum = 0;
	int i = 0;
	
	o_file << "# N Mean" << std::endl;
	
	while (i_file >> value)
	{
		if (value >= 1 && value <= 5) //mi voglio assicurare che tutti i numeri nel file siano davvero compresi tra 1 e 5
		{
			double mapped_value = map(value);
			sum = sum + mapped_value;
			
			double mean = mean_function(sum, ++i);
			
			o_file << std::setprecision(16) << i << mean << std::endl;
		}
	
	}
	
	i_file.close();
	o_file.close();
	
    return 0;
}
