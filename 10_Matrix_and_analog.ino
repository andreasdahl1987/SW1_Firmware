//------------------------------
//-------MATRIX VARIABLES-------
//------------------------------

uint8_t row[] = { 11, 3, 2, 30, 4, 12, 6 };
const uint8_t rowCount = sizeof(row) / sizeof(row[0]);

uint8_t col[] = { 7, A0, 13, 5, 10, 9, 8 };
const uint8_t colCount = sizeof(col) / sizeof(col[0]);

//---------------------------------------
//--------MATRIX DESCRIPTION-------------
//---------------------------------------

const uint8_t buttonNumber[rowCount][colCount] =
{
  {14, 0, 10, 11, 0, 1, 2},     //ROW 1
  {26, 27, 29, 25, 28, 0, 24},  //ROW 2
  {32, 31, 6, 0, 34, 18, 0},    //ROW 3
  {16, 0, 12, 13, 3, 4, 5},     //ROW 4
  {39, 41, 65, 0, 40, 0, 38},   //ROW 5
  {20, 0, 35, 33, 0, 0, 23},    //ROW 6
  {22, 37, 36 ,67 , 0, 0, 0}    //ROW 7
};


bool switchMode[rowCount][colCount] = //BOOT PRESET
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 1, 0, 0, 0, 0}, //ROW 6
  {0, 1, 0, 0, 0, 0, 0}  //ROW 7
};

//---------------------------------------
//--------ANALOG DESCRIPTION-------------
//---------------------------------------

const uint8_t analogButtonNumber[4] =         //ANALOG BUTTONS 1
{ 69, 81, 0, 0 };

const uint8_t analogButtonNumberIncMode[4] =  //ANALOG BUTTONS 2
{ 69, 81, 0, 0 };

int8_t analogSwitchMode1[4] = { 0, 0, 0, 0 }; //BOOT PRESET
int8_t analogSwitchMode2[4] = { 0, 0, 0, 0 };

//---------------------------------------
//--------------PRESETS------------------
//---------------------------------------


const bool preset1[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset2[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset3[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset4[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset5[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset6[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset7[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const bool preset8[rowCount][colCount] =
{
  {0, 0, 0, 0, 0, 0, 0}, //ROW 1
  {0, 0, 0, 0, 0, 0, 0}, //ROW 2
  {0, 0, 0, 0, 0, 0, 0}, //ROW 3
  {0, 0, 0, 0, 0, 0, 0}, //ROW 4
  {0, 0, 0, 0, 0, 0, 0}, //ROW 5
  {0, 0, 0, 0, 0, 0, 0}, //ROW 6
  {0, 0, 0, 0, 0, 0, 0}  //ROW 7
};

const int8_t analogMode1Preset1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset3[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset3[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset4[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset4[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset5[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset5[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset6[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset6[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset7[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset7[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const int8_t analogMode1Preset8[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const int8_t analogMode2Preset8[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };