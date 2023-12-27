#include"nick.h"
#pragma warning(disable : 4996)
std::vector<std::string> prefixs;
std::vector<std::string>headNicks;
std::vector<std::string>przydupki;
std::vector<std::string>* vectory[3] = { &prefixs,&headNicks,&przydupki };
void losujNick()
{
	srand(time(NULL));
	while (true)
	{
		std::string aha = "";
		int aha1 = rand() % prefixs.size();
		aha += prefixs[aha1];
		aha1 = rand() % headNicks.size();
		aha += headNicks[aha1];
		aha1 = rand() % przydupki.size();
		aha += przydupki[aha1];
		if (!(aha.size() > 25))
		{
			printf("NICK>NICK: ");
			printf("%s", aha.c_str());
			printf("\n\n");
			break;
		}
	}
}

int loadFromFile(std::vector<std::string> *zapis, const char* path)
{
	std::ifstream f(path);
	if (f.fail())
	{
			return 1;
	}
	std::string buffer;
	while (std::getline(f, buffer)) {
		zapis->push_back(buffer);
	}

	f.close();
	return 0;
}
std::string nick_commands[5] = { "load","losuj","clear","show","domyslne"};
void parsNick(int i, std::vector<std::string> args)
{

	if (args.size() == 1)
	{
		printf("IMAGE>\n      load (index)(filepath)\n      losuj/*no arguments*/\n      clear (index)\n      show (index)\n      domyslne/*no arguments*/\n\n");
		return;
	}
	int commandId = -1;
	for (int i = 0; i < 3; i++)
	{
		if (args[1] == nick_commands[i])
			commandId = i;
	}
	if (commandId == -1)
	{
		printf("WRONG ARGUMENTS\n");
		return;
	}
	switch (commandId)
	{
	case 0:
		if(args.size()<4)
		{
			printf("WRONG ARGUMENTS!\n");
			return;
		}
		if (!atoi(args[2].c_str()) && !(atoi(args[2].c_str()) < 4))
		{
			printf("WRONG ARGUMENTS!\n");
			return;
		}
		if (loadFromFile(vectory[atoi(args[2].c_str()) - 1], args[3].c_str()))
		{
			printf("WRONG FILEPATH!\n");
			return;
		}
		break;
	case 1:
		if (!prefixs.size() || !headNicks.size() || !przydupki.size())
			printf("UNABLE TO DRAW NICK\n");
		losujNick();
		break;
	case 2:
		if (args.size() < 3)
		{
			printf("WRONG ARGUMENTS!\n");
			return;
		}
		if (!atoi(args[2].c_str()) && !(atoi(args[2].c_str()) < 4))
		{
			printf("WRONG ARGUMENTS!\n");
			return;
		}
		clearNick(vectory[atoi(args[2].c_str())-1]);
		break;
	case 3:
		if (args.size() < 3)
		{
			printf("WRONG ARGUMENTS!\n");
			return;
		}
		if (!atoi(args[2].c_str()) && !(atoi(args[2].c_str()) < 4))
		{
			printf("WRONG ARGUMENTS!\n");
				return;
		}
		pokazNicki(atoi(args[2].c_str()));
		break;
	case 4:
		domyslne();
		break;
	}
}

void clearNick(std::vector<std::string>* zapis)
{
	zapis->clear();
}

void loadDefault(void)
{
	if (loadFromFile(&prefixs, "prefix.txt"))
		printf("FAILED TO LOAD PREFIX\n");
	if(loadFromFile(&headNicks, "nick.txt"))
	printf("FAILED TO LOAD NICK\n");
	if(loadFromFile(&przydupki, "postfix.txt"))
	printf("FAILED TO LOAD POSTFIX\n");
}
void pokazNicki(int i)
{
		for (int j = 0; j < vectory[i]->size(); j++)
			printf("%s", (*vectory[i])[j].c_str());
}

void domyslne(void)
{
	 prefixs = { "fx_","braun_","klub_r_","h2p_","Xn_","braun_" ,"stopLPG_" ,"NPTV_" ,"" ,"","" ,"" ,"" ,"" ,"","" ,"" ,"" ,"" ,"" };
	headNicks = { "natanas","braunownik","bieluch","jetafaja","jetasraja","rip_cajmanek" ,"piasek" ,"kolo" ,"murzynator" ,"debil","adamczyk" ,
	"kamilers" ,"braunownia" ,"paprykarz" ,"gerni","forsen" ,"jajo_w_guwnie" ,"demonzz1","gerberek" ,"anihilatorek","anihilatorekmatek" ,"wiadro440" ,"zagladaLPG"
	,"nieznany_braunownik" ,"aparatczyk","adamcy" ,"cyprianbanino187" ,"braun" ,"grzegorzbraun" ,"braunowniaBot","braunowniaBot1" ,"braunowniaBot2"
	,"szkajpur","kamrat" ,"spell","motorLublin" ,"piaseczek" ,"koleczek" ,"nusik" ,"hjw","zgnilyZachod","braunowniaBot4","atakBraunowni","potegaBraunowni",
	"LpgIdioci","niepodlegla3RP","kochamPis","fiutPatiro","sroll","dawidJasper" };
	przydupki = { "_harambowski","_cajmarkowski","_braunowski","_braunownia","_braunowniaAtakuje","wygnany","_meczennik","_braun","_adamczykowski"
	,"_zamordysta","_lublinski","_jpJetafaja","_harambowski" ,"_czarnouchy","_jebacLPG","_rasizm_w_sercu","_antysemita","_mizogin","_braunowniaJestTu","_grzegorzBraun",
	"_grabowiecki","_3nogatuska","_xd1","atakBraunowni","_wyjebacLPG","_zgnilyZachod","_jpKamil","_anioleczek","_PL","_bmw","_precz_z_WHO","_Eurokolchoz","_katolicki",
	"_444","_kalach","_nieuczesany","_zbraunonizowany","_zreformowany","_popieramRasizm","_homofob" };
}
