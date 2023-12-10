#include"nick.h"
std::string prefixs[20] = { "fx_","braun_","klub_r_","h2p_","Xn_","braun_" ,"stopLPG_" ,"NPTV_" ,"" ,"","" ,"" ,"" ,"" ,"","" ,"" ,"" ,"" ,"" };
std::string headNicks[50] = { "natanas","braunownik","bieluch","jetafaja","jetasraja","rip_cajmanek" ,"piasek" ,"kolo" ,"murzynator" ,"debil","adamczyk" ,
"kamilers" ,"braunownia" ,"paprykarz" ,"gerni","forsen" ,"jajo_w_guwnie" ,"demonzz1","gerberek" ,"anihilatorek","anihilatorekmatek" ,"wiadro440" ,"zagladaLPG"
,"nieznany_braunownik" ,"aparatczyk","adamcy" ,"cyprianbanino187" ,"braun" ,"grzegorzbraun" ,"braunowniaBot","braunowniaBot1" ,"braunowniaBot2"
,"szkajpur","kamrat" ,"spell","motorLublin" ,"piaseczek" ,"koleczek" ,"nusik" ,"hjw","zgnilyZachod","braunowniaBot4","atakBraunowni","potegaBraunowni",
"LpgIdioci","niepodlegla3RP","kochamPis","fiutPatiro","sroll","dawidJasper"};
 std::string przydupki[40] = { "_harambowski","_cajmarkowski","_braunowski","_braunownia","_braunowniaAtakuje","wygnany","_meczennik","_braun","_adamczykowski"
,"_zamordysta","_lublinski","_jpJetafaja","_harambowski" ,"_czarnouchy","_jebacLPG","_rasizm_w_sercu","_antysemita","_mizogin","_braunowniaJestTu","_grzegorzBraun",
"_grabowiecki","_3nogatuska","_xd1","atakBraunowni","_wyjebacLPG","_zgnilyZachod","_jpKamil","_anioleczek","_PL","_bmw","_precz_z_WHO","_Eurokolchoz","_katolicki",
"_444","_kalach","_nieuczesany","_zbraunonizowany","_zreformowany","_popieramRasizm","_homofob"};
void losujNick(int i, std::vector<std::string> args)
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