object frmDeltaEVerify: TfrmDeltaEVerify
  Left = 281
  Top = 175
  BorderStyle = bsNone
  Caption = 'frmDeltaEVerify'
  ClientHeight = 531
  ClientWidth = 507
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object chartDeltaE: TChart
    Left = 0
    Top = 1
    Width = 500
    Height = 500
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Font.Charset = ANSI_CHARSET
    Title.Font.Color = clBlue
    Title.Font.Height = -21
    Title.Font.Name = 'Times New Roman'
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      'DeltaE94')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 1
    BottomAxis.Maximum = 8
    BottomAxis.Title.Caption = ' Patterns'
    BottomAxis.Title.Font.Charset = ANSI_CHARSET
    BottomAxis.Title.Font.Color = clBlack
    BottomAxis.Title.Font.Height = -16
    BottomAxis.Title.Font.Name = 'Times New Roman'
    BottomAxis.Title.Font.Style = [fsBold]
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 20
    LeftAxis.Title.Caption = 'DeltaE'
    LeftAxis.Title.Font.Charset = ANSI_CHARSET
    LeftAxis.Title.Font.Color = clBlack
    LeftAxis.Title.Font.Height = -16
    LeftAxis.Title.Font.Name = 'Times New Roman'
    LeftAxis.Title.Font.Style = [fsBold]
    Legend.Visible = False
    View3D = False
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
    object serBarDeltaE: TBarSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = 12615680
      Title = 'DeltaE94'
      BarStyle = bsCilinder
      BarWidthPercent = 50
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Bar'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object btnSaveToBmp: TButton
    Left = 421
    Top = 506
    Width = 81
    Height = 25
    Caption = 'Save to .bmp'
    TabOrder = 1
    OnClick = btnSaveToBmpClick
  end
  object SaveDialog1: TSaveDialog
    Filter = '*.bmp|*.bmp'
    Left = 504
  end
end
