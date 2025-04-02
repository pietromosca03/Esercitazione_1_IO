#include <iostream>
#include <fstream>
#include <sstream>

double trasformazione_lineare(double n, double a, double b, double c, double d){
    double raggio_ab = std::abs(b-a)/2;
    double raggio_cd = std::abs(d-c)/2;
    
    n = n-a-raggio_ab;
    n = n/raggio_ab;
    n = n*raggio_cd;
    n += c+raggio_cd;
    
    return n;
}


int main()
{
    std::string input = "data.txt";
	std::string output = "result.txt";
	
	std:: ifstream fileinput(input);
	std:: ofstream fileoutput(output);

    if (fileinput.fail())
	{
		std::cout << "impossibile aprire data.txt" << std::endl;
		return 1;
	}
    if (fileoutput.fail())
	{
		std::cout << "impossibile creare result.txt" << std::endl;
		return 1;
	}

    std::string riga;
    double a = 1;
	double b = 5;	
	double c = -1;
	double d = 2;
    double somma = 0;

    int i = 0;

    fileoutput << "# N Mean"<<std::endl;

    while (std::getline(fileinput,riga)){
        i++;
        std::stringstream n;
        n << riga;
        double num;
        n >> num;
        num = trasformazione_lineare(num,a,b,c,d);
        somma += num;
        double media = somma/i;
        fileoutput << i;
        fileoutput << " ";
        fileoutput << media;
        fileoutput << std::endl;
    }
    fileinput.close();
	fileoutput.close();
    return 0;
}