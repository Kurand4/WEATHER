//---------------------------------------------------------------------------

#include <vcl.h>
# include <DateUtils.hpp>

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
	String ask_str, response;
	String s1 = "111fc293274bd7a3", s2 = "201358adf50ce678";
	String dt;  // unix time string - sec from 01.01.1970

	Screen->Cursor = crHourGlass;
	ask_str = "http://api.openweathermap.org/data/2.5/weather?lat=" + DBEd_Lat->Text + "&lon=" + DBEd_Lng->Text + "&appid=" + s1 + s2;
	StatusBar1->Panels->Items[0]->Text = ask_str;
	try {
		response = idHTTP->Get(ask_str);
		Memo1->Lines->Add(response);
		// Парсинг JSON ответа:
		TStringList * list = new TStringList;
		list->StrictDelimiter = true;
		list->Delimiter = '{';
		list->DelimitedText = response;
		for (int i = 0; i < list->Count; i++) {
			Memo2->Lines->Add(String(i) + ". " + list->Strings[i]);
		}
		TStringList * list8 = new TStringList;
		list8->StrictDelimiter = true;
		list8->Delimiter = ':';
		list8->DelimitedText = list->Strings[8];
		for (int i = 0; i < list8->Count; i++) {
			Memo2->Lines->Add(String(i) + ". " + list8->Strings[i]);
		}
		TStringList * listTemp = new TStringList;
		listTemp->StrictDelimiter = true;
		listTemp->Delimiter = ',';
		listTemp->DelimitedText = list8->Strings[1];
		for (int i = 0; i < listTemp->Count; i++) {
			Memo2->Lines->Add(String(i) + ". " + listTemp->Strings[i]);
		}
		LE_Temp->Text = FloatToStrF(listTemp->Strings[0].ToDouble() - 272.15, ffFixed, 6, 1);

		TStringList * listClouds = new TStringList;
		listClouds->StrictDelimiter = true;
		listClouds->Delimiter = ',';
		listClouds->DelimitedText = list->Strings[12];
		for (int i = 0; i < listClouds->Count; i++) {
			Memo2->Lines->Add(String(i) + ". " + listClouds->Strings[i]);
		}
		LE_Clouds->Text = listClouds->Strings[0].SubString(2,2);

		s  = listClouds->Strings[2];
		dt = s.SubString(2, s.Length());

		LE_Time->Text = YearOf((TDateTime)dt);
		delete listClouds;
		delete listTemp;
		delete list8;
		delete list;
		list = NULL;
		}
	__finally {
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

