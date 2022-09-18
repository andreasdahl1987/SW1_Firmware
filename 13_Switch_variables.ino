//Matrix variables

int8_t rawState[rowCount][colCount];
int8_t pushState[rowCount][colCount];
bool latchLock[rowCount][colCount];
bool latchState[rowCount][colCount];
bool switchModeLock[rowCount][colCount];
long switchTimer[rowCount][colCount];
long toggleTimer[rowCount][colCount];

//Analog variables

int8_t analogLastCounter[4];
int8_t analogTempState[4];
bool analogLatchLock[4];
long analogTimer1[4];
long analogTimer2[4];
int8_t analogRotaryCount[4];

#define clutchTopDeadzone 10
#define clutchBottomDeadzone 10

//Smoothing of analog signal

#define reads 4
int readings[4][reads];         // the readings from the analog input
int8_t readIndex[4];              // the index of the current reading
int total[4];                  // the running total
int average[4];