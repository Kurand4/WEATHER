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
#pragma link "IdIOHandler"
#pragma link "IdIOHandlerSocket"
#pragma link "IdIOHandlerStack"
#pragma link "IdSSL"
#pragma link "IdSSLOpenSSL"
#pragma link "IdIOHandler"
#pragma link "IdIOHandlerSocket"
#pragma link "IdIOHandlerStack"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner)
{
	String s1 = "111fc293274bd7a3", s2 = "201358adf50ce678";
	sAPIkey = s1 + s2;
	/*
	API_KEY: 111fc29_3274bd7a3_201358adf_50ce678
	{"coord":{"lon":30.3,"lat":60.005},"weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04d"}],"base":"
	stations","main":{
	"temp":283.2,"feels_like":282.45,"temp_min":283.2,"temp_max":283.2,"pressure":1000,"humidity":84,"sea_level":1000,"grnd_level":998},"visibility":10000,
	"wind":{"speed":4.98,"deg":237,"gust":5.91},
	"rain":{"1h":0.63},
	"clouds":{"all":100},
	"dt":1747218129,"sys":{"type":2,"id":2046422,"country":"RU","sunrise":1747185799,"sunset":1747247228},"timezone":10800,"id":535729,
	"name":"Komendantsky aerodrom","cod":200}
	*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetButtonClick(TObject *Sender)
{
	TCursor Save_Cursor = Screen->Cursor;
	TIdHTTP *idHTTP = new TIdHTTP(NULL);
	idHTTP->Request->UserAgent = "Mozilla/5.0";
	String dt;  // unix time string - sec from 01.01.1970
	String weather;

	Screen->Cursor = crHourGlass;

	// get current weather data:
	ask_str = "http://api.openweathermap.org/data/2.5/weather?lat=" + DBEd_Lat->Text + "&lon=" + DBEd_Lng->Text + "&appid=" + sAPIkey;

	StatusBar1->Panels->Items[0]->Text = ask_str;
	try {
		response = idHTTP->Get(ask_str);
//		Memo1->Lines->Add(response);
	} __finally {
		delete idHTTP;
	}

	// parsing response:

	weather = GetJSONstr("stations", "sys");
//	Memo2->Lines->Add(weather);

	float tempVal = GetJSONval(weather, "temp");
	sTemp = FloatToStrF(tempVal - 272.15, ffFixed, 6, 1);
	LE_Temp->Text = sTemp;

	float cloudsVal = GetJSONval(weather, "clouds");
	sClouds = FloatToStrF(cloudsVal, ffFixed, 6, 1);
	LE_Clouds->Text = sClouds;

	float rainVal = GetJSONval(weather, "1h");
	sRain = FloatToStrF(rainVal, ffFixed, 6, 1);
	LE_Rain->Text = sRain;

	String timeVal = GetJSONtime(weather, "dt");
	LE_Date->Text = castDate;
	LE_Time->Text = castTime;
	Screen->Cursor = Save_Cursor;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
	dt = DateTimePicker1->DateTime;

	DB->Connected = true;
	T_Fields->Active = true;
	DBLCB_Fields->KeyValue = T_Fields->FieldByName("FieldID")->AsInteger;
	Q_Weather->Open("");
	edUnix->Text = FloatToStr(Dateutils::DateTimeToUnix(StrToDateTime(dt.DateString() )));
}
//---------------------------------------------------------------------------
String __fastcall TMainForm::ConvertDate(unsigned int sUnixDate, String &castDate, String &castTime)
{
	AnsiString s;
	unsigned int unixTime = sUnixDate; // Unix-время
	TDateTime dateTime = UnixToDateTime(unixTime);

	// Вывод в строку (формат по умолчанию)
	String dateStr = DateTimeToStr(dateTime);
	//	s = dateTime.TimeString();
	castDate = dateTime.DateString();
	s = dateTime.TimeString();
	castTime = s.SubString(1, s.Length()-3);
	return dateStr; 	// Пример: "21.07.2025 12:58:42"
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
		if (isdigit(fullStr[i])) {
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
void __fastcall TMainForm::DBAddButtonClick(TObject *Sender)
{
	Q_Weather->Close();
	sql = "INSERT INTO t_Weather (FieldID, wDate, wTime, Temp, Clouds, Rain) VALUES (" +
		T_Fields->FieldByName("FieldID")->AsString + ",'" + castDate + "','" + castTime + "'," +
		sTemp + "," + sClouds + "," + sRain + ")";
	DB->ExecSQL(sql);
	Q_Weather->Open("");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Q_WeatherBeforeOpen(TDataSet *DataSet)
{
	Q_Weather->Params->ParamByName("FieldID")->AsInteger = T_Fields->FieldByName("FieldID")->AsInteger;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBGrid2CellClick(TColumn *Column)
{
	DBLCB_Fields->KeyValue = T_Fields->FieldByName("FieldID")->AsInteger;
	GetButtonClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ArchiveButtonClick(TObject *Sender)
{
// Настройка HTTP-клиента
//	IdHTTP1->IOHandler = IdSSLIOHandlerSocketOpenSSL1;
//	IdHTTP1->Request->UserAgent = "Mozilla/5.0";
//	IdHTTP1->Request->Accept = "application/json";

	IdSSLIOHandlerSocketOpenSSL1->SSLOptions->Method = sslvSSLv23;
	TIdHTTP *idHTTP = new TIdHTTP(NULL);
	idHTTP->Request->UserAgent = "Mozilla/5.0";

	// Параметры запроса
	String apiKey = sAPIkey;
	String city = "Moscow";
	String countryCode = "RU";
	String units = "metric"; // или "imperial"
	String lang = "ru";

	// Установка даты (архив доступен с 1 января 1979 года)
//	TDateTime archiveDate = StrToDate("02.06.2025"); // пример даты
//	unsigned int unixTime = 1748860677;
	unsigned int unixTime = edUnix->Text.ToInt();

// Формирование URL
	ask_str = "http://api.openweathermap.org/data/2.5/weather?lat=" + DBEd_Lat->Text + "&lon=" + DBEd_Lng->Text + "&dt=" + (String)unixTime + "&appid=" + apiKey;
//	ask_str = "http://api.openweathermap.org/data/2.5/onecall/timemachine?lat=55.7558&lon=37.6173&dt=" + IntToStr(unixTime) + "&appid=" + apiKey + "&units=" + units + "&lang=" + lang;
	StatusBar1->Panels->Items[0]->Text = ask_str;
	try {
		response = idHTTP->Get(ask_str);
		Memo1->Lines->Add(response);
//		Memo1->Lines->Add(response);
	} __finally {
		delete idHTTP;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DateTimePicker1Change(TObject *Sender)
{
	dt = DateTimePicker1->DateTime;
	edUnix->Text = FloatToStr(Dateutils::DateTimeToUnix(StrToDateTime(dt.DateString() )));
//	__int64 unixDate = DateTimeToUnix(const AValue: TDateTime);
//	TDateTime date = UnixToDateTime(const __int64 AValue, bool AReturnUTC = true);     DateUtils::
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RP5ButtonClick(TObject *Sender)
{
	TIdHTTP *idHTTP = new TIdHTTP(NULL);
	TIdSSLIOHandlerSocketOpenSSL *SSLHandler = new TIdSSLIOHandlerSocketOpenSSL(NULL);

	IdHTTP1->HandleRedirects = true; // Разрешаем редиректы
	try {
		// Настройка HTTPS
		SSLHandler->SSLOptions->Method = sslvSSLv23;
//		IdHTTP1->IOHandler = SSLHandler;
		IdHTTP1->IOHandler = IdSSLIOHandlerSocketOpenSSL1;
		IdHTTP1->Request->UserAgent = "Mozilla/5.0";
		IdHTTP1->Request->Referer = "https://rp5.ru/Архив_погоды_в_Москве";

		// URL архива погоды (пример для Москвы)
		//		String url = "http://rp5.ru/Архив_погоды_в_Пулково_(аэропорт),_METAR";
		//		String url = "https://rp5.ru/Архив_погоды_в_Москве";
		String url = "https://rp5.ru/Архив_погоды_в_Москве";

		// Загрузка страницы
		String html = idHTTP->Get(url);
		Memo1->Text = html; // Вывод HTML (для отладки)

		// Далее парсим HTML (см. ниже)
	}	catch (Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
	delete SSLHandler;
	delete IdHTTP1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	GetButtonClick(this);
	DBAddButtonClick(this);
	if (T_Fields->Eof)
		T_Fields->First();
	else
		T_Fields->Next();
}
//---------------------------------------------------------------------------



