#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

#define checking	if (hostByte>255){hostByte%=256;	bytes[2]++; if (bytes[2]>256){bytes[2]%=256;bytes[1]++;if (bytes[1]>256){bytes[1]%=256;if (bytes[0]>256) bytes[0]++;}}}; 
#define checking1	if (bytes[3]>255){bytes[3]%=256;	bytes[2]++; if (bytes[2]>256){bytes[2]%=256;bytes[1]++;if (bytes[1]>256){bytes[1]%=256;if (bytes[0]>256) bytes[0]++;}}}; 
#define show for(int i=0; i<3;i++){printf("%03i.", bytes[i]);}printf("%03i", hostByte); cout<<"       ";
#define show1 for(int i=0; i<3;i++){printf("%03i.", bytes[i]);}printf("%03i", bytes[3]); cout<<"       ";

using namespace std;

struct IP
{

	int firstByte;
	int secondByte;
	int thirdByte;
	int fourthByte;
	int bits;
	int bytes[4];
	IP(string& line)
	{
		int i;
		firstByte = 0;
		secondByte = 0;
		thirdByte = 0;
		fourthByte = 0;
		bits = 0;
		for (i = 0; line[i] != '.'; i++)
		{
			firstByte = firstByte * 10 + int(line[i]) - 48;
			bytes[0] = firstByte;
		}
		i++;
		for (; line[i] != '.'; i++)
		{
			secondByte = secondByte * 10 + int(line[i]) - 48;
			bytes[1] = secondByte;
		}
		i++;
		for (; line[i] != '.'; i++)
		{
			thirdByte = thirdByte * 10 + int(line[i]) - 48;
			bytes[2] = thirdByte;
		}
		i++;
		for (; line[i] != '/' or line[i] != '\0'; i++)
		{
			fourthByte = fourthByte * 10 + int(line[i]) - 48;
			bytes[3] = fourthByte;
			if (line[i + 1] == '\0')
			{
				bits = getClass() * 8;
				return;
			}
		}

		i++;
		for (; line[i] != '\0'; i++)
		{
			bits = bits * 10 + int(line[i]) - 48;
		}
	};
	IP(int fB, int sB, int tB, int foB, int subBits)
	{
		bytes[0] = fB;
		firstByte = fB;
		bytes[1] = sB;
		secondByte = sB;
		bytes[2] = tB;
		thirdByte = tB;
		bytes[3] = foB;
		fourthByte = foB;
		bits = subBits;
	}
	void showIP()
	{
		for (int i = 0; i < 4; i++)
		{
			if (i)
				cout << ".";
			printf("%03i", bytes[i]);
		}
	}
	int getClass()
	{
		if (firstByte < 128)
			return 1;
		if (firstByte < 192)
			return 2;
		if (firstByte < 224)
			return 3;
		if (firstByte < 240)
			return 4;
	};
	void bitsAnd()
	{
		int n = 0;
		int copyBits = bits;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[0] = (bitset<8>(firstByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[1] = (bitset<8>(secondByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[2] = (bitset<8>(thirdByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[3] = (bitset<8>(fourthByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
	}
	void showAsubnets(int k)
	{
		int n = 0;
		int copyBits = bits;
		int host;
		int hosts[5];
		int hostBit = 0;
		int subBit = 0;
		int subByte = 0;
		int hostByte = 0;
		double sumHost = 0;

		if (k > 10 and k < 21)
		{
			hosts[0] = 26 - k;
			hosts[1] = 32 - k;
			hosts[2] = 36 - k;
			hosts[3] = 41 - k;
			hosts[4] = 2;
			host = 41 - k;
		}
		else
		{
			hosts[0] = 10 + k;
			hosts[1] = 13 + k;
			hosts[2] = 16 + k;
			hosts[3] = 20 + k;
			hosts[4] = 2;
			host = 20 + k;
		}
		cout << endl << "\nIP: ";
		showIP(); cout << "/" << bits;
		bitsAnd();
		cout << endl << "IP: ";
		showIP();
		/*	firstByte=bytes[0];
			secondByte=bytes[1];
			thirdByte=bytes[2];
			fourthByte=bytes[3];*/
			//	cout<<"/"<<bits;    
		while (pow(2, hostBit) < (host + 2)) { hostBit++; };
		subBit = 32 - hostBit - getClass() * 8;
		cout << "/" << 32 - hostBit;
		subByte = 0;
		hostByte = 0;

		for (int j = 0; j < subBit; j++)
		{
			subByte += pow(2, j);
		}
		cout << endl;
		cout << endl;
		cout << "|Subnet|address of subnet| bits    |\n";
		for (int l = 0; l <= subByte and l < 5; l++)
		{

			printf("|%6i|", l);
			printf("%3i", bytes[0]);
			for (int j = 1; j < 3; j++)
			{
				printf(".%03i", bytes[j]);
			}
			printf(".%03i  ", hostByte);
			cout << "|" << bitset<8>(hostByte) << " |";
			cout << endl;
			hostByte += pow(2, hostBit);
			checking
		}
		cout << endl << endl;

		returnBytes();
		hostByte = 0;
		for (int i = 0; i < 5; i++)
		{
			cout << "\nHosts from " << i << " are not used:";
			bytes[3] = hostByte;
			hostByte += (1 + hosts[i]);
			checking
				cout << bytes[0] << "." << bytes[1] << "." << bytes[2] << "." << hostByte << "-";
			cout << (((bytes[3] + pow(2, hostBit)) < 255) ? bytes[3] + (pow(2, hostBit) - 2) : (bytes[3] + (int)pow(2, hostBit) - 2) % 256);
			hostByte = bytes[3] + pow(2, hostBit);
			checking
				sumHost += hosts[i];
		}
		cout << endl << double(sumHost) / (pow(2, hostBit) * 5 - 10) * 100 << "\% are used";

		cout << endl << endl;
		returnBytes();
		extendedMask(bits);
		cout << endl << endl;
		returnBytes();
		bitsAnd();
		extendedMask(getClass() * 8 + subBit);

		returnBytes();
		bitsAnd();
		cout << endl;
		cout << endl;
		hostByte = 0;
		cout << "|Subnet|address of subnet|first available address|last available address|broadcast      address|\n";
		for (int l = 0; l <= subByte and l < 5; l++)
		{

			printf("|%6i|", l);
			printf("%3i", bytes[0]);
			for (int j = 1; j < 3; j++)
			{
				printf(".%03i", bytes[j]);
			}
			printf(".%03i  ", hostByte);
			cout << "|";
			hostByte++;
			checking
				show

				cout << " |";
			hostByte += (pow(2, hostBit) - 3);
			checking
				show
				/*if (hostByte>255)
				{
					hostByte%=256;
					bytes[2]++;
					if (bytes[2]>256)
					{
						bytes[2]%=256;
						bytes[1]++;
						if (bytes[1]>256)
						{
							bytes[1]%=256;
							if (bytes[0]>256)
								bytes[0]++;

						}
					}
				}*/
				cout << "|";
			hostByte++;
			checking
				show
				cout << "|";
			hostByte++;
			checking

				cout << endl;
		}
		cout << endl;


		/*	inline void update()
			{
				if (hostByte>255)
					{
						hostByte%=256;
						bytes[2]++;
						if (bytes[2]>256)
						{
							bytes[2]%=256;
							bytes[1]++;
							if (bytes[1]>256)
							{
								bytes[1]%=256;
								if (bytes[0]>256)
									bytes[0]++;

							}
						}
					}
			};	*/

	}
	void showBsubnets(int k)
	{
		returnBytes();
		int copyBits = bits;
		int hosts[5];
		int n = 0;
		int t, secondT;
		double sumHost = 0;
		double difference = 2;
		if (k > 10 and k < 21)
		{
			hosts[0] = 24 - k;
			hosts[1] = 33 - k;
			hosts[2] = 48 - k;
			hosts[3] = 78 - k;
			hosts[4] = 2;
		}
		else
		{
			hosts[0] = 5 + k;
			hosts[1] = 13 + k;
			hosts[2] = 25 + k;
			hosts[3] = 57 + k;
			hosts[4] = 2;
		}


		cout << "\n\nIP: ";
		showIP();
		cout << "/" << bits;

		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[0] = (bitset<8>(firstByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[1] = (bitset<8>(secondByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[2] = (bitset<8>(thirdByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		for (int i = 0; i < 8 and i < (copyBits); n += pow(2, 7 - i), i++);
		bytes[3] = (bitset<8>(fourthByte) & bitset<8>(n)).to_ulong();
		n = 0;
		copyBits -= 8;
		cout << endl << "IP: ";
		showIP();
		cout << "/27";
		for (int i = 0; i < 4; i++)
			difference += hosts[i];
		for (int i = 0; i < 4; i++)
		{
			for (int j = i; j < 4; j++)
			{
				if (hosts[i] < hosts[j])
					swap(hosts[i], hosts[j]);
			}
		}
		sumHost = difference;
		cout << "\nVLSM scheme";
		cout << "\nNetwork description  |N.of h.| CIDR                |Mask                                 |first available address|last  available address|broadcast available address| unused";
		bytes[3] = 0;
		for (int i = 0; i < 5; i++)
		{
			if (i == 4)
			{
				cout << "\nConnection WAN       |";
			}
			else
			{
				cout << "\nHOST-" << char(i + 65) << " LAN           |";
			}
			printf("%7i| ", hosts[i]);
			for (n = 0; pow(2, n) < (hosts[i] + 2); n++);
			showIP();
			cout << "/" << 32 - n << "  | ";
			for (int j = 0, q = 32 - n; j < 36; j++)
			{
				if (j % 9 == 0 and j != 0)
				{
					cout << ".";
					continue;
				}
				if (q >= 0)
				{
					cout << "1";
					q--;
				}
				else
				{
					cout << "0";
				}
			}
			cout << "|";
			t = bytes[3] + hosts[i];
			if (t > 255) t %= 256;
			bytes[3]++;
			checking1
				showIP();
			bytes[3] += (pow(2, n) - 3);
			checking1
				cout << "       |   ";
			showIP();
			cout << "     |   ";
			secondT = bytes[3];
			bytes[3]++;
			checking1
				showIP();
			cout << "         | ";
			if (t != secondT)
			{
				cout << t + 1 << "-" << secondT;
				sumHost += secondT - t;
			}
			bytes[3]++;
			checking1

		}
		cout << endl << endl << difference / sumHost * 100 << "\% are used";
	}
	void extendedMask(int newBits = 0)
	{
		if (!newBits)
			newBits = bits;
		cout << "IP: ";
		showIP();
		cout << "\\" << newBits;
		int i = 0;
		int helper = newBits;
		cout << endl << "Extended mask (decimal view): ";
		for (i = 0; i < getClass(); i++)
		{
			cout << "255.";
		}
		int byte = 0;

		do
		{
			byte = 0;
			for (int j = 0; j < (helper - getClass() * 8); j++)
			{
				byte += pow(2, 7 - j);
			}
			cout << byte;
			if (i < 3)
			{
				cout << ".";
			}
			i++;
			helper -= 8;
		} while ((helper - getClass() * 8) > 0);

		for (; i < 4; i++)
		{
			cout << "0";
			if (i != 3)
				cout << ".";
		}
		helper = newBits;
		cout << endl << "Extended mask (binary view): ";
		for (i = 0; i < getClass(); i++)
		{
			cout << bitset<8>(255);
			cout << ".";
		}
		do
		{
			byte = 0;
			for (int j = 0; j < (helper - getClass() * 8); j++)
			{
				byte += pow(2, 7 - j);
			}
			cout << bitset<8>(byte);
			if (i < 3)
			{
				cout << ".";
			}
			i++;
			helper -= 8;
		} while ((helper - getClass() * 8) > 0);

		for (; i < 4; i++)
		{
			cout << bitset<8>(0);
			if (i != 3)
				cout << ".";
		}

	}
	void returnBytes()
	{
		bytes[0] = firstByte;
		bytes[1] = secondByte;
		bytes[2] = thirdByte;
		bytes[3] = fourthByte;
	}
};
int main()
{
	int k;
	cout << "Enter your K: ";
	cin >> k;
	IP ip1(192, 168, 5 + k, 14 + k, 24);
	IP ip2(172, 16, 4 + k, 254 - k, 20);
	IP ip3(10, 10, 16 + k, 0, 18);

	ip1.showAsubnets(k);
	ip2.showAsubnets(k);
	ip3.showAsubnets(k);

	ip1.showBsubnets(k);
	ip2.showBsubnets(k);
	ip3.showBsubnets(k);

	system("Pause>NULL");
	return 0;
}

 