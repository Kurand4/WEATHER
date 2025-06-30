object MainForm: TMainForm
  Left = 274
  Top = 154
  Caption = 'OpenWeatherMap '
  ClientHeight = 791
  ClientWidth = 1079
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1079
    Height = 791
    Align = alClient
    Caption = ' '
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 1
      Top = 710
      Width = 1077
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 1
      ExplicitWidth = 575
    end
    object Splitter2: TSplitter
      Left = 878
      Top = 1
      Height = 709
      Align = alRight
      ExplicitLeft = 736
      ExplicitTop = 272
      ExplicitHeight = 100
    end
    object StatusBar1: TStatusBar
      Left = 1
      Top = 771
      Width = 1077
      Height = 19
      Panels = <
        item
          Width = 999
        end
        item
          Width = 50
        end>
    end
    object Panel2: TPanel
      Left = 1
      Top = 713
      Width = 1077
      Height = 58
      Align = alBottom
      Caption = ' '
      TabOrder = 1
      DesignSize = (
        1077
        58)
      object RadioGroup1: TRadioGroup
        Left = 16
        Top = 3
        Width = 385
        Height = 44
        Caption = 'Mode'
        Columns = 3
        ItemIndex = 1
        Items.Strings = (
          'Archive'
          'Current'
          'Forecast')
        TabOrder = 0
      end
      object CloseButton: TButton
        Left = 912
        Top = 11
        Width = 137
        Height = 41
        Anchors = [akRight, akBottom]
        Caption = 'Close'
        TabOrder = 1
        OnClick = CloseButtonClick
      end
    end
    object Panel3: TPanel
      Left = 881
      Top = 1
      Width = 197
      Height = 709
      Align = alRight
      Caption = ' '
      TabOrder = 2
      DesignSize = (
        197
        709)
      object Label1: TLabel
        Left = 24
        Top = 21
        Width = 15
        Height = 13
        Caption = 'Lat'
      end
      object Label2: TLabel
        Left = 112
        Top = 21
        Width = 17
        Height = 13
        Caption = 'Lon'
      end
      object GetButton: TButton
        Left = 33
        Top = 504
        Width = 137
        Height = 33
        Anchors = [akRight, akBottom]
        Caption = 'OpenWeatherMap'
        TabOrder = 0
        OnClick = GetButtonClick
      end
      object DBLCB_Fields: TDBLookupComboBox
        Left = 33
        Top = 80
        Width = 145
        Height = 21
        Anchors = [akTop, akRight]
        KeyField = 'FieldID'
        ListField = 'FieldName'
        ListSource = DS_Fields
        TabOrder = 1
      end
      object DBEd_Lat: TDBEdit
        Left = 33
        Top = 40
        Width = 65
        Height = 21
        Anchors = [akTop, akRight]
        DataField = 'Lat'
        DataSource = DS_Fields
        TabOrder = 2
      end
      object DBEd_Lng: TDBEdit
        Left = 121
        Top = 40
        Width = 57
        Height = 21
        Anchors = [akTop, akRight]
        DataField = 'Lng'
        DataSource = DS_Fields
        TabOrder = 3
      end
      object LE_Temp: TLabeledEdit
        Left = 33
        Top = 228
        Width = 116
        Height = 21
        Anchors = [akTop, akRight]
        EditLabel.Width = 80
        EditLabel.Height = 13
        EditLabel.Caption = 'Temperature (C)'
        TabOrder = 4
      end
      object LE_Rain: TLabeledEdit
        Left = 33
        Top = 308
        Width = 116
        Height = 21
        Anchors = [akTop, akRight]
        EditLabel.Width = 58
        EditLabel.Height = 13
        EditLabel.Caption = 'Rain (mm/h)'
        TabOrder = 5
      end
      object LE_Clouds: TLabeledEdit
        Left = 33
        Top = 268
        Width = 116
        Height = 21
        Anchors = [akTop, akRight]
        EditLabel.Width = 54
        EditLabel.Height = 13
        EditLabel.Caption = 'Clouds (%)'
        TabOrder = 6
      end
      object LE_Time: TLabeledEdit
        Left = 33
        Top = 345
        Width = 116
        Height = 21
        Anchors = [akTop, akRight]
        EditLabel.Width = 22
        EditLabel.Height = 13
        EditLabel.Caption = 'Time'
        TabOrder = 7
      end
      object LE_Date: TLabeledEdit
        Left = 33
        Top = 385
        Width = 116
        Height = 21
        Anchors = [akTop, akRight]
        EditLabel.Width = 23
        EditLabel.Height = 13
        EditLabel.Caption = 'Date'
        TabOrder = 8
      end
      object DBAddButton: TButton
        Left = 33
        Top = 608
        Width = 137
        Height = 34
        Anchors = [akRight, akBottom]
        Caption = 'Add to DB'
        TabOrder = 9
        OnClick = DBAddButtonClick
      end
      object ArchiveButton: TButton
        Left = 32
        Top = 652
        Width = 137
        Height = 36
        Anchors = [akRight, akBottom]
        Caption = 'Archive'
        TabOrder = 10
        OnClick = ArchiveButtonClick
      end
      object DateTimePicker1: TDateTimePicker
        Left = 32
        Top = 168
        Width = 121
        Height = 21
        Date = 45813.210767905090000000
        Time = 45813.210767905090000000
        TabOrder = 11
        OnChange = DateTimePicker1Change
      end
      object edUnix: TLabeledEdit
        Left = 32
        Top = 141
        Width = 121
        Height = 21
        EditLabel.Width = 53
        EditLabel.Height = 13
        EditLabel.Caption = 'UNIX_Date'
        TabOrder = 12
      end
      object RP5Button: TButton
        Left = 32
        Top = 561
        Width = 137
        Height = 33
        Anchors = [akRight, akBottom]
        Caption = 'RP5.ru'
        TabOrder = 13
        OnClick = RP5ButtonClick
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 877
      Height = 709
      Align = alClient
      Caption = ' '
      TabOrder = 3
      object PageControl1: TPageControl
        Left = 1
        Top = 1
        Width = 875
        Height = 707
        ActivePage = TabSheet1
        Align = alClient
        TabOrder = 0
        object TabSheet1: TTabSheet
          Caption = 'TabSheet1'
          object DBGrid1: TDBGrid
            Left = 32
            Top = 240
            Width = 521
            Height = 385
            DataSource = DS_Weather
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -11
            TitleFont.Name = 'Tahoma'
            TitleFont.Style = []
            Columns = <
              item
                Expanded = False
                FieldName = 'wDate'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'wTime'
                Width = 58
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Temp'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Clouds'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Rain'
                Width = 67
                Visible = True
              end>
          end
          object DBGrid2: TDBGrid
            Left = 32
            Top = 15
            Width = 521
            Height = 202
            DataSource = DS_Fields
            TabOrder = 1
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -11
            TitleFont.Name = 'Tahoma'
            TitleFont.Style = []
            OnCellClick = DBGrid2CellClick
            Columns = <
              item
                Expanded = False
                FieldName = 'FieldID'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'FieldName'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Lat'
                Title.Alignment = taRightJustify
                Width = 77
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Lng'
                Title.Alignment = taRightJustify
                Width = 73
                Visible = True
              end>
          end
          object DBNavigator1: TDBNavigator
            Left = 313
            Top = 631
            Width = 240
            Height = 25
            DataSource = DS_Weather
            TabOrder = 2
          end
          object Memo1: TMemo
            Left = 559
            Top = 15
            Width = 305
            Height = 610
            Lines.Strings = (
              'Memo1')
            TabOrder = 3
          end
        end
        object TabSheet2: TTabSheet
          Caption = 'TabSheet2'
          ImageIndex = 1
          object DBChart1: TDBChart
            Left = 0
            Top = 0
            Width = 867
            Height = 679
            Title.Text.Strings = (
              'TDBChart')
            View3D = False
            Align = alClient
            TabOrder = 0
          end
        end
        object TabSheet3: TTabSheet
          Caption = 'TabSheet3'
          ImageIndex = 2
        end
      end
    end
  end
  object DB: TADConnection
    Params.Strings = (
      'Database=C:/AFI/WEATHER/OpenWeather.db'
      'DriverID=SQLite')
    LoginPrompt = False
    Left = 48
    Top = 48
  end
  object IdHTTP1: TIdHTTP
    AllowCookies = False
    HandleRedirects = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/5.0 (compatible; Indy Library)'
    HTTPOptions = [hoForceEncodeParams]
    Left = 104
    Top = 584
  end
  object T_Fields: TADTable
    IndexFieldNames = 'FieldID'
    Connection = DB
    UpdateOptions.UpdateTableName = 't_Fields'
    TableName = 't_Fields'
    Left = 808
    Top = 128
    object T_FieldsFieldID: TADAutoIncField
      FieldName = 'FieldID'
      Origin = 'FieldID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = False
    end
    object T_FieldsFieldName: TStringField
      FieldName = 'FieldName'
      Origin = 'FieldName'
      Size = 33
    end
    object T_FieldsLat: TFloatField
      FieldName = 'Lat'
      Origin = 'Lat'
    end
    object T_FieldsLng: TFloatField
      FieldName = 'Lng'
      Origin = 'Lng'
    end
  end
  object DS_Fields: TDataSource
    DataSet = T_Fields
    Left = 856
    Top = 128
  end
  object ADPhysSQLiteDriverLink1: TADPhysSQLiteDriverLink
    Left = 176
    Top = 48
  end
  object ADSQLiteSecurity1: TADSQLiteSecurity
    Left = 312
    Top = 48
  end
  object ADGUIxWaitCursor1: TADGUIxWaitCursor
    Left = 448
    Top = 48
  end
  object T_Weather: TADTable
    IndexFieldNames = 'wID'
    Connection = DB
    UpdateOptions.UpdateTableName = 'T_Weather'
    TableName = 'T_Weather'
    Left = 424
    Top = 720
    object T_WeatherwID: TADAutoIncField
      FieldName = 'wID'
      Origin = 'wID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = False
    end
    object T_WeatherFieldID: TIntegerField
      FieldName = 'FieldID'
      Origin = 'FieldID'
    end
    object T_WeatherwDate: TStringField
      FieldName = 'wDate'
      Origin = 'wDate'
      Size = 10
    end
    object T_WeatherwTime: TStringField
      FieldName = 'wTime'
      Origin = 'wTime'
      Size = 5
    end
    object T_WeatherTemp: TFloatField
      FieldName = 'Temp'
      Origin = '"Temp"'
      DisplayFormat = '#0.0'
    end
    object T_WeatherClouds: TIntegerField
      FieldName = 'Clouds'
      Origin = 'Clouds'
    end
    object T_WeatherRain: TLargeintField
      FieldName = 'Rain'
      Origin = 'Rain'
      DisplayFormat = '#0.0'
    end
  end
  object DS_Weather: TDataSource
    DataSet = Q_Weather
    Left = 600
    Top = 720
  end
  object Q_Weather: TADQuery
    BeforeOpen = Q_WeatherBeforeOpen
    MasterSource = DS_Fields
    MasterFields = 'FieldID'
    Connection = DB
    SQL.Strings = (
      'SELECT * FROM t_Weather'
      'WHERE FieldID=:FieldID')
    Left = 512
    Top = 720
    ParamData = <
      item
        Name = 'FIELDID'
        DataType = ftAutoInc
        ParamType = ptInput
        Size = 4
        Value = Null
      end>
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Method = sslvSSLv23
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 104
    Top = 504
  end
  object Timer1: TTimer
    Interval = 360000
    OnTimer = Timer1Timer
    Left = 704
    Top = 256
  end
  object Timer2: TTimer
    Interval = 36000
    Left = 704
    Top = 352
  end
end
