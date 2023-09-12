object frmGammaVerify: TfrmGammaVerify
  Left = 670
  Top = 76
  BorderStyle = bsNone
  ClientHeight = 544
  ClientWidth = 506
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
  object chartGamma: TChart
    Left = 0
    Top = 0
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
      'Gamma')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 256
    BottomAxis.Ticks.Visible = False
    BottomAxis.Title.Caption = 'Gray Step'
    BottomAxis.Title.Font.Charset = ANSI_CHARSET
    BottomAxis.Title.Font.Color = clBlack
    BottomAxis.Title.Font.Height = -16
    BottomAxis.Title.Font.Name = 'Times New Roman'
    BottomAxis.Title.Font.Style = [fsBold]
    Chart3DPercent = 1
    LeftAxis.Ticks.Visible = False
    LeftAxis.Title.Caption = 'Lv (cd/m^2)'
    LeftAxis.Title.Font.Charset = ANSI_CHARSET
    LeftAxis.Title.Font.Color = clBlack
    LeftAxis.Title.Font.Height = -16
    LeftAxis.Title.Font.Name = 'Times New Roman'
    LeftAxis.Title.Font.Style = [fsBold]
    Legend.Visible = False
    View3D = False
    View3DOptions.Elevation = 270
    View3DOptions.Orthogonal = False
    View3DOptions.Perspective = 0
    View3DOptions.ZoomText = False
    View3DWalls = False
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
    object PointSeriesGammaMeas: TPointSeries
      Marks.ArrowLength = 0
      Marks.Visible = False
      SeriesColor = clGreen
      Title = 'Gamma measure'
      Pointer.Brush.Color = clRed
      Pointer.InflateMargins = True
      Pointer.Pen.Visible = False
      Pointer.Style = psTriangle
      Pointer.Visible = True
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object LineSeriesGammaRef: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'Gamma Ref'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object rgRefGammaIndex: TRadioGroup
    Left = 3
    Top = 503
    Width = 185
    Height = 39
    Caption = 'Reference Gamma'
    Columns = 3
    ItemIndex = 1
    Items.Strings = (
      '2.0'
      '2.2'
      '2.4')
    TabOrder = 1
    OnClick = rgRefGammaIndexClick
  end
  object btnSavetoBmp: TButton
    Left = 419
    Top = 507
    Width = 81
    Height = 25
    Caption = 'Save to .bmp'
    TabOrder = 2
    OnClick = btnSavetoBmpClick
  end
  object SaveDialog1: TSaveDialog
    Filter = '*.bmp|*.bmp'
    Left = 536
  end
end
