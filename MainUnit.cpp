//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>

#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "uADCompClient"
#pragma link "uADGUIxIntf"
#pragma link "uADPhysIntf"
#pragma link "uADPhysManager"
#pragma link "uADStanAsync"
#pragma link "uADStanDef"
#pragma link "uADStanError"
#pragma link "uADStanIntf"
#pragma link "uADStanOption"
#pragma link "uADStanPool"
#pragma link "uADCompDataSet"
#pragma link "uADDAptIntf"
#pragma link "uADDAptManager"
#pragma link "uADDatSManager"
#pragma link "uADStanParam"
#pragma link "uADPhysSQLite"
#pragma link "uADStanExprFuncs"
#pragma link "uADCompGUIx"
#pragma link "uADGUIxFormsWait"
#pragma link "Chart"
#pragma link "DBChart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "Chart"
#pragma link "DBChart"
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "uADCompClient"
#pragma link "uADCompDataSet"
#pragma link "uADCompGUIx"
#pragma link "uADDAptIntf"
#pragma link "uADDAptManager"
#pragma link "uADDatSManager"
#pragma link "uADGUIxFormsWait"
#pragma link "uADGUIxIntf"
#pragma link "uADPhysIntf"
#pragma link "uADPhysManager"
#pragma link "uADPhysSQLite"
#pragma link "uADStanAsync"
#pragma link "uADStanDef"
#pragma link "uADStanError"
#pragma link "uADStanExprFuncs"
#pragma link "uADStanIntf"
#pragma link "uADStanOption"
#pragma link "uADStanParam"
#pragma link "uADStanPool"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
/*
111fc29_3274bd7a3_201358adf_50ce678
*/
//{"coord":{"lon":30.3,"lat":60.005},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"base":"stations","main":{"temp":283.2,"feels_like":282.45,"temp_min":283.2,"temp_max":283.2,"pressure":1000,"humidity":84,"sea_level":1000,"grnd_level":998},"visibility":10000,"wind":{"speed":4.98,"deg":237,"gust":5.91},"clouds":{"all":100},"dt":1747218129,"sys":{"type":2,"id":2046422,"country":"RU","sunrise":1747185799,"sunset":1747247228},"timezone":10800,"id":535729,"name":"Komendantsky aerodrom","cod":200}
void __fastcall TMainForm::GetButtonClick(TObject *Sender)
{
	TCursor Save_Cursor = Screen->Cursor;
	TIdHTTP *idHTTP = new TIdHTTP(NULL);
	idHTTP->Request->UserAgent = "Mozilla/5.0";
	String s1 = "111fc293274bd7a3", s2 = "201358adf50ce678";
	String dt;  // unix time string - sec from 01.01.1970

	Screen->Cursor = crHourGlass;
	ask_str = "http://api.openweathermap.org/data/2.5/weather?lat=" + DBEd_Lat->Text + "&lon=" + DBEd_Lng->Text + "&appid=" + s1 + s2;
	StatusBar1->Panels->Items[0]->Text = ask_str;
	try {
		response = idHTTP->Get(ask_str);
		Memo1->Lines->Add(response);
	} __finally {
		delete idHTTP;
		Screen->Cursor = Save_Cursor;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
	DB->Connected = true;
	T_Fields->Active = true;
	DBLCB_Fields->KeyValue = T_Fields->FieldByName("FieldID")->AsInteger;
}
//---------------------------------------------------------------------------
String __fastcall TMainForm::ConvertDate(unsigned int sUnixDate, String &castDate, String &castTime)
{
	unsigned int unixTime = sUnixDate; // Unix-время
	TDateTime dateTime = UnixToDateTime(unixTime);

	// Вывод в строку (формат по умолчанию)
	String dateStr = DateTimeToStr(dateTime);
	castDate = dateStr.SubString(1, 10);
	castTime = dateStr.SubString(12, 5);
	return dateStr; // Пример: "21.07.2025 12:58:42"
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ParsButtonClick(TObject *Sender)
{
	String weather, temp, dt;

	weather = GetJSONstr("stations", "sys");
	Memo2->Lines->Add(weather);

	float tempVal = GetJSONval(weather, "temp");
	LE_Temp->Text = FloatToStrF(tempVal - 272.15, ffFixed, 6, 1);

	float cloudsVal = GetJSONval(weather, "clouds");
	LE_Clouds->Text = FloatToStrF(cloudsVal, ffFixed, 6, 1);

	float rainVal = GetJSONval(weather, "1h");
	LE_Rain->Text = FloatToStrF(rainVal, ffFixed, 6, 1);

	String timeVal = GetJSONtime(weather, "dt");
	LE_Date->Text = castDate;
	LE_Time->Text = castTime;

/*
Re: JSON пример
Andrey Kurashvili
Сегодня, 6:47
Кому:вам
{"coord":{"lon":28.756,"lat":60.717},"weather":[{"id":502,"main":"Rain","description":"heavy intensity rain","icon":"10d"}],"base":"
stations","main":{"temp":286.14,"feels_like":286,"temp_min":286.14,"temp_max":286.14,"pressure":1011,"humidity":96,"sea_level":1011,"grnd_level":1009},"visibility":10000,"wind":{"speed":1.57,"deg":93,"gust":3.43},"rain":{"1h":10.29},"clouds":{"all":100},"dt":1748490335,
"sys":{"country":"RU","sunrise":1748479916,"sunset":1748545991},"timezone":10800,"id":470546,"name":"Vyborg","cod":200}
*/

}
//---------------------------------------------------------------------------
String __fastcall TMainForm::GetJSONstr(String startStr, String finStr)
{
	int beg = response.Pos(startStr) + startStr.Length();
	int fin = response.Pos(finStr);
	return response.SubString(beg, fin);
}
//---------------------------------------------------------------------------
float __fastcall TMainForm::GetJSONval(String fullStr, String startStr)
{
	AnsiString 	s = "";
	float       res;
	bool        found = false;

	if (fullStr.Pos(startStr)) {
		int beg = fullStr.Pos(startStr) + startStr.Length() + 2;
		for (int i = beg; i < fullStr.Length(); i++) {
			if (isdigit(fullStr[i]) || (fullStr[i] == '.' && found)) {
				s += fullStr[i];
				found = true;
			} else {
				if (found) break;
			}
		}
	}
	if (s.Length()) {
		res = s.ToDouble();
	}
	return res;
}
//---------------------------------------------------------------------------
String __fastcall TMainForm::GetJSONtime(String fullStr, String startStr)
{
	AnsiString 	    s = "";
	float       res;
	bool        found = false;
	String dt;  // unix time string - sec from 01.01.1970

	int beg = fullStr.Pos(startStr) + startStr.Length() + 2;
	for (int i = beg; i < fullStr.Length(); i++) {
		if (isdigit(fullStr[i]) || (fullStr[i] == '.' && found)) {
			s += fullStr[i];
			found = true;
		} else {
			if (found) break;
		}
	}
	dt = s;
	if (s.Length()) {
		ConvertDate(StrToInt64(dt)+3600*3, castDate, castTime);
	}
	return res;
}
//---------------------------------------------------------------------------

