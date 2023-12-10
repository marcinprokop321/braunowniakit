#include"nick.h"
std::string prefixs[20] = { "fx_","braun_","klub_r_","h2p_","Xn_","" ,"" ,"" ,"" ,"","" ,"" ,"" ,"" ,"","" ,"" ,"" ,"" ,"" };
std::string headNicks[40] = { "natanas","braunownik","bieluch","jetafaja","jetasraja","rip_cajmanek" ,"piasek" ,"kolo" ,"murzynator" ,"debil","adamczyk" ,
"kamilers" ,"braunownia" ,"paprykarz" ,"gerni","forsen" ,"jajo_w_guwnie" ,"demonzz1","gerberek" ,"anihilatorek","anihilatorekmatek" ,"wiadro440" ,"zagladaLPG"
,"nieznany_braunownik" ,"aparatczyk","adamcy" ,"cyprianbanino187" ,"braun" ,"grzegorzbraun" ,"braunowniaBot","braunowniaBot1" ,"braunowniaBot2"
,"szkajpur","kamrat" ,"spell","motorLublin" ,"piaseczek" ,"koleczek" ,"nusik" ,"hjw" };
 std::string przydupki[30] = { "_harambowski","_cajmarkowski","_braunowski","_braunownia","_braunowniaAtakuje","wygnany","_meczennik","_braun","_adamczykowski"
,"_zamordysta","_lublinski","_jpJetafaja","_harambowski" ,"_czarnouchy","_jebacLPG","_rasizm_w_sercu","_antysemita","_mizogin","_braunowniaJestTu","_grzegorzBraun",
"_grabowiecki","_3nogatuska","_xd1","atakBraunowni","_wyjebacLPG","_zgnilyZachod","_jpKamil","_anioleczek","_PL","_bwm" };
void losujNick(int i)
{
	srand(time(NULL));
	while (true)
	{
		std::string aha = "";
		int aha1 = rand() % 20;
		aha += prefixs[aha1];
		aha1 = rand() % 40;
		aha += headNicks[aha1];
		aha1 = rand() % 30;
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