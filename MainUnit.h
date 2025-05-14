//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
//#include <System.Net.HttpClient.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TIdHTTP *IdHTTP1;
	TButton *GetButton;
	TMemo *Memo1;
	TButton *CloseButton;
	TLabeledEdit *LE_Lat;
	TLabeledEdit *LE_Lng;
	TLabeledEdit *LE_Temp;
	TLabeledEdit *LE_Presipitation;
	void __fastcall GetButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
