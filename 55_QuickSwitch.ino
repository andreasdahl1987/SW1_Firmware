void quickSwitch(int8_t row, int8_t column)
{
    int8_t Row = row - 1;
    int8_t Column = column - 1;

    if (pushState[Row][Column] != rawState[Row][Column] && (globalClock - switchTimer[Row][Column]) > buttonCooldown)
    {
        switchTimer[Row][Column] = globalClock;
        pushState[Row][Column] = rawState[Row][Column];
    }

    if ((globalClock - switchTimer[Row][Column]) > buttonCooldown)
    {
        pushState[Row][Column] = rawState[Row][Column];
    }

    if (pushState[Row][Column] == 0)
    {
        latchLock[Row][Column] = false;
    }

    if (pushState[Row][Column] == 1 && !latchLock[Row][Column])
    {
        latchLock[Row][Column] = true;
        latchState[Row][Column] = !latchState[Row][Column];
    }

    quickSwitchState = latchState[Row][Column];

    //Push switch mode
    long push = 0;
    push = push | quickSwitchState;
    push = push << 7;
    buttonField = buttonField | push;
}
