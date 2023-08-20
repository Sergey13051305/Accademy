#include <iostream>
#include<fstream> // Подключаем файловую библеотеку
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILES
//#define RIGHT_TO_FILES

void main()
{
	setlocale(LC_ALL, " ");
#ifdef WRITE_TO_FILES

	cout << "Hello Files" << endl;
	//1) Создаем поток
	std::ofstream fout;
	//2) Открываем поток
	fout.open("File.txt", std::ios_base::app);
	//3)Пишем в поток
	fout << "Hello Files" << endl;
	fout << "Ну привет" << endl;
	//3) Закрываем поток
	fout.close();

	system("start notepad File.txt");
#endif

#ifdef RIGHT_TO_FILES

	std::ifstream fin;
	fin.open("File.txt");
	//3) Проверка на открытие потока 
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:file not found" << endl;
	}
#endif // Read_to_files

	std::ofstream fout("201 ready.txt");
	std::ofstream fout_dhcpd("201 ready.txt");
	std::ifstream fout("201 RAW.txt");
	std::ifstream fin;
	if (fin.is_open())
	{
		const int MAC_SIZE = 18;
		const int IP_SIZE = 16;
		char sz_mac_buffer[MAC_SIZE]{};
		char sz_ip_buffer[IP_SIZE]{};
		while (!fin.eof())
			fin.close();
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;
		for (int i = 0; !fin.eof(); i++)
		{

			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (strlen(sz_ip_buffer) == 0)continue;
			for (int i = 0; sz_mac_buffer[i]; i++)
				if (sz_mac_buffer[i] == '-')
					sz_mac_buffer[i] = ':';
			cout << "host-" << i + 1 << endl;
			cout << "{\n";
			cout << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			cout << "\ttfixed-adress:\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";

			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			fout_dhcpd << "host-" << i + 1 << endl;
			fout_dhcpd << "{\n";
			fout_dhcpd << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			fout_dhcpd << "\ttfixed-adress:\t\t" << sz_ip_buffer << ";\n";
			fout_dhcpd << "}\n";
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fout.close();
	system("notepad 201 ready.txt");
	system("notepad 201dhcp.txt");


}