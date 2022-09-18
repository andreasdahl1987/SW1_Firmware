void funkyRotary(int Arow, int Acol, int Bcol) {

    int Row = Arow - 1;
    int Column = Acol - 1;
    int Number = buttonNumber[Row][Column];

    int bCol = Bcol - 1;

    if (!rawState[Row][Column] && !rawState[Row][bCol])
    {
        pushState[Row][Column] = 1;
    }
    else if (!rawState[Row][Column] && rawState[Row][bCol])
    {
        pushState[Row][Column] = 2;
        latchLock[Row][Column] = 1; //Fetching 01
    }
    else if (rawState[Row][Column] && rawState[Row][bCol])
    {
        pushState[Row][Column] = 3;
    }
    else if (rawState[Row][Column] && !rawState[Row][bCol])
    {
        pushState[Row][Column] = 4;
        latchLock[Row][bCol] = 1; //Fetching 10
    }

    if ((globalClock - switchTimer[Row][Column] > funkyCooldown) && (globalClock - switchTimer[Row][bCol] > funkyCooldown))
    {
        if ((latchLock[Row][bCol] && pushState[Row][Column] == 1) || (latchLock[Row][Column] && pushState[Row][Column] == 3))
        {
            switchTimer[Row][Column] = globalClock;
        }

        else if ((latchLock[Row][bCol] && pushState[Row][Column] == 3) || (latchLock[Row][Column] && pushState[Row][Column] == 1))
        {
            switchTimer[Row][bCol] = globalClock;
        }
    }

    else
    {
        latchLock[Row][bCol] = 0;
        latchLock[Row][Column] = 0;
    }

    Joystick.setButton(Number, (globalClock - switchTimer[Row][Column] < funkyPulse));
    Joystick.setButton(Number + 1, (globalClock - switchTimer[Row][bCol] < funkyPulse));

}
