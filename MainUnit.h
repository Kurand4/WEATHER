//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
#include "Chart.hpp"
#include "DBChart.hpp"
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include "uADCompClient.hpp"
#include "uADCompDataSet.hpp"
#include "uADCompGUIx.hpp"
#include "uADDAptIntf.hpp"
#include "uADDAptManager.hpp"
#include "uADDatSManager.hpp"
#include "uADGUIxFormsWait.hpp"
#include "uADGUIxIntf.hpp"
#include "uADPhysIntf.hpp"
#include "uADPhysManager.hpp"
#include "uADPhysSQLite.hpp"
#include "uADStanAsync.hpp"
#include "uADStanDef.hpp"
#include "uADStanError.hpp"
#include "uADStanExprFuncs.hpp"
#include "uADStanIntf.hpp"
#include "uADStanOption.hpp"
#include "uADStanParam.hpp"
#include "uADStanPool.hpp"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <DateUtils.hpp> // Äëÿ UnixToDateTime
#include <SysUtils.hpp>

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//#include <DBXJSON.hpp>

#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
//#include <System.Net.HttpClient.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include <IdHTTP.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include "IdIOHandler.hpp"
#include "IdIOHandlerSocket.hpp"
#include "IdIOHandlerStack.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBXJSON.hpp>
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include <ExtCtrls.hpp>
#include "uADCompClient.hpp"
#include "uADGUIxIntf.hpp"
#include "uADPhysIntf.hpp"
#include "uADPhysManager.hpp"
#include "uADStanAsync.hpp"
#include "uADStanDef.hpp"
#include "uADStanError.hpp"
#include "uADStanIntf.hpp"
#include "uADStanOption.hpp"
#include "uADStanPool.hpp"
#include <DB.hpp>
#include "uADCompDataSet.hpp"
#include "uADDAptIntf.hpp"
#include "uADDAptManager.hpp"
#include "uADDatSManager.hpp"
#include "uADStanParam.hpp"
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include "uADPhysSQLite.hpp"
#include "uADStanExprFuncs.hpp"
#include "uADCompGUIx.hpp"
#include "uADGUIxFormsWait.hpp"
#include <Mask.hpp>
#include "Chart.hpp"
#include "DBChart.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "IdIOHandler.hpp"
#include "IdIOHandlerSocket.hpp"
#include "IdIOHandlerStack.hpp"
#include "IdSSL.hpp"
#include "IdSSLOpenSSL.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPanel *Panel3;
	TSplitter *Splitter2;
	TPanel *Panel4;
	TADConnection *DB;
	TIdHTTP *IdHTTP1;
	TADTable *T_Fields;
	TDataSource *DS_Fields;
	TButton *CloseButton;
	TButton *GetButton;
	TDBLookupComboBox *DBLCB_Fields;
	TADPhysSQLiteDriverLink *ADPhysSQLiteDriverLink1;
	TADSQLiteSecurity *ADSQLiteSecurity1;
	TADGUIxWaitCursor *ADGUIxWaitCursor1;
	TDBEdit *DBEd_Lat;
	TDBEdit *DBEd_Lng;
	TLabeledEdit *LE_Temp;
	TLabeledEdit *LE_Rain;
	TLabeledEdit *LE_Clouds;
	TRadioGroup *RadioGroup1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TDBChart *DBChart1;
	TLabeledEdit *LE_Time;
	TLabeledEdit *LE_Date;
	TButton *DBAddButton;
	TADTable *T_Weather;
	TDataSource *DS_Weather;
	TLabel *Label1;
	TLabel *Label2;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TADAutoIncField *T_WeatherwID;
	TIntegerField *T_WeatherFieldID;
	TStringField *T_WeatherwDate;
	TStringField *T_WeatherwTime;
	TFloatField *T_WeatherTemp;
	TIntegerField *T_WeatherClouds;
	TLargeintField *T_WeatherRain;
	TADAutoIncField *T_FieldsFieldID;
	TStringField *T_FieldsFieldName;
	TFloatField *T_FieldsLat;
	TFloatField *T_FieldsLng;
	TDBNavigator *DBNavigator1;
	TADQuery *Q_Weather;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TButton *ArchiveButton;
	TMemo *Memo1;
	TTabSheet *TabSheet3;
	TDateTimePicker *DateTimePicker1;
	TLabeledEdit *edUnix;
	void __fastcall GetButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall DBAddButtonClick(TObject *Sender);
	void __fastcall Q_WeatherBeforeOpen(TDataSet *DataSet);
	void __fastcall DBGrid2CellClick(TColumn *Column);
	void __fastcall ArchiveButtonClick(TObject *Sender);
	void __fastcall DateTimePicker1Change(TObject *Sender);

private:	// User declarations
	TDateTime dt;
	String  sAPIkey;
	String  sql;
	String 	ask_str, response;
	String  castDate, castTime;
	String  sTemp, sClouds, sRain;

	String __fastcall GetJSONstr(String startStr, String finStr);
	float  __fastcall GetJSONval(String fullStr, String startStr);
	String __fastcall GetJSONtime(String fullStr, String startStr);
	String __fastcall ConvertDate(unsigned int sUnixDate, String &castYear, String &castTime);

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
